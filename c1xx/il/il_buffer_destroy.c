void __fastcall il_buffer_destroy(c1_il_buffer *buf)

{
  c1_u8 *pcVar1;
  
  if ((FILE *)buf->file != (FILE *)0x0) {
    fclose((FILE *)buf->file);
  }
  if (buf->ilstore_stream_name != (char *)0x0) {
    mem_free(buf->ilstore_stream_name);
  }
  pcVar1 = (buf->bytes).start;
  if (pcVar1 != (c1_u8 *)0x0) {
    __3_YAXPAX_Z(pcVar1);
    (buf->bytes).size = 0;
  }
  return;
}

