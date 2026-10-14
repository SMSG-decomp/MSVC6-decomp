void __thiscall token_stream_unget(c1_saved_token_stream *stream,c1_token *token)

{
  c1_token_source_frame **ppcVar1;
  _func_240 **pp_Var2;
  c1_token_block *pcVar3;
  c1_u8 *pcVar4;
  int iVar5;
  c1_saved_token_stream *pcVar6;
  
  iVar5 = g_token_arena_index;
  pcVar3 = (stream->read).block;
  if (((token != (c1_token *)0x0) &&
      (pcVar4 = pcVar3->slot[(stream->read).index + -1], pcVar4 != (c1_u8 *)0x0)) &&
     (token->code != *pcVar4)) {
    pcVar6 = arena_alloc(g_arenas + g_token_arena_index,0x38);
    if (pcVar6 == (c1_saved_token_stream *)0x0) {
      pcVar6 = (c1_saved_token_stream *)0x0;
    }
    else {
      pcVar6 = token_stream_init(pcVar6,iVar5,1);
    }
    token_source_push(&g_token_record_position,(int)pcVar6,iVar5,0,0,&g_token_position);
    (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,token);
    (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,g_token_end_of_stream);
    pcVar6 = (c1_saved_token_stream *)0x0;
    if (g_token_save_frame != (c1_token_source_frame *)0x0) {
      ppcVar1 = &g_token_save_frame->prev;
      pcVar6 = g_token_save_frame->stream;
      g_token_record_position = g_token_save_frame->position;
      pp_Var2 = &g_token_save_frame->on_pop;
      g_token_save_frame = *ppcVar1;
      if (*pp_Var2 != (_func_240 *)0x0) {
        (**pp_Var2)();
      }
    }
    token_source_push(&g_token_position,(int)pcVar6,7,1,0,&g_token_position);
    return;
  }
  iVar5 = (stream->read).index;
  (stream->read).index = iVar5 + -1;
  pcVar3->slot[iVar5 + -1] = &token->code;
  return;
}

