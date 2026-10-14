void __fastcall path_make_relative(char *from,char *to,char *out)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char full_from [260];
  char full_to [260];
  
  _fullpath(full_from,from,0x104);
  _fullpath(full_to,to,0x104);
  pcVar7 = full_to;
  pcVar2 = full_from;
  if (full_from[0] == full_to[0]) {
    do {
      pcVar9 = pcVar2 + 1;
      pcVar8 = pcVar7 + 1;
      pcVar2 = pcVar2 + 1;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar9 == *pcVar8);
  }
  cVar1 = *pcVar2;
  for (; ((cVar1 != '\\' && (cVar1 != '/')) && (full_from < pcVar2)); pcVar2 = pcVar2 + -1) {
    cVar1 = pcVar2[-1];
  }
  if (pcVar2 != full_from) {
    cVar1 = *pcVar7;
    for (; ((cVar1 != '\\' && (cVar1 != '/')) && (full_to < pcVar7)); pcVar7 = pcVar7 + -1) {
      cVar1 = pcVar7[-1];
    }
    iVar6 = 0;
    cVar1 = pcVar2[1];
    while (cVar1 != '\0') {
      if ((cVar1 == '\\') || (cVar1 == '/')) {
        iVar6 = iVar6 + 1;
      }
      cVar1 = pcVar2[2];
      pcVar2 = pcVar2 + 1;
    }
    *out = '\0';
    if (0 < iVar6) {
      do {
        uVar3 = 0xffffffff;
        pcVar2 = "..\\";
        do {
          pcVar9 = pcVar2;
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          pcVar9 = pcVar2 + 1;
          cVar1 = *pcVar2;
          pcVar2 = pcVar9;
        } while (cVar1 != '\0');
        uVar3 = ~uVar3;
        iVar5 = -1;
        pcVar2 = out;
        do {
          pcVar8 = pcVar2;
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          pcVar8 = pcVar2 + 1;
          cVar1 = *pcVar2;
          pcVar2 = pcVar8;
        } while (cVar1 != '\0');
        pcVar2 = pcVar9 + -uVar3;
        pcVar9 = pcVar8 + -1;
        for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined4 *)pcVar9 = *(undefined4 *)pcVar2;
          pcVar2 = pcVar2 + 4;
          pcVar9 = pcVar9 + 4;
        }
        iVar6 = iVar6 + -1;
        for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *pcVar9 = *pcVar2;
          pcVar2 = pcVar2 + 1;
          pcVar9 = pcVar9 + 1;
        }
      } while (iVar6 != 0);
    }
    uVar3 = 0xffffffff;
    pcVar2 = pcVar7 + 1;
    do {
      pcVar7 = pcVar2;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar7 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar7;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar6 = -1;
    do {
      pcVar2 = out;
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      pcVar2 = out + 1;
      cVar1 = *out;
      out = pcVar2;
    } while (cVar1 != '\0');
    pcVar7 = pcVar7 + -uVar3;
    pcVar2 = pcVar2 + -1;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar2 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar2 = pcVar2 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar2 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar2 = pcVar2 + 1;
    }
    return;
  }
  uVar3 = 0xffffffff;
  pcVar2 = full_to;
  do {
    pcVar7 = pcVar2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar7 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar7;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar2 = pcVar7 + -uVar3;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)out = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    out = out + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *out = *pcVar2;
    pcVar2 = pcVar2 + 1;
    out = out + 1;
  }
  return;
}

