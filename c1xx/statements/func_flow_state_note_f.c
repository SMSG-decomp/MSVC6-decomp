void __cdecl func_flow_state_note_f(void)

{
  c1_flow_state *pcVar1;
  c1_flow_state *pcVar2;
  c1_u8 local_14 [16];
  int local_4;
  
  local_14[0] = '\x0f';
  local_14[1] = '\0';
  local_14[2] = '\0';
  local_14[3] = '\0';
  local_14[8] = '\0';
  local_14[9] = '\0';
  local_14[10] = '\0';
  local_14[0xb] = '\0';
  local_14[0xc] = '\0';
  local_14[0xd] = '\0';
  local_14[0xe] = '\0';
  local_14[0xf] = '\0';
  if (g_flow_state_abandoned == '\0') {
    local_14[4] = '\0';
    local_14[5] = '\0';
    local_14[6] = '\0';
    local_14[7] = '\0';
    local_4 = g_eh_current_state;
    func_check_flow_state_complexity(local_14,0x14);
    if (g_flow_state_function_record != (c1_flow_state *)0x0) {
      pcVar1 = g_flow_state_function_record->next;
      pcVar2 = g_flow_state_top->prev;
      g_flow_state_top->next = pcVar1;
      pcVar1->prev = g_flow_state_top;
      g_flow_state_top->prev = g_flow_state_function_record;
      g_flow_state_function_record->next = g_flow_state_top;
      pcVar2->next = (c1_flow_state *)0x0;
      g_flow_state_function_record = (c1_flow_state *)0x0;
      g_flow_state_top = pcVar2;
    }
  }
  return;
}

