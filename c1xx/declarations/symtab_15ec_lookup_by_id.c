void * __cdecl symtab_15ec_lookup_by_id(c1_symbol *sym)

{
  void *pvVar1;
  
  if (g_debug_type_by_id_table != (c1_symtab *)0x0) {
    pvVar1 = symtab_lookup(g_debug_type_by_id_table,(void *)(sym->entity & 0xffffff));
    return pvVar1;
  }
  return (void *)0x0;
}

