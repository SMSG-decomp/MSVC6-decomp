void __fastcall il_buffer_flush(c1_il_buffer *buf)

{
  c1_u8 *_Str;
  size_t sVar1;
  
  _Str = (buf->bytes).start;
  sVar1 = (int)(buf->bytes).cur - (int)_Str;
  if (sVar1 != 0) {
    if (((((uint)(1 < g_warnings_as_errors) + g_error_count == 0) && (g_opt_E_preprocess == 0)) &&
        (g_opt_Zg == '\0')) &&
       ((buf->open == '\0' ||
        (sVar1 = fwrite(_Str,1,sVar1,(FILE *)buf->file),
        (int)(buf->bytes).cur - (int)(buf->bytes).start != sVar1)))) {
      diag_fatal_file_errno(0x58,0x153,buf->name);
    }
    (buf->bytes).cur = (buf->bytes).start;
    return;
  }
  return;
}

