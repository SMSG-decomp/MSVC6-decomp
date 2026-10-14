int __thiscall idb_include_enter(c1xx_idb *idb,char *file,byte untracked)

{
  c1_u8 *pcVar1;
  c1_u32 *pcVar2;
  c1xx_pdb_map *pcVar3;
  uint *puVar4;
  c1xx_pdb_namemap_vtbl *pcVar5;
  c1_u32 cVar6;
  c1_u16 cVar7;
  c1_u8 cVar8;
  c1_u8 cVar9;
  c1_u8 cVar10;
  int iVar11;
  char *pcVar12;
  c1_idb_region *pcVar13;
  uint uVar14;
  c1_u32 *empty_src;
  c1_idb_class_record *pcVar15;
  c1_u32 *empty_src_2;
  c1_u32 *pcVar16;
  uint uStack_164;
  c1_u32 cStack_160;
  c1_idb_include_state fresh_state;
  c1_idb_region file_region;
  char acStack_104 [260];
  
  if ((idb->state != 1) && (idb->state != 5)) {
    pcVar1 = &(idb->file).current.flags;
    *pcVar1 = *pcVar1 | 8;
  }
  iVar11 = idb_include_stack_set_size(&idb->include_stack,(idb->include_stack).count + 1);
  if (iVar11 != 0) {
    idb_include_state_assign
              ((idb->include_stack).data + ((idb->include_stack).count - 1),&idb->file);
  }
  fresh_state.regions.data = (c1_idb_region *)0x0;
  fresh_state.regions.capacity = 0;
  fresh_state.regions.count = 0;
  gi_region_entry_init(&fresh_state.current,0);
  fresh_state.pending_class.class_ni = 0;
  fresh_state.pending_class.first_region = 0;
  fresh_state.pending_class.unk08 = 0;
  fresh_state.cursor = 0;
  fresh_state.pending_class.depth = 0;
  fresh_state.pending_class.change = 0;
  iVar11 = 5;
  empty_src = &g_idb_empty_class_record.class_ni;
  pcVar15 = &fresh_state.pending_class;
  for (; iVar11 != 0; iVar11 = iVar11 + -1) {
    pcVar15->class_ni = *empty_src;
    empty_src = empty_src + 1;
    pcVar15 = (c1_idb_class_record *)&pcVar15->first_region;
  }
  fresh_state.tracker = (c1_mre_file *)0x0;
  fresh_state.name_ni = 0;
  fresh_state.unk40 = 0;
  fresh_state.untracked = untracked;
  fresh_state.mtime = -1;
  fresh_state.changed = '\0';
  region_array_assign(&(idb->file).regions,&fresh_state.regions);
  (idb->file).cursor = fresh_state.cursor;
  (idb->file).current.signature = fresh_state.current.signature;
  (idb->file).current.length = fresh_state.current.length;
  (idb->file).current.start_line = fresh_state.current.start_line;
  (idb->file).current.line_count = fresh_state.current.line_count;
  (idb->file).name_ni = fresh_state.name_ni;
  (idb->file).current.flags = fresh_state.current.flags;
  (idb->file).current.pad0d[0] = fresh_state.current.pad0d[0];
  (idb->file).current.pad0d[1] = fresh_state.current.pad0d[1];
  (idb->file).current.pad0d[2] = fresh_state.current.pad0d[2];
  (idb->file).mtime = fresh_state.mtime;
  (idb->file).changed = fresh_state.changed;
  iVar11 = 5;
  pcVar15 = &fresh_state.pending_class;
  empty_src_2 = &(idb->file).pending_class.class_ni;
  for (; iVar11 != 0; iVar11 = iVar11 + -1) {
    *empty_src_2 = pcVar15->class_ni;
    pcVar15 = (c1_idb_class_record *)&pcVar15->first_region;
    empty_src_2 = empty_src_2 + 1;
  }
  (idb->file).untracked = fresh_state.untracked;
  (idb->file).tracker = fresh_state.tracker;
  (idb->file).unk40 = fresh_state.unk40;
  if (fresh_state.regions.data != (c1_idb_region *)0x0) {
    __3_YAXPAX_Z(fresh_state.regions.data);
  }
  if ((idb->file).untracked == '\0') {
    pcVar2 = &(idb->file).name_ni;
    pcVar5 = idb->name_map->vtbl;
    pcVar16 = pcVar2;
    pcVar12 = file_make_canonical_path(acStack_104,file,0x104);
    iVar11 = (*pcVar5->get_ni)(pcVar12,pcVar16);
    if (iVar11 == 0) {
      return 0;
    }
    iVar11 = pdb_map_find(&idb->old_file_times,*pcVar2,&cStack_160);
    if (iVar11 == 0) {
      iVar11 = stat(file,&fresh_state);
      if (iVar11 != 0) {
        return 0;
      }
    }
    else {
      fresh_state.current._12_4_ = (idb->old_file_times).range.data[cStack_160];
    }
    uVar14 = *pcVar2;
    (idb->file).mtime = fresh_state.current._12_4_;
    pcVar3 = &idb->file_times;
    cStack_160 = fresh_state.current._12_4_;
    iVar11 = pdb_map_find(pcVar3,uVar14,&uStack_164);
    if (iVar11 == 0) {
      if (uStack_164 < (idb->file_times).deleted.count << 5) {
        puVar4 = (idb->file_times).deleted.data + (uStack_164 >> 5);
        *puVar4 = *puVar4 & ~(1 << ((byte)uStack_164 & 0x1f));
      }
      iset_add(&(idb->file_times).present,uStack_164);
      (pcVar3->domain).data[uStack_164] = uVar14;
      (idb->file_times).range.data[uStack_164] = cStack_160;
      map_grow_2(pcVar3);
    }
    else {
      (idb->file_times).range.data[uStack_164] = cStack_160;
    }
    pcVar3 = &idb->header_times;
    iVar11 = pdb_map_find(pcVar3,(idb->file).name_ni,&cStack_160);
    if ((iVar11 == 0) || ((idb->header_times).range.data[cStack_160] != (idb->file).mtime)) {
      uVar14 = idb_load_header_regions(idb,&idb->file);
      if (uVar14 == 0) {
        return 0;
      }
      uVar14 = (idb->file).name_ni;
      cVar6 = (idb->file).mtime;
      iVar11 = pdb_map_find(pcVar3,uVar14,&uStack_164);
      if (iVar11 == 0) {
        iset_remove(&(idb->header_times).deleted,uStack_164);
        iset_add(&(idb->header_times).present,uStack_164);
        (pcVar3->domain).data[uStack_164] = uVar14;
        (idb->header_times).range.data[uStack_164] = cVar6;
        map_grow_2(pcVar3);
      }
      else {
        (idb->header_times).range.data[uStack_164] = cVar6;
      }
    }
    else {
      (idb->file).untracked = '\x01';
    }
  }
  pcVar13 = gi_region_entry_set(&file_region,1,0,-1,1,0);
  (idb->file).current.signature = pcVar13->signature;
  (idb->file).current.length = pcVar13->length;
  cVar7 = pcVar13->line_count;
  (idb->file).current.start_line = pcVar13->start_line;
  (idb->file).current.line_count = cVar7;
  cVar8 = pcVar13->pad0d[0];
  cVar9 = pcVar13->pad0d[1];
  cVar10 = pcVar13->pad0d[2];
  (idb->file).current.flags = pcVar13->flags;
  (idb->file).current.pad0d[0] = cVar8;
  (idb->file).current.pad0d[1] = cVar9;
  (idb->file).current.pad0d[2] = cVar10;
  return 1;
}

