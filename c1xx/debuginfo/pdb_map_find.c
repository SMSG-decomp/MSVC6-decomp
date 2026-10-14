int __thiscall pdb_map_find(c1xx_pdb_map *map,uint key,uint *slot)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint local_8;
  
  uVar1 = (map->domain).count;
  uVar3 = (key & 0xffff) % uVar1;
  local_8 = 0xffffffff;
  uVar2 = uVar3;
  do {
    if ((uVar2 < (map->present).count << 5) &&
       (((map->present).data[uVar2 >> 5] & 1 << ((byte)uVar2 & 0x1f)) != 0)) {
      if ((map->domain).data[uVar2] == key) {
        *slot = uVar2;
        return 1;
      }
    }
    else {
      if (local_8 == 0xffffffff) {
        local_8 = uVar2;
      }
      if (((map->deleted).count << 5 <= uVar2) ||
         (((map->deleted).data[uVar2 >> 5] & 1 << ((byte)uVar2 & 0x1f)) == 0)) break;
    }
    uVar2 = uVar2 + 1 & -(uint)(uVar2 + 1 < uVar1);
  } while (uVar2 != uVar3);
  *slot = local_8;
  return 0;
}

