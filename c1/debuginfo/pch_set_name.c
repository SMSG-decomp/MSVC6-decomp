void __cdecl pch_set_name(char *file)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char local_204 [4];
  char local_200 [256];
  char local_100 [256];
  
  if (g_pch_file_name != (char *)0x0) {
    g_il_pch_name = g_pch_file_name;
    return;
  }
  _splitpath(file,local_204,local_100,local_200,(char *)0x0);
  uVar2 = 0xffffffff;
  pcVar5 = local_204;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = 0xffffffff;
  pcVar5 = local_100;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar4 = 0xffffffff;
  pcVar5 = local_200;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (g_pch_name_buffer != (char *)0x0) {
    free(g_pch_name_buffer);
  }
  g_pch_name_buffer = mem_xmalloc(~uVar2 + ~uVar3 + ~uVar4 + 2);
  _makepath(g_pch_name_buffer,local_204,local_100,local_200,".pch");
  g_pch_file_name = g_pch_name_buffer;
  g_il_pch_name = g_pch_name_buffer;
  return;
}

