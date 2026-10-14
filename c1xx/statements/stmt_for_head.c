void __cdecl stmt_for_head(c1_node *node,c1_node *node2,c1_node *node3)

{
  c1_node *node_00;
  
  stmt_new_loop_label(&g_loop_top_label_stack,8);
  stmt_new_loop_label(&g_continue_label_stack,0xc);
  stmt_new_loop_label(&g_break_label_stack,0xb);
  if (node != (c1_node *)0x0) {
    stmt_emit_expression(node);
  }
  if (node3 != (c1_node *)0x0) {
    node_00 = expr_full_expression_guarded(node3,2);
    if (node_00 != (c1_node *)0x0) {
      il_emit_tuple(0x3a,g_loop_top_label_stack->label);
      label_emit_definition(g_continue_label_stack->label);
      stmt_emit_expression(node_00);
      label_emit_definition(g_loop_top_label_stack->label);
      goto LAB_10442103;
    }
  }
  g_loop_top_label_stack->label = g_continue_label_stack->label;
  label_emit_definition(g_continue_label_stack->label);
LAB_10442103:
  if (node2 != (c1_node *)0x0) {
    stmt_emit_condition(node2,*(c1_node **)((int)g_break_label_stack + 4),0);
  }
  return;
}

