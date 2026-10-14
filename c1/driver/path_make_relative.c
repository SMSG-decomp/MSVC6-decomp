char * __cdecl path_make_relative(char *out,char *base_dir,char *path,size_t size)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  
  pcVar6 = path;
  *out = '\0';
  pcVar2 = base_dir;
  if (*base_dir == *path) {
    do {
      pcVar8 = pcVar2 + 1;
      pcVar7 = path + 1;
      pcVar2 = pcVar2 + 1;
      path = path + 1;
    } while (*pcVar8 == *pcVar7);
  }
  cVar1 = *pcVar2;
  for (; (cVar1 != '\\' && (base_dir < pcVar2)); pcVar2 = pcVar2 + -1) {
    cVar1 = pcVar2[-1];
  }
  if (pcVar2 == base_dir) {
    strncpy(out,pcVar6,size);
    return out;
  }
  cVar1 = *path;
  while ((cVar1 != '\\' && (base_dir < pcVar2))) {
    cVar1 = path[-1];
    path = path + -1;
  }
  pcVar2 = strchr(pcVar2 + 1,0x5c);
  do {
    if ((pcVar2 == (char *)0x0) || (size == 0)) {
      strncat(out,path + 1,size);
      return out;
    }
    uVar3 = 0xffffffff;
    size = size - 3;
    pcVar6 = "..\\";
    do {
      pcVar8 = pcVar6;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar8 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar8;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar4 = -1;
    pcVar6 = out;
    do {
      pcVar7 = pcVar6;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar7;
    } while (cVar1 != '\0');
    pcVar6 = pcVar8 + -uVar3;
    pcVar8 = pcVar7 + -1;
    for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar8 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar8 = pcVar8 + 1;
    }
    pcVar2 = strchr(pcVar2 + 1,0x5c);
  } while( true );
}

