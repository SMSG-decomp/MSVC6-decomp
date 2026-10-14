uint __cdecl diag_warning_is_enabled(uint level,int n)

{
  uint uVar1;
  
  uVar1 = (int)g_warning_state->state[n];
  switch((int)g_warning_state->state[n]) {
  case 0:
  case 5:
    uVar1 = level;
switchD_10488ee6_caseD_1:
    return uVar1 & (g_warning_state->level < (int)uVar1) - 1;
  case 1:
  case 2:
  case 3:
  case 4:
    goto switchD_10488ee6_caseD_1;
  default:
    return 0;
  case 0xe:
    return 1;
  }
}

