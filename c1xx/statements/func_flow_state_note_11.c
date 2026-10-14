void __cdecl func_flow_state_note_11(void)

{
  c1_u8 local_18 [24];
  
  local_18[0] = '\x11';
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
  if (g_flow_state_abandoned == '\0') {
    local_18[0x10] = '\0';
    local_18[0x11] = '\0';
    local_18[0x12] = '\0';
    local_18[0x13] = '\0';
    local_18[4] = '\0';
    local_18[5] = '\0';
    local_18[6] = '\0';
    local_18[7] = '\0';
    local_18[0x14] = '\0';
    local_18[0x15] = '\0';
    local_18[0x16] = '\0';
    local_18[0x17] = '\0';
    func_check_flow_state_complexity(local_18,0x18);
    stmt_if_condition_begin_flow_state();
  }
  return;
}

