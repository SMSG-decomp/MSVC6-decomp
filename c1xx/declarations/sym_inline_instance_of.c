void * __cdecl sym_inline_instance_of(c1_symbol *key)

{
  void *pvVar1;
  
  pvVar1 = symtab_lookup(g_inline_instance_table,key);
  return pvVar1;
}

