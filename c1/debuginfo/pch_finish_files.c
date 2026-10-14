void pch_finish_files(void)

{
  int iVar1;
  
  if ((g_pch_files_closed == 0) &&
     (((g_pch_creating != 0 && ((uint)(1 < g_warnings_as_errors) + g_error_count != 0)) ||
      ((g_pch_in_ex_file != '\0' || g_pch_write_file_unfinished != '\0') ||
       g_pch_file_unfinished != '\0')))) {
    g_pch_files_closed = 1;
    if (g_pch_file_unfinished == '\0') {
      if (g_pch_write_file_unfinished == '\0') {
        if (g_pch_in_ex_file == '\0') {
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
      _g_io_result = fclose(g_pch_file);
      if (_g_io_result == -1) {
        diag_fatal_file_errno(0x52,0x158,g_pch_file_name);
      }
      g_pch_file = (FILE *)0x0;
    }
    iVar1 = _unlink(g_pch_file_name);
    if (iVar1 != 0) {
      diag_fatal_file_errno(0x53,0x154,g_pch_file_name);
    }
    g_pch_in_ex_file = '\0';
    g_pch_write_file_unfinished = '\0';
    g_pch_file_unfinished = '\0';
  }
  return;
}

