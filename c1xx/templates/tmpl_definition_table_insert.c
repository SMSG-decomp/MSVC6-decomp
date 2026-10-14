void __cdecl tmpl_definition_table_insert(void *value,c1_symbol *key)

{
  if (g_tmpl_definition_table == (c1_symtab *)0x0) {
    g_tmpl_definition_table = symtab_new(0x10,0,10,9,'\x01','\x01');
  }
  symtab_insert(g_tmpl_definition_table,key,value);
  return;
}

