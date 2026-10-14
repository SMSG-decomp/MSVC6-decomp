void __cdecl func_flow_state_note_25(void)

{
  c1_u8 local_14 [20];
  
  local_14[0] = '%';
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
  local_14[0x10] = '\0';
  local_14[0x11] = '\0';
  local_14[0x12] = '\0';
  local_14[0x13] = '\0';
  if (g_flow_state_abandoned == '\0') {
    local_14[4] = '\0';
    local_14[5] = '\0';
    local_14[6] = '\0';
    local_14[7] = '\0';
    func_check_flow_state_complexity(local_14,0x14);
    stmt_for_test_begin_flow_state();
  }
  return;
}

