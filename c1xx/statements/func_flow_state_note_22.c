void __cdecl func_flow_state_note_22(void)

{
  c1_u8 local_10 [16];
  
  if (g_flow_state_abandoned == '\0') {
    stmt_do_body_end_flow_state();
    local_10[4] = '\0';
    local_10[5] = '\0';
    local_10[6] = '\0';
    local_10[7] = '\0';
    local_10[8] = '\0';
    local_10[9] = '\0';
    local_10[10] = '\0';
    local_10[0xb] = '\0';
    local_10[0] = '\"';
    local_10[1] = '\0';
    local_10[2] = '\0';
    local_10[3] = '\0';
    local_10[0xc] = '\0';
    local_10[0xd] = '\0';
    local_10[0xe] = '\0';
    local_10[0xf] = '\0';
    func_check_flow_state_complexity(local_10,0x10);
  }
  return;
}

