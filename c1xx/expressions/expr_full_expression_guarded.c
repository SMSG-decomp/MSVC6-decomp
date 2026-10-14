c1_node * __cdecl expr_full_expression_guarded(c1_node *node,uint flags)

{
  c1_u16 cVar1;
  c1_type *type;
  bool bVar2;
  char cVar3;
  c1_node *pcVar4;
  uint entity;
  c1_node *pcVar5;
  c1_node *left;
  int iVar6;
  byte *pbVar7;
  int jmpbuf [16];
  int flow_kind;
  int flow_w1;
  int flow_w2;
  int flow_w3;
  int flow2_kind;
  int flow2_w1;
  int flow2_w2;
  int flow2_w3;
  int flow3_kind;
  int flow3_w1;
  int flow3_w2;
  int flow3_w3;
  int guard_kind;
  byte local_28 [12];
  void *local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  c1_node *local_8;
  
  if ((g_flow_analysis_active != 0) && (g_flow_error_jmpbuf == (void *)0x0)) {
    local_8 = node;
    if (g_flow_state_abandoned != '\0') {
      return node;
    }
    g_flow_error_jmpbuf = jmpbuf;
    iVar6 = _setjmp3(jmpbuf,0);
    if (iVar6 != 0) {
      g_flow_error_jmpbuf = (void *)0x0;
      return local_8;
    }
  }
  if ((g_flow_state_abandoned != '\0') || (g_sizeof_depth != 0)) {
    if (g_flow_error_jmpbuf == jmpbuf) {
      g_flow_error_jmpbuf = (void *)0x0;
    }
    return node;
  }
  if ((g_flow_state_top == (c1_flow_state *)0x0) ||
     ((g_flow_state_top->kind != 0xd &&
      ((g_flow_state_top == (c1_flow_state *)0x0 || (g_flow_state_top->kind != 0x3e))))))
  goto LAB_1042e020;
  guard_kind = 0xd;
  pbVar7 = local_28;
  for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
    pbVar7[0] = 0;
    pbVar7[1] = 0;
    pbVar7[2] = 0;
    pbVar7[3] = 0;
    pbVar7 = pbVar7 + 4;
  }
  local_28[0] = local_28[0] | 3;
  local_1c = (void *)0x0;
  if (node == (c1_node *)0x0) {
LAB_1042e089:
    if ((node == (c1_node *)0x0) ||
       ((cVar3 = expr_full_expression_in_eh_state(flags), cVar3 == '\0' ||
        (type = node->type, ((byte)type->code >> 6 & 1) != 0)))) {
      flow_w1 = 0;
      flow_w2 = 0;
      flow_kind = 0xc;
      flow_w3 = 0;
      func_check_flow_state_complexity((c1_u8 *)&flow_kind,0x10);
      pcVar4 = expr_unwind_actions(node);
LAB_1042e0c4:
      pcVar5 = pcVar4;
    }
    else {
      entity = sym_new_local_key();
      pcVar4 = tree_new_leaf_9c(entity,type);
      pcVar4 = tree_new_binary('4',pcVar4,node);
      flow3_w1 = 0;
      flow3_w2 = 0;
      flow3_kind = 0xc;
      flow3_w3 = 0;
      func_check_flow_state_complexity((c1_u8 *)&flow3_kind,0x10);
      pcVar4 = expr_unwind_actions(pcVar4);
      pcVar5 = tree_new_leaf_9c(entity,type);
      pcVar5 = tree_new_rvalue(pcVar5);
      pcVar5 = tree_new_node('7',pcVar4,pcVar5,type);
    }
  }
  else {
    cVar1 = node->type->code;
    if ((cVar1 == 0x80c) || (cVar1 == 0x80e)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((!bVar2) || (cVar3 = expr_full_expression_in_eh_state(flags), cVar3 == '\0'))
    goto LAB_1042e089;
    pcVar5 = expr_resolve_function_address(PTR_104d152c,node);
    if (pcVar5 == (c1_node *)0x0) {
      pcVar5 = expr_report_function_operand(node->op,node);
    }
    flow2_w1 = 0;
    flow2_w2 = 0;
    flow2_kind = 0xc;
    flow2_w3 = 0;
    func_check_flow_state_complexity((c1_u8 *)&flow2_kind,0x10);
    pcVar4 = tree_new_int_constant(1);
    left = expr_unwind_actions(pcVar5);
    pcVar4 = expr_build_binary('7',left,pcVar4);
    if (pcVar4 != (c1_node *)0x0) goto LAB_1042e0c4;
  }
  func_flow_state_pop_record();
  g_flow_operator_depth = g_flow_operator_depth + 1;
  if (g_flow_operator_depth == 0) {
    g_flow_operator_depth = 0;
  }
  else {
    do {
      while ((g_flow_state_top != (c1_flow_state *)0x0 && (g_flow_state_top->kind == 0xd))) {
        if ((g_flow_state_top->flags & 1) != 0) {
          local_1c = g_flow_state_top->subject;
          local_18 = g_flow_state_top->word14;
          local_14 = g_flow_state_top->word18;
          local_10 = g_flow_state_top->word1c;
          local_c = g_flow_state_top->word20;
        }
        func_flow_state_pop_record();
      }
      g_flow_operator_depth = g_flow_operator_depth + -1;
    } while (((((flags & 2) != 0) && (g_flow_state_top != (c1_flow_state *)0x0)) &&
             (g_flow_state_top->kind == 0x3e)) &&
            (func_flow_state_pop_record(), g_flow_operator_depth != 0));
  }
  if (local_1c != (void *)0x0) {
    func_check_flow_state_complexity((c1_u8 *)&guard_kind,0x24);
  }
  eh_merge_state_markers(pcVar5);
  node = pcVar5;
LAB_1042e020:
  if (g_flow_error_jmpbuf == jmpbuf) {
    g_flow_error_jmpbuf = (void *)0x0;
  }
  return node;
}

