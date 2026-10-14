void stmt_do_head(void)

{
  stmt_new_loop_label(&g_loop_top_label_stack,5);
  stmt_new_loop_label(&g_continue_label_stack,7);
  stmt_new_loop_label(&g_break_label_stack,6);
  label_emit_definition(g_loop_top_label_stack->label);
  return;
}

