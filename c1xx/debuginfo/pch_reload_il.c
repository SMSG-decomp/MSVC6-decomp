void __cdecl pch_reload_il(char with_db)

{
  if (g_pch_creating == 0) {
    il_files_open();
  }
  pch_read_into_buffer(&g_il_gl,g_pch_file,g_pch_header.gl_size);
  pch_read_into_buffer(&g_il_in,g_pch_file,g_pch_header.in_size);
  g_pch_db_reloaded = with_db;
  if (with_db != '\0') {
    pch_read_into_buffer(&g_il_db,g_pch_file,g_pch_header.db_size);
  }
  return;
}

