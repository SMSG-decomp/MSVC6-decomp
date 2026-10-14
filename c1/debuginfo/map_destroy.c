void __fastcall map_destroy(Map_DWORD_DWORD *map)

{
  ulong *puVar1;
  
  puVar1 = (map->isetDeleted).rgw.rgt;
  if (puVar1 != (ulong *)0x0) {
    __3_YAXPAX_Z(puVar1);
  }
  puVar1 = (map->isetPresent).rgw.rgt;
  if (puVar1 != (ulong *)0x0) {
    __3_YAXPAX_Z(puVar1);
  }
  puVar1 = (map->rgr).rgt;
  if (puVar1 != (ulong *)0x0) {
    __3_YAXPAX_Z(puVar1);
  }
  puVar1 = (map->rgd).rgt;
  if (puVar1 != (ulong *)0x0) {
    __3_YAXPAX_Z(puVar1);
  }
  return;
}

