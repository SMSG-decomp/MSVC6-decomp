void __cdecl tu_emit_guid_object(int *item)

{
  c1_symbol *sym;
  c1_node *pcVar1;
  int iVar2;
  int no_dynamic;
  uint auStack_8 [2];
  
  if ((char)item[2] == '\0') {
    sym = (c1_symbol *)decl_begin_initialized_definition((c1_symbol *)*item);
    *item = (int)sym;
    init_begin(sym,'\0');
    auStack_8[0] = *(uint *)item[1];
    iVar2 = 0;
    auStack_8[1] = 0;
    pcVar1 = tree_new_constant(g_type_unsigned_long,auStack_8,g_expr_arena_index);
    init_process_initializer(pcVar1,iVar2);
    auStack_8[0] = (uint)*(ushort *)(item[1] + 4);
    auStack_8[1] = 0;
    iVar2 = 0;
    pcVar1 = tree_new_constant(g_type_unsigned_short,auStack_8,g_expr_arena_index);
    init_process_initializer(pcVar1,iVar2);
    auStack_8[0] = (uint)*(ushort *)(item[1] + 6);
    auStack_8[1] = 0;
    iVar2 = 0;
    pcVar1 = tree_new_constant(g_type_unsigned_short,auStack_8,g_expr_arena_index);
    init_process_initializer(pcVar1,iVar2);
    iVar2 = 0;
    do {
      no_dynamic = 0;
      auStack_8[0] = (uint)*(byte *)(item[1] + 8 + iVar2);
      auStack_8[1] = 0;
      pcVar1 = tree_new_constant(g_type_unsigned_char,auStack_8,g_expr_arena_index);
      init_process_initializer(pcVar1,no_dynamic);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
    init_finish((c1_symbol *)*item);
    *(undefined1 *)(item + 2) = 1;
  }
  return;
}

