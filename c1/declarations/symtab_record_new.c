c1_u8 * __cdecl symtab_record_new(int count)

{
  uchar *puVar1;
  int iVar2;
  
  iVar2 = counted_array_size((short)count);
  puVar1 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + iVar2;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  puVar1[0] = '\0';
  puVar1[1] = '\0';
  *(short *)(puVar1 + 2) = (short)count;
  if (g_empty_symbol_vector == (c1_u8 *)0x0) {
    g_empty_symbol_vector = (c1_u8 *)0x1;
    g_empty_symbol_vector = symtab_record_new(0);
  }
  return puVar1;
}

