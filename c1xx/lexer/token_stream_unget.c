void __thiscall token_stream_unget(c1xx_token_stream *token_stream,char *token)

{
  c1_token_source_frame **ppcVar1;
  _func_193 **pp_Var2;
  c1_token_chunk *pcVar3;
  c1xx_token *pcVar4;
  int iVar5;
  c1xx_token_stream *pcVar6;
  
  iVar5 = g_token_arena_index;
  pcVar3 = (token_stream->read).chunk;
  if (((token != (char *)0x0) &&
      (pcVar4 = pcVar3->slots[(token_stream->read).index + -1], pcVar4 != (c1xx_token *)0x0)) &&
     (*token != pcVar4->code)) {
    pcVar6 = arena_alloc(g_arenas + g_token_arena_index,0x38);
    if (pcVar6 == (c1xx_token_stream *)0x0) {
      pcVar6 = (c1xx_token_stream *)0x0;
    }
    else {
      pcVar6 = token_stream_init(pcVar6,iVar5,1);
    }
    token_source_push((c1_token_reader *)&g_token_record_position,pcVar6,iVar5,0,(void *)0x0,
                      &g_token_position);
    (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)token);
    (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,g_token_end_of_stream);
    pcVar6 = (c1xx_token_stream *)0x0;
    if (g_token_save_frame != (c1_token_source_frame *)0x0) {
      ppcVar1 = &g_token_save_frame->prev;
      pcVar6 = g_token_save_frame->stream;
      g_token_record_position = g_token_save_frame->position;
      pp_Var2 = &g_token_save_frame->on_pop;
      g_token_save_frame = *ppcVar1;
      if (*pp_Var2 != (_func_193 *)0x0) {
        (**pp_Var2)();
      }
    }
    token_source_push((c1_token_reader *)&g_token_position,pcVar6,10,1,(void *)0x0,&g_token_position
                     );
    return;
  }
  iVar5 = (token_stream->read).index;
  (token_stream->read).index = iVar5 + -1;
  pcVar3->slots[iVar5 + -1] = (c1xx_token *)token;
  return;
}

