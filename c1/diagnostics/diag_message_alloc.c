fe_message * diag_message_alloc(void)

{
  uchar *puVar1;
  
  puVar1 = g_arenas[6].cur;
  g_arenas[6].cur = g_arenas[6].cur + 0x48;
  if (g_arenas[6].end < g_arenas[6].cur) {
    arena_grow(g_arenas + 6);
  }
  return (fe_message *)puVar1;
}

