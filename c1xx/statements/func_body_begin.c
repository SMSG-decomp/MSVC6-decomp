c1_symbol * __cdecl func_body_begin(c1_symbol *fn)

{
  c1_type *pcVar1;
  c1_line_map_row *pcVar2;
  
  local_keys_reset();
  if (fn == (c1_symbol *)0x0) {
    fn = func_new_dynamic_initializer();
  }
  if (((fn->flags21 & 1) != 0) && ((fn->storage & 7) != 3)) {
    g_static_guard_record.guard = (c1_symbol *)0x0;
    g_static_guard_record.mask = '\0';
    g_static_guard_record.pad05[0] = '\0';
    g_static_guard_record.pad05[1] = '\0';
    g_static_guard_record.pad05[2] = '\0';
    g_static_guard_count = 0;
  }
  g_function_has_body = 0;
  g_function_auto_inline = g_pragma_auto_inline;
  g_function_not_inlinable = 0;
  pcVar1 = g_return_object_pointer_type;
  if ((*(byte *)((int)&fn->tail + 9) & 1) == 0) {
    pcVar1 = type_function_return(fn->type);
  }
  g_compile_flags_c8 = g_compile_flags_c8 & 0xfffff7ff;
  g_function_return_type = pcVar1;
  if (((byte)g_compile_flags_c4 & 0x20) == 0) {
    scope_new_block_record(g_current_scope,g_pending_parameter_scope);
  }
  g_il_block_level = '\x01';
  g_block_depth = '\x01';
  g_block_number = 1;
  g_function_string_literal_count = 0;
  if (g_line_map_cached_row.position == g_token_position) {
    pcVar2 = &g_line_map_cached_row;
  }
  else {
    pcVar2 = pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  g_function_start_line = (pcVar2->line - pcVar2->position) + g_token_position;
  func_reset_line_markers();
  func_record_alloc(fn);
  g_function_uses_line_helper = '\0';
  return fn;
}

