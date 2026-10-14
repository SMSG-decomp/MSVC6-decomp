c1_u8 * __cdecl lex_make_operator_name_token(byte *token)

{
  c1_u8 *pcVar1;
  uint uVar2;
  c1_arena *a;
  c1_u8 *pcVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  int directive;
  
  uVar2 = (uint)*token;
  if ((g_token_op_flags[uVar2] & 0x40) == 0) {
    if (*token == 6) {
      uVar2 = *(uint *)(token + 8);
      directive = 0x49;
    }
    else {
      directive = 0x4c;
    }
    diag_error(0x341,directive,uVar2);
    return g_token_newline;
  }
  g_yylval_word1 = name_intern(g_token_spelling[uVar2]);
  g_yylval._0_1_ = token[8];
  if (g_token_arena_index == 0) {
    if (g_pool_default_left < 0x30) {
      pool_reserve((c1xx_pool *)&g_pool_default,0x30);
    }
    g_pool_default_left = g_pool_default_left - 0x30;
    pcVar3 = g_pool_default;
    g_pool_default = g_pool_default + 0x30;
  }
  else {
    a = g_arenas + g_token_arena_index;
    pcVar3 = a->cur;
    pcVar1 = g_arenas[g_token_arena_index].end;
    a->cur = pcVar3 + 0x30;
    if (pcVar1 < pcVar3 + 0x30) {
      arena_grow(a);
    }
  }
  if (pcVar3 == (c1_u8 *)0x0) {
    return (c1_u8 *)0x0;
  }
  *pcVar3 = 0x8e;
  puVar5 = &g_yylval;
  puVar6 = (uint *)(pcVar3 + 8);
  for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  return pcVar3;
}

