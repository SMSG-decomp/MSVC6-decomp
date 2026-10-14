void __fastcall ilstore_flush(fe_il_buffer *buf)

{
  PB pvBuf;
  int iVar1;
  
  pvBuf = (buf->bytes).pbStart;
  iVar1 = (int)(buf->bytes).pbEnd - (int)pvBuf;
  if (iVar1 != 0) {
    if (((((uint)(1 < g_warnings_as_errors) + g_error_count == 0) && (g_opt_E_preprocess == 0)) &&
        (g_opt_Zg == '\0')) &&
       ((buf->open == '\0' ||
        (iVar1 = (*buf->ilstore_stream->vtbl->Append)(buf->ilstore_stream,pvBuf,iVar1), iVar1 == 0))
       )) {
      ilstore_report_error();
    }
    (buf->bytes).pbEnd = (buf->bytes).pbStart;
    return;
  }
  return;
}

