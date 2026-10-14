void include_alias_table_new(void)

{
  uchar *puVar1;
  
  puVar1 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 4;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  g_include_alias_table = (c1_include_alias **)puVar1;
  return;
}

