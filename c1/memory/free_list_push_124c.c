void __cdecl free_list_push_124c(c1_symbol *sym)

{
  uchar *puVar1;
  c1_symbol_stack_node **ppcVar2;
  
  ppcVar2 = g_type_emission_stack;
  if (g_type_emission_stack == (c1_symbol_stack_node **)0x0) {
    ppcVar2 = (c1_symbol_stack_node **)g_arenas[1].cur;
    g_arenas[1].cur = g_arenas[1].cur + 4;
    if (g_arenas[1].end < g_arenas[1].cur) {
      arena_grow(g_arenas + 1);
    }
  }
  g_type_emission_stack = ppcVar2;
  puVar1 = g_arenas[3].cur;
  ppcVar2 = g_type_emission_stack;
  g_arenas[3].cur = g_arenas[3].cur + 8;
  if (g_arenas[3].end < g_arenas[3].cur) {
    arena_grow(g_arenas + 3);
  }
  *(c1_symbol **)puVar1 = sym;
  *(c1_symbol_stack_node **)(puVar1 + 4) = *ppcVar2;
  *ppcVar2 = (c1_symbol_stack_node *)puVar1;
  return;
}

