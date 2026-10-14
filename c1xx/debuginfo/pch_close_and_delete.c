void __cdecl pch_close_and_delete(char pch_read_open,char pch_write_open,char pch_is_ex_file)

{
  int iVar1;
  
  g_pch_files_closed = 1;
  if (pch_read_open == '\0') {
    if (pch_write_open == '\0') {
      if (pch_is_ex_file == '\0') {
        g_pch_files_closed = 1;
        return;
      }
      _g_io_result = il_buffer_close_file(&g_il_ex);
      if (_g_io_result == -1) {
        diag_fatal_file_errno(0x52,0x158,g_pch_file_name);
      }
    }
    else {
      _g_io_result = fclose(g_pch_write_file);
      if (_g_io_result == -1) {
        diag_fatal_file_errno(0x52,0x158,g_pch_file_name);
      }
      g_pch_write_file = (FILE *)0x0;
    }
  }
  else {
    _g_io_result = fclose((FILE *)g_pch_file);
    if (_g_io_result == -1) {
      diag_fatal_file_errno(0x52,0x158,g_pch_file_name);
    }
    g_pch_file = (FILE *)0x0;
  }
  iVar1 = _unlink(g_pch_file_name);
  if (iVar1 != 0) {
    diag_fatal_file_errno(0x53,0x154,g_pch_file_name);
  }
  g_pch_write_file_unfinished = 0;
  g_pch_file_unfinished = 0;
  g_pch_in_ex_file = 0;
  return;
}

