void __cdecl sym_defer_emission(c1_symbol *sym)

{
  uchar *puVar1;
  
  puVar1 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 8;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  *(c1_symbol **)puVar1 = sym;
  *(void **)(puVar1 + 4) = g_deferred_symbols;
  g_deferred_symbols = puVar1;
  sym->kind = sym->kind | 0x20;
  return;
}

