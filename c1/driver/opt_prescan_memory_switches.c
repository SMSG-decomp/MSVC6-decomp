void __cdecl opt_prescan_memory_switches(char **argv)

{
  char **ppcVar1;
  char *word;
  int iVar2;
  byte *pbVar3;
  char **ppcVar4;
  byte local_204 [516];
  
  iVar2 = 0;
  ppcVar4 = argv + 1;
  word = *ppcVar4;
  while (word != (char *)0x0) {
    iVar2 = opt_prescan_Bm_ZB_Zm(word,iVar2);
    ppcVar1 = ppcVar4 + 1;
    ppcVar4 = ppcVar4 + 1;
    word = *ppcVar1;
  }
  iVar2 = 0;
  pbVar3 = (byte *)getenv("MSC_CMD_FLAGS");
  if (pbVar3 != (byte *)0x0) {
    pbVar3 = opt_check_switch_length(pbVar3,local_204,0x202);
    while (local_204[0] != 0) {
      iVar2 = opt_prescan_Bm_ZB_Zm((char *)local_204,iVar2);
      pbVar3 = opt_check_switch_length(pbVar3,local_204,0x202);
    }
  }
  return;
}

