int __thiscall gi_region_record_begin(c1_idb_state *idb,byte kind)

{
  uint uVar1;
  ushort uVar2;
  uchar uVar3;
  uchar uVar4;
  uchar uVar5;
  byte bVar6;
  fe_idb_region *pfVar7;
  int iVar8;
  fe_idb_region *src_region;
  uint uVar9;
  uint uVar10;
  fe_idb_region *region_00;
  uint uStack_18;
  fe_idb_region region;
  fe_idb_region *dst_region;
  
  uVar9 = 1;
  if (idb->state == 1) {
    (*idb->tracker->vtbl->reset)(idb->tracker);
  }
  else {
    region.signature = 0;
    region.length = -1;
    region.start_line = 0;
    region.line_count = 0;
    region._12_4_ =
         CONCAT31(region.pad0d,region.flags ^ (region.flags ^ kind) & 7) & 0xffffff1f | 0x18;
    bVar6 = (*idb->tracker->vtbl->take)(idb->tracker,&region.signature,&region.length);
    uVar9 = (uint)bVar6;
    if (uVar9 == 0) {
      return 0;
    }
    uVar10 = (idb->file).cursor;
    uVar1 = (idb->file).regions.count;
    if (uVar10 == uVar1) {
      uVar9 = (idb->file).regions.capacity;
      uVar10 = uVar1 + 1;
      if (uVar9 < uVar10) {
        uVar9 = uVar9 * 3 >> 1;
        _kind = uVar10;
        if (uVar10 <= uVar9) {
          _kind = uVar9;
        }
        pfVar7 = __2_YAPAXI_Z(_kind << 4);
        if (pfVar7 == (fe_idb_region *)0x0) {
          return 0;
        }
        if (-1 < (int)(_kind - 1)) {
          uStack_18 = _kind;
          region_00 = pfVar7;
          do {
            gi_region_entry_init(region_00,0);
            region_00 = region_00 + 1;
            uStack_18 = uStack_18 - 1;
          } while (uStack_18 != 0);
        }
        if ((idb->file).regions.data != (fe_idb_region *)0x0) {
          uVar9 = 0;
          if ((idb->file).regions.count != 0) {
            iVar8 = 0;
            do {
              src_region = (fe_idb_region *)(((idb->file).regions.data)->pad0d + iVar8 + -0xd);
              dst_region = (fe_idb_region *)(pfVar7->pad0d + iVar8 + -0xd);
              uVar9 = uVar9 + 1;
              iVar8 = iVar8 + 0x10;
              dst_region->signature = src_region->signature;
              dst_region->length = src_region->length;
              uVar2 = src_region->line_count;
              dst_region->start_line = src_region->start_line;
              dst_region->line_count = uVar2;
              uVar3 = src_region->pad0d[0];
              uVar4 = src_region->pad0d[1];
              uVar5 = src_region->pad0d[2];
              dst_region->flags = src_region->flags;
              dst_region->pad0d[0] = uVar3;
              dst_region->pad0d[1] = uVar4;
              dst_region->pad0d[2] = uVar5;
            } while (uVar9 < (idb->file).regions.count);
          }
          __3_YAXPAX_Z((idb->file).regions.data);
        }
        (idb->file).regions.data = pfVar7;
        (idb->file).regions.capacity = _kind;
      }
      pfVar7 = (idb->file).regions.data;
      (idb->file).regions.count = uVar10;
      uVar9 = 1;
      pfVar7[uVar1].signature = region.signature;
      pfVar7[uVar1].length = region.length;
      pfVar7[uVar1].start_line = region.start_line;
      pfVar7[uVar1].line_count = region.line_count;
      pfVar7 = pfVar7 + uVar1;
      pfVar7->flags = region.flags;
      pfVar7->pad0d[0] = region.pad0d[0];
      pfVar7->pad0d[1] = region.pad0d[1];
      pfVar7->pad0d[2] = region.pad0d[2];
    }
    else {
      pfVar7 = (idb->file).regions.data + uVar10;
      pfVar7->signature = region.signature;
      pfVar7->length = region.length;
      pfVar7->start_line = region.start_line;
      pfVar7->line_count = region.line_count;
      pfVar7->flags = region.flags;
      pfVar7->pad0d[0] = region.pad0d[0];
      pfVar7->pad0d[1] = region.pad0d[1];
      pfVar7->pad0d[2] = region.pad0d[2];
    }
  }
  (*g_il_emitter->vtbl->region_boundary)();
  (idb->file).cursor = (idb->file).cursor + 1;
  return uVar9;
}

