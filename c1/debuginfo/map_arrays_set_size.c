int __thiscall map_arrays_set_size(Map_DWORD_DWORD *map,uint n)

{
  uint uVar1;
  ulong *puVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = (map->rgd).itMax;
  if (uVar4 < n) {
    uVar1 = uVar4 * 3 >> 1;
    uVar4 = n;
    if (n <= uVar1) {
      uVar4 = uVar1;
    }
    puVar2 = __2_YAPAXI_Z(uVar4 * 4);
    if (puVar2 == (ulong *)0x0) {
      return 0;
    }
    if ((map->rgd).rgt != (ulong *)0x0) {
      uVar1 = 0;
      if ((map->rgd).itMac != 0) {
        do {
          uVar3 = uVar1 + 1;
          puVar2[uVar1] = (map->rgd).rgt[uVar1];
          uVar1 = uVar3;
        } while (uVar3 < (map->rgd).itMac);
      }
      __3_YAXPAX_Z((map->rgd).rgt);
    }
    (map->rgd).rgt = puVar2;
    (map->rgd).itMax = uVar4;
  }
  (map->rgd).itMac = n;
  uVar4 = (map->rgr).itMax;
  if (uVar4 < n) {
    uVar1 = uVar4 * 3 >> 1;
    uVar4 = n;
    if (n <= uVar1) {
      uVar4 = uVar1;
    }
    puVar2 = __2_YAPAXI_Z(uVar4 * 4);
    if (puVar2 == (ulong *)0x0) {
      return 0;
    }
    if ((map->rgr).rgt != (ulong *)0x0) {
      uVar1 = 0;
      if ((map->rgr).itMac != 0) {
        do {
          uVar3 = uVar1 + 1;
          puVar2[uVar1] = (map->rgr).rgt[uVar1];
          uVar1 = uVar3;
        } while (uVar3 < (map->rgr).itMac);
      }
      __3_YAXPAX_Z((map->rgr).rgt);
    }
    (map->rgr).rgt = puVar2;
    (map->rgr).itMax = uVar4;
  }
  (map->rgr).itMac = n;
  return 1;
}

