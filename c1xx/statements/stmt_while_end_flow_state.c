void __cdecl stmt_while_end_flow_state(void)

{
  c1_flow_state **ppcVar1;
  c1_flow_state *pcVar2;
  c1_flow_state *pcVar3;
  int iVar4;
  c1_flow_state *pcVar5;
  int jmpbuf [16];
  c1_u8 local_14 [16];
  
  if (g_flow_state_abandoned != '\0') {
    return;
  }
  stmt_while_body_end_flow_state();
  if ((g_flow_state_top != (c1_flow_state *)0x0) && (g_flow_state_top->kind == 0x19)) {
    func_flow_state_pop_record();
    return;
  }
  if ((g_flow_analysis_active != 0) && (g_flow_error_jmpbuf == (void *)0x0)) {
    if (g_flow_state_abandoned != '\0') {
      return;
    }
    g_flow_error_jmpbuf = jmpbuf;
    iVar4 = _setjmp3(jmpbuf,0);
    if (iVar4 != 0) {
      g_flow_error_jmpbuf = (void *)0x0;
      return;
    }
  }
  local_14[4] = '\0';
  local_14[5] = '\0';
  local_14[6] = '\0';
  local_14[7] = '\0';
  local_14[8] = '\0';
  local_14[9] = '\0';
  local_14[10] = '\0';
  local_14[0xb] = '\0';
  local_14[0] = '\x1e';
  local_14[1] = '\0';
  local_14[2] = '\0';
  local_14[3] = '\0';
  local_14[0xc] = '\0';
  local_14[0xd] = '\0';
  local_14[0xe] = '\0';
  local_14[0xf] = '\0';
  func_check_flow_state_complexity(local_14,0x10);
  pcVar2 = g_flow_state_top;
  ppcVar1 = &g_flow_state_top->prev;
  pcVar3 = func_flow_state_find(g_flow_state_top->prev,0x19,'\x01');
  pcVar5 = pcVar3->next;
  if (pcVar5->kind == 0x1a) {
    iVar4 = pcVar5->next->kind;
    if (iVar4 == 0x3f) {
      pcVar3->flags = pcVar3->flags | 0x10;
      pcVar5 = pcVar5->next;
    }
    else {
      if (iVar4 != 0x40) goto LAB_10449288;
      pcVar3->flags = pcVar3->flags | 0x20;
      pcVar5 = pcVar5->next;
    }
    func_flow_state_release(pcVar5);
  }
LAB_10449288:
  pcVar5 = pcVar3->next;
  pcVar3->next = pcVar2;
  pcVar3->subject = pcVar5;
  *ppcVar1 = pcVar3;
  if (g_flow_error_jmpbuf == jmpbuf) {
    g_flow_error_jmpbuf = (void *)0x0;
    return;
  }
  return;
}

