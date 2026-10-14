void __cdecl init_push_brace_level(c1_symbol *sym)

{
  uchar *puVar1;
  c1_symbol *pcVar2;
  
  pcVar2 = (c1_symbol *)g_arenas[1].cur;
  g_init_brace_depth = g_init_brace_depth + 1;
  g_init_level = g_init_levels + g_init_brace_depth;
  if (g_init_brace_depth < 0x20) {
    if (g_init_level->cursor == (c1_symbol *)0x0) {
      g_arenas[1].cur = g_arenas[1].cur + (g_symbol_size_table[1] + 3 & 0xfffffffc);
      if (g_arenas[1].end < g_arenas[1].cur) {
        arena_grow(g_arenas + 1);
      }
      if (pcVar2 == (c1_symbol *)0x0) {
        pcVar2 = (c1_symbol *)0x0;
      }
      else {
        puVar1 = (uchar *)((int)pcVar2 + 8);
        pcVar2->kind = pcVar2->kind & 0xe1 | 1;
        if (puVar1 != (uchar *)0x0) {
          puVar1[0] = '\0';
          puVar1[1] = '\0';
          puVar1[2] = '\0';
          puVar1[3] = '\0';
          *(uchar *)((int)pcVar2 + 0xc) = '\0';
          *(uchar *)((int)pcVar2 + 0xd) = '\0';
          *(uchar *)((int)pcVar2 + 0xe) = '\0';
          *(uchar *)((int)pcVar2 + 0xf) = '\0';
        }
      }
      g_init_level->cursor = pcVar2;
    }
    init_new_brace_level(g_init_level->cursor,sym,1);
    g_init_level->type = sym->type;
    g_init_level->cursor->type = g_init_level->type;
    g_init_level->from_string = '\0';
    g_init_level->count = 0;
    g_init_level->flags = '\0';
    return;
  }
  diag_fatal_simple(0x36);
}

