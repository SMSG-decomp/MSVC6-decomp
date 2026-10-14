void * __cdecl sym_extra_record(c1_symbol *key)

{
  void *pvVar1;
  
  pvVar1 = symtab_lookup(g_declspec_record_table,key);
  return pvVar1;
}

