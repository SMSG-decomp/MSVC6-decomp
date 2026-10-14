void __fastcall ovl_candidates_alloc(c1_ovl_resolution *res)

{
  c1_u8 *pcVar1;
  
  pcVar1 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + (res->nargs * 0x50 + 0x40) * res->count;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  res->candidates = (c1_ovl_candidate *)pcVar1;
  res->conversions = (c1_conversion *)(pcVar1 + res->count * 0x40);
  return;
}

