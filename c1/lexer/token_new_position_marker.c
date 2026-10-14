c1_token * __cdecl token_new_position_marker(int arena)

{
  c1_token *pcVar1;
  fe_arena *a;
  c1_token *pcVar2;
  int iVar3;
  uint *puVar4;
  c1_yystype *pcVar5;
  
  g_yylval = g_token_position;
  if (arena == 0) {
    if (g_pool_default.left < 0x20) {
      pool_reserve(&g_pool_default,0x20);
    }
    g_pool_default.left = g_pool_default.left - 0x20;
    pcVar2 = (c1_token *)g_pool_default.cur;
    g_pool_default.cur = g_pool_default.cur + 0x20;
  }
  else {
    a = g_arenas + arena;
    pcVar2 = (c1_token *)a->cur;
    pcVar1 = (c1_token *)g_arenas[arena].end;
    a->cur = &pcVar2[1].code;
    if (pcVar1 < pcVar2 + 1) {
      arena_grow(a);
    }
  }
  if (pcVar2 == (c1_token *)0x0) {
    return (c1_token *)0x0;
  }
  pcVar2->code = 0xf2;
  puVar4 = &g_yylval;
  pcVar5 = &pcVar2->value;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    pcVar5->words[0] = *puVar4;
    puVar4 = puVar4 + 1;
    pcVar5 = (c1_yystype *)((int)pcVar5 + 4);
  }
  return pcVar2;
}

