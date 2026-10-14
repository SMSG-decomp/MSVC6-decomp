c1_token * __cdecl pp_include_directive_token(int value)

{
  c1_token_source_frame **ppcVar1;
  _func_240 **pp_Var2;
  c1_token *pcVar3;
  c1_saved_token_stream *pcVar4;
  c1_token *pcVar5;
  fe_arena *a;
  int iVar6;
  uint *puVar7;
  c1_yystype *pcVar8;
  
  iVar6 = g_token_arena_index;
  pcVar4 = arena_alloc(g_arenas + g_token_arena_index,0x38);
  if (pcVar4 == (c1_saved_token_stream *)0x0) {
    pcVar4 = (c1_saved_token_stream *)0x0;
  }
  else {
    pcVar4 = token_stream_init(pcVar4,iVar6,0);
  }
  token_source_push(&g_token_record_position,(int)pcVar4,iVar6,0,0,&g_token_position);
  g_yylval = value;
  pcVar5 = token_new_position_marker(g_token_arena_index);
  (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,pcVar5);
  if (g_token_arena_index == 0) {
    pcVar5 = (c1_token *)pool_alloc_raw(&g_pool_default,0x20);
  }
  else {
    pcVar5 = arena_alloc(g_arenas + g_token_arena_index,0x20);
  }
  if (pcVar5 == (c1_token *)0x0) {
    pcVar5 = (c1_token *)0x0;
  }
  else {
    pcVar5->code = ';';
    puVar7 = &g_yylval;
    pcVar8 = &pcVar5->value;
    for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
      pcVar8->words[0] = *puVar7;
      puVar7 = puVar7 + 1;
      pcVar8 = (c1_yystype *)((int)pcVar8 + 4);
    }
  }
  (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,pcVar5);
  (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,g_token_directive_end);
  pcVar4 = (c1_saved_token_stream *)0x0;
  if (g_token_save_frame != (c1_token_source_frame *)0x0) {
    ppcVar1 = &g_token_save_frame->prev;
    pcVar4 = g_token_save_frame->stream;
    g_token_record_position = g_token_save_frame->position;
    pp_Var2 = &g_token_save_frame->on_pop;
    g_token_save_frame = *ppcVar1;
    if (*pp_Var2 != (_func_240 *)0x0) {
      (**pp_Var2)();
    }
  }
  g_yylval = (uint)pcVar4;
  if (g_token_arena_index == 0) {
    if (g_pool_default.left < 0x20) {
      pool_reserve(&g_pool_default,0x20);
    }
    g_pool_default.left = g_pool_default.left - 0x20;
    pcVar5 = (c1_token *)g_pool_default.cur;
    g_pool_default.cur = g_pool_default.cur + 0x20;
  }
  else {
    a = g_arenas + g_token_arena_index;
    pcVar5 = (c1_token *)a->cur;
    pcVar3 = (c1_token *)g_arenas[g_token_arena_index].end;
    a->cur = &pcVar5[1].code;
    if (pcVar3 < pcVar5 + 1) {
      arena_grow(a);
    }
  }
  if (pcVar5 == (c1_token *)0x0) {
    return (c1_token *)0x0;
  }
  pcVar5->code = 0xf4;
  puVar7 = &g_yylval;
  pcVar8 = &pcVar5->value;
  for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
    pcVar8->words[0] = *puVar7;
    puVar7 = puVar7 + 1;
    pcVar8 = (c1_yystype *)((int)pcVar8 + 4);
  }
  return pcVar5;
}

