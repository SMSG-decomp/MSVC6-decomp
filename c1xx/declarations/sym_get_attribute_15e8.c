void * __cdecl sym_get_attribute_15e8(c1_symbol *sym)

{
  void *pvVar1;
  
  pvVar1 = symtab_lookup(g_vcall_attribute_table,(void *)(sym->entity & 0xffffff));
  return pvVar1;
}

