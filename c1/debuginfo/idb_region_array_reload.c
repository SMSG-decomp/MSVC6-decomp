int __thiscall idb_region_array_reload(fe_idb_region_array *regions,c1_u32 **cursor)

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
  fe_idb_region *src_region;
  uint *puVar10;
  uint local_8;
  fe_idb_region *dst_region;
  
  uVar1 = **cursor;
  *cursor = *cursor + 1;
  if (regions->capacity < uVar1) {
    uVar6 = regions->capacity * 3 >> 1;
    local_8 = uVar1;
    if (uVar1 <= uVar6) {
      local_8 = uVar6;
    }
    pfVar7 = __2_YAPAXI_Z(local_8 << 4);
    if (pfVar7 == (fe_idb_region *)0x0) {
      return 0;
    }
    if (-1 < (int)(local_8 - 1)) {
      puVar8 = &pfVar7->start_line;
      uVar6 = local_8;
      do {
        ((fe_idb_region *)(puVar8 + -4))->signature = 0;
        *(int *)(puVar8 + -2) = -1;
        *puVar8 = 0;
        puVar8[1] = 0;
        *(uchar *)(puVar8 + 2) = '\x18';
        puVar8 = puVar8 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    if (regions->data != (fe_idb_region *)0x0) {
      uVar6 = 0;
      if (regions->count != 0) {
        iVar9 = 0;
        do {
          src_region = (fe_idb_region *)(regions->data->pad0d + iVar9 + -0xd);
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
        } while (uVar6 < regions->count);
      }
      __3_YAXPAX_Z(regions->data);
    }
    regions->data = pfVar7;
    regions->capacity = local_8;
  }
  regions->count = uVar1;
  puVar10 = *cursor;
  pfVar7 = regions->data;
  for (iVar9 = (uVar1 & 0xfffffff) << 2; iVar9 != 0; iVar9 = iVar9 + -1) {
    pfVar7->signature = *puVar10;
    puVar10 = puVar10 + 1;
    pfVar7 = (fe_idb_region *)&pfVar7->length;
  }
  for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
    *(char *)&pfVar7->signature = (char)*puVar10;
    puVar10 = (uint *)((int)puVar10 + 1);
    pfVar7 = (fe_idb_region *)((int)&pfVar7->signature + 1);
  }
  *cursor = *cursor + regions->count * 4;
  return 1;
}

