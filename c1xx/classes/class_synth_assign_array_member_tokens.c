void __cdecl class_synth_assign_array_member_tokens(c1_symbol *member)

{
  byte *pbVar1;
  byte bVar2;
  c1xx_token_stream *this;
  c1_u8 *pcVar3;
  byte *pbVar4;
  void *pvVar5;
  char *tok;
  char *tok_2;
  char *tok_3;
  char *tok_4;
  c1_u8 *pcVar6;
  c1_arena *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  uint *src_4;
  uint *src_3;
  uint *src_2;
  uint *src;
  uint *puVar12;
  uint *dst_4;
  uint *dst_3;
  uint *dst_2;
  uint *dst;
  
  iVar8 = 0;
  iVar10 = 1;
  pbVar4 = (byte *)((uint)member->type & -(uint)((member->type->code & 0x80) != 0));
  bVar2 = *pbVar4;
  while ((bVar2 & 0x8f) == 0x83) {
    pbVar1 = pbVar4 + 8;
    pbVar4 = *(byte **)(pbVar4 + 4);
    iVar10 = iVar10 * *(int *)pbVar1;
    iVar8 = iVar8 + 1;
    bVar2 = *pbVar4;
  }
  pvVar5 = name_new_S();
  this = g_token_save_frame->stream;
  (*this->vtbl->append)(this,(int)g_token_for);
  (*this->vtbl->append)(this,g_token_lparen);
  (*this->vtbl->append)(this,(int)g_token_unsigned);
  g_yylval = (uint)pvVar5;
  tok = (char *)arena_or_pool_alloc(0x30,g_token_arena_index);
  if (tok == (char *)0x0) {
    tok = (char *)0x0;
  }
  else {
    *tok = '\x06';
    puVar11 = &g_yylval;
    puVar12 = (uint *)(tok + 8);
    for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar12 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
    }
  }
  (*this->vtbl->append)(this,(int)tok);
  (*this->vtbl->append)(this,(int)g_token_assign);
  _g_yylval_word2 = 0;
  _g_yylval_word3 = 0;
  g_yylval = (uint)g_type_int;
  tok_2 = (char *)arena_or_pool_alloc(0x30,g_token_arena_index);
  if (tok_2 == (char *)0x0) {
    tok_2 = (char *)0x0;
  }
  else {
    *tok_2 = 'e';
    puVar11 = &g_yylval;
    puVar12 = (uint *)(tok_2 + 8);
    for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar12 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
    }
  }
  (*this->vtbl->append)(this,(int)tok_2);
  (*this->vtbl->append)(this,(int)g_token_semicolon);
  g_yylval = (uint)pvVar5;
  tok_3 = (char *)arena_or_pool_alloc(0x30,g_token_arena_index);
  if (tok_3 == (char *)0x0) {
    tok_3 = (char *)0x0;
  }
  else {
    *tok_3 = '\x06';
    puVar11 = &g_yylval;
    puVar12 = (uint *)(tok_3 + 8);
    for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar12 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
    }
  }
  (*this->vtbl->append)(this,(int)tok_3);
  (*this->vtbl->append)(this,(int)g_token_less);
  _g_yylval_word3 = iVar10 >> 0x1f;
  g_yylval = (uint)g_type_int;
  _g_yylval_word2 = iVar10;
  if (g_token_arena_index == 0) {
    tok_4 = (char *)pool_alloc_raw(&g_pool_default,0x30);
  }
  else {
    tok_4 = arena_alloc(g_arenas + g_token_arena_index,0x30);
  }
  if (tok_4 == (char *)0x0) {
    tok_4 = (char *)0x0;
  }
  else {
    *tok_4 = 'e';
    puVar11 = &g_yylval;
    puVar12 = (uint *)(tok_4 + 8);
    for (iVar10 = 10; iVar10 != 0; iVar10 = iVar10 + -1) {
      *puVar12 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
    }
  }
  (*this->vtbl->append)(this,(int)tok_4);
  (*this->vtbl->append)(this,(int)g_token_semicolon);
  if (g_token_arena_index == 0) {
    g_yylval = (uint)pvVar5;
    pcVar6 = pool_alloc_raw(&g_pool_default,0x30);
  }
  else {
    g_yylval = (uint)pvVar5;
    pcVar6 = arena_alloc(g_arenas + g_token_arena_index,0x30);
  }
  if (pcVar6 == (c1_u8 *)0x0) {
    pcVar6 = (c1_u8 *)0x0;
  }
  else {
    *pcVar6 = '\x06';
    puVar11 = &g_yylval;
    puVar12 = (uint *)(pcVar6 + 8);
    for (iVar10 = 10; iVar10 != 0; iVar10 = iVar10 + -1) {
      *puVar12 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
    }
  }
  (*this->vtbl->append)(this,(int)pcVar6);
  (*this->vtbl->append)(this,(int)g_token_plus_plus);
  (*this->vtbl->append)(this,g_token_rparen);
  (*this->vtbl->append)(this,g_token_lparen);
  if (1 < iVar8) {
    iVar10 = iVar8 + -1;
    do {
      (*this->vtbl->append)(this,(int)g_token_star);
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  g_yylval = (uint)member->name;
  if (g_token_arena_index == 0) {
    pcVar6 = pool_alloc_raw(&g_pool_default,0x30);
  }
  else {
    pcVar6 = arena_alloc(g_arenas + g_token_arena_index,0x30);
  }
  if (pcVar6 == (c1_u8 *)0x0) {
    pcVar6 = (c1_u8 *)0x0;
  }
  else {
    *pcVar6 = '\x06';
    puVar11 = &g_yylval;
    puVar12 = (uint *)(pcVar6 + 8);
    for (iVar10 = 10; iVar10 != 0; iVar10 = iVar10 + -1) {
      *puVar12 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
    }
  }
  (*this->vtbl->append)(this,(int)pcVar6);
  (*this->vtbl->append)(this,g_token_rparen);
  (*this->vtbl->append)(this,(int)g_token_lbracket);
  if (g_token_arena_index == 0) {
    g_yylval = (uint)pvVar5;
    pcVar6 = pool_alloc_raw(&g_pool_default,0x30);
  }
  else {
    g_yylval = (uint)pvVar5;
    pcVar6 = arena_alloc(g_arenas + g_token_arena_index,0x30);
  }
  if (pcVar6 == (c1_u8 *)0x0) {
    pcVar6 = (c1_u8 *)0x0;
  }
  else {
    *pcVar6 = '\x06';
    src_4 = &g_yylval;
    dst_4 = (uint *)(pcVar6 + 8);
    for (iVar10 = 10; iVar10 != 0; iVar10 = iVar10 + -1) {
      *dst_4 = *src_4;
      src_4 = src_4 + 1;
      dst_4 = dst_4 + 1;
    }
  }
  (*this->vtbl->append)(this,(int)pcVar6);
  (*this->vtbl->append)(this,(int)g_token_rbracket);
  (*this->vtbl->append)(this,(int)g_token_assign);
  (*this->vtbl->append)(this,g_token_lparen);
  if (1 < iVar8) {
    iVar8 = iVar8 + -1;
    do {
      (*this->vtbl->append)(this,(int)g_token_star);
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  g_yylval = (uint)PTR_104d164c;
  if (g_token_arena_index == 0) {
    pcVar6 = pool_alloc_raw(&g_pool_default,0x30);
  }
  else {
    pcVar7 = g_arenas + g_token_arena_index;
    pcVar6 = pcVar7->cur;
    pcVar3 = g_arenas[g_token_arena_index].end;
    pcVar7->cur = pcVar6 + 0x30;
    if (pcVar3 < pcVar6 + 0x30) {
      arena_grow(pcVar7);
    }
  }
  if (pcVar6 == (c1_u8 *)0x0) {
    pcVar6 = (c1_u8 *)0x0;
  }
  else {
    *pcVar6 = '\x06';
    src_3 = &g_yylval;
    dst_3 = (uint *)(pcVar6 + 8);
    for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *dst_3 = *src_3;
      src_3 = src_3 + 1;
      dst_3 = dst_3 + 1;
    }
  }
  (*this->vtbl->append)(this,(int)pcVar6);
  (*this->vtbl->append)(this,(int)g_token_dot);
  g_yylval = (uint)member->name;
  if (g_token_arena_index == 0) {
    if (g_pool_default_left < 0x30) {
      pool_reserve((c1xx_pool *)&g_pool_default,0x30);
    }
    g_pool_default_left = g_pool_default_left - 0x30;
    pcVar6 = g_pool_default;
    g_pool_default = g_pool_default + 0x30;
  }
  else {
    pcVar6 = arena_alloc(g_arenas + g_token_arena_index,0x30);
  }
  if (pcVar6 == (c1_u8 *)0x0) {
    pcVar6 = (c1_u8 *)0x0;
  }
  else {
    *pcVar6 = '\x06';
    src_2 = &g_yylval;
    dst_2 = (uint *)(pcVar6 + 8);
    for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *dst_2 = *src_2;
      src_2 = src_2 + 1;
      dst_2 = dst_2 + 1;
    }
  }
  (*this->vtbl->append)(this,(int)pcVar6);
  (*this->vtbl->append)(this,g_token_rparen);
  (*this->vtbl->append)(this,(int)g_token_lbracket);
  if (g_token_arena_index == 0) {
    g_yylval = (uint)pvVar5;
    if (g_pool_default_left < 0x30) {
      pool_reserve((c1xx_pool *)&g_pool_default,0x30);
    }
    g_pool_default_left = g_pool_default_left - 0x30;
    pcVar6 = g_pool_default;
    g_pool_default = g_pool_default + 0x30;
  }
  else {
    pcVar7 = g_arenas + g_token_arena_index;
    pcVar6 = pcVar7->cur;
    pcVar3 = g_arenas[g_token_arena_index].end;
    g_yylval = (uint)pvVar5;
    pcVar7->cur = pcVar6 + 0x30;
    if (pcVar3 < pcVar6 + 0x30) {
      arena_grow(pcVar7);
    }
  }
  if (pcVar6 == (c1_u8 *)0x0) {
    pcVar6 = (c1_u8 *)0x0;
  }
  else {
    *pcVar6 = '\x06';
    src = &g_yylval;
    dst = (uint *)(pcVar6 + 8);
    for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *dst = *src;
      src = src + 1;
      dst = dst + 1;
    }
  }
  (*this->vtbl->append)(this,(int)pcVar6);
  (*this->vtbl->append)(this,(int)g_token_rbracket);
  (*this->vtbl->append)(this,(int)g_token_semicolon);
  return;
}

