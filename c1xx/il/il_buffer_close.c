void __fastcall il_buffer_close(c1_il_buffer *buf)

{
  _g_io_result = il_buffer_close_file(buf);
  if (_g_io_result == -1) {
    diag_fatal_file_errno(0x52,0x153,(char *)0x0);
  }
  return;
}

