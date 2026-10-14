void __fastcall tu_end_emit_global_scope(int *scope)

{
  int *sym_link;
  byte bVar1;
  c1_node *node;
  c1_symbol *sym;
  int iVar2;
  uint uVar3;
  PB puVar4;
  uchar *puStack_8;
  uint uStack_4;
  
  g_il_block_level = '\0';
  if (g_error_count != 0) {
    g_il_block_level = '\0';
    return;
  }
  g_error_count = 0;
  for (sym_link = (int *)scope[0x84]; sym_link != (int *)0x0; sym_link = (int *)sym_link[1]) {
    il_emit_global_symbol(sym_link);
  }
  tu_emit_function_records();
  if ((g_pch_use_only == 0) || (g_opt_BnoWorkList != '\0')) {
    (**(code **)(*(int *)*scope + 0x20))();
  }
  else {
    sym_emit_deferred();
  }
  for (iVar2 = scope[0x84]; iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
    if (*(int *)(iVar2 + 0x24) != 0) {
      il_emit_global_symbol((int *)(*(int *)(iVar2 + 0x24) + 8));
      node = tree_new_symbol_ref((c1_symbol *)(iVar2 + -8));
      init_begin_variable(*(c1_symbol **)(iVar2 + 0x24));
      decl_finish_initialization(sym,node);
    }
  }
  if (g_c9il_mode != '\0') goto LAB_10620549;
  ilstore_fatal_write_error(1,(int)&puStack_8);
  iVar2 = uStack_4 + 1;
  if (iVar2 < 0) {
    bVar1 = 0;
  }
  else {
    if (g_il_gl.bytes.pbStart + g_il_gl.bytes.cbAlloc < g_il_gl.bytes.pbEnd + iVar2) {
      iVar2 = il_buffer_grow(&g_il_gl.bytes,iVar2);
      bVar1 = 0;
      if (iVar2 == 0) goto LAB_10649f25;
    }
    bVar1 = 1;
  }
LAB_10649f25:
  g_il_gl.open = g_il_gl.open & bVar1;
  if (g_il_gl.open != 0) {
    puVar4 = g_il_gl.bytes.pbEnd;
    for (uVar3 = uStack_4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)puVar4 = *(undefined4 *)puStack_8;
      puStack_8 = puStack_8 + 4;
      puVar4 = puVar4 + 4;
    }
    for (uVar3 = uStack_4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar4 = *puStack_8;
      puStack_8 = puStack_8 + 1;
      puVar4 = puVar4 + 1;
    }
    g_il_gl.bytes.pbEnd = g_il_gl.bytes.pbEnd + uStack_4;
  }
LAB_10620549:
  il_emit_symbol(10,(c1_symbol *)0x0);
  return;
}

