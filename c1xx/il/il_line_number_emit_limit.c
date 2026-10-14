int __cdecl il_line_number_emit_limit(void)

{
  c1_line_map_row *pcVar1;
  int iVar2;
  
  if (((g_current_function == (c1_symbol *)0x0) || ((g_current_function->flags3 & 1) == 0)) &&
     (((byte)g_compile_flags_c8 & 0x80) == 0)) {
    if (g_line_map_cached_row.position == g_token_position) {
      pcVar1 = &g_line_map_cached_row;
    }
    else {
      pcVar1 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    if (g_c9il_mode == '\0') {
      return 1;
    }
    if ((pcVar1->line - pcVar1->position) + g_token_position < 0x10000) {
      g_il_line_numbers_in_range = '\x01';
      return 1;
    }
    if (g_il_line_numbers_in_range != '\0') {
      diag_warning(1,0x31);
      g_il_line_numbers_in_range = '\0';
      iVar2 = il_line_limit_disabled();
      return iVar2;
    }
  }
  return 0;
}

