c1_u8 * __cdecl record_pos_new(short a,short b,int *p)

{
  uchar *puVar1;
  
  puVar1 = g_arenas[3].cur;
  g_arenas[3].cur = g_arenas[3].cur + 0x10;
  if (g_arenas[3].end < g_arenas[3].cur) {
    arena_grow(g_arenas + 3);
  }
  *(short *)puVar1 = a;
  *(short *)(puVar1 + 2) = b;
  *(int *)(puVar1 + 8) = *p;
  return puVar1;
}

