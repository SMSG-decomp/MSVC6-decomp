c1_u8 * __cdecl record_pos_new(short a,short b,int *p)

{
  c1_u8 *pcVar1;
  
  pcVar1 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x10;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  *(short *)pcVar1 = a;
  *(short *)(pcVar1 + 2) = b;
  *(int *)(pcVar1 + 8) = *p;
  return pcVar1;
}

