int __fastcall warning_state_lookup(int id)

{
  int iVar1;
  c2_warning_state *pcVar2;
  
  iVar1 = 0;
  if (0 < g_warning_state_count) {
    pcVar2 = g_warning_state_table;
    do {
      if (pcVar2->warning == id) {
        return (int)g_warning_state_table[iVar1].state;
      }
      iVar1 = iVar1 + 1;
      pcVar2 = pcVar2 + 1;
    } while (iVar1 < g_warning_state_count);
  }
  return 0;
}

