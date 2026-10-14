void __cdecl eh_except_end(void)

{
  eh_labels_leave_try_scope();
  g_seh_except_depth = g_seh_except_depth + -1;
  il_emit_tuple(0x90,(c1_node *)0x0);
  return;
}

