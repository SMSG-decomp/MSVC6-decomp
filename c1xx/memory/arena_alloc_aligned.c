c1_u8 * __cdecl arena_alloc_aligned(uint n)

{
  c1_u8 *pcVar1;
  
  pcVar1 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + (n + 3 & 0xfffffffc);
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  return pcVar1;
}

