c1_u8 * __cdecl arena_or_pool_alloc(uint n,int arena)

{
  c1_u8 *pcVar1;
  c1_u8 *pcVar2;
  c1_u8 *pcVar3;
  c1_arena *a;
  
  if (arena != 0) {
    a = g_arenas + arena;
    pcVar3 = a->cur;
    pcVar1 = g_arenas[arena].end;
    pcVar2 = pcVar3 + n;
    a->cur = pcVar2;
    if (pcVar1 < pcVar2) {
      arena_grow(a);
    }
    return pcVar3;
  }
  if (g_pool_default_left < n) {
    pool_reserve((c1xx_pool *)&g_pool_default,n);
  }
  pcVar3 = g_pool_default;
  g_pool_default = g_pool_default + n;
  g_pool_default_left = g_pool_default_left - n;
  return pcVar3;
}

