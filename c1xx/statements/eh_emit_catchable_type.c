void __cdecl eh_emit_catchable_type(int *item)

{
  c1_symbol *sym;
  c1_node *pcVar1;
  int iVar2;
  uint uStack_8;
  int iStack_4;
  
  sym = (c1_symbol *)decl_begin_initialized_definition((c1_symbol *)*item);
  init_begin(sym,'\0');
  uStack_8 = (uint)(*(char *)((int)item + 5) != '\0');
  if ((char)item[1] != '\0') {
    uStack_8 = uStack_8 | 2;
  }
  if (*(char *)((int)item + 6) != '\0') {
    uStack_8 = uStack_8 | 4;
  }
  iVar2 = 0;
  iStack_4 = 0;
  pcVar1 = tree_new_constant(g_type_unsigned_int,&uStack_8,g_expr_arena_index);
  init_process_initializer(pcVar1,iVar2);
  iVar2 = 0;
  pcVar1 = expr_reference_named_entity((c1_symbol *)item[2],0);
  pcVar1 = (c1_node *)expr_build_unary(0x31,pcVar1);
  init_process_initializer(pcVar1,iVar2);
  init_check_too_many_2();
  if ((uint *)item[3] == (uint *)0x0) {
    iVar2 = 0;
    uStack_8 = 0;
    iStack_4 = 0;
    pcVar1 = tree_new_constant(g_type_int,&uStack_8,g_expr_arena_index);
    init_process_initializer(pcVar1,iVar2);
    uStack_8 = 0xffffffff;
    iStack_4 = -1;
  }
  else {
    uStack_8 = *(uint *)item[3];
    iStack_4 = (int)uStack_8 >> 0x1f;
    iVar2 = 0;
    pcVar1 = tree_new_constant(g_type_int,&uStack_8,g_expr_arena_index);
    init_process_initializer(pcVar1,iVar2);
    uStack_8 = *(uint *)(item[3] + 4);
    iStack_4 = (int)uStack_8 >> 0x1f;
    iVar2 = 0;
    pcVar1 = tree_new_constant(g_type_int,&uStack_8,g_expr_arena_index);
    init_process_initializer(pcVar1,iVar2);
    uStack_8 = *(uint *)(item[3] + 8);
    iStack_4 = (int)uStack_8 >> 0x1f;
  }
  iVar2 = 0;
  pcVar1 = tree_new_constant(g_type_int,&uStack_8,g_expr_arena_index);
  init_process_initializer(pcVar1,iVar2);
  init_pop_brace_level();
  uStack_8 = item[4];
  iVar2 = 0;
  iStack_4 = 0;
  pcVar1 = tree_new_constant(g_type_int,&uStack_8,g_expr_arena_index);
  init_process_initializer(pcVar1,iVar2);
  init_emit_pmfn_item((c1_symbol *)item[5]);
  init_finish(sym);
  return;
}

