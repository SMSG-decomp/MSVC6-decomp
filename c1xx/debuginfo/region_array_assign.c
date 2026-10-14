c1_idb_region_array * __thiscall
region_array_assign(c1_idb_region_array *regions,c1_idb_region_array *src)

{
  c1_idb_region *pcVar1;
  int iVar2;
  c1_u16 *pcVar3;
  uint uVar4;
  c1_u32 cVar5;
  c1_u32 *src_entry;
  c1_u32 *dst_entry;
  
  if (src != regions) {
    if (regions->capacity < src->count) {
      if (regions->data != (c1_idb_region *)0x0) {
        __3_YAXPAX_Z(regions->data);
      }
      cVar5 = src->count;
      regions->capacity = cVar5;
      pcVar1 = __2_YAPAXI_Z(cVar5 << 4);
      if (pcVar1 == (c1_idb_region *)0x0) {
        pcVar1 = (c1_idb_region *)0x0;
      }
      else if (-1 < (int)(cVar5 - 1)) {
        pcVar3 = &pcVar1->start_line;
        do {
          ((c1_idb_region *)(pcVar3 + -4))->signature = 0;
          *(int *)(pcVar3 + -2) = -1;
          *pcVar3 = 0;
          pcVar3[1] = 0;
          *(c1_u8 *)(pcVar3 + 2) = '\x18';
          pcVar3 = pcVar3 + 8;
          cVar5 = cVar5 - 1;
        } while (cVar5 != 0);
      }
      regions->data = pcVar1;
      if (pcVar1 == (c1_idb_region *)0x0) {
        regions->capacity = 0;
        regions->count = 0;
        return regions;
      }
    }
    cVar5 = src->count;
    uVar4 = 0;
    regions->count = cVar5;
    if (cVar5 != 0) {
      iVar2 = 0;
      do {
        src_entry = (c1_u32 *)(src->data->pad0d + iVar2 + -0xd);
        dst_entry = (c1_u32 *)(regions->data->pad0d + iVar2 + -0xd);
        uVar4 = uVar4 + 1;
        iVar2 = iVar2 + 0x10;
        *dst_entry = *src_entry;
        dst_entry[1] = src_entry[1];
        dst_entry[2] = src_entry[2];
        dst_entry[3] = src_entry[3];
      } while (uVar4 < regions->count);
    }
  }
  return regions;
}

