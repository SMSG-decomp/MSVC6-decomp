c1_u8 * __cdecl pp_include_directive_token(int value)

{
  c1_token_source_frame **ppcVar1;
  _func_193 **pp_Var2;
  c1_u8 *pcVar3;
  c1xx_token_stream *pcVar4;
  c1_u8 *token;
  c1_u8 *token_2;
  c1_arena *a;
  c1_u8 *token_3;
  int iVar5;
  uint *puVar6;
  uint *dst_2;
  uint *dst;
  
  iVar5 = g_token_arena_index;
  pcVar4 = arena_alloc(g_arenas + g_token_arena_index,0x38);
  if (pcVar4 == (c1xx_token_stream *)0x0) {
    pcVar4 = (c1xx_token_stream *)0x0;
  }
  else {
    pcVar4 = token_stream_init(pcVar4,iVar5,0);
  }
  token_source_push((c1_token_reader *)&g_token_record_position,pcVar4,iVar5,0,(void *)0x0,
                    &g_token_position);
  g_yylval = value;
  token = token_new_position_marker(g_token_arena_index);
  (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)token);
  if (g_token_arena_index == 0) {
    token_2 = pool_alloc_raw(&g_pool_default,0x30);
  }
  else {
    token_2 = arena_alloc(g_arenas + g_token_arena_index,0x30);
  }
  if (token_2 == (c1_u8 *)0x0) {
    token_2 = (c1_u8 *)0x0;
  }
  else {
    *token_2 = ';';
    puVar6 = &g_yylval;
    dst_2 = (uint *)(token_2 + 8);
    for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *dst_2 = *puVar6;
      puVar6 = puVar6 + 1;
      dst_2 = dst_2 + 1;
    }
  }
  (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)token_2);
  (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)g_token_directive_end)
  ;
  pcVar4 = (c1xx_token_stream *)0x0;
  if (g_token_save_frame != (c1_token_source_frame *)0x0) {
    ppcVar1 = &g_token_save_frame->prev;
    pcVar4 = g_token_save_frame->stream;
    g_token_record_position = g_token_save_frame->position;
    pp_Var2 = &g_token_save_frame->on_pop;
    g_token_save_frame = *ppcVar1;
    if (*pp_Var2 != (_func_193 *)0x0) {
      (**pp_Var2)();
    }
  }
  g_yylval = (uint)pcVar4;
  if (g_token_arena_index == 0) {
    if (g_pool_default_left < 0x30) {
      pool_reserve((c1xx_pool *)&g_pool_default,0x30);
    }
    g_pool_default_left = g_pool_default_left - 0x30;
    token_3 = g_pool_default;
    g_pool_default = g_pool_default + 0x30;
  }
  else {
    a = g_arenas + g_token_arena_index;
    token_3 = a->cur;
    pcVar3 = g_arenas[g_token_arena_index].end;
    a->cur = token_3 + 0x30;
    if (pcVar3 < token_3 + 0x30) {
      arena_grow(a);
    }
  }
  if (token_3 == (c1_u8 *)0x0) {
    return (c1_u8 *)0x0;
  }
  *token_3 = 0xf4;
  puVar6 = &g_yylval;
  dst = (uint *)(token_3 + 8);
  for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *dst = *puVar6;
    puVar6 = puVar6 + 1;
    dst = dst + 1;
  }
  return token_3;
}

