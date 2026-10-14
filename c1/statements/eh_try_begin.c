void __cdecl eh_try_begin(void)

{
  if ((g_current_function->flags22 & 1) != 0) {
    diag_error(0x1ea,0x4c,0xa1);
  }
  il_emit_tuple(0x8f,(c1_node *)0x0);
  g_current_function->flags4 = g_current_function->flags4 | 0x10;
  g_current_function->flags4 = g_current_function->flags4 | 1;
  g_seh_try_depth = g_seh_try_depth + 1;
  stmt_new_loop_label(&g_leave_label_stack,0x1a);
  return;
}

