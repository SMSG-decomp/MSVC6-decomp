c1_node * __cdecl expr_condition_guarded(c1_node *node,int want_value)

{
  c1_node *pcVar1;
  int iVar2;
  c1_node *left;
  c1_type *type;
  int flow_jmpbuf [16];
  c1_u8 local_20 [16];
  uint local_10;
  c1_node *local_c;
  c1_node *local_8;
  
  type = (c1_type *)0x0;
  local_8 = (c1_node *)0x0;
  if ((g_flow_analysis_active != 0) && (g_flow_error_jmpbuf == (void *)0x0)) {
    local_c = node;
    if (g_flow_state_abandoned != '\0') {
      return node;
    }
    g_flow_error_jmpbuf = flow_jmpbuf;
    iVar2 = _setjmp3(flow_jmpbuf,0);
    if (iVar2 != 0) {
      g_flow_error_jmpbuf = (void *)0x0;
      return local_c;
    }
  }
  if (g_flow_state_top != (c1_flow_state *)0x0) {
    if (g_flow_state_top->kind == 0xd) {
      local_8 = expr_full_expression_guarded((c1_node *)0x0,2);
    }
    if ((g_flow_state_top != (c1_flow_state *)0x0) && (g_flow_state_top->kind == 8)) {
      g_flow_state_top->kind = 0xb;
      goto LAB_1042ba07;
    }
  }
  local_20[4] = '\0';
  local_20[5] = '\0';
  local_20[6] = '\0';
  local_20[7] = '\0';
  local_20[8] = '\0';
  local_20[9] = '\0';
  local_20[10] = '\0';
  local_20[0xb] = '\0';
  local_20[0] = '\t';
  local_20[1] = '\0';
  local_20[2] = '\0';
  local_20[3] = '\0';
  local_20[0xc] = '\0';
  local_20[0xd] = '\0';
  local_20[0xe] = '\0';
  local_20[0xf] = '\0';
  func_check_flow_state_complexity(local_20,0x10);
LAB_1042ba07:
  if ((node == (c1_node *)0x0) && (want_value != 0)) {
    pcVar1 = expr_condition_guarded_error_exit((void *)0x0,&stack0xfffffffc);
    return pcVar1;
  }
  g_eh_context_kind = 1;
  pcVar1 = expr_unwind_actions((c1_node *)0x0);
  eh_merge_state_markers(pcVar1);
  if ((local_8 != (c1_node *)0x0) || (pcVar1 != (c1_node *)0x0)) {
    local_c = (c1_node *)0x0;
    if ((want_value != 0) &&
       ((node != (c1_node *)0x0 && (type = node->type, ((byte)type->code >> 6 & 1) == 0)))) {
      local_10 = sym_new_local_key();
      local_c = tree_new_leaf_9c(local_10,type);
      node = tree_new_binary('4',local_c,node);
    }
    left = node;
    if ((local_8 != (c1_node *)0x0) && (left = local_8, node != (c1_node *)0x0)) {
      left = tree_new_binary_typed_right('7',node,local_8);
    }
    node = left;
    if ((pcVar1 != (c1_node *)0x0) && (node = pcVar1, left != (c1_node *)0x0)) {
      node = tree_new_binary_typed_right('7',left,pcVar1);
    }
    if (local_c != (c1_node *)0x0) {
      pcVar1 = tree_new_leaf_9c(local_10,type);
      pcVar1 = tree_new_rvalue(pcVar1);
      node = tree_new_node('7',node,pcVar1,type);
    }
  }
  g_eh_unresolved_dtor_class = (c1_symbol *)0x0;
  if (g_flow_error_jmpbuf == flow_jmpbuf) {
    g_flow_error_jmpbuf = (void *)0x0;
  }
  return node;
}

