void stmt_jump_flow_state_2(void)

{
  c1_node *tree;
  c1_u8 local_10 [16];
  
  if (g_flow_state_abandoned == '\0') {
    switch(g_flow_state_top->kind) {
    case 9:
    case 0xb:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
      break;
    default:
      local_10[4] = '\0';
      local_10[5] = '\0';
      local_10[6] = '\0';
      local_10[7] = '\0';
      local_10[8] = '\0';
      local_10[9] = '\0';
      local_10[10] = '\0';
      local_10[0xb] = '\0';
      local_10[0] = '<';
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
  }
  return;
}

