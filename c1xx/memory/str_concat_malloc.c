char * __cdecl str_concat_malloc(char *prefix,char *suffix)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  
  uVar3 = 0xffffffff;
  pcVar2 = prefix;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar4 = ~uVar3 - 1;
  uVar5 = 0xffffffff;
  pcVar2 = suffix;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = mem_xmalloc(~uVar5 + 1 + iVar4);
  uVar5 = 0xffffffff;
  do {
    pcVar7 = prefix;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar7 = prefix + 1;
    cVar1 = *prefix;
    prefix = pcVar7;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar7 + -uVar5;
  pcVar8 = pcVar2;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar2[iVar4] = '/';
  do {
    pcVar7 = suffix;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar7 = suffix + 1;
    cVar1 = *suffix;
    suffix = pcVar7;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar7 + -uVar5;
  pcVar8 = pcVar2 + ~uVar3;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  return pcVar2;
}

