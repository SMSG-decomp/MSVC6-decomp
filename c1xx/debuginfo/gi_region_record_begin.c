int __thiscall gi_region_record_begin(c1xx_idb *idb,byte kind)

{
  c1_u32 cVar1;
  c1_u32 cVar2;
  c1_idb_region *pcVar3;
  int iVar4;
  uint *src;
  uint uVar5;
  uint uVar6;
  c1_idb_region *region;
  uint uStack_18;
  c1_idb_region new_region;
  c1_u32 *dst;
  
  uVar5 = 1;
  if (idb->state == 1) {
    (*idb->source_tracker->vtbl->reset)();
  }
  else {
    new_region.signature = 0;
    new_region.length = -1;
    new_region.start_line = 0;
    new_region.line_count = 0;
    new_region._12_4_ =
         CONCAT31(new_region.pad0d,new_region.flags ^ (new_region.flags ^ kind) & 7) & 0xffffff1f |
         0x18;
    uVar5 = (*idb->source_tracker->vtbl->take)(&new_region,&new_region.length);
    uVar5 = uVar5 & 0xff;
    if (uVar5 == 0) {
      return 0;
    }
    cVar1 = (idb->file).cursor;
    cVar2 = (idb->file).regions.count;
    if (cVar1 == cVar2) {
      uVar5 = (idb->file).regions.capacity;
      uVar6 = cVar2 + 1;
      if (uVar5 < uVar6) {
        uVar5 = uVar5 * 3 >> 1;
        _kind = uVar6;
        if (uVar6 <= uVar5) {
          _kind = uVar5;
        }
        pcVar3 = __2_YAPAXI_Z(_kind << 4);
        if (pcVar3 == (c1_idb_region *)0x0) {
          return 0;
        }
        if (-1 < (int)(_kind - 1)) {
          uStack_18 = _kind;
          region = pcVar3;
          do {
            gi_region_entry_init(region,0);
            region = region + 1;
            uStack_18 = uStack_18 - 1;
          } while (uStack_18 != 0);
        }
        if ((idb->file).regions.data != (c1_idb_region *)0x0) {
          uVar5 = 0;
          if ((idb->file).regions.count != 0) {
            iVar4 = 0;
            do {
              src = (uint *)(((idb->file).regions.data)->pad0d + iVar4 + -0xd);
              dst = (c1_u32 *)(pcVar3->pad0d + iVar4 + -0xd);
              uVar5 = uVar5 + 1;
              iVar4 = iVar4 + 0x10;
              *dst = *src;
              dst[1] = src[1];
              dst[2] = src[2];
              dst[3] = src[3];
            } while (uVar5 < (idb->file).regions.count);
          }
          __3_YAXPAX_Z((idb->file).regions.data);
        }
        (idb->file).regions.data = pcVar3;
        (idb->file).regions.capacity = _kind;
      }
      pcVar3 = (idb->file).regions.data;
      (idb->file).regions.count = uVar6;
      uVar5 = 1;
      pcVar3[cVar2].signature = new_region.signature;
      pcVar3[cVar2].length = new_region.length;
      pcVar3[cVar2].start_line = new_region.start_line;
      pcVar3[cVar2].line_count = new_region.line_count;
      pcVar3 = pcVar3 + cVar2;
      pcVar3->flags = new_region.flags;
      pcVar3->pad0d[0] = new_region.pad0d[0];
      pcVar3->pad0d[1] = new_region.pad0d[1];
      pcVar3->pad0d[2] = new_region.pad0d[2];
    }
    else {
      pcVar3 = (idb->file).regions.data + cVar1;
      pcVar3->signature = new_region.signature;
      pcVar3->length = new_region.length;
      pcVar3->start_line = new_region.start_line;
      pcVar3->line_count = new_region.line_count;
      pcVar3->flags = new_region.flags;
      pcVar3->pad0d[0] = new_region.pad0d[0];
      pcVar3->pad0d[1] = new_region.pad0d[1];
      pcVar3->pad0d[2] = new_region.pad0d[2];
    }
  }
  (*g_il_emitter->vtbl->region_boundary)();
  (idb->file).cursor = (idb->file).cursor + 1;
  return uVar5;
}

