void __thiscall lex_source_unget_token(c1xx_lex_source_stream *stream,c1_u8 *token)

{
  stream->pushed[stream->pushed_count] = (c1xx_token *)token;
  stream->pushed_count = stream->pushed_count + 1;
  return;
}

