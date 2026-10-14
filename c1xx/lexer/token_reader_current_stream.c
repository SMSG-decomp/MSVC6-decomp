c1xx_token_stream * __fastcall token_reader_current_stream(c1_token_reader *reader)

{
  return reader->top->stream;
}

