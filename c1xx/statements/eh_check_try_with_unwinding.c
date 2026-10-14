void __cdecl eh_check_try_with_unwinding(void)

{
  c1_node *tree;
  c1_u8 local_10 [16];
  
  if (g_current_function != (c1_symbol *)0x0) {
    if (g_flow_state_top != (c1_flow_state *)0x0) {
      if (((*(byte *)((int)&g_current_function->tail + 10) & 2) != 0) &&
         ((g_current_function->flags5 & 1) != 0)) {
        diag_error(0x2c8);
      }
      if ((g_flow_state_abandoned != '\0') || (g_error_count == g_flow_error_count_at_start)) {
        if ((g_flow_state_top == (c1_flow_state *)0x0) || (g_flow_state_top->kind != 1)) {
          local_10[4] = '\0';
          local_10[5] = '\0';
          local_10[6] = '\0';
          local_10[7] = '\0';
          local_10[8] = '\0';
          local_10[9] = '\0';
          local_10[10] = '\0';
          local_10[0xb] = '\0';
          local_10[0] = '\x04';
          local_10[1] = '\0';
          local_10[2] = '\0';
          local_10[3] = '\0';
          local_10[0xc] = '\0';
          local_10[0xd] = '\0';
          local_10[0xe] = '\0';
          local_10[0xf] = '\0';
          func_check_flow_state_complexity(local_10,0x10);
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

