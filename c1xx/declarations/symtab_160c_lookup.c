void * __cdecl symtab_160c_lookup(void *key)

{
  void *pvVar1;
  
  if (PTR_104d160c != (c1_symtab *)0x0) {
    pvVar1 = symtab_lookup(PTR_104d160c,key);
    return pvVar1;
  }
  return (void *)0x0;
}

