c1_symbol_vector * __cdecl symtab_record_new(int count)

{
  c1_u8 *pcVar1;
  int iVar2;
  
  iVar2 = counted_array_size((short)count);
  pcVar1 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + iVar2;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  pcVar1[0] = '\0';
  pcVar1[1] = '\0';
  *(short *)(pcVar1 + 2) = (short)count;
  if (g_empty_symbol_vector == (c1_symbol_vector *)0x0) {
    g_empty_symbol_vector = (c1_symbol_vector *)0x1;
    g_empty_symbol_vector = symtab_record_new(0);
  }
  return (c1_symbol_vector *)pcVar1;
}

