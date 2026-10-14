c1_u8 * __cdecl arena5_alloc_1c(void)

{
  c1_u8 *pcVar1;
  
  pcVar1 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x1c;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  return pcVar1;
}

