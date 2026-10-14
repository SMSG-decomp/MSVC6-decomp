void __fastcall ilstore_close(fe_il_buffer *buf)

{
  int iVar1;
  
  ilstore_flush(buf);
  iVar1 = (*buf->ilstore_stream->vtbl->Release)(buf->ilstore_stream);
  if (iVar1 == 0) {
    ilstore_report_error();
  }
  buf->ilstore_stream = (Stream *)0x0;
  return;
}

