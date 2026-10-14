c1_symtab * __cdecl symtab_ensure_1704(void)

{
  if (g_placement_delete_target_table == (c1_symtab *)0x0) {
    g_placement_delete_target_table = symtab_new(0x1f,0,0,0,'\x01','\x01');
  }
  return g_placement_delete_target_table;
}

