void __fastcall ilstore_flush(c1_il_buffer *buf)

{
  c1_u8 *pcVar1;
  int iVar2;
  
  pcVar1 = (buf->bytes).start;
  iVar2 = (int)(buf->bytes).cur - (int)pcVar1;
  if (iVar2 != 0) {
    if (((((uint)(1 < g_warnings_as_errors) + g_error_count == 0) && (g_opt_E_preprocess == 0)) &&
        (g_opt_Zg == '\0')) &&
       ((buf->open == '\0' ||
        (iVar2 = (*buf->ilstore_stream->vtbl->append)(pcVar1,iVar2), iVar2 == 0)))) {
      ilstore_report_error();
    }
    (buf->bytes).cur = (buf->bytes).start;
    return;
  }
  return;
}

