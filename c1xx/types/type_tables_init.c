void __cdecl type_tables_init(void)

{
  c1_u8 *pcVar1;
  c1_u8 *pcVar2;
  uint **ppuVar3;
  uint **ppuVar4;
  
  pcVar1 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0x2000;
  pcVar2 = g_arenas[0].cur;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
    pcVar2 = g_arenas[0].cur;
  }
  g_type_hash = pcVar1;
  g_arenas[0].cur = pcVar2 + 0x1000;
  ppuVar3 = (uint **)g_arenas[0].cur;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
    ppuVar3 = (uint **)g_arenas[0].cur;
  }
  g_arenas[0].cur = (c1_u8 *)(ppuVar3 + 0x400);
  ppuVar4 = (uint **)g_arenas[0].cur;
  g_unused_hash_table = pcVar2;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
    ppuVar4 = (uint **)g_arenas[0].cur;
  }
  g_arenas[0].cur = (c1_u8 *)(ppuVar4 + 0x200);
  g_function_params_hash = ppuVar3;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  g_type_list_hash = ppuVar4;
  return;
}

