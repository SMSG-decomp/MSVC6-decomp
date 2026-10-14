void * __cdecl sym_get_attribute(c1_symbol *sym)

{
  void *pvVar1;
  
  pvVar1 = symtab_lookup(g_clone_attribute_table,(void *)(sym->entity & 0xffffff));
  return pvVar1;
}

