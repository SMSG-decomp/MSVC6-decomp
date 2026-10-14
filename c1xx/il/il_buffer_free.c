void __fastcall il_buffer_free(c1_byte_buffer *buf)

{
  __3_YAXPAX_Z(buf->start);
  buf->size = 0;
  return;
}

