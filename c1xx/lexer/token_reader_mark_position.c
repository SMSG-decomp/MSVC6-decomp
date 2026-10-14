void __fastcall token_reader_mark_position(c1xx_token_stream *stream)

{
  (stream->read).chunk = (stream->first).chunk;
  (stream->read).index = (stream->first).index;
  (stream->read).arena = (stream->first).arena;
  return;
}

