void __fastcall warning_state_set(uint16_t warning,int16_t state)

{
  c2_warning_state *pcVar1;
  int iVar2;
  
  iVar2 = 0;
  if (g_warning_state_table[0].warning != warning) {
    pcVar1 = g_warning_state_table;
    do {
      pcVar1 = pcVar1 + 1;
      iVar2 = iVar2 + 1;
    } while (pcVar1->warning != warning);
  }
  g_warning_state_table[iVar2].state = state;
  return;
}

