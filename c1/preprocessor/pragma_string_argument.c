c1_token * __cdecl pragma_string_argument(void)

{
  c1_u8 cVar1;
  c1_token *pcVar2;
  c1_token *pcVar3;
  fe_arena *a;
  int iVar4;
  uint *puVar5;
  c1_yystype *pcVar6;
  uint joined [2];
  
  pcVar3 = pragma_warn_expected_token('\a');
  if (pcVar3 == (c1_token *)0x0) {
    return (c1_token *)0x0;
  }
  joined[0] = (pcVar3->value).words[0];
  joined[1] = (pcVar3->value).words[1];
  pcVar3 = token_next(&g_token_position);
  cVar1 = pcVar3->code;
  while (cVar1 == '\a') {
    lex_concatenate_strings((c1_string_value *)joined,&pcVar3->value);
    pcVar3 = token_next(&g_token_position);
    cVar1 = pcVar3->code;
  }
  (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar3);
  g_yylval = joined[0];
  g_yylval_word1 = joined[1];
  if (g_token_arena_index == 0) {
    if (g_pool_default.left < 0x20) {
      pool_reserve(&g_pool_default,0x20);
    }
    g_pool_default.left = g_pool_default.left - 0x20;
    pcVar3 = (c1_token *)g_pool_default.cur;
    g_pool_default.cur = g_pool_default.cur + 0x20;
  }
  else {
    a = g_arenas + g_token_arena_index;
    pcVar3 = (c1_token *)a->cur;
    pcVar2 = (c1_token *)g_arenas[g_token_arena_index].end;
    a->cur = &pcVar3[1].code;
    if (pcVar2 < pcVar3 + 1) {
      arena_grow(a);
    }
  }
  if (pcVar3 != (c1_token *)0x0) {
    pcVar3->code = '\a';
    puVar5 = &g_yylval;
    pcVar6 = &pcVar3->value;
    for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
      pcVar6->words[0] = *puVar5;
      puVar5 = puVar5 + 1;
      pcVar6 = (c1_yystype *)((int)pcVar6 + 4);
    }
    return pcVar3;
  }
  return (c1_token *)0x0;
}

