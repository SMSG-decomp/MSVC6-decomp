c1_symtab * __cdecl symtab_ensure_16f4(void)

{
  if (g_special_member_alias_table_a == (c1_symtab *)0x0) {
    g_special_member_alias_table_a = symtab_new(0x1f,0,0,0,'\x01','\x01');
  }
  return g_special_member_alias_table_a;
}

