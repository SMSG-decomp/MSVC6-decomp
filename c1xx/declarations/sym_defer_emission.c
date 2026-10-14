void __cdecl sym_defer_emission(c1_symbol *sym)

{
  c1_u8 *pcVar1;
  
  pcVar1 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 8;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  *(c1_symbol **)pcVar1 = sym;
  *(void **)(pcVar1 + 4) = g_deferred_symbols;
  g_deferred_symbols = pcVar1;
  sym->kind = sym->kind | 0x20;
  return;
}

