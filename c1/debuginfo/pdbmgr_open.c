char __thiscall
pdbmgr_open(c1_pdb_state *state,char *name,PDB **out_pdb,char retry,long page_size,char *mode)

{
  char cVar1;
  char *pcVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  time_t tVar9;
  int local_418;
  char local_414 [20];
  char local_400 [1024];
  
  state->read_only = '\0';
  if (mode == (char *)0x0) {
    uVar4 = 0xffffffff;
    pcVar2 = "w";
    do {
      pcVar8 = pcVar2;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar8 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar8;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar2 = pcVar8 + -uVar4;
    pcVar8 = local_414;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      pcVar8 = pcVar8 + 4;
    }
  }
  else {
    uVar4 = 0xffffffff;
    pcVar2 = mode;
    do {
      pcVar8 = pcVar2;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar8 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar8;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar2 = pcVar8 + -uVar4;
    pcVar8 = local_414;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar8 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      pcVar8 = pcVar8 + 1;
    }
    pcVar2 = strchr(local_414,0x72);
    if (pcVar2 != (char *)0x0) {
      state->read_only = '\x01';
      goto LAB_10624a39;
    }
    uVar4 = 0xffffffff;
    pcVar2 = "w";
    do {
      pcVar8 = pcVar2;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar8 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar8;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar6 = -1;
    pcVar2 = local_414;
    do {
      pcVar7 = pcVar2;
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      pcVar7 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar7;
    } while (cVar1 != '\0');
    pcVar2 = pcVar8 + -uVar4;
    pcVar8 = pcVar7 + -1;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      pcVar8 = pcVar8 + 4;
    }
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar8 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar8 = pcVar8 + 1;
  }
LAB_10624a39:
  if (g_opt_Brepro == 0) {
    tVar9 = time((time_t *)0x0);
    uVar3 = (ulong)tVar9;
  }
  else {
    uVar3 = 1;
  }
  iVar6 = PDB::OpenEx(name,local_414,uVar3,page_size,&local_418,local_400,(PDB **)out_pdb);
  if (iVar6 != 0) {
    return '\x01';
  }
  if (((retry != '\0') && (local_418 == 0xb)) && (iVar6 = _unlink(name), iVar6 == 0)) {
    cVar1 = pdbmgr_open(state,name,out_pdb,'\0',page_size,mode);
    return cVar1;
  }
  if ((local_418 < 0) || (0x13 < local_418)) {
    iVar6 = 0x409;
  }
  else {
    iVar6 = *(int *)(&g_pdb_error_messages + local_418 * 4);
    if (1999 < iVar6) {
      diag_error((short)iVar6 + -2000,name);
      return '\0';
    }
    if (iVar6 == 0x3e9) {
      diag_fatal(1,".\\pdbmgr.cpp",0x71);
    }
  }
  diag_fatal(iVar6 + -1000,name);
}

