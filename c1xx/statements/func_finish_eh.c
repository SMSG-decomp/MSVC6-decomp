void __cdecl func_finish_eh(int member_class)

{
  c1_node *tree;
  uint flow_record [3];
  uint flow_record_w3;
  
  if (member_class == 0) {
    return;
  }
  eh_flush_pending_state();
  if (g_current_function != (c1_symbol *)0x0) {
    if (g_flow_state_top != (c1_flow_state *)0x0) {
      if (((*(byte *)((int)&g_current_function->tail + 10) & 2) != 0) &&
         ((g_current_function->flags5 & 1) != 0)) {
        diag_error(0x2c8);
      }
      if ((g_flow_state_abandoned != '\0') || (g_error_count == g_flow_error_count_at_start)) {
        if ((g_flow_state_top == (c1_flow_state *)0x0) || (g_flow_state_top->kind != 1)) {
          flow_record[1] = 0;
          flow_record[2] = 0;
          flow_record[0] = 4;
          func_check_flow_state_complexity((c1_u8 *)flow_record,0x10);
          tree = expr_unwind_actions((c1_node *)0x0);
          stmt_emit_merged_expression(tree);
        }
        else {
          func_flow_state_pop_record();
        }
        if (((g_current_function->flags1 & 0x10) != 0x10) &&
           ((g_current_function->flags1 & 0x20) != 0x20)) {
          stmt_check_missing_return_value();
        }
      }
    }
    func_flow_state_reset();
  }
  return;
}

