void eh_check_leave(void)

{
  if (g_leave_label_stack != (c1_label_cell *)0x0) {
    il_emit_tuple(0x3a,g_leave_label_stack->label);
    return;
  }
  diag_error(0x2bf);
  return;
}

