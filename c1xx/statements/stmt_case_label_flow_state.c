void __cdecl stmt_case_label_flow_state(c1_node *case_value)

{
  c1_flow_state *pcVar1;
  int iVar2;
  c1_u8 *record;
  uint size;
  int jmpbuf [16];
  c1_u8 local_30 [20];
  void *local_1c;
  c1_u8 local_18 [20];
  
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
  stmt_check_case_skips_initialization((uint)(case_value != (c1_node *)0x0));
  if (case_value == (c1_node *)0x0) {
    local_18[0] = '8';
    local_18[1] = '\0';
    local_18[2] = '\0';
    local_18[3] = '\0';
    local_18[8] = '\0';
    local_18[9] = '\0';
    local_18[10] = '\0';
    local_18[0xb] = '\0';
    local_18[0xc] = '\0';
    local_18[0xd] = '\0';
    local_18[0xe] = '\0';
    local_18[0xf] = '\0';
    local_18[0x10] = '\0';
    local_18[0x11] = '\0';
    local_18[0x12] = '\0';
    local_18[0x13] = '\0';
    if (g_flow_switch_record != (c1_flow_state *)0x0) {
      g_flow_switch_record->flags = g_flow_switch_record->flags | 1;
    }
    size = 0x14;
    record = local_18;
    local_18[4] = '\0';
    local_18[5] = '\0';
    local_18[6] = '\0';
    local_18[7] = '\0';
  }
  else {
    local_30[0] = '7';
    local_30[1] = '\0';
    local_30[2] = '\0';
    local_30[3] = '\0';
    size = 0x18;
    local_30[8] = '\0';
    local_30[9] = '\0';
    local_30[10] = '\0';
    local_30[0xb] = '\0';
    record = local_30;
    local_30[0xc] = '\0';
    local_30[0xd] = '\0';
    local_30[0xe] = '\0';
    local_30[0xf] = '\0';
    local_30[0x10] = '\0';
    local_30[0x11] = '\0';
    local_30[0x12] = '\0';
    local_30[0x13] = '\0';
    local_30[4] = '\0';
    local_30[5] = '\0';
    local_30[6] = '\0';
    local_30[7] = '\0';
    local_1c = case_value->left;
  }
  func_check_flow_state_complexity(record,size);
  pcVar1 = g_flow_state_top;
  if (g_flow_switch_record != (c1_flow_state *)0x0) {
    g_flow_state_top->subject = (void *)g_flow_switch_record->word14;
    g_flow_switch_record->word14 = (int)pcVar1;
  }
  if (g_flow_error_jmpbuf == jmpbuf) {
    g_flow_error_jmpbuf = (void *)0x0;
    return;
  }
  return;
}

