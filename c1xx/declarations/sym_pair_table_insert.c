void __cdecl sym_pair_table_insert(char local,c1_symbol *key,c1_symbol *first,void *second)

{
  uint arena;
  c1_symtab *pcVar1;
  c1_u8 *value;
  c1_symtab **ppcVar2;
  
  ppcVar2 = &g_sym_pair_table_local;
  if (local == '\0') {
    ppcVar2 = &g_sym_pair_table_global;
  }
  arena = -(uint)(local != '\0') & 4;
  if (*ppcVar2 == (c1_symtab *)0x0) {
    pcVar1 = symtab_new(0xb,arena,2,1,'\x01','\x01');
    *ppcVar2 = pcVar1;
  }
  value = sym_pair_new(first,second,arena);
  symtab_insert(*ppcVar2,key,value);
  return;
}

