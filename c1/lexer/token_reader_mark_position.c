void __fastcall token_reader_mark_position(c1_saved_token_stream *stream)

{
  (stream->read).block = (stream->start).block;
  (stream->read).index = (stream->start).index;
  (stream->read).arena = (stream->start).arena;
  return;
}

