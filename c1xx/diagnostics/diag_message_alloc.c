msg * diag_message_alloc(void)

{
  c1_u8 *pcVar1;
  
  pcVar1 = g_arenas[9].cur;
  g_arenas[9].cur = g_arenas[9].cur + 0x48;
  if (g_arenas[9].end < g_arenas[9].cur) {
    arena_grow(g_arenas + 9);
  }
  return (msg *)pcVar1;
}

