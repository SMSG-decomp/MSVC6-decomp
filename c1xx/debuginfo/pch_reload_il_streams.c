void __cdecl pch_reload_il_streams(char with_db)

{
  _g_io_result = fseek((FILE *)g_pch_file,g_pch_header.sy_size + 0x3f4 + g_pch_header.ex_size,0);
  if (_g_io_result != 0) {
    diag_fatal_file_errno(0x56,0x158,g_pch_file_name);
  }
  if (g_c9il_mode != '\0') {
    g_file_copy_buffer = mem_xmalloc(0x8000);
    il_buffer_flush(&g_il_gl);
    fflush((FILE *)g_il_gl.file);
    rewind((FILE *)g_il_gl.file);
    file_copy_contents(g_pch_file,g_il_gl.file,g_pch_header.gl_size);
    il_buffer_flush(&g_il_in);
    fflush((FILE *)g_il_in.file);
    rewind((FILE *)g_il_in.file);
    file_copy_contents(g_pch_file,g_il_in.file,g_pch_header.in_size);
    if (with_db == '\0') {
      if (g_pch_header.db_size != 0) {
        _g_io_result = fseek((FILE *)g_pch_file,g_pch_header.db_size,1);
        if (_g_io_result != 0) {
          diag_fatal_file_errno(0x56,0x158,g_pch_file_name);
        }
      }
      return;
    }
    il_buffer_flush(&g_il_db);
    fflush((FILE *)g_il_db.file);
    rewind((FILE *)g_il_db.file);
    file_copy_contents(g_pch_file,g_il_db.file,g_pch_header.db_size);
    return;
  }
  pch_reload_il(with_db);
  return;
}

