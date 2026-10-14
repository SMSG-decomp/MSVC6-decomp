void __cdecl stmt_if_end_flow_state(void)

{
  void *pvVar1;
  c1_flow_state *pcVar2;
  int iVar3;
  c1_flow_state *pcVar4;
  c1_flow_state **ppcVar5;
  int jmpbuf [16];
  c1_u8 local_20 [16];
  void *local_10;
  c1_flow_state *else_open;
  c1_flow_state *local_8;
  
  if (g_flow_state_top != (c1_flow_state *)0x0) {
    if (g_flow_state_top->kind == 0x11) {
      func_flow_state_pop_record();
      return;
    }
    if ((g_flow_state_top != (c1_flow_state *)0x0) && (g_flow_state_top->kind == 0x13)) {
      func_flow_state_pop_record();
      if (g_flow_state_top == (c1_flow_state *)0x0) goto LAB_104a4c46;
      if (g_flow_state_top->kind == 0x3f) {
LAB_104a4c22:
        func_flow_state_pop_record();
      }
      else {
        if (g_flow_state_top == (c1_flow_state *)0x0) goto LAB_104a4c46;
        if (g_flow_state_top->kind == 0x40) goto LAB_104a4c22;
      }
      if ((g_flow_state_top != (c1_flow_state *)0x0) && (g_flow_state_top->kind == 0x12)) {
        func_flow_state_pop_record();
        func_flow_state_pop_record();
        return;
      }
LAB_104a4c46:
      func_flow_state_release_innermost(0x11);
      func_flow_state_release_innermost(0x12);
      return;
    }
  }
  if ((g_flow_analysis_active != 0) && (g_flow_error_jmpbuf == (void *)0x0)) {
    if (g_flow_state_abandoned != '\0') {
      return;
    }
    g_flow_error_jmpbuf = jmpbuf;
    iVar3 = _setjmp3(jmpbuf,0);
    if (iVar3 != 0) {
      g_flow_error_jmpbuf = (void *)0x0;
      return;
    }
  }
  local_20[4] = '\0';
  local_20[5] = '\0';
  local_20[6] = '\0';
  local_20[7] = '\0';
  local_20[8] = '\0';
  local_20[9] = '\0';
  local_20[10] = '\0';
  local_20[0xb] = '\0';
  local_20[0] = '\x18';
  local_20[1] = '\0';
  local_20[2] = '\0';
  local_20[3] = '\0';
  local_20[0xc] = '\0';
  local_20[0xd] = '\0';
  local_20[0xe] = '\0';
  local_20[0xf] = '\0';
  func_check_flow_state_complexity(local_20,0x10);
  local_8 = g_flow_state_top;
  ppcVar5 = &g_flow_state_top->prev;
  pcVar2 = func_flow_state_find(*ppcVar5,0x11,'\x01');
  local_10 = pcVar2->subject;
  else_open = (c1_flow_state *)pcVar2->word14;
  if (pcVar2->next->kind != 0x12) {
    pcVar2->next = local_8;
    *ppcVar5 = pcVar2;
    goto LAB_10426ac3;
  }
  pcVar4 = func_flow_state_find_next(pcVar2->next->next,0x13,'\x01');
  iVar3 = pcVar4->prev->kind;
  if (iVar3 == 0x3f) {
    pcVar2->flags = pcVar2->flags | 0x10;
    pcVar2 = pcVar4->prev;
LAB_104a4cce:
    func_flow_state_release(pcVar2);
  }
  else if (iVar3 == 0x40) {
    pcVar2->flags = pcVar2->flags | 0x20;
    pcVar2 = pcVar4->prev;
    goto LAB_104a4cce;
  }
  pcVar4->next = local_8;
  *ppcVar5 = pcVar4;
LAB_10426ac3:
  pvVar1 = local_10;
  if ((local_10 != (void *)0x0) && (else_open != (c1_flow_state *)0x0)) {
    pcVar2 = func_flow_state_find_next(*(c1_flow_state **)((int)local_10 + 8),0x15,'\x01');
    pcVar2->next = local_8;
    else_open->prev = *(c1_flow_state **)((int)pvVar1 + 0xc);
  }
  if (g_flow_error_jmpbuf == jmpbuf) {
    g_flow_error_jmpbuf = (void *)0x0;
    return;
  }
  return;
}

