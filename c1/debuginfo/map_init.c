Map_DWORD_DWORD * __thiscall map_init(Map_DWORD_DWORD *map,uint slots)

{
  ulong *puVar1;
  uint uVar2;
  
  uVar2 = slots;
  if (slots == 0) {
    uVar2 = 1;
  }
  puVar1 = __2_YAPAXI_Z(uVar2 * 4);
  (map->rgd).rgt = puVar1;
  uVar2 = -(uint)(puVar1 != (ulong *)0x0) & uVar2;
  (map->rgd).itMax = uVar2;
  (map->rgd).itMac = uVar2;
  if (slots == 0) {
    slots = 1;
  }
  puVar1 = __2_YAPAXI_Z(slots * 4);
  (map->rgr).rgt = puVar1;
  uVar2 = -(uint)(puVar1 != (ulong *)0x0) & slots;
  (map->rgr).itMax = uVar2;
  (map->rgr).itMac = uVar2;
  (map->isetPresent).rgw.rgt = (ulong *)0x0;
  (map->isetPresent).rgw.itMax = 0;
  (map->isetPresent).rgw.itMac = 0;
  (map->isetDeleted).rgw.rgt = (ulong *)0x0;
  (map->isetDeleted).rgw.itMax = 0;
  (map->isetDeleted).rgw.itMac = 0;
  map->cdr = 0;
  return map;
}

