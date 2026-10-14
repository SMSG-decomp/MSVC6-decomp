c1_u8 * __cdecl token_new_position_marker(int arena)

{
  c1_u8 *pcVar1;
  c1_arena *a;
  c1_u8 *pcVar2;
  int iVar3;
  uint *yylval_words;
  uint *puVar4;
  
  g_yylval = g_token_position;
  if (arena == 0) {
    if (g_pool_default_left < 0x30) {
      pool_reserve((c1xx_pool *)&g_pool_default,0x30);
    }
    g_pool_default_left = g_pool_default_left - 0x30;
    pcVar2 = g_pool_default;
    g_pool_default = g_pool_default + 0x30;
  }
  else {
    a = g_arenas + arena;
    pcVar2 = a->cur;
    pcVar1 = g_arenas[arena].end;
    a->cur = pcVar2 + 0x30;
    if (pcVar1 < pcVar2 + 0x30) {
      arena_grow(a);
    }
  }
  if (pcVar2 == (c1_u8 *)0x0) {
    return (c1_u8 *)0x0;
  }
  *pcVar2 = 0xf2;
  yylval_words = &g_yylval;
  puVar4 = (uint *)(pcVar2 + 8);
  for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *yylval_words;
    yylval_words = yylval_words + 1;
    puVar4 = puVar4 + 1;
  }
  return pcVar2;
}

