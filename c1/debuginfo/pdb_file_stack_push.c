char __thiscall pdb_file_stack_push(c1_pdb_source_file **stack,char *name,int fd,c1_u8 by_handle)

{
  char cVar1;
  MRECmp *this;
  MRECmp_vtbl *pMVar2;
  c1_pdb_source_file *pcVar3;
  uchar *puVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uchar *puVar9;
  char *pcVar10;
  uchar *puVar11;
  uint file_id;
  c1_pdb_source_file **local_4;
  
  file_id = 0;
  local_4 = stack;
  if (*stack == (c1_pdb_source_file *)0x0) {
    iVar6 = (*g_pdb_gi->mre_driver->vtbl->FOpenCompiland)
                      (g_pdb_gi->mre_driver,(MREFile **)&file_id,name,g_object_file_name);
  }
  else {
    if (by_handle == '\0') goto LAB_106228ab;
    this = g_pdb_gi->mre_driver;
    pMVar2 = this->vtbl;
    pvVar5 = (void *)_get_osfhandle(fd);
    iVar6 = (*pMVar2->FPushFile)(this,(MREFile **)&file_id,name,pvVar5);
  }
  if (iVar6 == 0) {
    diag_error(0x1d7,&g_pdb_file_name);
    return '\0';
  }
LAB_106228ab:
  puVar4 = g_arenas[1].cur;
  g_arenas[1].cur = g_arenas[1].cur + 0x10;
  if (g_arenas[1].end < g_arenas[1].cur) {
    arena_grow(g_arenas + 1);
  }
  if (puVar4 == (uchar *)0x0) {
    *stack = (c1_pdb_source_file *)0x0;
    return '\x01';
  }
  pcVar3 = *stack;
  *(uint *)(puVar4 + 4) = file_id;
  puVar4[0] = '\0';
  puVar4[1] = '\0';
  puVar4[2] = '\0';
  puVar4[3] = '\0';
  *(c1_pdb_source_file **)(puVar4 + 8) = pcVar3;
  puVar4[0xc] = by_handle;
  puVar11 = g_arenas[1].cur;
  if (pcVar3 != (c1_pdb_source_file *)0x0) {
    *(char **)puVar4 = name;
    *stack = (c1_pdb_source_file *)puVar4;
    return '\x01';
  }
  uVar7 = 0xffffffff;
  pcVar10 = name;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar1 != '\0');
  g_arenas[1].cur = g_arenas[1].cur + (~uVar7 + 3 & 0xfffffffc);
  if (g_arenas[1].end < g_arenas[1].cur) {
    arena_grow(g_arenas + 1);
  }
  uVar7 = 0xffffffff;
  *(uchar **)puVar4 = puVar11;
  do {
    pcVar10 = name;
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    pcVar10 = name + 1;
    cVar1 = *name;
    name = pcVar10;
  } while (cVar1 != '\0');
  uVar7 = ~uVar7;
  puVar9 = (uchar *)(pcVar10 + -uVar7);
  for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)puVar11 = *(undefined4 *)puVar9;
    puVar9 = puVar9 + 4;
    puVar11 = puVar11 + 4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *puVar11 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar11 = puVar11 + 1;
  }
  *local_4 = (c1_pdb_source_file *)puVar4;
  return '\x01';
}

