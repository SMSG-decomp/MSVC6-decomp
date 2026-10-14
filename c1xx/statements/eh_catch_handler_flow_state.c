void __cdecl eh_catch_handler_flow_state(c1_symbol *handler_sym)

{
  int iVar1;
  byte *pbVar2;
  c1_u8 local_20 [4];
  byte local_1c [12];
  c1_symbol *local_10;
  int local_c;
  int local_8;
  int record_word1c;
  
  local_20[0] = '\x0e';
  local_20[1] = '\0';
  local_20[2] = '\0';
  local_20[3] = '\0';
  pbVar2 = local_1c;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    pbVar2[0] = 0;
    pbVar2[1] = 0;
    pbVar2[2] = 0;
    pbVar2[3] = 0;
    pbVar2 = pbVar2 + 4;
  }
  if (g_flow_state_abandoned == '\0') {
    local_1c[0] = local_1c[0] | 2;
    if (g_error_count == 0) {
      local_8 = g_eh_current_state;
      local_c = g_eh_previous_state;
      record_word1c = 1;
    }
    local_10 = handler_sym;
    func_check_flow_state_complexity(local_20,0x20);
  }
  return;
}

