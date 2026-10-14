void * __cdecl symtab_16f8_lookup(void *key)

{
  c1_symtab *tab;
  void *pvVar1;
  
  tab = symtab_ensure_16f8();
  pvVar1 = symtab_lookup(tab,key);
  return pvVar1;
}

