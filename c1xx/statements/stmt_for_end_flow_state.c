void stmt_for_end_flow_state(void)

{
  c1_flow_state *pcVar1;
  c1_flow_state **ppcVar2;
  c1_flow_state *pcVar3;
  c1_flow_state *pcVar4;
  c1_flow_state *pcVar5;
  c1_flow_state *pcVar6;
  int iVar7;
  c1_flow_state *pcVar8;
  c1_flow_state *pcVar9;
  int jmpbuf [16];
  c1_u8 for_close_record [16];
  
  if (g_flow_state_abandoned != '\0') {
    return;
  }
  stmt_for_body_end_flow_state();
  if ((g_flow_state_top != (c1_flow_state *)0x0) && (g_flow_state_top->kind == 0x25)) {
    func_flow_state_pop_record();
    return;
  }
  for_close_record[0] = ',';
  for_close_record[1] = '\0';
  for_close_record[2] = '\0';
  for_close_record[3] = '\0';
  for_close_record[4] = '\0';
  for_close_record[5] = '\0';
  for_close_record[6] = '\0';
  for_close_record[7] = '\0';
  for_close_record[8] = '\0';
  for_close_record[9] = '\0';
  for_close_record[10] = '\0';
  for_close_record[0xb] = '\0';
  for_close_record[0xc] = '\0';
  for_close_record[0xd] = '\0';
  for_close_record[0xe] = '\0';
  for_close_record[0xf] = '\0';
  if ((g_flow_analysis_active != 0) && (g_flow_error_jmpbuf == (void *)0x0)) {
    if (g_flow_state_abandoned != '\0') {
      return;
    }
    g_flow_error_jmpbuf = jmpbuf;
    iVar7 = _setjmp3(jmpbuf,0);
    if (iVar7 != 0) {
      g_flow_error_jmpbuf = (void *)0x0;
      return;
    }
  }
  for_close_record._4_4_ = for_close_record._4_4_ & 0xfffffffb;
  func_check_flow_state_complexity(for_close_record,0x10);
  pcVar1 = g_flow_state_top;
  ppcVar2 = &g_flow_state_top->prev;
  pcVar3 = func_flow_state_find(*ppcVar2,0x25,'\x01');
  pcVar4 = func_flow_state_find_next(pcVar3->next,0x26,'\0');
  pcVar5 = func_flow_state_find_next(pcVar3->next,0x28,'\0');
  pcVar6 = func_flow_state_find_next(pcVar3->next,0x2a,'\0');
  if (pcVar4 == (c1_flow_state *)0x0) {
    if (pcVar6 == (c1_flow_state *)0x0) {
      pcVar3->subject = pcVar5;
    }
    else {
      pcVar3->subject = pcVar6;
      if (pcVar5 != (c1_flow_state *)0x0) {
        pcVar4 = func_flow_state_find_next(pcVar6->next,0x2b,'\x01');
        pcVar9 = func_flow_state_find_next(pcVar5->next,0x29,'\x01');
        pcVar6->prev = pcVar3;
        pcVar4->next = pcVar5;
        pcVar5->prev = pcVar4;
        pcVar9->next = pcVar1;
      }
    }
    goto LAB_10442269;
  }
  pcVar3->subject = pcVar4;
  pcVar4 = func_flow_state_find_next(pcVar4->next,0x27,'\x01');
  iVar7 = pcVar4->prev->kind;
  if (iVar7 == 0x3f) {
    pcVar3->flags = pcVar3->flags | 0x10;
    pcVar9 = pcVar4->prev;
LAB_104422c8:
    func_flow_state_release(pcVar9);
  }
  else if (iVar7 == 0x40) {
    pcVar3->flags = pcVar3->flags | 0x20;
    pcVar9 = pcVar4->prev;
    goto LAB_104422c8;
  }
  if ((pcVar6 != (c1_flow_state *)0x0) && (pcVar5 != (c1_flow_state *)0x0)) {
    pcVar9 = func_flow_state_find_next(pcVar6->next,0x2b,'\x01');
    pcVar8 = func_flow_state_find_next(pcVar5->next,0x29,'\x01');
    pcVar4->next = pcVar6;
    pcVar6->prev = pcVar4;
    pcVar9->next = pcVar5;
    pcVar5->prev = pcVar9;
    pcVar8->next = pcVar1;
  }
LAB_10442269:
  pcVar3->next = pcVar1;
  *ppcVar2 = pcVar3;
  if (g_flow_error_jmpbuf == jmpbuf) {
    g_flow_error_jmpbuf = (void *)0x0;
    return;
  }
  return;
}

