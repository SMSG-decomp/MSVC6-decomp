void __cdecl diag_end_global(void)

{
  if (g_diag_message_list.nesting == 1) {
    if (g_diag_message_list.state == 2) {
      g_diag_message_list.state = 4;
      diag_queue_release_pending((int *)&g_diag_message_list);
      diag_run_context_notes(&g_diag_message_list);
    }
    arena_reset_ptr(g_arenas + 9);
    g_diag_message_list.state = 0;
  }
  g_diag_message_list.nesting = g_diag_message_list.nesting + -1;
  return;
}

