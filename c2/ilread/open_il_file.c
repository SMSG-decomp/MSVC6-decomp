FILE * __fastcall open_il_file(char *prefix,char *suffix,char *mode,char *description)

{
  char cVar1;
  FILE *pFVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char local_104 [260];
  
  uVar4 = 0xffffffff;
  do {
    pcVar7 = prefix;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar7 = prefix + 1;
    cVar1 = *prefix;
    prefix = pcVar7;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar7 + -uVar4;
  pcVar3 = local_104;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar3 = pcVar3 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar3 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar3 = pcVar3 + 1;
  }
  uVar4 = 0xffffffff;
  do {
    pcVar7 = suffix;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar7 = suffix + 1;
    cVar1 = *suffix;
    suffix = pcVar7;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar6 = -1;
  pcVar3 = local_104;
  do {
    pcVar8 = pcVar3;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar8 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar8;
  } while (cVar1 != '\0');
  pcVar7 = pcVar7 + -uVar4;
  pcVar3 = pcVar8 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar3 = pcVar3 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar3 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar3 = pcVar3 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = local_104;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  if (0x104 < ~uVar4 - 1) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\Common\\ioin.c",0x13b);
  }
  pFVar2 = fopen(local_104,mode);
  pcVar7 = local_104;
  if (pFVar2 != (FILE *)0x0) {
    return pFVar2;
  }
  pcVar3 = load_message(0x137);
  fatal_error_errno(0x53,pcVar3,pcVar7);
}

