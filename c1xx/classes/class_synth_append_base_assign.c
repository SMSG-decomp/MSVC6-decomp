void __cdecl class_synth_append_base_assign(c1_symbol *base)

{
  c1xx_token_stream *this;
  byte *pbVar1;
  byte *tok;
  byte *tok_2;
  c1_arena *a;
  byte *tok_3;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  
  this = g_token_save_frame->stream;
  g_yylval = g_name_this;
  if (g_token_arena_index == 0) {
    tok = pool_alloc_raw(&g_pool_default,0x30);
  }
  else {
    tok = arena_alloc(g_arenas + g_token_arena_index,0x30);
  }
  if (tok == (byte *)0x0) {
    tok = (byte *)0x0;
  }
  else {
    *tok = 0x90;
    puVar3 = &g_yylval;
    puVar4 = (uint *)(tok + 8);
    for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  (*this->vtbl->append)(this,(int)tok);
  (*this->vtbl->append)(this,(int)g_token_arrow);
  g_yylval = (uint)base->name;
  if (g_token_arena_index == 0) {
    tok_2 = pool_alloc_raw(&g_pool_default,0x30);
  }
  else {
    tok_2 = arena_alloc(g_arenas + g_token_arena_index,0x30);
  }
  if (tok_2 == (byte *)0x0) {
    tok_2 = (byte *)0x0;
  }
  else {
    *tok_2 = 6;
    puVar3 = &g_yylval;
    puVar4 = (uint *)(tok_2 + 8);
    for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  (*this->vtbl->append)(this,(int)tok_2);
  (*this->vtbl->append)(this,(int)g_token_colon_colon);
  (*this->vtbl->append)(this,(int)g_token_operator);
  (*this->vtbl->append)(this,(int)g_token_assign);
  (*this->vtbl->append)(this,g_token_lparen);
  g_yylval = (uint)PTR_104d164c;
  if (g_token_arena_index == 0) {
    if (g_pool_default_left < 0x30) {
      pool_reserve((c1xx_pool *)&g_pool_default,0x30);
    }
    g_pool_default_left = g_pool_default_left - 0x30;
    tok_3 = g_pool_default;
    g_pool_default = g_pool_default + 0x30;
  }
  else {
    a = g_arenas + g_token_arena_index;
    tok_3 = a->cur;
    pbVar1 = g_arenas[g_token_arena_index].end;
    a->cur = tok_3 + 0x30;
    if (pbVar1 < tok_3 + 0x30) {
      arena_grow(a);
    }
  }
  if (tok_3 == (byte *)0x0) {
    tok_3 = (byte *)0x0;
  }
  else {
    *tok_3 = 6;
    puVar3 = &g_yylval;
    puVar4 = (uint *)(tok_3 + 8);
    for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  (*this->vtbl->append)(this,(int)tok_3);
  (*this->vtbl->append)(this,g_token_rparen);
  (*this->vtbl->append)(this,(int)g_token_semicolon);
  return;
}

