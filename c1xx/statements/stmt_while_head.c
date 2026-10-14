void stmt_while_head(void)

{
  stmt_new_loop_label(&g_loop_top_label_stack,8);
  stmt_new_loop_label(&g_continue_label_stack,0xc);
  stmt_new_loop_label(&g_break_label_stack,0xb);
  g_loop_top_label_stack->label = g_continue_label_stack->label;
  label_emit_definition(g_continue_label_stack->label);
  return;
}

