void type_tables_init(void)

{
  uchar *puVar1;
  void **ppvVar2;
  c1_param_list_entry **ppcVar3;
  
  puVar1 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0x2000;
  ppvVar2 = (void **)g_arenas[0].cur;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
    ppvVar2 = (void **)g_arenas[0].cur;
  }
  g_type_hash = puVar1;
  g_arenas[0].cur = (uchar *)(ppvVar2 + 0x400);
  ppcVar3 = (c1_param_list_entry **)g_arenas[0].cur;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
    ppcVar3 = (c1_param_list_entry **)g_arenas[0].cur;
  }
  g_arenas[0].cur = (uchar *)(ppcVar3 + 0x400);
  g_type_tables_spare_hash = ppvVar2;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  g_param_list_hash = ppcVar3;
  return;
}

