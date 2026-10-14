byte __cdecl import_search_env_path(char *file,char *variable,char *result)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *rest;
  char local_108 [264];
  
  pcVar2 = getenv(variable);
  if (pcVar2 != (char *)0x0) {
    rest = env_path_next_dir(pcVar2,local_108,0x104);
    while ((rest != (char *)0x0 && (local_108[0] != '\0'))) {
      uVar5 = 0xffffffff;
      pcVar2 = local_108;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      pcVar2 = local_108 + (uVar5 - 1);
      pcVar3 = strchr(g_opt_pc,(int)local_108[uVar5 - 2]);
      uVar6 = uVar5 - 1;
      if (pcVar3 == (char *)0x0) {
        *pcVar2 = '\\';
        pcVar2 = local_108 + uVar5;
        uVar6 = uVar5;
      }
      uVar5 = 0xffffffff;
      pcVar3 = file;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if ((~uVar5 - 1) + uVar6 < 0x105) {
        uVar5 = 0xffffffff;
        pcVar3 = file;
        do {
          pcVar7 = pcVar3;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          pcVar7 = pcVar3 + 1;
          cVar1 = *pcVar3;
          pcVar3 = pcVar7;
        } while (cVar1 != '\0');
        uVar5 = ~uVar5;
        pcVar3 = pcVar7 + -uVar5;
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar2 = *(undefined4 *)pcVar3;
          pcVar3 = pcVar3 + 4;
          pcVar2 = pcVar2 + 4;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pcVar2 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          pcVar2 = pcVar2 + 1;
        }
        iVar4 = _access(local_108,0);
        if (iVar4 == 0) {
          uVar5 = 0xffffffff;
          pcVar2 = local_108;
          goto code_r0x104a272f;
        }
      }
      rest = env_path_next_dir(rest,local_108,0x104);
    }
  }
  *result = '\0';
  return 0;
  while( true ) {
    uVar5 = uVar5 - 1;
    pcVar3 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar3;
    if (cVar1 == '\0') break;
code_r0x104a272f:
    pcVar3 = pcVar2;
    if (uVar5 == 0) break;
  }
  uVar5 = ~uVar5;
  pcVar2 = pcVar3 + -uVar5;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)result = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    result = result + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *result = *pcVar2;
    pcVar2 = pcVar2 + 1;
    result = result + 1;
  }
  return 1;
}

