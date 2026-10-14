void __cdecl stmt_loop_end(void)

{
  il_emit_tuple(0x3a,g_continue_label_stack->label);
  label_emit_definition(*(c1_node **)((int)g_break_label_stack + 4));
  g_loop_top_label_stack = g_loop_top_label_stack->next;
  g_continue_label_stack = g_continue_label_stack->next;
  g_break_label_stack = *(void **)g_break_label_stack;
  g_loop_label_count = g_loop_label_count + -3;
  if (g_loop_label_count == 0) {
    arena_reset_ptr(g_arenas + 6);
    return;
  }
  return;
}

