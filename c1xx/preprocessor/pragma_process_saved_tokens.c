int __cdecl pragma_process_saved_tokens(byte *token)

{
  c1_token_source_frame **ppcVar1;
  c1xx_token_stream *stream;
  int iVar2;
  uint *callback;
  
  stream = *(c1xx_token_stream **)(token + 8);
  (*stream->vtbl->start)(stream);
  token_source_push((c1_token_reader *)&g_token_position,stream,10,0,(void *)0x0,&g_token_position);
  iVar2 = pragma_dispatch();
  pragma_expect_dash_token();
  if (g_token_source != (c1_token_source_frame *)0x0) {
    ppcVar1 = &g_token_source->prev;
    g_token_position = g_token_source->position;
    callback = (uint *)&g_token_source->on_pop;
    g_token_source = *ppcVar1;
    if ((code *)*callback != (code *)0x0) {
      (*(code *)*callback)();
    }
  }
  return iVar2;
}

