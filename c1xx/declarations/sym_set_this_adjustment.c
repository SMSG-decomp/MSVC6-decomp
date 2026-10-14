void __cdecl sym_set_this_adjustment(c1_symbol *fn,void *adj)

{
  byte *pbVar1;
  
  if (adj == (void *)0x0) {
    pbVar1 = (byte *)((int)&fn->tail + 10);
    *pbVar1 = *pbVar1 & 0xef;
    return;
  }
  if (PTR_104d15e0 == (c1_symtab *)0x0) {
    PTR_104d15e0 = symtab_new(0x1f,0,3,2,'\0','\0');
  }
  symtab_insert(PTR_104d15e0,(void *)(fn->entity & 0xffffff),adj);
  *(byte *)((int)&fn->tail + 10) = *(byte *)((int)&fn->tail + 10) | 0x10;
  return;
}

