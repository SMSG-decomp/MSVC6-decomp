void eh_check_leave(void)

{
  if (g_seh_try_label_stack != (c1xx_label_cell *)0x0) {
    il_emit_tuple(0x3a,g_seh_try_label_stack->label);
    return;
  }
  diag_error(0x2bf);
  return;
}

