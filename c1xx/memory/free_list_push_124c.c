void __cdecl free_list_push_124c(c1_symbol *sym)

{
  c1_u8 *pcVar1;
  c1_type_emission_cell **ppcVar2;
  
  ppcVar2 = g_type_emission_stack;
  if (g_type_emission_stack == (c1_type_emission_cell **)0x0) {
    ppcVar2 = (c1_type_emission_cell **)g_arenas[1].cur;
    g_arenas[1].cur = g_arenas[1].cur + 4;
    if (g_arenas[1].end < g_arenas[1].cur) {
      arena_grow(g_arenas + 1);
    }
  }
  g_type_emission_stack = ppcVar2;
  pcVar1 = g_arenas[5].cur;
  ppcVar2 = g_type_emission_stack;
  g_arenas[5].cur = g_arenas[5].cur + 8;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  *(c1_symbol **)pcVar1 = sym;
  *(c1_type_emission_cell **)(pcVar1 + 4) = *ppcVar2;
  *ppcVar2 = (c1_type_emission_cell *)pcVar1;
  return;
}

