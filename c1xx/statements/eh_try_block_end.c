void __cdecl eh_try_block_end(void)

{
  eh_labels_leave_try_scope();
  g_seh_try_depth = g_seh_try_depth + -1;
  label_emit_definition(g_seh_try_label_stack->label);
  g_seh_try_label_stack = g_seh_try_label_stack->next;
  g_loop_label_count = g_loop_label_count + -1;
  if (g_loop_label_count == 0) {
    arena_reset_ptr(g_arenas + 6);
    return;
  }
  return;
}

