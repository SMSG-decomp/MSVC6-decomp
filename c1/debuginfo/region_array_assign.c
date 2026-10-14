fe_idb_region_array * __thiscall
region_array_assign(fe_idb_region_array *array,fe_idb_region_array *from)

{
  ushort uVar1;
  uchar uVar2;
  uchar uVar3;
  uchar uVar4;
  fe_idb_region *pfVar5;
  int iVar6;
  ushort *puVar7;
  uint uVar8;
  uint uVar9;
  fe_idb_region *src_region;
  fe_idb_region *dst_region;
  
  if (from != array) {
    if (array->capacity < from->count) {
      if (array->data != (fe_idb_region *)0x0) {
        __3_YAXPAX_Z(array->data);
      }
      uVar9 = from->count;
      array->capacity = uVar9;
      pfVar5 = __2_YAPAXI_Z(uVar9 << 4);
      if (pfVar5 == (fe_idb_region *)0x0) {
        pfVar5 = (fe_idb_region *)0x0;
      }
      else if (-1 < (int)(uVar9 - 1)) {
        puVar7 = &pfVar5->start_line;
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
      array->data = pfVar5;
      if (pfVar5 == (fe_idb_region *)0x0) {
        array->capacity = 0;
        array->count = 0;
        return array;
      }
    }
    uVar9 = from->count;
    uVar8 = 0;
    array->count = uVar9;
    if (uVar9 != 0) {
      iVar6 = 0;
      do {
        src_region = (fe_idb_region *)(from->data->pad0d + iVar6 + -0xd);
        dst_region = (fe_idb_region *)(array->data->pad0d + iVar6 + -0xd);
        uVar8 = uVar8 + 1;
        iVar6 = iVar6 + 0x10;
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
      } while (uVar8 < array->count);
    }
  }
  return array;
}

