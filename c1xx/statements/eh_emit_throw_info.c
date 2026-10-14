void __cdecl eh_emit_throw_info(c1_throw_info_item *item)

{
  byte bVar1;
  c1_symbol *sym;
  c1_node *pcVar2;
  int iVar3;
  uint auStack_8 [2];
  
  sym = (c1_symbol *)decl_begin_initialized_definition(item->sym);
  init_begin(sym,'\0');
  bVar1 = (byte)item->cv;
  auStack_8[0] = (uint)((bVar1 >> 5 & 1) != 0);
  if ((bVar1 >> 6 & 1) != 0) {
    auStack_8[0] = auStack_8[0] | 2;
  }
  if ((char)bVar1 < '\0') {
    auStack_8[0] = auStack_8[0] | 4;
  }
  iVar3 = 0;
  auStack_8[1] = 0;
  pcVar2 = tree_new_constant(g_type_unsigned_int,auStack_8,g_expr_arena_index);
  init_process_initializer(pcVar2,iVar3);
  init_emit_pmfn_item(item->dtor);
  auStack_8[0] = 0;
  auStack_8[1] = 0;
  iVar3 = 0;
  pcVar2 = tree_new_constant(g_type_unsigned_int,auStack_8,g_expr_arena_index);
  init_process_initializer(pcVar2,iVar3);
  init_emit_address_or_zero((int)item->catchable_array);
  init_finish(sym);
  return;
}

