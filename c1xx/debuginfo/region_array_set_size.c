int __thiscall region_array_set_size(c1_idb_region_array *regions,uint count)

{
  uint uVar1;
  c1_idb_region *pcVar2;
  c1_u16 *pcVar3;
  int iVar4;
  uint uVar5;
  uint *src;
  uint local_4;
  uint *dst;
  
  if (regions->capacity < count) {
    local_4 = count;
    uVar1 = regions->capacity * 3 >> 1;
    if (count <= uVar1) {
      local_4 = uVar1;
    }
    pcVar2 = __2_YAPAXI_Z(local_4 << 4);
    uVar1 = 0;
    if (pcVar2 == (c1_idb_region *)0x0) {
      return 0;
    }
    if (-1 < (int)(local_4 - 1)) {
      pcVar3 = &pcVar2->start_line;
      uVar5 = local_4;
      do {
        ((c1_idb_region *)(pcVar3 + -4))->signature = 0;
        *(int *)(pcVar3 + -2) = -1;
        *pcVar3 = 0;
        pcVar3[1] = 0;
        *(c1_u8 *)(pcVar3 + 2) = '\x18';
        pcVar3 = pcVar3 + 8;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    if (regions->data != (c1_idb_region *)0x0) {
      if (regions->count != 0) {
        iVar4 = 0;
        do {
          src = (uint *)(regions->data->pad0d + iVar4 + -0xd);
          dst = (uint *)(pcVar2->pad0d + iVar4 + -0xd);
          uVar1 = uVar1 + 1;
          iVar4 = iVar4 + 0x10;
          *dst = *src;
          dst[1] = src[1];
          dst[2] = src[2];
          dst[3] = src[3];
        } while (uVar1 < regions->count);
      }
      __3_YAXPAX_Z(regions->data);
    }
    regions->data = pcVar2;
    regions->capacity = local_4;
  }
  regions->count = count;
  return 1;
}

