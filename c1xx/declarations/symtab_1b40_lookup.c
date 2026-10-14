void * __cdecl symtab_1b40_lookup(c1_symbol *key)

{
  void *pvVar1;
  
  pvVar1 = symtab_lookup(g_declarator_record_table,key);
  return pvVar1;
}

