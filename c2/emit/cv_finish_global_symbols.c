void cv_finish_global_symbols(void)

{
  g_debug_symbols_section = fe_symbol_lookup_id(7);
  if (g_cv_symbols_header_written == 0) {
    g_cv_symbols_header_written = 1;
    cv_emit_symbols_signature();
    cv_emit_objname_record();
  }
  scope_for_each(0,emit_symbol_definition_edx0);
  for (; g_global_class_b_symbols != (c2_fe_symbol *)0x0;
      g_global_class_b_symbols = g_global_class_b_symbols->next) {
    emit_symbol_definition_edx0(g_global_class_b_symbols);
  }
  g_db_il_file = open_il_file(g_opt_il_path,"db","rb","db il");
  if (g_db_il_file == (FILE *)0x0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\emit.c",0x57f);
  }
  read_global_symbols(g_db_il_file);
  fclose(g_db_il_file);
  return;
}

