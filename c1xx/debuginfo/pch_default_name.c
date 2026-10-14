char * __cdecl pch_default_name(char *path)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char local_204 [4];
  char local_200 [256];
  char local_100 [256];
  
  pcVar2 = g_pch_file_name;
  if (g_pch_file_name == (char *)0x0) {
    _splitpath(path,local_204,local_100,local_200,(char *)0x0);
    uVar3 = 0xffffffff;
    pcVar2 = local_204;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    uVar4 = 0xffffffff;
    pcVar2 = local_100;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    uVar5 = 0xffffffff;
    pcVar2 = local_200;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (g_pch_name_buffer != (char *)0x0) {
      free(g_pch_name_buffer);
    }
    g_pch_name_buffer = mem_xmalloc(~uVar3 + ~uVar4 + ~uVar5 + 2);
    _makepath(g_pch_name_buffer,local_204,local_100,local_200,".pch");
    pcVar2 = g_pch_name_buffer;
  }
  return pcVar2;
}

