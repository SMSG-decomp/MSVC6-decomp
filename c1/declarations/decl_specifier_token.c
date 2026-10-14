c1_token * __thiscall decl_specifier_token(c1_specifier_state *spec,c1_u8 code)

{
  byte bVar1;
  c1_token *pcVar2;
  fe_arena *a;
  c1_token *pcVar3;
  int iVar4;
  uint *puVar5;
  c1_yystype *pcVar6;
  
  if (spec->spec_token != (c1_token *)0x0) {
    return spec->spec_token;
  }
  if (spec->type == (c1_type *)0x0) {
    spec->type = spec->named_type;
  }
  bVar1 = (spec->words).storage;
  if ((bVar1 & 7) == 0) {
    (spec->words).storage = bVar1 | 0x20;
  }
  g_yylval_word5 = spec->tag_insert;
  g_yylval_word4 = spec->named;
  _g_yylval_word3 = spec->type;
  g_yylval._0_1_ = (spec->words).storage;
  g_yylval._1_1_ = (spec->words).inlining;
  g_yylval._2_1_ = (spec->words).declspec;
  g_yylval._3_1_ = (spec->words).allocate;
  g_yylval_word1 = (spec->words).segment;
  g_yylval_word2 = (spec->words).flags8;
  unique0x00017201 = (spec->words).pad09[0];
  unique0x00017202 = (spec->words).pad09[1];
  unique0x00017203 = (spec->words).pad09[2];
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
  if (pcVar3 == (c1_token *)0x0) {
    spec->spec_token = (c1_token *)0x0;
    return (c1_token *)0x0;
  }
  pcVar3->code = code;
  puVar5 = &g_yylval;
  pcVar6 = &pcVar3->value;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    pcVar6->words[0] = *puVar5;
    puVar5 = puVar5 + 1;
    pcVar6 = (c1_yystype *)((int)pcVar6 + 4);
  }
  spec->spec_token = pcVar3;
  return pcVar3;
}

