c1_u8 * __cdecl token_new_decl_specifiers(int p1,byte storage,byte *spec,int p4)

{
  c1_u8 *pcVar1;
  byte bVar2;
  c1_u8 *pcVar3;
  c1_arena *a;
  int iVar4;
  int iVar5;
  uint *yylval_words;
  uint *yylval_words_4;
  uint *yylval_words_3;
  uint *yylval_words_2;
  uint local_18 [6];
  
  bVar2 = (byte)local_18[0];
  iVar5 = g_token_arena_index;
  if (spec == (byte *)0x0) {
    yylval_words_4 = local_18;
    for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
      *yylval_words_4 = 0;
      yylval_words_4 = yylval_words_4 + 1;
    }
    spec = (byte *)local_18;
    bVar2 = (byte)local_18[0] ^ ((byte)local_18[0] ^ bVar2 & 7) & 7;
    if (storage == 0) {
      bVar2 = bVar2 | 0x20;
    }
    local_18[0]._0_1_ = bVar2 ^ (bVar2 ^ storage) & 7;
  }
  g_yylval_spec_type = (c1_type *)p1;
  yylval_words_3 = &g_yylval;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *yylval_words_3 = *(uint *)spec;
    spec = (byte *)((int)spec + 4);
    yylval_words_3 = yylval_words_3 + 1;
  }
  g_yylval_spec_type_sym = (c1_symbol *)p4;
  if (iVar5 == 0) {
    if (g_pool_default_left < 0x30) {
      pool_reserve((c1xx_pool *)&g_pool_default,0x30);
    }
    g_pool_default_left = g_pool_default_left - 0x30;
    pcVar3 = g_pool_default;
    g_pool_default = g_pool_default + 0x30;
  }
  else {
    a = g_arenas + iVar5;
    pcVar3 = a->cur;
    pcVar1 = g_arenas[iVar5].end;
    a->cur = pcVar3 + 0x30;
    if (pcVar1 < pcVar3 + 0x30) {
      arena_grow(a);
    }
  }
  if (pcVar3 == (c1_u8 *)0x0) {
    return (c1_u8 *)0x0;
  }
  *pcVar3 = '$';
  yylval_words = &g_yylval;
  yylval_words_2 = (uint *)(pcVar3 + 8);
  for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *yylval_words_2 = *yylval_words;
    yylval_words = yylval_words + 1;
    yylval_words_2 = yylval_words_2 + 1;
  }
  return pcVar3;
}

