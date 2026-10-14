void __fastcall tu_end_emit_global_scope(c1_scope_stack *scope_stack)

{
  int *symref;
  void *pvVar1;
  byte bVar2;
  c1_node *node;
  c1_symbol *sym;
  int iVar3;
  uint uVar4;
  c1_u8 *pcVar5;
  c1_ilstore_blob local_8;
  
  g_il_block_level = '\0';
  if (g_error_count != 0) {
    g_il_block_level = '\0';
    return;
  }
  g_error_count = 0;
  for (symref = scope_stack->segments; symref != (int *)0x0; symref = (int *)symref[1]) {
    il_emit_global_symbol(symref);
  }
  tu_emit_function_records();
  if ((g_pch_use_only == 0) || (g_opt_BnoWorkList != '\0')) {
    (*scope_stack->global_scope->vtbl->emit_il)(scope_stack->global_scope);
  }
  else {
    sym_emit_deferred();
  }
  for (pvVar1 = scope_stack->segments; pvVar1 != (void *)0x0; pvVar1 = *(void **)((int)pvVar1 + 4))
  {
    if (*(int *)((int)pvVar1 + 0x24) != 0) {
      il_emit_global_symbol((int *)(*(int *)((int)pvVar1 + 0x24) + 8));
      node = tree_new_symbol_ref((c1_symbol *)((int)pvVar1 + -8),'\0');
      sym = init_begin_variable(*(c1_symbol **)((int)pvVar1 + 0x24));
      decl_finish_initialization(sym,node);
    }
  }
  if (g_c9il_mode != '\0') goto LAB_104427ef;
  ilstore_fatal_write_error(1,&local_8);
  iVar3 = local_8.size + 1;
  if (iVar3 < 0) {
    bVar2 = 0;
  }
  else {
    if (g_il_gl.bytes.start + g_il_gl.bytes.size < g_il_gl.bytes.cur + iVar3) {
      iVar3 = il_buffer_grow(&g_il_gl.bytes,iVar3);
      bVar2 = 0;
      if (iVar3 == 0) goto LAB_10494221;
    }
    bVar2 = 1;
  }
LAB_10494221:
  g_il_gl.open = g_il_gl.open & bVar2;
  if (g_il_gl.open != 0) {
    pcVar5 = g_il_gl.bytes.cur;
    for (uVar4 = local_8.size >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)local_8.data;
      local_8.data = local_8.data + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar4 = local_8.size & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar5 = *local_8.data;
      local_8.data = local_8.data + 1;
      pcVar5 = pcVar5 + 1;
    }
    g_il_gl.bytes.cur = g_il_gl.bytes.cur + local_8.size;
  }
LAB_104427ef:
  il_emit_symbol(10,(c1_symbol *)0x0);
  return;
}

