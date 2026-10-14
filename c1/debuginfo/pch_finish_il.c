void __cdecl pch_finish_il(void)

{
  byte bVar1;
  char *pdb;
  
  il_files_close('\x01');
  if (((uint)(1 < g_warnings_as_errors) + g_error_count == 0) &&
     ((g_pch_directive_mode == 1 || (g_auto_pch_creating != 0)))) {
    ilstore_release();
    ilstore_open(g_pdb_gi->pdb);
    if (g_pch_directive_mode == 1) {
      bVar1 = pdb_commit_session(g_pdb_gi);
      if (bVar1 == 0) {
        ilstore_report_error();
      }
    }
  }
  if (((g_opt_E_preprocess == 0) && (g_opt_Zg == '\0')) &&
     (g_compile_flags_cc = g_compile_flags_cc | 0x2000, g_il_files_opened == '\0')) {
    pdb = pdb_relative_path(g_object_file_name);
    ilstore_open_streams(pdb);
    il_file_open(&g_il_sy,(byte *)g_opt_il_prefix,"sy","w+b");
    il_file_open(&g_il_gl,(byte *)g_opt_il_prefix,"gl","w+b");
    il_file_open(&g_il_in,(byte *)g_opt_il_prefix,"in","w+b");
    if ((g_opt_Zi != '\0') && (g_il_db.file == (FILE *)0x0)) {
      il_file_open(&g_il_db,(byte *)g_opt_il_prefix,"db","w+b");
    }
    if ((g_debug_types_in_pdb != '\0') && (g_pch_db_reloaded == '\0')) {
      debug_begin('\0');
    }
    il_globals_rewind();
    emit_version_string_literal();
    g_il_files_opened = '\x01';
  }
  return;
}

