int __thiscall idb_include_enter(c1_idb_state *idb,char *file,byte registered)

{
  ISet *set;
  uchar *puVar1;
  uint *puVar2;
  Map_DWORD_DWORD *map;
  NameMap_vtbl *pNVar3;
  byte bVar4;
  ushort uVar5;
  uchar uVar6;
  uchar uVar7;
  uchar uVar8;
  uint uVar9;
  ulong uVar10;
  int iVar11;
  char *sz;
  fe_idb_region *pfVar12;
  fe_idb_class_record *pfVar13;
  MREFile **ppMVar14;
  uint *pni;
  uint uStack_168;
  fe_idb_region_array fStack_164;
  uint uStack_158;
  uint uStack_154;
  int iStack_150;
  uint current_lines;
  ulong uStack_148;
  MREFile *apMStack_144 [6];
  uint uStack_12c;
  int iStack_128;
  uint uStack_124;
  uchar uStack_120;
  byte bStack_11f;
  ulong uStack_11c;
  uint uStack_118;
  fe_idb_region fStack_114;
  char acStack_104 [260];
  
  if ((idb->state != 1) && (idb->state != 5)) {
    puVar1 = &(idb->file).current.flags;
    *puVar1 = *puVar1 | 8;
  }
  iVar11 = idb_include_stack_set_size(&idb->include_stack,(idb->include_stack).count + 1);
  if (iVar11 != 0) {
    idb_include_state_assign
              ((idb->include_stack).data + ((idb->include_stack).count - 1),&idb->file);
  }
  fStack_164.data = (fe_idb_region *)0x0;
  fStack_164.capacity = 0;
  uStack_148 = CONCAT31(uStack_148._1_3_,0x18);
  apMStack_144[0] = (MREFile *)0x0;
  fStack_164.count = 0;
  apMStack_144[1] = (MREFile *)0x0;
  uStack_154 = 0;
  apMStack_144[2] = (MREFile *)0x0;
  iStack_150 = -1;
  apMStack_144[3] = (MREFile *)0x0;
  current_lines = 0;
  apMStack_144[4] = (MREFile *)0x0;
  uStack_158 = 0;
  pfVar13 = &g_idb_empty_class_record;
  ppMVar14 = apMStack_144;
  for (iVar11 = 5; iVar11 != 0; iVar11 = iVar11 + -1) {
    *ppMVar14 = (MREFile *)pfVar13->class_ni;
    pfVar13 = (fe_idb_class_record *)&pfVar13->first_region;
    ppMVar14 = ppMVar14 + 1;
  }
  apMStack_144[5] = (MREFile *)0x0;
  uStack_12c = 0;
  iStack_128 = -1;
  uStack_124 = 0;
  bStack_11f = registered;
  uStack_120 = '\0';
  region_array_assign(&(idb->file).regions,&fStack_164);
  (idb->file).cursor = uStack_158;
  (idb->file).current.signature = uStack_154;
  (idb->file).current.length = iStack_150;
  (idb->file).current.start_line = (undefined2)current_lines;
  (idb->file).current.line_count = current_lines._2_2_;
  (idb->file).name_ni = uStack_12c;
  (idb->file).current.flags = (undefined1)uStack_148;
  (idb->file).current.pad0d[0] = uStack_148._1_1_;
  (idb->file).current.pad0d[1] = uStack_148._2_1_;
  (idb->file).current.pad0d[2] = uStack_148._3_1_;
  (idb->file).mtime = iStack_128;
  (idb->file).changed = uStack_120;
  ppMVar14 = apMStack_144;
  pfVar13 = &(idb->file).pending_class;
  for (iVar11 = 5; iVar11 != 0; iVar11 = iVar11 + -1) {
    pfVar13->class_ni = (uint)*ppMVar14;
    ppMVar14 = ppMVar14 + 1;
    pfVar13 = (fe_idb_class_record *)&pfVar13->first_region;
  }
  (idb->file).untracked = bStack_11f;
  (idb->file).tracker = apMStack_144[5];
  (idb->file).unk40 = uStack_124;
  if (fStack_164.data != (fe_idb_region *)0x0) {
    __3_YAXPAX_Z(fStack_164.data);
  }
  if ((idb->file).untracked == '\0') {
    puVar2 = &(idb->file).name_ni;
    pNVar3 = idb->name_map->vtbl;
    pni = puVar2;
    sz = (char *)file_make_canonical_path(acStack_104,file,0x104);
    iVar11 = (*pNVar3->getNi)(idb->name_map,sz,pni);
    if (iVar11 == 0) {
      return 0;
    }
    iVar11 = pdb_map_find(&idb->file_times,*puVar2,&uStack_168);
    if (iVar11 == 0) {
      iVar11 = stat(file,&fStack_164);
      if (iVar11 != 0) {
        return 0;
      }
    }
    else {
      uStack_148 = (idb->file_times).rgr.rgt[uStack_168];
    }
    uVar10 = uStack_148;
    (idb->file).mtime = uStack_148;
    uStack_118 = *puVar2;
    map = &idb->unit_files;
    uStack_11c = uStack_148;
    iVar11 = pdb_map_find(map,uStack_118,&uStack_168);
    uVar9 = uStack_168;
    if (iVar11 == 0) {
      bVar4 = (byte)uStack_168;
      if (uStack_168 < (idb->unit_files).isetDeleted.rgw.itMac << 5) {
        puVar2 = (idb->unit_files).isetDeleted.rgw.rgt + (uStack_168 >> 5);
        *puVar2 = *puVar2 & ~(1 << (bVar4 & 0x1f));
      }
      set = &(idb->unit_files).isetPresent;
      iVar11 = iset_ensure_room(set,uStack_168);
      if (iVar11 != 0) {
        puVar2 = (set->rgw).rgt + (uVar9 >> 5);
        *puVar2 = *puVar2 | 1 << (bVar4 & 0x1f);
      }
      (map->rgd).rgt[uStack_168] = uStack_118;
      (idb->unit_files).rgr.rgt[uStack_168] = uStack_11c;
      map_grow_2(map);
    }
    else {
      (idb->unit_files).rgr.rgt[uStack_168] = uVar10;
    }
    (idb->file).untracked = '\x01';
  }
  pfVar12 = gi_region_entry_set(&fStack_114,1,0,-1,1,0);
  (idb->file).current.signature = pfVar12->signature;
  (idb->file).current.length = pfVar12->length;
  uVar5 = pfVar12->line_count;
  (idb->file).current.start_line = pfVar12->start_line;
  (idb->file).current.line_count = uVar5;
  uVar6 = pfVar12->pad0d[0];
  uVar7 = pfVar12->pad0d[1];
  uVar8 = pfVar12->pad0d[2];
  (idb->file).current.flags = pfVar12->flags;
  (idb->file).current.pad0d[0] = uVar6;
  (idb->file).current.pad0d[1] = uVar7;
  (idb->file).current.pad0d[2] = uVar8;
  return 1;
}

