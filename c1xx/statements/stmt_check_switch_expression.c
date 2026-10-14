void stmt_check_switch_expression(int edi,c1_node *node)

{
  ushort uVar1;
  c1_node *node_00;
  
  switch(g_stmt_switch_expression_case_table[edi]) {
  case 0:
    diag_warning(1,0x91);
    break;
  case 1:
    diag_warning(1,0x90);
  }
  uVar1 = node->type->code;
  if ((uVar1 & 0x110) == 0) {
    diag_error(0x32);
    g_loop_top_label_stack->label->type = g_type_int;
  }
  else {
    if (((uVar1 & 0x100) == 0) && ((uVar1 & 0xfff) != 0x10)) {
      node = (c1_node *)expr_apply_implicit_conversion(node);
    }
    g_loop_top_label_stack->label->type = node->type;
  }
  node_00 = tree_new_unary(0x85,node->type,node);
  PTR_104de3b4 = g_loop_top_label_stack->label->left;
  il_emit_pragma_or_segment_record(0x24);
  il_emit_expression_tree(node_00);
  stmt_switch_body_begin_flow_state(node_00->type);
  return;
}

