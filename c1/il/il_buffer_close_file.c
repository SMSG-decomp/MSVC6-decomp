int __fastcall il_buffer_close_file(fe_il_buffer *buf)

{
  int iVar1;
  
  if (buf->file != (FILE *)0x0) {
    il_buffer_flush(buf);
    iVar1 = fclose(buf->file);
    buf->file = (FILE *)0x0;
    return iVar1;
  }
  return ((uint)(1 < g_warnings_as_errors) + g_error_count != 0) - 1;
}

