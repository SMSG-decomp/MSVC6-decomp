void * __cdecl symtab_15f4_lookup(void *key)

{
  void *pvVar1;
  
  if (g_instance_arguments_table != (c1_symtab *)0x0) {
    pvVar1 = symtab_lookup(g_instance_arguments_table,key);
    return pvVar1;
  }
  return (void *)0x0;
}

