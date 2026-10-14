void * __cdecl symtab_1700_lookup(c1_symbol *key)

{
  c1_symtab *tab;
  void *pvVar1;
  
  tab = symtab_ensure_1700();
  pvVar1 = symtab_lookup(tab,key);
  return pvVar1;
}

