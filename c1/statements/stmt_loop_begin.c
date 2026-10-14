void __cdecl stmt_loop_begin(c1_node *node,int node2,c1_node *node3)

{
  stmt_new_loop_label(&g_loop_top_label_stack,8);
  stmt_new_loop_label(&g_continue_label_stack,0xc);
  stmt_new_loop_label(&g_break_label_stack,0xb);
  if (node != (c1_node *)0x0) {
    stmt_emit_expression(node);
  }
  if (node3 == (c1_node *)0x0) {
    g_loop_top_label_stack->label = g_continue_label_stack->label;
    label_emit_definition(g_continue_label_stack->label);
  }
  else {
    il_emit_tuple(0x3a,g_loop_top_label_stack->label);
    label_emit_definition(g_continue_label_stack->label);
    stmt_emit_expression(node3);
    label_emit_definition(g_loop_top_label_stack->label);
  }
  if (node2 != 0) {
    stmt_check_controlling_expression((c1_node *)node2,g_break_label_stack->label,0);
  }
  return;
}

