int __fastcall idb_invalidate(c1_idb_state *idb)

{
  uint uVar1;
  ushort uVar2;
  uchar uVar3;
  uchar uVar4;
  uchar uVar5;
  uint uVar6;
  fe_idb_region *pfVar7;
  ushort *puVar8;
  int iVar9;
  uint uVar10;
  fe_idb_region *src_region;
  uint uStack_8;
  fe_idb_region *dst_region;
  
  idb->invalidated = 1;
  if (idb->state == 1) {
    idb->state = 5;
  }
  uVar1 = (idb->file).cursor;
  uVar6 = (idb->file).regions.capacity;
  if (uVar6 < uVar1) {
    uVar6 = uVar6 * 3 >> 1;
    uStack_8 = uVar1;
    if (uVar1 <= uVar6) {
      uStack_8 = uVar6;
    }
    pfVar7 = __2_YAPAXI_Z(uStack_8 << 4);
    uVar6 = 0;
    if (pfVar7 == (fe_idb_region *)0x0) {
      return 0;
    }
    if (-1 < (int)(uStack_8 - 1)) {
      puVar8 = &pfVar7->start_line;
      uVar10 = uStack_8;
      do {
        ((fe_idb_region *)(puVar8 + -4))->signature = 0;
        *(int *)(puVar8 + -2) = -1;
        *puVar8 = 0;
        puVar8[1] = 0;
        *(uchar *)(puVar8 + 2) = '\x18';
        puVar8 = puVar8 + 8;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
    }
    if ((idb->file).regions.data != (fe_idb_region *)0x0) {
      if ((idb->file).regions.count != 0) {
        iVar9 = 0;
        do {
          src_region = (fe_idb_region *)(((idb->file).regions.data)->pad0d + iVar9 + -0xd);
          dst_region = (fe_idb_region *)(pfVar7->pad0d + iVar9 + -0xd);
          uVar6 = uVar6 + 1;
          iVar9 = iVar9 + 0x10;
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
        } while (uVar6 < (idb->file).regions.count);
      }
      __3_YAXPAX_Z((idb->file).regions.data);
    }
    (idb->file).regions.data = pfVar7;
    (idb->file).regions.capacity = uStack_8;
  }
  (idb->file).regions.count = uVar1;
  return 1;
}

