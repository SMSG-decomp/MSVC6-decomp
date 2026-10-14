char __thiscall pdb_source_file_push(c1_mre_tracker *tracker,char *name,int fd,byte tracked)

{
  char cVar1;
  c1_mre_compiler_vtbl *pcVar2;
  c1_source_file_record *pcVar3;
  intptr_t iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  c1_u32 *name_src;
  char *pcVar8;
  c1_u32 *pcVar9;
  c1_mre_file *file;
  c1_mre_tracker *local_4;
  c1_u8 *rec;
  
  file = (c1_mre_file *)0x0;
  local_4 = tracker;
  if (tracker->current == (c1_source_file_record *)0x0) {
    iVar5 = (*g_pdb_gi->mre_compiler->vtbl->open_compiland)(&file,name,g_object_file_name);
  }
  else {
    if (tracked == 0) goto LAB_10432fdc;
    pcVar2 = g_pdb_gi->mre_compiler->vtbl;
    iVar4 = _get_osfhandle(fd);
    iVar5 = (*pcVar2->push_file)(&file,name,iVar4);
  }
  if (iVar5 == 0) {
    diag_error(0x1d7,g_pdb_file_name);
    return '\0';
  }
LAB_10432fdc:
  iVar5 = 0;
  if (((tracker->current == (c1_source_file_record *)0x0) ||
      (iVar5 = tracker->current->minrebuild_off, iVar5 == 0)) && (file != (c1_mre_file *)0x0)) {
    iVar5 = (*file->vtbl->query_minrebuild_off)();
  }
  rec = g_arenas[1].cur;
  g_arenas[1].cur = g_arenas[1].cur + 0x14;
  if (g_arenas[1].end < g_arenas[1].cur) {
    arena_grow(g_arenas + 1);
  }
  if (rec == (c1_u8 *)0x0) {
    tracker->current = (c1_source_file_record *)0x0;
    return '\x01';
  }
  pcVar3 = tracker->current;
  rec[0] = '\0';
  rec[1] = '\0';
  rec[2] = '\0';
  rec[3] = '\0';
  *(c1_mre_file **)(rec + 4) = file;
  *(c1_source_file_record **)(rec + 8) = pcVar3;
  rec[0xc] = tracked;
  *(int *)(rec + 0x10) = iVar5;
  pcVar9 = (c1_u32 *)g_arenas[1].cur;
  if (pcVar3 != (c1_source_file_record *)0x0) {
    *(char **)rec = name;
    tracker->current = (c1_source_file_record *)rec;
    return '\x01';
  }
  uVar6 = 0xffffffff;
  pcVar8 = name;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  g_arenas[1].cur = g_arenas[1].cur + (~uVar6 + 3 & 0xfffffffc);
  if (g_arenas[1].end < g_arenas[1].cur) {
    arena_grow(g_arenas + 1);
  }
  uVar6 = 0xffffffff;
  *(c1_u32 **)rec = pcVar9;
  do {
    pcVar8 = name;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar8 = name + 1;
    cVar1 = *name;
    name = pcVar8;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  name_src = (c1_u32 *)(pcVar8 + -uVar6);
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pcVar9 = *name_src;
    name_src = name_src + 1;
    pcVar9 = pcVar9 + 1;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(c1_u8 *)pcVar9 = (c1_u8)*name_src;
    name_src = (c1_u32 *)((int)name_src + 1);
    pcVar9 = (c1_u32 *)((int)pcVar9 + 1);
  }
  pdb_source_file_register_name((c1_source_file_record *)rec);
  local_4->current = (c1_source_file_record *)rec;
  return '\x01';
}

