char * __cdecl pdb_relative_path(char *file)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  char local_204 [256];
  char local_104 [260];
  
  if (g_pdb_directory_split == '\0') {
    _splitpath(g_pdb_file_name,&g_pdb_directory,g_pdb_dir_part,local_204,local_204);
    uVar3 = 0xffffffff;
    pcVar2 = g_pdb_dir_part;
    do {
      pcVar7 = pcVar2;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar7 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar7;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    g_pdb_directory_split = '\x01';
    iVar4 = -1;
    pcVar2 = &g_pdb_directory;
    do {
      pcVar6 = pcVar2;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar6 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar6;
    } while (cVar1 != '\0');
    pcVar2 = pcVar7 + -uVar3;
    pcVar7 = pcVar6 + -1;
    for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar7 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      pcVar7 = pcVar7 + 1;
    }
  }
  file_make_canonical_path(local_104,file,0x104);
  pcVar2 = path_make_relative(&g_pdb_relative_path,&g_pdb_directory,local_104,0x104);
  return pcVar2;
}

