void __cdecl stmt_switch_body_begin_flow_state(c1_type *selector_type)

{
  c1_flow_state *pcVar1;
  c1_u8 local_10 [16];
  
  if (g_flow_state_abandoned == '\0') {
    stmt_switch_selector_end_flow_state();
    local_10[4] = '\0';
    local_10[5] = '\0';
    local_10[6] = '\0';
    local_10[7] = '\0';
    local_10[8] = '\0';
    local_10[9] = '\0';
    local_10[10] = '\0';
    local_10[0xb] = '\0';
    local_10[0] = '4';
    local_10[1] = '\0';
    local_10[2] = '\0';
    local_10[3] = '\0';
    local_10[0xc] = '\0';
    local_10[0xd] = '\0';
    local_10[0xe] = '\0';
    local_10[0xf] = '\0';
    func_check_flow_state_complexity(local_10,0x10);
    if (selector_type != (c1_type *)0x0) {
      if ((selector_type->code & 0x100) != 0) {
        pcVar1 = func_flow_state_find(g_flow_state_top,0x31,'\x01');
        pcVar1->flags = pcVar1->flags | 0x10;
        pcVar1->word1c = (int)selector_type->extra;
        return;
      }
      if ((selector_type->code & 0xfff) == 0x10) {
        pcVar1 = func_flow_state_find(g_flow_state_top,0x31,'\x01');
        pcVar1->word1c = 0;
        pcVar1->flags = pcVar1->flags | 0x10;
      }
    }
  }
  return;
}

