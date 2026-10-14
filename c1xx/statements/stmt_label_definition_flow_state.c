void __cdecl stmt_label_definition_flow_state(c1_symbol *label)

{
  c1_node *tree;
  c1_u8 local_18 [16];
  c1_symbol *local_8;
  c1_flow_state *local_4;
  
  local_18[0] = '9';
  local_18[1] = '\0';
  local_18[2] = '\0';
  local_18[3] = '\0';
  local_18[8] = '\0';
  local_18[9] = '\0';
  local_18[10] = '\0';
  local_18[0xb] = '\0';
  local_18[0xc] = '\0';
  local_18[0xd] = '\0';
  local_18[0xe] = '\0';
  local_18[0xf] = '\0';
  if (g_flow_state_abandoned == '\0') {
    local_18[4] = '\0';
    local_18[5] = '\0';
    local_18[6] = '\0';
    local_18[7] = '\0';
    local_8 = label;
    local_4 = g_defined_label_flow_states;
    func_check_flow_state_complexity(local_18,0x18);
    g_defined_label_flow_states = g_flow_state_top;
    tree = expr_unwind_actions((c1_node *)0x0);
    stmt_emit_merged_expression(tree);
  }
  return;
}

