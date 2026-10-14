c1_symbol * __cdecl label_new_user(int name)

{
  uchar *puVar1;
  
  puVar1 = g_arenas[2].cur;
  g_arenas[2].cur = g_arenas[2].cur + (g_symbol_size_table[9] + 3 & 0xfffffffc);
  if (g_arenas[2].end < g_arenas[2].cur) {
    arena_grow(g_arenas + 2);
  }
  if (puVar1 != (uchar *)0x0) {
    *puVar1 = *puVar1 & 0xe9 | 9;
    if ((int *)(puVar1 + 8) != (int *)0x0) {
      puVar1[0xc] = '\0';
      puVar1[0xd] = '\0';
      puVar1[0xe] = '\0';
      puVar1[0xf] = '\0';
      *(int *)(puVar1 + 8) = name;
    }
    puVar1[0x24] = '\0';
    puVar1[0x25] = '\0';
    puVar1[0x26] = '\0';
    puVar1[0x27] = '\0';
    *(c1_type **)(puVar1 + 0x14) = g_type_none;
    return (c1_symbol *)puVar1;
  }
  uRam00000024 = 0;
  pcRam00000014 = g_type_none;
  return (c1_symbol *)0x0;
}

