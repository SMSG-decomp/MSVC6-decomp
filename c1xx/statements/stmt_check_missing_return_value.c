void __cdecl stmt_check_missing_return_value(void)

{
  int iVar1;
  int jmpbuf [16];
  
  if (g_current_function == (c1_symbol *)0x0) {
    return;
  }
  if (g_flow_state_top == (c1_flow_state *)0x0) {
    if (((g_current_function->flags22 & 1) != 0) && ((g_current_function->flags5 & 0x10) == 0)) {
      diag_error(0x231,g_current_function);
    }
    func_flow_state_reset();
    return;
  }
  iVar1 = func_has_unreferenced_label();
  if ((char)iVar1 != '\0') {
    return;
  }
  if ((g_flow_analysis_active != 0) && (g_flow_error_jmpbuf == (void *)0x0)) {
    if (g_flow_state_abandoned != '\0') {
      return;
    }
    g_flow_error_jmpbuf = jmpbuf;
    iVar1 = _setjmp3(jmpbuf,0);
    if (iVar1 != 0) {
      g_flow_error_jmpbuf = (void *)0x0;
      return;
    }
  }
  if (g_error_count == 0) {
    eh_check_goto_targets();
  }
  if (g_flow_error_jmpbuf == jmpbuf) {
    g_flow_error_jmpbuf = (void *)0x0;
    return;
  }
  return;
}

