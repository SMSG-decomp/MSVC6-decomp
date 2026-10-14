int __cdecl eh_state_find_by_source_number(int number)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = g_eh_current_state;
  if (-1 < g_eh_current_state) {
    piVar2 = &g_eh_state_table[g_eh_current_state].source_number;
    do {
      if (*piVar2 == number) {
        return uVar1;
      }
      uVar1 = uVar1 - 1;
      piVar2 = piVar2 + -4;
    } while (uVar1 < 0x80000000);
  }
  return uVar1;
}

