void __cdecl stmt_else_end_flow_state(void)

{
  c1_flow_state *pcVar1;
  c1_node *tree;
  int iVar2;
  int jmpbuf [16];
  c1_u8 local_14 [16];
  
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
  if ((g_flow_state_top == (c1_flow_state *)0x0) || (g_flow_state_top->kind != 0x16)) {
    pcVar1 = func_flow_state_find(g_flow_state_top,0x16,'\x01');
    pcVar1->subject = (void *)((int)pcVar1->subject - g_flow_goto_count);
    local_14[4] = '\0';
    local_14[5] = '\0';
    local_14[6] = '\0';
    local_14[7] = '\0';
    local_14[8] = '\0';
    local_14[9] = '\0';
    local_14[10] = '\0';
    local_14[0xb] = '\0';
    local_14[0] = '\x17';
    local_14[1] = '\0';
    local_14[2] = '\0';
    local_14[3] = '\0';
    local_14[0xc] = '\0';
    local_14[0xd] = '\0';
    local_14[0xe] = '\0';
    local_14[0xf] = '\0';
    func_check_flow_state_complexity(local_14,0x10);
    tree = expr_unwind_actions((c1_node *)0x0);
    stmt_emit_merged_expression(tree);
  }
  else {
    pcVar1 = func_flow_state_find(g_flow_state_top,0x11,'\x01');
    pcVar1->word14 = 0;
    func_flow_state_pop_record();
  }
  stmt_if_end_flow_state();
  if (g_flow_error_jmpbuf == jmpbuf) {
    g_flow_error_jmpbuf = (void *)0x0;
    return;
  }
  return;
}

