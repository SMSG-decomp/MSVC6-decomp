void __thiscall lex_source_unget_token(c1_source_stream *stream,c1_token *token)

{
  stream->unget[stream->unget_count] = token;
  stream->unget_count = stream->unget_count + 1;
  return;
}

