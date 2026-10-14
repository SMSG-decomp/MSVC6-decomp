int __fastcall map_grow_2(Map_DWORD_DWORD *map)

{
  ulong uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint local_38;
  Map_DWORD_DWORD local_34;
  
  uVar4 = (map->rgd).itMac;
  uVar2 = map->cdr + 1;
  map->cdr = uVar2;
  if (uVar2 < (uVar4 << 1) / 3 + 1) {
    return 1;
  }
  local_34.rgd.rgt = __2_YAPAXI_Z(4);
  local_34.rgd.itMac = (uint)(local_34.rgd.rgt != (ulong *)0x0);
  local_34.rgd.itMax = local_34.rgd.itMac;
  array_init_count(&local_34.rgr,1);
  il_buffer_init_empty((int *)&local_34.isetPresent);
  il_buffer_init_empty((int *)&local_34.isetDeleted);
  local_34.cdr = 0;
  uVar4 = ((uint)((ulonglong)((map->rgd).itMac << 1) * 0xaaaaaaab >> 0x20) & 0xfffffffe) + 2;
  iVar3 = array_set_size(&local_34.rgd,uVar4);
  if ((iVar3 == 0) || (iVar3 = array_set_size(&local_34.rgr,uVar4), iVar3 == 0)) {
    pdb_array_destroy(&local_34.isetDeleted.rgw);
    pdb_array_destroy(&local_34.isetPresent.rgw);
    if (local_34.rgr.rgt != (ulong *)0x0) {
      __3_YAXPAX_Z(local_34.rgr.rgt);
    }
    pdb_array_destroy(&local_34.rgd);
    return 0;
  }
  uVar4 = 0xffffffff;
  while( true ) {
    uVar2 = (map->rgd).itMac;
    uVar4 = uVar4 + 1;
    if (uVar2 <= uVar4) break;
    while (((map->isetPresent).rgw.itMac << 5 <= uVar4 ||
           (((map->isetPresent).rgw.rgt[uVar4 >> 5] & 1 << ((byte)uVar4 & 0x1f)) == 0))) {
      uVar4 = uVar4 + 1;
      if (uVar2 <= uVar4) goto LAB_1064979e;
    }
    uVar2 = (map->rgd).rgt[uVar4];
    uVar1 = (map->rgr).rgt[uVar4];
    iVar3 = pdb_map_find(&local_34,uVar2,&local_38);
    if (iVar3 == 0) {
      iset_remove(&local_34.isetDeleted,local_38);
      iset_add(&local_34.isetPresent,local_38);
      local_34.rgd.rgt[local_38] = uVar2;
      local_34.rgr.rgt[local_38] = uVar1;
      map_grow_2(&local_34);
    }
    else {
      local_34.rgr.rgt[local_38] = uVar1;
    }
  }
LAB_1064979e:
  array_swap(&(map->isetPresent).rgw,&local_34.isetPresent.rgw);
  array_swap(&(map->isetDeleted).rgw,&local_34.isetDeleted.rgw);
  array_swap(&map->rgd,&local_34.rgd);
  array_swap(&map->rgr,&local_34.rgr);
  uVar4 = map->cdr;
  map->cdr = local_34.cdr;
  local_34.cdr = uVar4;
  map_destroy(&local_34);
  return 1;
}

