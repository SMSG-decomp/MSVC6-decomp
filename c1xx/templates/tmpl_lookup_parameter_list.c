void * __cdecl tmpl_lookup_parameter_list(void *key)

{
  void *pvVar1;
  
  if (PTR_104d15f0 != (c1_symtab *)0x0) {
    pvVar1 = symtab_lookup(PTR_104d15f0,key);
    return pvVar1;
  }
  return (void *)0x0;
}

