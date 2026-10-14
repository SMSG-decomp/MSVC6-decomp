void __cdecl stmt_goto_flow_state(c1_symbol *label,int defined)

{
  c1_flow_state *pcVar1;
  c1_node *tree;
  int iVar2;
  c1_symbol **ppcVar3;
  c1_u8 local_1c [4];
  c1_symbol *local_18 [4];
  node *local_8;
  uint *prev_pending;
  
  if (g_flow_state_abandoned == '\0') {
    if (g_flow_state_top == (c1_flow_state *)0x0) {
      func_flow_state_reset();
      return;
    }
    switch(g_flow_state_top->kind) {
    case 9:
    case 0xb:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
      break;
    default:
      g_flow_goto_count = g_flow_goto_count + 1;
      if ((defined != 0) &&
         (pcVar1 = stmt_find_label_flow_state(label), pcVar1 != (c1_flow_state *)0x0)) {
        local_18[0] = (c1_symbol *)0x0;
        local_18[1] = (c1_symbol *)0x0;
        local_18[2] = (c1_symbol *)0x0;
        local_1c[0] = ':';
        local_1c[1] = '\0';
        local_1c[2] = '\0';
        local_1c[3] = '\0';
        local_18[3] = label;
        func_check_flow_state_complexity(local_1c,0x14);
        tree = expr_unwind_actions((c1_node *)0x0);
        stmt_emit_merged_expression(tree);
        return;
      }
      local_1c[0] = ';';
      local_1c[1] = '\0';
      local_1c[2] = '\0';
      local_1c[3] = '\0';
      ppcVar3 = local_18;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *ppcVar3 = (c1_symbol *)0x0;
        ppcVar3 = ppcVar3 + 1;
      }
      local_18[3] = label;
      local_8 = label_new(0x47);
      prev_pending = g_pending_goto_list;
      func_check_flow_state_complexity(local_1c,0x1c);
      g_pending_goto_list = (uint *)g_flow_state_top;
      il_emit_tuple(0x3a,local_8);
    }
  }
  return;
}

