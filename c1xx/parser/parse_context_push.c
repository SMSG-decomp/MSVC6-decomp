void ** __fastcall parse_context_push(void **saved)

{
  c1_u8 *rec;
  c1_parse_state *pcVar1;
  
  rec = g_arenas[8].cur;
  g_parse_context_depth = g_parse_context_depth + 1;
  if (2000 < g_parse_context_depth) {
    diag_fatal_simple(0xca);
  }
  g_arenas[8].cur = g_arenas[8].cur + 0xc0;
  if (g_arenas[8].end < g_arenas[8].cur) {
    arena_grow(g_arenas + 8);
  }
  if (rec != (c1_u8 *)0x0) {
    pcVar1 = func_parse_state_save((c1_parse_state *)rec);
    *saved = pcVar1;
    parse_context_reset();
    return saved;
  }
  *saved = (void *)0x0;
  parse_context_reset();
  return saved;
}

