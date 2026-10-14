void __thiscall token_source_unget(c1_token_reader *reader,c1xx_token *tok)

{
  c1xx_token_stream *token_stream;
  
  token_stream = reader->top->stream;
  (*token_stream->vtbl->unget)(token_stream,(char *)tok);
  return;
}

