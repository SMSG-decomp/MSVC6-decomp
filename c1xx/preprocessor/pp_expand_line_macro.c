char * __cdecl pp_expand_line_macro(void)

{
  c1_line_map_row *pcVar1;
  int iVar2;
  
  if ((((g_opt_ZI != '\0') && (g_include_depth == 0)) && (g_current_function != (c1_symbol *)0x0))
     && (((g_compile_flags_c4 & 0x20) == 0 && ((g_compile_flags_c4 & 0x8000) == 0)))) {
    sym_ensure_global_helper_function();
    if (g_line_map_cached_row.position == g_token_position) {
      pcVar1 = &g_line_map_cached_row;
    }
    else {
      pcVar1 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    format_snprintf((char *)g_number_digit_buffer,"(%s+%d)",0x80,g_name_line_var->text,
                    ((pcVar1->line - pcVar1->position) - g_function_start_line) + g_token_position);
    g_function_uses_line_helper = '\x01';
    return (char *)g_number_digit_buffer;
  }
  iVar2 = (*g_idb->vtbl->idb_in_function)(g_idb);
  if (((iVar2 != 0) && ((g_compile_flags_c4 & 0x8000) == 0)) &&
     (((g_current_function == (c1_symbol *)0x0 || ((g_current_function->flags21 & 1) == 0)) ||
      (((g_current_function->storage & 7) == 3 && ((g_current_function->flags1 & 4) == 0)))))) {
    sym_ensure_global_helper_function();
    if (g_line_map_cached_row.position == g_token_position) {
      pcVar1 = &g_line_map_cached_row;
    }
    else {
      pcVar1 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    format_snprintf((char *)g_number_digit_buffer,"(%s+%d)",0x80,g_name_line_var->text,
                    ((pcVar1->line - g_function_start_line) - pcVar1->position) + g_token_position);
    return (char *)g_number_digit_buffer;
  }
  iVar2 = (*g_idb->vtbl->idb_note_line_dependency)(g_idb);
  if (iVar2 == 0) {
    diag_fatal(0x49,".\\iccLINE.cpp",0xee);
  }
  if (g_line_map_cached_row.position == g_token_position) {
    pcVar1 = &g_line_map_cached_row;
  }
  else {
    pcVar1 = pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  format_snprintf((char *)g_number_digit_buffer,"%d",0x80,
                  (pcVar1->line - pcVar1->position) + g_token_position);
  return (char *)g_number_digit_buffer;
}

