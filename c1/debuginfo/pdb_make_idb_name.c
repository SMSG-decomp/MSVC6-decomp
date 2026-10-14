void __cdecl pdb_make_idb_name(char *out)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  pcVar2 = strrchr(&g_pdb_file_name,0x2e);
  if (pcVar2 == (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar2 = &g_pdb_file_name;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = (char *)~uVar3;
  }
  else {
    pcVar2 = pcVar2 + -0x1065dbb3;
  }
  pcVar4 = &g_pdb_file_name;
  pcVar5 = out;
  for (uVar3 = (uint)pcVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar3 = (uint)pcVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  builtin_strncpy(pcVar2 + (int)out,".idb",4);
  return;
}

