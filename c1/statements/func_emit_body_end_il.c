void __cdecl func_emit_body_end_il(int has_return)

{
  c1_node *node;
  
  if (g_current_function != (c1_symbol *)0x0) {
    if (g_ilstore_status == 4) {
      stmt_block_end();
    }
    else {
      if (g_opt_Zg == '\0') {
        if (has_return == 0) {
          il_emit_pragma_or_segment_record(0x24);
        }
        label_emit_definition(PTR_106692b4);
        if (g_opt_Zi != '\0') {
          il_emit_pragma_or_segment_record(0x12);
        }
        il_emit_tuple(0x47,(c1_node *)0x0);
      }
      stmt_block_end();
      il_emit_function_symbols((int *)g_current_scope);
      if (g_opt_Zg == '\0') {
        node = tree_new_three_fields_flagged(0,0,4);
        il_emit_tuple(0x54,node);
      }
    }
  }
  g_current_scope->unk20c = 0;
  if ((has_return != 0) && (g_c9il_mode == '\0')) {
    g_function_start_line = 0;
  }
  func_finish_il(g_current_function);
  PTR_1065d46c = (c1_type *)0x0;
  g_pending_destructor_list = (c1_list_cell *)0x0;
  g_static_guard_variable = (c1_symbol *)0x0;
  g_file_scope_decl_since_body = 0;
  g_il_block_level = '\0';
  g_block_depth = '\0';
  g_function_cleared_word = 0;
  g_block_scope_number = 0;
  g_string_literal_cur = &g_string_literal_buffer;
  return;
}

