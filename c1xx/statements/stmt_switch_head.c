void __cdecl stmt_switch_head(int node)

{
  uint edi;
  ushort uVar1;
  byte bVar2;
  c1_node *pcVar3;
  
  stmt_new_loop_label(&g_loop_top_label_stack,0x11);
  stmt_new_loop_label(&g_break_label_stack,0x12);
  stmt_new_loop_label((c1xx_label_cell **)&g_switch_case_stack,0x13);
  g_switch_case_stack->cases = (void *)0x0;
  stmt_new_loop_label(&g_default_label_stack,0x14);
  g_default_label_stack->label = (c1_node *)0x0;
  if (node == 0) {
    g_loop_top_label_stack->label->type = g_type_int;
    stmt_switch_body_begin_flow_state((c1_type *)0x0);
    return;
  }
  pcVar3 = stmt_check_controlling_expression((c1_node *)node,1);
  bVar2 = pcVar3->kind & 7;
  if (bVar2 == 1) {
    if (pcVar3->op == '<') {
      diag_warning(1,0x90,0x3c);
    }
  }
  else if ((bVar2 == 2) && (edi = pcVar3->op - 0x32, edi < 0x1e)) {
    stmt_check_switch_expression(edi,pcVar3);
    return;
  }
  uVar1 = pcVar3->type->code;
  if ((uVar1 & 0x110) == 0) {
    diag_error(0x32);
    g_loop_top_label_stack->label->type = g_type_int;
  }
  else {
    if (((uVar1 & 0x100) == 0) && ((uVar1 & 0xfff) != 0x10)) {
      pcVar3 = (c1_node *)expr_apply_implicit_conversion(pcVar3);
    }
    g_loop_top_label_stack->label->type = pcVar3->type;
  }
  pcVar3 = tree_new_unary(0x85,pcVar3->type,pcVar3);
  PTR_104de3b4 = g_loop_top_label_stack->label->left;
  il_emit_pragma_or_segment_record(0x24);
  il_emit_expression_tree(pcVar3);
  stmt_switch_body_begin_flow_state(pcVar3->type);
  return;
}

