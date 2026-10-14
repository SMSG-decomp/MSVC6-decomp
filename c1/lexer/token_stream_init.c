c1_saved_token_stream * __thiscall
token_stream_init(c1_saved_token_stream *stream,int arena,byte flag)

{
  c1_token_cursor *buffer;
  int iVar1;
  int iVar2;
  
  iVar1 = g_token_position;
  buffer = &stream->start;
  stream->position = g_token_position;
  stream->position_end = iVar1;
  token_buffer_init(buffer,arena);
  stream->arena = arena;
  stream->vtbl = (c1_token_stream_vtbl *)&PTR_token_stream_next_raw_1065240c;
  (stream->read).block = buffer->block;
  (stream->read).index = (stream->start).index;
  (stream->read).arena = (stream->start).arena;
  iVar1 = (stream->start).index;
  (stream->write).block = buffer->block;
  iVar2 = (stream->start).arena;
  (stream->write).index = iVar1;
  (stream->write).arena = iVar2;
  stream->flags = (stream->flags ^ flag) & 1 ^ stream->flags;
  return stream;
}

