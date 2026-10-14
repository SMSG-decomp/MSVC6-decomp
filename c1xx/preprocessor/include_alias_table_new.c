void __cdecl include_alias_table_new(void)

{
  c1_u8 *pcVar1;
  
  pcVar1 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 4;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  g_include_alias_table = pcVar1;
  return;
}

