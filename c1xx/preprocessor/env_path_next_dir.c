char * __cdecl env_path_next_dir(char *list,char *buf,int size)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  
  cVar2 = *list;
  while (cVar2 == ';') {
    pcVar3 = list + 1;
    list = list + 1;
    cVar2 = *pcVar3;
  }
  iVar4 = size + -1;
  pcVar3 = list;
  if (iVar4 != 0) {
    cVar2 = *list;
    while ((cVar2 != '\0' && (cVar2 != ';'))) {
      if (cVar2 == '\"') {
        pcVar1 = pcVar3 + 1;
        pcVar3 = pcVar3 + 1;
        cVar2 = *pcVar1;
        while ((cVar2 != '\0' && (cVar2 != '\"'))) {
          *buf = cVar2;
          buf = buf + 1;
          pcVar3 = pcVar3 + 1;
          iVar4 = iVar4 + -1;
          if (iVar4 == 0) goto LAB_104a25ff;
          cVar2 = *pcVar3;
        }
        if (*pcVar3 != '\0') {
          pcVar3 = pcVar3 + 1;
        }
      }
      else {
        *buf = cVar2;
        buf = buf + 1;
        pcVar3 = pcVar3 + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) {
LAB_104a25ff:
          *buf = '\0';
          return (char *)0x0;
        }
      }
      cVar2 = *pcVar3;
    }
    if (*pcVar3 == ';') {
      do {
        pcVar1 = pcVar3 + 1;
        pcVar3 = pcVar3 + 1;
      } while (*pcVar1 == ';');
      *buf = '\0';
      return (char *)(-(uint)(list != pcVar3) & (uint)pcVar3);
    }
  }
  *buf = '\0';
  return (char *)(-(uint)(list != pcVar3) & (uint)pcVar3);
}

