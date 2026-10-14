int __thiscall idb_region_array_reload(c1_idb_region_array *regions,c1_u32 **cursor)

{
  uint uVar1;
  uint uVar2;
  c1_idb_region *entries;
  c1_u16 *pcVar3;
  int iVar4;
  c1_u32 *old_entry;
  c1_u32 *src;
  c1_idb_region *entries_2;
  uint local_8;
  c1_u32 *new_entry;
  
  uVar1 = **cursor;
  *cursor = *cursor + 1;
  if (regions->capacity < uVar1) {
    uVar2 = regions->capacity * 3 >> 1;
    local_8 = uVar1;
    if (uVar1 <= uVar2) {
      local_8 = uVar2;
    }
    entries = __2_YAPAXI_Z(local_8 << 4);
    if (entries == (c1_idb_region *)0x0) {
      return 0;
    }
    if (-1 < (int)(local_8 - 1)) {
      pcVar3 = &entries->start_line;
      uVar2 = local_8;
      do {
        ((c1_idb_region *)(pcVar3 + -4))->signature = 0;
        *(int *)(pcVar3 + -2) = -1;
        *pcVar3 = 0;
        pcVar3[1] = 0;
        *(c1_u8 *)(pcVar3 + 2) = '\x18';
        pcVar3 = pcVar3 + 8;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    if (regions->data != (c1_idb_region *)0x0) {
      uVar2 = 0;
      if (regions->count != 0) {
        iVar4 = 0;
        do {
          old_entry = (c1_u32 *)(regions->data->pad0d + iVar4 + -0xd);
          new_entry = (c1_u32 *)(entries->pad0d + iVar4 + -0xd);
          uVar2 = uVar2 + 1;
          iVar4 = iVar4 + 0x10;
          *new_entry = *old_entry;
          new_entry[1] = old_entry[1];
          new_entry[2] = old_entry[2];
          new_entry[3] = old_entry[3];
        } while (uVar2 < regions->count);
      }
      __3_YAXPAX_Z(regions->data);
    }
    regions->data = entries;
    regions->capacity = local_8;
  }
  regions->count = uVar1;
  src = *cursor;
  entries_2 = regions->data;
  for (iVar4 = (uVar1 & 0xfffffff) << 2; iVar4 != 0; iVar4 = iVar4 + -1) {
    entries_2->signature = *src;
    src = src + 1;
    entries_2 = (c1_idb_region *)&entries_2->length;
  }
  for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(char *)&entries_2->signature = (char)*src;
    src = (c1_u32 *)((int)src + 1);
    entries_2 = (c1_idb_region *)((int)&entries_2->signature + 1);
  }
  *cursor = *cursor + regions->count * 4;
  return 1;
}

