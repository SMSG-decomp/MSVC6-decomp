c1_token * __fastcall lex_source_peek_token(c1_source_stream *stream)

{
  c1_token *token;
  
  token = (*stream->vtbl->next)(stream);
  (*stream->vtbl->unget)(stream,token);
  return token;
}

