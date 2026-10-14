void __cdecl il_emit_end_of_globals(void)

{
  c1_line_map_row *pcVar1;
  
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

