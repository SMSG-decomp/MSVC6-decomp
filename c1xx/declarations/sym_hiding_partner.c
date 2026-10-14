void * __cdecl sym_hiding_partner(void *key)

{
  c1_symbol *pcVar1;
  void *pvVar2;
  
  if ((*(byte *)((int)key + 2) & 0x20) != 0) {
    pcVar1 = sym_hiding_partner_link(key);
    return pcVar1;
  }
  if ((*(byte *)((int)key + 2) & 0x40) != 0) {
    pvVar2 = symtab_lookup(g_hiding_pair_table,key);
    return pvVar2;
  }
  return (void *)0x0;
}

