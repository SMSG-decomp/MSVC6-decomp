void __cdecl sym_set_or_clear_attribute(c1_symbol *sym,void *value)

{
  byte *pbVar1;
  
  if (value == (void *)0x0) {
    pbVar1 = (byte *)((int)&sym->tail + 10);
    *pbVar1 = *pbVar1 & 0xef;
    return;
  }
  if (g_clone_attribute_table == (c1_symtab *)0x0) {
    g_clone_attribute_table = symtab_new(0x1f,0,3,2,'\0','\0');
  }
  symtab_insert(g_clone_attribute_table,(void *)(sym->entity & 0xffffff),value);
  *(byte *)((int)&sym->tail + 10) = *(byte *)((int)&sym->tail + 10) | 0x10;
  return;
}

