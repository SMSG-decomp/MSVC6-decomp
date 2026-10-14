char __cdecl class_synth_assign_member_tokens(c1_symbol *member)

{
  c1_type *pcVar1;
  c1xx_token_stream *this;
  c1_u8 *pcVar2;
  int iVar3;
  char *tok;
  char *tok_2;
  c1_arena *a;
  char *tok_3;
  uint *src_3;
  uint *src_2;
  uint *src;
  uint *dst_3;
  uint *dst_2;
  uint *dst;
  
  iVar3 = member_is_copied_data(member);
  if ((char)iVar3 != '\0') {
    pcVar1 = member->type;
    if (((-1 < (char)pcVar1->code) || (pcVar1 == (c1_type *)0x0)) ||
       ((*(byte *)((uint)pcVar1 & -(uint)((pcVar1->code & 0x80) != 0)) & 0x8f) != 0x83)) {
      g_yylval = (uint)member->name;
      this = g_token_save_frame->stream;
      if (g_token_arena_index == 0) {
        tok = (char *)pool_alloc_raw(&g_pool_default,0x30);
      }
      else {
        tok = arena_alloc(g_arenas + g_token_arena_index,0x30);
      }
      if (tok == (char *)0x0) {
        tok = (char *)0x0;
      }
      else {
        *tok = '\x06';
        src_3 = &g_yylval;
        dst_3 = (uint *)(tok + 8);
        for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *dst_3 = *src_3;
          src_3 = src_3 + 1;
          dst_3 = dst_3 + 1;
        }
      }
      (*this->vtbl->append)(this,(int)tok);
      (*this->vtbl->append)(this,(int)g_token_assign);
      g_yylval = (uint)PTR_104d164c;
      if (g_token_arena_index == 0) {
        tok_2 = (char *)pool_alloc_raw(&g_pool_default,0x30);
      }
      else {
        tok_2 = arena_alloc(g_arenas + g_token_arena_index,0x30);
      }
      if (tok_2 == (char *)0x0) {
        tok_2 = (char *)0x0;
      }
      else {
        *tok_2 = '\x06';
        src_2 = &g_yylval;
        dst_2 = (uint *)(tok_2 + 8);
        for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *dst_2 = *src_2;
          src_2 = src_2 + 1;
          dst_2 = dst_2 + 1;
        }
      }
      (*this->vtbl->append)(this,(int)tok_2);
      (*this->vtbl->append)(this,(int)g_token_dot);
      g_yylval = (uint)member->name;
      if (g_token_arena_index == 0) {
        if (g_pool_default_left < 0x30) {
          pool_reserve((c1xx_pool *)&g_pool_default,0x30);
        }
        g_pool_default_left = g_pool_default_left - 0x30;
        tok_3 = (char *)g_pool_default;
        g_pool_default = g_pool_default + 0x30;
      }
      else {
        a = g_arenas + g_token_arena_index;
        tok_3 = (char *)a->cur;
        pcVar2 = g_arenas[g_token_arena_index].end;
        a->cur = (c1_u8 *)(tok_3 + 0x30);
        if (pcVar2 < tok_3 + 0x30) {
          arena_grow(a);
        }
      }
      if ((c1_u8 *)tok_3 == (c1_u8 *)0x0) {
        tok_3 = (char *)0x0;
      }
      else {
        *tok_3 = '\x06';
        src = &g_yylval;
        dst = (uint *)(tok_3 + 8);
        for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *dst = *src;
          src = src + 1;
          dst = dst + 1;
        }
      }
      (*this->vtbl->append)(this,(int)tok_3);
      (*this->vtbl->append)(this,(int)g_token_semicolon);
      return '\x01';
    }
    class_synth_assign_array_member_tokens(member);
  }
  return '\x01';
}

