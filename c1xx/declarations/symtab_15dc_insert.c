void __cdecl symtab_15dc_insert(void *value,void *key)

{
  if (g_hiding_pair_table == (c1_symtab *)0x0) {
    g_hiding_pair_table = symtab_new(0x10,0,0xe,0xd,'\x01','\x01');
  }
  symtab_insert(g_hiding_pair_table,key,value);
  return;
}

