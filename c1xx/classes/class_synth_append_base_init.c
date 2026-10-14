void __cdecl class_synth_append_base_init(c1_symbol *base,int *count)

{
  c1xx_token_stream *this;
  c1_u8 *pcVar1;
  void *token;
  c1_arena *a;
  c1_u8 *pcVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  
  this = g_token_save_frame->stream;
  token = g_token_comma;
  if (*count == 0) {
    token = g_token_colon;
  }
  (*this->vtbl->append)(this,(int)token);
  *count = *count + 1;
  g_yylval = (uint)base->name;
  if (g_token_arena_index == 0) {
    if (g_pool_default_left < 0x30) {
      pool_reserve((c1xx_pool *)&g_pool_default,0x30);
    }
    g_pool_default_left = g_pool_default_left - 0x30;
    pcVar2 = g_pool_default;
    g_pool_default = g_pool_default + 0x30;
  }
  else {
    pcVar2 = arena_alloc(g_arenas + g_token_arena_index,0x30);
  }
  if (pcVar2 == (c1_u8 *)0x0) {
    pcVar2 = (c1_u8 *)0x0;
  }
  else {
    *pcVar2 = '\x06';
    puVar4 = &g_yylval;
    puVar5 = (uint *)(pcVar2 + 8);
    for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  (*this->vtbl->append)(this,(int)pcVar2);
  (*this->vtbl->append)(this,g_token_lparen);
  g_yylval = (uint)PTR_104d164c;
  if (g_token_arena_index == 0) {
    if (g_pool_default_left < 0x30) {
      pool_reserve((c1xx_pool *)&g_pool_default,0x30);
    }
    g_pool_default_left = g_pool_default_left - 0x30;
    pcVar2 = g_pool_default;
    g_pool_default = g_pool_default + 0x30;
  }
  else {
    a = g_arenas + g_token_arena_index;
    pcVar2 = a->cur;
    pcVar1 = g_arenas[g_token_arena_index].end;
    a->cur = pcVar2 + 0x30;
    if (pcVar1 < pcVar2 + 0x30) {
      arena_grow(a);
    }
  }
  if (pcVar2 == (c1_u8 *)0x0) {
    pcVar2 = (c1_u8 *)0x0;
  }
  else {
    *pcVar2 = '\x06';
    puVar4 = &g_yylval;
    puVar5 = (uint *)(pcVar2 + 8);
    for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  (*this->vtbl->append)(this,(int)pcVar2);
  (*this->vtbl->append)(this,g_token_rparen);
  return;
}

