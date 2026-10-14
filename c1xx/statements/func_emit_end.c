void __cdecl func_emit_end(int flag)

{
  c1_node *n;
  
  if (g_current_function != (c1_symbol *)0x0) {
    if (g_ilstore_status == 4) {
      scope_end_block();
    }
    else {
      if (g_opt_Zg == '\0') {
        if (flag == 0) {
          il_emit_pragma_or_segment_record(0x24);
        }
        label_emit_definition(g_function_exit_label);
        if ((g_current_function->flags1 & 0x10) == 0x10) {
          func_emit_return_this((int)g_member_function_class);
        }
        if ((g_current_function->flags1 & 0x20) == 0x20) {
          func_finish_eh((int)g_member_function_class);
        }
        else if (g_current_function->name == g_name_vbase_dtor) {
          class_build_vbase_dtor_body(g_member_function_class);
        }
        if (g_opt_Zi != '\0') {
          il_emit_pragma_or_segment_record(0x12);
        }
        il_emit_tuple(0x47,(node *)0x0);
      }
      scope_end_block();
      il_emit_function_symbols((int *)g_current_scope);
      if (g_opt_Zg == '\0') {
        n = tree_new_three_fields_flagged(0,0,4);
        il_emit_tuple(0x54,n);
      }
    }
    if (((g_current_function->flags21 & 1) != 0) && ((g_current_function->storage & 7) != 3)) {
      g_static_guard_record.guard = (c1_symbol *)0x0;
      g_static_guard_record.mask = '\0';
      g_static_guard_record.pad05[0] = '\0';
      g_static_guard_record.pad05[1] = '\0';
      g_static_guard_record.pad05[2] = '\0';
      g_static_guard_count = 0;
    }
  }
  g_current_scope->closed_blocks = (c1xx_scope *)0x0;
  if ((flag != 0) && (g_c9il_mode == '\0')) {
    func_emit_end_reset_state(0);
    return;
  }
  func_end_emit_il(g_current_function);
  g_function_return_type = (c1_type *)0x0;
  g_pending_destructor_list = (c1_value_cell *)0x0;
  g_static_guard_variable = (c1_symbol *)0x0;
  g_file_scope_decl_since_body = 0;
  g_string_literal_cur = &g_string_literal_buffer;
  g_il_block_level = '\0';
  g_block_depth = '\0';
  g_member_function_class = (c1_symbol *)0x0;
  g_block_number = 0;
  expr_reset_shared_temporary();
  return;
}

