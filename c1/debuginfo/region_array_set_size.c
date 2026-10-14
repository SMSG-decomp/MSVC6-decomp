int __thiscall region_array_set_size(fe_idb_region_array *array,uint n)

{
  ushort uVar1;
  uchar uVar2;
  uchar uVar3;
  uchar uVar4;
  uint uVar5;
  fe_idb_region *pfVar6;
  ushort *puVar7;
  int iVar8;
  uint uVar9;
  fe_idb_region *src_region;
  uint local_4;
  fe_idb_region *dst_region;
  
  if (array->capacity < n) {
    local_4 = n;
    uVar5 = array->capacity * 3 >> 1;
    if (n <= uVar5) {
      local_4 = uVar5;
    }
    pfVar6 = __2_YAPAXI_Z(local_4 << 4);
    uVar5 = 0;
    if (pfVar6 == (fe_idb_region *)0x0) {
      return 0;
    }
    if (-1 < (int)(local_4 - 1)) {
      puVar7 = &pfVar6->start_line;
      uVar9 = local_4;
      do {
        ((fe_idb_region *)(puVar7 + -4))->signature = 0;
        *(int *)(puVar7 + -2) = -1;
        *puVar7 = 0;
        puVar7[1] = 0;
        *(uchar *)(puVar7 + 2) = '\x18';
        puVar7 = puVar7 + 8;
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
    }
    if (array->data != (fe_idb_region *)0x0) {
      if (array->count != 0) {
        iVar8 = 0;
        do {
          src_region = (fe_idb_region *)(array->data->pad0d + iVar8 + -0xd);
          dst_region = (fe_idb_region *)(pfVar6->pad0d + iVar8 + -0xd);
          uVar5 = uVar5 + 1;
          iVar8 = iVar8 + 0x10;
          dst_region->signature = src_region->signature;
          dst_region->length = src_region->length;
          uVar1 = src_region->line_count;
          dst_region->start_line = src_region->start_line;
          dst_region->line_count = uVar1;
          uVar2 = src_region->pad0d[0];
          uVar3 = src_region->pad0d[1];
          uVar4 = src_region->pad0d[2];
          dst_region->flags = src_region->flags;
          dst_region->pad0d[0] = uVar2;
          dst_region->pad0d[1] = uVar3;
          dst_region->pad0d[2] = uVar4;
        } while (uVar5 < array->count);
      }
      __3_YAXPAX_Z(array->data);
    }
    array->data = pfVar6;
    array->capacity = local_4;
  }
  array->count = n;
  return 1;
}

