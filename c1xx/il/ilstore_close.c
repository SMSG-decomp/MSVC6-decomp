void __fastcall ilstore_close(c1_il_buffer *buf)

{
  int iVar1;
  
  ilstore_flush(buf);
  iVar1 = (*buf->ilstore_stream->vtbl->release)();
  if (iVar1 == 0) {
    ilstore_report_error();
  }
  buf->ilstore_stream = (c1xx_pdb_stream *)0x0;
  return;
}

