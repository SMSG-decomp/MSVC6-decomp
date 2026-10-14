void __cdecl sym_list_1b58_insert(c1_symbol *sym,int value)

{
  c1_u8 *value_00;
  
  if (g_redeclaration_table == (c1_symtab *)0x0) {
    g_redeclaration_table = symtab_new(0x1f,0,0,2,'\x01','\x01');
  }
  value_00 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 8;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  if (value_00 == (c1_u8 *)0x0) {
    value_00 = (c1_u8 *)0x0;
  }
  else {
    *(fe_name **)value_00 = g_map_region_name;
    *(int *)(value_00 + 4) = value;
  }
  symtab_insert(g_redeclaration_table,sym,value_00);
  *(byte *)((int)&sym->tail + 10) = *(byte *)((int)&sym->tail + 10) | 0x80;
  return;
}

