c1_u8 * __cdecl arena_alloc_aligned(int n)

{
  uchar *puVar1;
  
  puVar1 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + (n + 3U & 0xfffffffc);
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  return puVar1;
}

