void __fastcall il_buffer_destroy(fe_il_buffer *buf)

{
  PB puVar1;
  
  if (buf->file != (FILE *)0x0) {
    fclose(buf->file);
  }
  if (buf->ilstore_stream_name != (char *)0x0) {
    mem_free(buf->ilstore_stream_name);
  }
  puVar1 = (buf->bytes).pbStart;
  if (puVar1 != (PB)0x0) {
    __3_YAXPAX_Z(puVar1);
    (buf->bytes).cbAlloc = 0;
  }
  return;
}

