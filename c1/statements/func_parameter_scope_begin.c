c1_symbol * __cdecl func_parameter_scope_begin(c1_symbol *func)

{
  fe_line_map_row *pfVar1;
  
  il_symbol_key_counter_reset();
  g_function_auto_inline = g_pragma_auto_inline;
  g_function_has_body = 0;
  g_function_not_inlinable = 0;
  PTR_1065d46c = type_function_return(func->type);
  g_compile_flags_c8 = g_compile_flags_c8 & 0xfffff7ff;
  if (((byte)g_compile_flags_c4 & 0x20) == 0) {
    block_scope_new(g_current_scope,g_pending_parameter_scope);
  }
  g_il_block_level = '\x01';
  g_block_depth = '\x01';
  g_block_scope_number = 1;
  g_function_string_count = 0;
  if (g_line_map_cached_row.position == g_token_position) {
    pfVar1 = &g_line_map_cached_row;
  }
  else {
    pfVar1 = pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  g_function_start_line = (pfVar1->line - pfVar1->position) + g_token_position;
  il_reset_last_line_and_file();
  func_record_alloc(func);
  g_function_uses_line_helper = '\0';
  return func;
}

