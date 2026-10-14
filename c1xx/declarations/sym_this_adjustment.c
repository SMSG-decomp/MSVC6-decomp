void * __cdecl sym_this_adjustment(c1_symbol *sym)

{
  void *pvVar1;
  
  pvVar1 = symtab_lookup(PTR_104d15e0,(void *)(sym->entity & 0xffffff));
  return pvVar1;
}

