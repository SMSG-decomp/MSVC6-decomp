c1_u8 * __cdecl scope_pool_or_arena_alloc(uint n,int arena)

{
  c1_u8 *pcVar1;
  c1_u8 *pcVar2;
  c1_u8 *pcVar3;
  c1_arena *a;
  
  if (arena == 0) {
    if (g_scope_pool_left < n) {
      pool_reserve((c1xx_pool *)&g_scope_pool,n);
    }
    pcVar2 = g_scope_pool;
    g_scope_pool = g_scope_pool + n;
    g_scope_pool_left = g_scope_pool_left - n;
    return pcVar2;
  }
  a = g_arenas + arena;
  pcVar2 = a->cur;
  pcVar1 = g_arenas[arena].end;
  pcVar3 = pcVar2 + n;
  a->cur = pcVar3;
  if (pcVar1 < pcVar3) {
    arena_grow(a);
  }
  return pcVar2;
}

