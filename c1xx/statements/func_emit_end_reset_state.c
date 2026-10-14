void __cdecl func_emit_end_reset_state(int zero)

{
  g_function_start_line = zero;
  func_end_emit_il(g_current_function);
  g_string_literal_cur = &g_string_literal_buffer;
  g_il_block_level = (c1_u8)zero;
  g_block_number = (short)zero;
  g_function_return_type = (c1_type *)zero;
  g_member_function_class = (c1_symbol *)zero;
  g_block_depth = g_il_block_level;
  g_file_scope_decl_since_body = zero;
  g_static_guard_variable = (c1_symbol *)zero;
  g_pending_destructor_list = (c1_value_cell *)zero;
  expr_reset_shared_temporary();
  return;
}

