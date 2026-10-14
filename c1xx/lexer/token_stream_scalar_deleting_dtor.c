c1xx_lex_source_stream * __thiscall
token_stream_scalar_deleting_dtor(c1xx_lex_source_stream *stream,byte flags)

{
  stream->vtbl = (c1xx_lex_source_stream_vtbl *)&PTR_token_stream_next_raw_104bc55c;
  if ((flags & 1) != 0) {
    __3_YAXPAX_Z(stream);
  }
  return stream;
}

