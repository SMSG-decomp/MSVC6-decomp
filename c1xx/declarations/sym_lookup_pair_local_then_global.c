c1_symbol * __cdecl sym_lookup_pair_local_then_global(c1_symbol *key,uint *second)

{
  uint *entry_cell;
  
  entry_cell = symtab_lookup(g_sym_pair_table_local,key);
  if (entry_cell == (uint *)0x0) {
    entry_cell = symtab_lookup(g_sym_pair_table_global,key);
  }
  *second = entry_cell[1];
  return (c1_symbol *)*entry_cell;
}

