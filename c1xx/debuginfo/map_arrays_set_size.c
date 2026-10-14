int __thiscall map_arrays_set_size(c1xx_pdb_map *map,uint size)

{
  uint uVar1;
  c1_u32 *pcVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = (map->domain).capacity;
  if (uVar4 < size) {
    uVar1 = uVar4 * 3 >> 1;
    uVar4 = size;
    if (size <= uVar1) {
      uVar4 = uVar1;
    }
    pcVar2 = __2_YAPAXI_Z(uVar4 * 4);
    if (pcVar2 == (c1_u32 *)0x0) {
      return 0;
    }
    if ((map->domain).data != (c1_u32 *)0x0) {
      uVar1 = 0;
      if ((map->domain).count != 0) {
        do {
          uVar3 = uVar1 + 1;
          pcVar2[uVar1] = (map->domain).data[uVar1];
          uVar1 = uVar3;
        } while (uVar3 < (map->domain).count);
      }
      __3_YAXPAX_Z((map->domain).data);
    }
    (map->domain).data = pcVar2;
    (map->domain).capacity = uVar4;
  }
  (map->domain).count = size;
  uVar4 = (map->range).capacity;
  if (uVar4 < size) {
    uVar1 = uVar4 * 3 >> 1;
    uVar4 = size;
    if (size <= uVar1) {
      uVar4 = uVar1;
    }
    pcVar2 = __2_YAPAXI_Z(uVar4 * 4);
    if (pcVar2 == (c1_u32 *)0x0) {
      return 0;
    }
    if ((map->range).data != (c1_u32 *)0x0) {
      uVar1 = 0;
      if ((map->range).count != 0) {
        do {
          uVar3 = uVar1 + 1;
          pcVar2[uVar1] = (map->range).data[uVar1];
          uVar1 = uVar3;
        } while (uVar3 < (map->range).count);
      }
      __3_YAXPAX_Z((map->range).data);
    }
    (map->range).data = pcVar2;
    (map->range).capacity = uVar4;
  }
  (map->range).count = size;
  return 1;
}

