void il_files_open(void)

{
  char *module_name;
  
  if (((g_opt_E_preprocess == 0) && (g_opt_Zg == '\0')) &&
     (g_compile_flags_cc = g_compile_flags_cc | 0x2000, g_il_files_opened == 0)) {
    module_name = pdb_relative_path(g_object_file_name);
    ilstore_open_streams(module_name);
    il_file_open(&g_il_sy,g_opt_il_prefix,"sy","w+b");
    il_file_open(&g_il_gl,g_opt_il_prefix,"gl","w+b");
    il_file_open(&g_il_in,g_opt_il_prefix,"in","w+b");
    if ((g_opt_Zi != '\0') && (g_il_db.file == (FILE *)0x0)) {
      il_file_open(&g_il_db,g_opt_il_prefix,"db","w+b");
    }
    if ((g_debug_types_in_pdb != '\0') && (g_pch_db_reloaded == 0)) {
      debug_begin('\0');
    }
    il_globals_rewind();
    emit_version_string_literal();
    g_il_files_opened = 1;
  }
  return;
}

