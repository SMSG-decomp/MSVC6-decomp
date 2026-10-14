void __cdecl rtti_emit_class_hierarchy_descriptor(int *item)

{
  c1_symbol *sym;
  c1_node *pcVar1;
  int iVar2;
  int iStack_8;
  int iStack_4;
  
  sym = (c1_symbol *)decl_begin_initialized_definition((c1_symbol *)*item);
  init_begin(sym,'\0');
  iStack_8 = item[1];
  iStack_4 = iStack_8 >> 0x1f;
  iVar2 = 0;
  pcVar1 = tree_new_constant(g_type_unsigned_long,&iStack_8,g_expr_arena_index);
  init_process_initializer(pcVar1,iVar2);
  iStack_8 = item[2];
  iStack_4 = iStack_8 >> 0x1f;
  iVar2 = 0;
  pcVar1 = tree_new_constant(g_type_unsigned_long,&iStack_8,g_expr_arena_index);
  init_process_initializer(pcVar1,iVar2);
  iStack_8 = item[3];
  iStack_4 = iStack_8 >> 0x1f;
  iVar2 = 0;
  pcVar1 = tree_new_constant(g_type_unsigned_long,&iStack_8,g_expr_arena_index);
  init_process_initializer(pcVar1,iVar2);
  init_emit_address_or_zero(item[4]);
  init_finish(sym);
  return;
}

