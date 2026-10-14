char * __cdecl iccline_check_incremental(void)

{
  int iVar1;
  fe_line_map_row *pfVar2;
  
  if ((((g_opt_ZI != '\0') && (g_include_depth == 0)) && (g_current_function != (c1_symbol *)0x0))
     && (((g_compile_flags_c4 & 0x20) == 0 && ((g_compile_flags_c4 & 0x8000) == 0)))) {
    sym_ensure_global_helper_function();
    if (g_line_map_cached_row.position == g_token_position) {
      pfVar2 = &g_line_map_cached_row;
    }
    else {
      pfVar2 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    format_snprintf(g_number_digit_buffer,"(%s+%d)",0x80,g_name_LINE_Var->text,
                    ((pfVar2->line - pfVar2->position) - g_function_start_line) + g_token_position);
    g_function_uses_line_helper = '\x01';
    return g_number_digit_buffer;
  }
  iVar1 = (*g_idb->vtbl->idb_in_function)(g_idb);
  if (((iVar1 != 0) && ((g_compile_flags_c4 & 0x8000) == 0)) &&
     ((g_current_function == (c1_symbol *)0x0 ||
      (((g_current_function->flags21 & 1) == 0 || ((g_current_function->storage & 7) == 3)))))) {
    sym_ensure_global_helper_function();
    if (g_line_map_cached_row.position == g_token_position) {
      pfVar2 = &g_line_map_cached_row;
    }
    else {
      pfVar2 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    format_snprintf(g_number_digit_buffer,"(%s+%d)",0x80,g_name_LINE_Var->text,
                    ((pfVar2->line - g_function_start_line) - pfVar2->position) + g_token_position);
    return g_number_digit_buffer;
  }
  iVar1 = (*g_idb->vtbl->idb_note_line_dependency)(g_idb);
  if (iVar1 != 0) {
    if (g_line_map_cached_row.position == g_token_position) {
      pfVar2 = &g_line_map_cached_row;
    }
    else {
      pfVar2 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    format_snprintf(g_number_digit_buffer,"%d",0x80,
                    (pfVar2->line - pfVar2->position) + g_token_position);
    return g_number_digit_buffer;
  }
  diag_fatal(0x49,".\\iccLINE.cpp",0xee);
}

