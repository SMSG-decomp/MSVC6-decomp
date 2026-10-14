void * __cdecl sym_list_1b58_lookup(c1_symbol *key)

{
  void *pvVar1;
  
  pvVar1 = symtab_lookup(g_redeclaration_table,key);
  return pvVar1;
}

