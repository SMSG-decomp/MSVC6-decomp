void * __cdecl tmpl_definition_table_lookup(void *key)

{
  void *pvVar1;
  
  if (g_tmpl_definition_table != (c1_symtab *)0x0) {
    pvVar1 = symtab_lookup(g_tmpl_definition_table,key);
    return pvVar1;
  }
  return (void *)0x0;
}

