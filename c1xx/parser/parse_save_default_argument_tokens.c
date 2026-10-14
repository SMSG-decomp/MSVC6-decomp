c1xx_token * __cdecl parse_save_default_argument_tokens(void)

{
  c1xx_token_cursor *cursor;
  int *piVar1;
  c1xx_token_stream *pcVar2;
  int iVar3;
  c1xx_token *pcVar4;
  c1_u32 stop_set;
  c1_arena *pcVar5;
  c1xx_token *pcVar6;
  int iVar7;
  uint *puVar8;
  int *piVar9;
  c1xx_token_stream *this;
  void **ppvVar10;
  
  if (((g_compile_flags_c8 & 0x10000000) == 0) && ((g_compile_flags_cc & 8) == 0)) {
    iVar7 = 3;
  }
  else {
    iVar7 = 0;
  }
  piVar9 = (int *)g_arenas[iVar7].cur;
  piVar1 = (int *)g_arenas[iVar7].end;
  pcVar5 = g_arenas + iVar7;
  pcVar5->cur = (c1_u8 *)(piVar9 + 2);
  if (piVar1 < piVar9 + 2) {
    arena_grow(pcVar5);
  }
  if (piVar9 == (int *)0x0) {
    piVar9 = (int *)0x0;
  }
  else {
    *piVar9 = g_token_arena_index;
    piVar9[1] = (int)g_token_arena_stack;
  }
  this = (c1xx_token_stream *)pcVar5->cur;
  pcVar2 = (c1xx_token_stream *)g_arenas[iVar7].end;
  g_token_arena_index = iVar7;
  g_token_arena_stack = piVar9;
  pcVar5->cur = (c1_u8 *)(this + 1);
  if (pcVar2 < this + 1) {
    arena_grow(pcVar5);
  }
  iVar3 = g_token_position;
  if (this == (c1xx_token_stream *)0x0) {
    this = (c1xx_token_stream *)0x0;
  }
  else {
    cursor = &this->first;
    this->start_position = g_token_position;
    this->position = iVar3;
    token_buffer_init(cursor,iVar7);
    this->arena = iVar7;
    this->vtbl = (c1xx_token_stream_vtbl *)&PTR_token_stream_next_raw_104bc55c;
    (this->read).chunk = cursor->chunk;
    (this->read).index = (this->first).index;
    (this->read).arena = (this->first).arena;
    iVar7 = (this->first).index;
    (this->write).chunk = cursor->chunk;
    iVar3 = (this->first).arena;
    (this->write).index = iVar7;
    (this->write).arena = iVar3;
    this->flags = this->flags | 1;
  }
  if ((g_compile_flags_c8 & 0x10000000) == 0) {
    g_compile_flags_c8 = g_compile_flags_c8 & 0xf7ffffff;
    (*this->vtbl->append)(this,(int)g_token_default_argument);
    stop_set = 0x88;
  }
  else {
    stop_set = 0x480;
    g_compile_flags_c8 = g_compile_flags_c8 & 0xf7ffffff;
  }
  parse_record_tokens_to_delimiter(this,stop_set,'\0');
  if ((g_compile_flags_c8 & 0x10000000) == 0) {
    (*this->vtbl->append)(this,(int)g_token_semicolon);
  }
  (*this->vtbl->append)(this,g_token_end_of_stream);
  g_compile_flags_c8 = g_compile_flags_c8 | 0x1000000;
  g_token_arena_index = *g_token_arena_stack;
  g_token_arena_stack = (int *)g_token_arena_stack[1];
  g_compile_flags_cc = g_compile_flags_cc | 0x10;
  g_context_arena_index = 0;
  g_expr_arena_index = 0;
  g_yylval = (uint)this;
  if (g_token_arena_index == 0) {
    if (g_pool_default_left < 0x30) {
      pool_reserve((c1xx_pool *)&g_pool_default,0x30);
    }
    g_pool_default_left = g_pool_default_left - 0x30;
    pcVar6 = (c1xx_token *)g_pool_default;
    g_pool_default = g_pool_default + 0x30;
  }
  else {
    pcVar5 = g_arenas + g_token_arena_index;
    pcVar6 = (c1xx_token *)pcVar5->cur;
    pcVar4 = (c1xx_token *)g_arenas[g_token_arena_index].end;
    pcVar5->cur = &pcVar6[1].code;
    if (pcVar4 < pcVar6 + 1) {
      arena_grow(pcVar5);
    }
  }
  if (pcVar6 == (c1xx_token *)0x0) {
    return (c1xx_token *)0x0;
  }
  pcVar6->code = 0xc6;
  puVar8 = &g_yylval;
  ppvVar10 = &pcVar6->value;
  for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
    *ppvVar10 = (void *)*puVar8;
    puVar8 = puVar8 + 1;
    ppvVar10 = ppvVar10 + 1;
  }
  return pcVar6;
}

