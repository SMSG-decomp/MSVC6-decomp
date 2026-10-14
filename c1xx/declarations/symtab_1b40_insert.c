void __cdecl symtab_1b40_insert(c1_symbol *key,void *value)

{
  if (g_declarator_record_table == (c1_symtab *)0x0) {
    g_declarator_record_table = symtab_new(0x1f,0,0,0,'\x01','\x01');
  }
  symtab_insert(g_declarator_record_table,key,value);
  return;
}

