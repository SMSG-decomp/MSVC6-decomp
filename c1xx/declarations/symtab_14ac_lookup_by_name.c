void * __cdecl symtab_14ac_lookup_by_name(c1_symbol *sym)

{
  void *pvVar1;
  
  if (g_esumem_copy_table != (c1_symtab *)0x0) {
    pvVar1 = symtab_lookup(g_esumem_copy_table,sym->name);
    return pvVar1;
  }
  return (void *)0x0;
}

