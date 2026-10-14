void __cdecl opt_prescan_memory_switches(char **argv)

{
  char **ppcVar1;
  char *pending;
  byte *pbVar2;
  char **ppcVar3;
  char *pcVar4;
  byte local_204 [516];
  
  pending = (char *)0x0;
  ppcVar3 = argv + 1;
  pcVar4 = *ppcVar3;
  while (pcVar4 != (char *)0x0) {
    pending = opt_prescan_Bm_ZB_Zm(pcVar4,pending);
    ppcVar1 = ppcVar3 + 1;
    ppcVar3 = ppcVar3 + 1;
    pcVar4 = *ppcVar1;
  }
  pcVar4 = (char *)0x0;
  pbVar2 = (byte *)getenv("MSC_CMD_FLAGS");
  if (pbVar2 != (byte *)0x0) {
    pbVar2 = opt_check_switch_length(pbVar2,local_204,0x202);
    while (local_204[0] != 0) {
      pcVar4 = opt_prescan_Bm_ZB_Zm((char *)local_204,pcVar4);
      pbVar2 = opt_check_switch_length(pbVar2,local_204,0x202);
    }
  }
  return;
}

