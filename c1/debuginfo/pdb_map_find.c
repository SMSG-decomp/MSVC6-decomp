int __thiscall pdb_map_find(Map_DWORD_DWORD *map,uint key,uint *slot)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint local_8;
  
  uVar1 = (map->rgd).itMac;
  uVar3 = (key & 0xffff) % uVar1;
  local_8 = 0xffffffff;
  uVar2 = uVar3;
  do {
    if ((uVar2 < (map->isetPresent).rgw.itMac << 5) &&
       (((map->isetPresent).rgw.rgt[uVar2 >> 5] & 1 << ((byte)uVar2 & 0x1f)) != 0)) {
      if ((map->rgd).rgt[uVar2] == key) {
        *slot = uVar2;
        return 1;
      }
    }
    else {
      if (local_8 == 0xffffffff) {
        local_8 = uVar2;
      }
      if (((map->isetDeleted).rgw.itMac << 5 <= uVar2) ||
         (((map->isetDeleted).rgw.rgt[uVar2 >> 5] & 1 << ((byte)uVar2 & 0x1f)) == 0)) break;
    }
    uVar2 = uVar2 + 1 & -(uint)(uVar2 + 1 < uVar1);
  } while (uVar2 != uVar3);
  *slot = local_8;
  return 0;
}

