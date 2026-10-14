int __fastcall map_grow(c1xx_pdb_map *map)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint local_38;
  c1xx_pdb_map local_34;
  uint value;
  uint value_3;
  c1_u32 value_2;
  
  value = (map->domain).count;
  uVar2 = map->count + 1;
  map->count = uVar2;
  if (uVar2 < (value << 1) / 3 + 1) {
    return 1;
  }
  local_34.domain.data = __2_YAPAXI_Z(4);
  local_34.domain.count = (c1_u32)(local_34.domain.data != (c1_u32 *)0x0);
  local_34.domain.capacity = local_34.domain.count;
  array_init_count(&local_34.range,1);
  il_buffer_init_empty((int *)&local_34.present);
  il_buffer_init_empty((int *)&local_34.deleted);
  local_34.count = 0;
  uVar2 = ((uint)((ulonglong)((map->domain).count << 1) * 0xaaaaaaab >> 0x20) & 0xfffffffe) + 2;
  iVar3 = array_set_size(&local_34.domain,uVar2);
  if ((iVar3 == 0) || (iVar3 = array_set_size(&local_34.range,uVar2), iVar3 == 0)) {
    pdb_array_destroy(&local_34.deleted);
    pdb_array_destroy(&local_34.present);
    if (local_34.range.data != (c1_u32 *)0x0) {
      __3_YAXPAX_Z(local_34.range.data);
    }
    pdb_array_destroy(&local_34.domain);
    return 0;
  }
  uVar2 = 0xffffffff;
  while( true ) {
    uVar1 = (map->domain).count;
    uVar2 = uVar2 + 1;
    if (uVar1 <= uVar2) break;
    while (((map->present).count << 5 <= uVar2 ||
           (((map->present).data[uVar2 >> 5] & 1 << ((byte)uVar2 & 0x1f)) == 0))) {
      uVar2 = uVar2 + 1;
      if (uVar1 <= uVar2) goto LAB_104922e9;
    }
    uVar1 = (map->domain).data[uVar2];
    value_3 = (map->range).data[uVar2];
    iVar3 = pdb_map_find(&local_34,uVar1,&local_38);
    if (iVar3 == 0) {
      iset_remove(&local_34.deleted,local_38);
      iset_add(&local_34.present,local_38);
      local_34.domain.data[local_38] = uVar1;
      local_34.range.data[local_38] = value_3;
      map_grow(&local_34);
    }
    else {
      local_34.range.data[local_38] = value_3;
    }
  }
LAB_104922e9:
  array_swap(&map->present,&local_34.present);
  array_swap(&map->deleted,&local_34.deleted);
  array_swap(&map->domain,&local_34.domain);
  array_swap(&map->range,&local_34.range);
  value_2 = map->count;
  map->count = local_34.count;
  local_34.count = value_2;
  map_destroy(&local_34);
  return 1;
}

