c1_u8 * __cdecl pragma_string_argument(void)

{
  byte bVar1;
  c1_u8 *pcVar2;
  uchar *puVar3;
  byte *token;
  c1_arena *a;
  c1_u8 *pcVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  c1_string_value joined;
  
  puVar3 = pragma_warn_expected_token('\a');
  if (puVar3 == (uchar *)0x0) {
    return (c1_u8 *)0x0;
  }
  joined.text = *(c1_u8 **)(puVar3 + 8);
  joined._4_4_ = *(undefined4 *)(puVar3 + 0xc);
  token = token_next((c1_token_reader *)&g_token_position);
  bVar1 = *token;
  while (bVar1 == 7) {
    lex_concatenate_strings(&joined,(c1_string_value *)(token + 8));
    token = token_next((c1_token_reader *)&g_token_position);
    bVar1 = *token;
  }
  (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)token);
  g_yylval = (uint)joined.text;
  g_yylval_word1 = (c1_u8 *)joined._4_4_;
  if (g_token_arena_index == 0) {
    if (g_pool_default_left < 0x30) {
      pool_reserve((c1xx_pool *)&g_pool_default,0x30);
    }
    g_pool_default_left = g_pool_default_left - 0x30;
    pcVar4 = g_pool_default;
    g_pool_default = g_pool_default + 0x30;
  }
  else {
    a = g_arenas + g_token_arena_index;
    pcVar4 = a->cur;
    pcVar2 = g_arenas[g_token_arena_index].end;
    a->cur = pcVar4 + 0x30;
    if (pcVar2 < pcVar4 + 0x30) {
      arena_grow(a);
    }
  }
  if (pcVar4 != (c1_u8 *)0x0) {
    *pcVar4 = '\a';
    puVar6 = &g_yylval;
    puVar7 = (uint *)(pcVar4 + 8);
    for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    return pcVar4;
  }
  return (c1_u8 *)0x0;
}

