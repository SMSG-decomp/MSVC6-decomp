void * __cdecl symtab_1608_lookup(void *key)

{
  void *pvVar1;
  
  if (PTR_104d1608 != (c1_symtab *)0x0) {
    pvVar1 = symtab_lookup(PTR_104d1608,key);
    return pvVar1;
  }
  return (void *)0x0;
}

