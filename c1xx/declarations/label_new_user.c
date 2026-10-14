c1_u8 * __cdecl label_new_user(int name)

{
  c1_u8 *pcVar1;
  
  pcVar1 = g_arenas[4].cur;
  g_arenas[4].cur = g_arenas[4].cur + (g_symbol_size_table[9] + 3 & 0xfffffffc);
  if (g_arenas[4].end < g_arenas[4].cur) {
    arena_grow(g_arenas + 4);
  }
  if (pcVar1 != (c1_u8 *)0x0) {
    *pcVar1 = *pcVar1 & 0xe9 | 9;
    if ((int *)(pcVar1 + 8) != (int *)0x0) {
      pcVar1[0xc] = '\0';
      pcVar1[0xd] = '\0';
      pcVar1[0xe] = '\0';
      pcVar1[0xf] = '\0';
      *(int *)(pcVar1 + 8) = name;
    }
    pcVar1[0x24] = '\0';
    pcVar1[0x25] = '\0';
    pcVar1[0x26] = '\0';
    pcVar1[0x27] = '\0';
    *(c1_type **)(pcVar1 + 0x14) = g_type_none;
    return pcVar1;
  }
  uRam00000024 = 0;
  pcRam00000014 = g_type_none;
  return (c1_u8 *)0x0;
}

