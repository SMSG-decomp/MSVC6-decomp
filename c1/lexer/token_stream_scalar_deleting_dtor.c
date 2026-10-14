c1_token_stream * __thiscall token_stream_scalar_deleting_dtor(c1_token_stream *stream,byte flags)

{
  stream->vtbl = (c1_token_stream_vtbl *)&PTR_token_stream_next_raw_1065240c;
  if ((flags & 1) != 0) {
    __3_YAXPAX_Z(stream);
  }
  return stream;
}

