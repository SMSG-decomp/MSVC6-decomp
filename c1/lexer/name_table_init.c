void name_table_init(void)

{
  uchar *puVar1;
  
  puVar1 = g_arenas[0].cur;
  if (g_name_hash == (fe_name **)0x0) {
    g_arenas[0].cur = g_arenas[0].cur + 0x2000;
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    g_name_hash = (fe_name **)puVar1;
  }
  return;
}

