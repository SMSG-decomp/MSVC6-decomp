int __cdecl class_synth_copy_ctor_member_init_tokens(c1_symbol *member,int *count)

{
  c1xx_token_stream *this;
  c1_u8 *pcVar1;
  int iVar2;
  void *token;
  c1_u8 *ident_tok;
  c1_u8 *ident_tok_2;
  uint stream_token;
  c1_arena *a;
  c1_u8 *ident_tok_3;
  uint *src_3;
  uint *src_2;
  uint *src;
  uint *dst_3;
  uint *dst_2;
  uint *dst;
  
  iVar2 = member_is_copied_data(member);
  if ((char)iVar2 == '\0') {
    return CONCAT31((int3)((uint)iVar2 >> 8),1);
  }
  this = g_token_save_frame->stream;
  token = g_token_comma;
  if (*count == 0) {
    token = g_token_colon;
  }
  (*this->vtbl->append)(this,(int)token);
  *count = *count + 1;
  g_yylval = (uint)member->name;
  if (g_token_arena_index == 0) {
    ident_tok = pool_alloc_raw(&g_pool_default,0x30);
  }
  else {
    ident_tok = arena_alloc(g_arenas + g_token_arena_index,0x30);
  }
  if (ident_tok == (c1_u8 *)0x0) {
    ident_tok = (c1_u8 *)0x0;
  }
  else {
    *ident_tok = '\x06';
    src_3 = &g_yylval;
    dst_3 = (uint *)(ident_tok + 8);
    for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *dst_3 = *src_3;
      src_3 = src_3 + 1;
      dst_3 = dst_3 + 1;
    }
  }
  (*this->vtbl->append)(this,(int)ident_tok);
  (*this->vtbl->append)(this,g_token_lparen);
  g_yylval = (uint)PTR_104d164c;
  if (g_token_arena_index == 0) {
    ident_tok_2 = pool_alloc_raw(&g_pool_default,0x30);
  }
  else {
    ident_tok_2 = arena_alloc(g_arenas + g_token_arena_index,0x30);
  }
  if (ident_tok_2 == (c1_u8 *)0x0) {
    ident_tok_2 = (c1_u8 *)0x0;
  }
  else {
    *ident_tok_2 = '\x06';
    src_2 = &g_yylval;
    dst_2 = (uint *)(ident_tok_2 + 8);
    for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *dst_2 = *src_2;
      src_2 = src_2 + 1;
      dst_2 = dst_2 + 1;
    }
  }
  (*this->vtbl->append)(this,(int)ident_tok_2);
  (*this->vtbl->append)(this,(int)g_token_dot);
  g_yylval = (uint)member->name;
  if (g_token_arena_index == 0) {
    if (g_pool_default_left < 0x30) {
      pool_reserve((c1xx_pool *)&g_pool_default,0x30);
    }
    g_pool_default_left = g_pool_default_left - 0x30;
    ident_tok_3 = g_pool_default;
    g_pool_default = g_pool_default + 0x30;
  }
  else {
    a = g_arenas + g_token_arena_index;
    ident_tok_3 = a->cur;
    pcVar1 = g_arenas[g_token_arena_index].end;
    a->cur = ident_tok_3 + 0x30;
    if (pcVar1 < ident_tok_3 + 0x30) {
      arena_grow(a);
    }
  }
  if (ident_tok_3 == (c1_u8 *)0x0) {
    ident_tok_3 = (c1_u8 *)0x0;
  }
  else {
    *ident_tok_3 = '\x06';
    src = &g_yylval;
    dst = (uint *)(ident_tok_3 + 8);
    for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *dst = *src;
      src = src + 1;
      dst = dst + 1;
    }
  }
  (*this->vtbl->append)(this,(int)ident_tok_3);
  stream_token = (*this->vtbl->append)(this,g_token_rparen);
  return CONCAT31((int3)(stream_token >> 8),1);
}

