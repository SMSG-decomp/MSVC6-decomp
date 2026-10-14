void __cdecl stmt_else_begin_flow_state(void)

{
  c1_flow_state *pcVar1;
  int iVar2;
  int jmpbuf [16];
  c1_u8 local_18 [16];
  int local_8;
  
  local_18[0] = '\x16';
  local_18[1] = '\0';
  local_18[2] = '\0';
  local_18[3] = '\0';
  local_18[4] = '\0';
  local_18[5] = '\0';
  local_18[6] = '\0';
  local_18[7] = '\0';
  local_18[8] = '\0';
  local_18[9] = '\0';
  local_18[10] = '\0';
  local_18[0xb] = '\0';
  local_18[0xc] = '\0';
  local_18[0xd] = '\0';
  local_18[0xe] = '\0';
  local_18[0xf] = '\0';
  local_8 = 0;
  if ((g_flow_analysis_active != 0) && (g_flow_error_jmpbuf == (void *)0x0)) {
    if (g_flow_state_abandoned != '\0') {
      return;
    }
    g_flow_error_jmpbuf = jmpbuf;
    iVar2 = _setjmp3(jmpbuf,0);
    if (iVar2 != 0) {
      g_flow_error_jmpbuf = (void *)0x0;
      return;
    }
  }
  stmt_if_then_end_flow_state(0);
  local_8 = g_flow_goto_count;
  func_check_flow_state_complexity(local_18,0x14);
  pcVar1 = func_flow_state_find(g_flow_state_top,0x11,'\x01');
  pcVar1->word14 = (int)g_flow_state_top;
  if (g_flow_error_jmpbuf == jmpbuf) {
    g_flow_error_jmpbuf = (void *)0x0;
    return;
  }
  return;
}

