c1_u8 * __fastcall lex_source_peek_token(c1xx_lex_source_stream *stream)

{
  c1_u8 *token;
  
  token = (*stream->vtbl->lex_source_next_token)(stream);
  (*stream->vtbl->lex_source_unget_token)(stream,token);
  return token;
}

