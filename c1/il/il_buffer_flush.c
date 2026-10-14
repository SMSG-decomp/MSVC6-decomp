void __fastcall il_buffer_flush(fe_il_buffer *buf)

{
  PB _Str;
  size_t sVar1;
  
  _Str = (buf->bytes).pbStart;
  sVar1 = (int)(buf->bytes).pbEnd - (int)_Str;
  if (sVar1 != 0) {
    if (((((uint)(1 < g_warnings_as_errors) + g_error_count == 0) && (g_opt_E_preprocess == 0)) &&
        (g_opt_Zg == '\0')) &&
       ((buf->open == '\0' ||
        (sVar1 = fwrite(_Str,1,sVar1,buf->file),
        (int)(buf->bytes).pbEnd - (int)(buf->bytes).pbStart != sVar1)))) {
      diag_fatal_file_errno(0x58,0x153,buf->name);
    }
    (buf->bytes).pbEnd = (buf->bytes).pbStart;
    return;
  }
  return;
}

