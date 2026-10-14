void __cdecl ilstore_open_for_gi(void)

{
  c1_line_map_row *pcVar1;
  char *module_name;
  
  if ((g_opt_E_preprocess != 0) || (g_opt_Zg != '\0')) {
    return;
  }
  g_compile_flags_cc = g_compile_flags_cc | 0x2000;
  module_name = pch_and_pdb_names();
  ilstore_open_streams(module_name);
  ilstore_open_stream(&g_il_gl,module_name,"gl");
  ilstore_open_stream(&g_il_in,module_name,"in");
  if (g_opt_Zi != '\0') {
    if (g_pch_debug_in_object == '\0') {
      il_file_open(&g_il_db,g_opt_il_prefix,"db","w+b");
    }
    else {
      ilstore_open_stream(&g_il_db,module_name,"db");
    }
  }
  if ((g_debug_types_in_pdb != '\0') && (g_pch_db_reloaded == 0)) {
    debug_begin('\0');
    il_emit_end_of_globals();
    return;
  }
  if (g_c9il_mode == '\0') {
    if (g_line_map_cached_row.position == g_token_position) {
      pcVar1 = &g_line_map_cached_row;
    }
    else {
      pcVar1 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    if ((((pcVar1->file->key_ref & 0xfffffff8) == 0) && (g_opt_E_preprocess == 0)) &&
       (g_opt_Zg == '\0')) {
      il_emit_symbol(0x12,(c1_symbol *)0x0);
      (*g_idb->vtbl->idb_note_global_il_record)(g_idb);
      return;
    }
  }
  return;
}

