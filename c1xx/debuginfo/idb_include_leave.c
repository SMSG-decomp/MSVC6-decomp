int __thiscall idb_include_leave(c1xx_idb *idb,uint line)

{
  c1xx_pdb_iset *set;
  c1xx_pdb_map *map;
  uint *puVar1;
  c1_mre_file *pcVar2;
  c1_u32 cVar3;
  int iVar4;
  byte bVar5;
  c1_u16 cVar6;
  c1_u8 cVar7;
  c1_u8 cVar8;
  c1_u8 cVar9;
  int iVar10;
  uint uVar11;
  c1_idb_region *pcVar12;
  uint uVar13;
  c1_idb_include_state *pcVar14;
  uint *src;
  c1_idb_region *region;
  c1_idb_class_record *pcVar15;
  c1_idb_class_record *pcVar16;
  c1_idb_include_state cStack_48;
  uint *dst;
  uint *dst_2;
  
  if ((idb->include_stack).count == 0) {
    return 1;
  }
  if ((idb->state != 1) && (idb->state != 5)) {
    dst_2 = (uint *)&(idb->file).current.flags;
    *(byte *)dst_2 = (byte)*dst_2 | 8;
  }
  if ((idb->file).untracked == '\0') {
    iVar10 = idb_close_region_changed(idb,line);
    if (iVar10 == 0) {
      return 1;
    }
    if ((((idb->file).cursor == 1) && ((idb->file).changed == '\0')) &&
       (iVar10 = pdb_map_find(&idb->header_signatures,(idb->file).name_ni,&line), iVar10 != 0)) {
      (idb->file).changed =
           (idb->file).current.signature != (idb->header_signatures).range.data[line];
    }
    pcVar2 = (idb->file).tracker;
    if ((pcVar2 != (c1_mre_file *)0x0) &&
       (iVar10 = (*pcVar2->vtbl->note_end_include)(-((idb->file).changed != '\0') & 4), iVar10 == 0)
       ) {
      return 1;
    }
    uVar13 = (idb->file).cursor;
    if (uVar13 < (idb->file).regions.count) {
      uVar11 = (idb->file).regions.capacity;
      if (uVar11 < uVar13) {
        uVar11 = uVar11 * 3 >> 1;
        line = uVar13;
        if (uVar13 <= uVar11) {
          line = uVar11;
        }
        pcVar12 = __2_YAPAXI_Z(line << 4);
        if (pcVar12 == (c1_idb_region *)0x0) {
          return 1;
        }
        uVar11 = line;
        region = pcVar12;
        if (-1 < (int)(line - 1)) {
          do {
            gi_region_entry_init(region,0);
            uVar11 = uVar11 - 1;
            region = region + 1;
          } while (uVar11 != 0);
        }
        if ((idb->file).regions.data != (c1_idb_region *)0x0) {
          uVar11 = 0;
          if ((idb->file).regions.count != 0) {
            iVar10 = 0;
            do {
              src = (uint *)(((idb->file).regions.data)->pad0d + iVar10 + -0xd);
              dst = (uint *)(pcVar12->pad0d + iVar10 + -0xd);
              uVar11 = uVar11 + 1;
              iVar10 = iVar10 + 0x10;
              *dst = *src;
              dst[1] = src[1];
              dst[2] = src[2];
              dst[3] = src[3];
            } while (uVar11 < (idb->file).regions.count);
          }
          __3_YAXPAX_Z((idb->file).regions.data);
        }
        (idb->file).regions.data = pcVar12;
        (idb->file).regions.capacity = line;
      }
      (idb->file).regions.count = uVar13;
    }
    uVar13 = idb_save_header_regions(idb,&idb->file);
    if (uVar13 == 0) {
      return 0;
    }
    if ((idb->file).regions.count == 1) {
      uVar13 = (idb->file).name_ni;
      cVar3 = (idb->file).current.signature;
      map = &idb->header_signatures;
      iVar10 = pdb_map_find(map,uVar13,&line);
      uVar11 = line;
      if (iVar10 == 0) {
        bVar5 = (byte)line;
        if (line < (idb->header_signatures).deleted.count << 5) {
          puVar1 = (idb->header_signatures).deleted.data + (line >> 5);
          *puVar1 = *puVar1 & ~(1 << (bVar5 & 0x1f));
        }
        set = &(idb->header_signatures).present;
        iVar10 = iset_ensure_room(set,line);
        if (iVar10 != 0) {
          puVar1 = set->data + (uVar11 >> 5);
          *puVar1 = *puVar1 | 1 << (bVar5 & 0x1f);
        }
        (map->domain).data[line] = uVar13;
        (idb->header_signatures).range.data[line] = cVar3;
        map_grow(map);
      }
      else {
        (idb->header_signatures).range.data[line] = cVar3;
      }
    }
  }
  line = (uint)&idb->include_stack;
  pcVar14 = (idb->include_stack).data + ((idb->include_stack).count - 1);
  region_array_assign(&(idb->file).regions,&pcVar14->regions);
  uVar13 = line;
  (idb->file).cursor = pcVar14->cursor;
  (idb->file).current.signature = (pcVar14->current).signature;
  (idb->file).current.length = (pcVar14->current).length;
  cVar6 = (pcVar14->current).line_count;
  (idb->file).current.start_line = (pcVar14->current).start_line;
  (idb->file).current.line_count = cVar6;
  cVar7 = (pcVar14->current).pad0d[0];
  cVar8 = (pcVar14->current).pad0d[1];
  cVar9 = (pcVar14->current).pad0d[2];
  (idb->file).current.flags = (pcVar14->current).flags;
  (idb->file).current.pad0d[0] = cVar7;
  (idb->file).current.pad0d[1] = cVar8;
  (idb->file).current.pad0d[2] = cVar9;
  pcVar15 = (c1_idb_class_record *)(&pcVar14->current + 1);
  pcVar16 = &(idb->file).pending_class;
  for (iVar10 = 5; iVar10 != 0; iVar10 = iVar10 + -1) {
    pcVar16->class_ni = pcVar15->class_ni;
    pcVar15 = (c1_idb_class_record *)&pcVar15->first_region;
    pcVar16 = (c1_idb_class_record *)&pcVar16->first_region;
  }
  (idb->file).tracker = pcVar14->tracker;
  (idb->file).name_ni = pcVar14->name_ni;
  (idb->file).mtime = pcVar14->mtime;
  (idb->file).unk40 = pcVar14->unk40;
  (idb->file).changed = pcVar14->changed;
  (idb->file).untracked = pcVar14->untracked;
  iVar10 = *(int *)(line + 4);
  if (iVar10 != 0) {
    iVar4 = *(int *)line;
    pcVar14 = idb_include_state_init(&cStack_48,0);
    idb_include_state_assign((c1_idb_include_state *)(iVar4 + -0x48 + iVar10 * 0x48),pcVar14);
    pdb_array_destroy((c1xx_pdb_array *)&cStack_48);
    idb_include_stack_set_size((c1_idb_include_stack *)uVar13,*(int *)(uVar13 + 4) - 1);
  }
  return 1;
}

