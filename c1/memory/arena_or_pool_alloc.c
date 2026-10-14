c1_u8 * __cdecl arena_or_pool_alloc(uint n,int arena)

{
  uchar *puVar1;
  uchar *puVar2;
  c1_u8 *pcVar3;
  fe_arena *a;
  
  if (arena != 0) {
    a = g_arenas + arena;
    pcVar3 = a->cur;
    puVar1 = g_arenas[arena].end;
    puVar2 = pcVar3 + n;
    a->cur = puVar2;
    if (puVar1 < puVar2) {
      arena_grow(a);
    }
    return pcVar3;
  }
  if (g_pool_default.left < n) {
    pool_reserve(&g_pool_default,n);
  }
  pcVar3 = g_pool_default.cur;
  g_pool_default.cur = g_pool_default.cur + n;
  g_pool_default.left = g_pool_default.left - n;
  return pcVar3;
}

