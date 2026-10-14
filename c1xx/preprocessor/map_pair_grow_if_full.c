int __fastcall map_pair_grow_if_full(void *map)

{
  uint key;
  uint uVar1;
  int iVar2;
  uint local_40 [2];
  uint value;
  c1_u32 *local_34;
  uint local_30;
  uint local_2c;
  c1_u32_pair *local_28;
  uint saved_count;
  uint value_word0;
  uint value_word0_2;
  
  uVar1 = *(int *)((int)map + 0x30) + 1;
  *(uint *)((int)map + 0x30) = uVar1;
  if (uVar1 < (uint)(*(int *)((int)map + 4) << 1) / 3 + 1) {
    return 1;
  }
  local_34 = __2_YAPAXI_Z(4);
  local_30 = (uint)(local_34 != (c1_u32 *)0x0);
  local_2c = local_30;
  array8_init_count(&stack0xffffffd8,1);
  il_buffer_init_empty((int *)&stack0xffffffe4);
  il_buffer_init_empty((int *)&stack0xfffffff0);
  saved_count = 0;
  uVar1 = ((uint)((ulonglong)(uint)(*(int *)((int)map + 4) << 1) * 0xaaaaaaab >> 0x20) & 0xfffffffe)
          + 2;
  iVar2 = array_set_size((c1xx_pdb_array *)&stack0xffffffcc,uVar1);
  if ((iVar2 == 0) || (iVar2 = array8_set_size((c1_pair_array *)&stack0xffffffd8,uVar1), iVar2 == 0)
     ) {
    pdb_array_destroy((c1xx_pdb_array *)&stack0xfffffff0);
    pdb_array_destroy((c1xx_pdb_array *)&stack0xffffffe4);
    if (local_28 != (c1_u32_pair *)0x0) {
      __3_YAXPAX_Z(local_28);
    }
    pdb_array_destroy((c1xx_pdb_array *)&stack0xffffffcc);
    return 0;
  }
  uVar1 = 0xffffffff;
  while( true ) {
    uVar1 = uVar1 + 1;
    if (*(uint *)((int)map + 4) <= uVar1) break;
    while (((uint)(*(int *)((int)map + 0x1c) << 5) <= uVar1 ||
           ((*(uint *)(*(int *)((int)map + 0x18) + (uVar1 >> 5) * 4) & 1 << ((byte)uVar1 & 0x1f)) ==
            0))) {
      uVar1 = uVar1 + 1;
      if (*(uint *)((int)map + 4) <= uVar1) goto LAB_104a306d;
    }
    value_word0_2 = *(uint *)(*(int *)((int)map + 0xc) + uVar1 * 8);
    key = *(uint *)(*(int *)map + uVar1 * 4);
    value = *(uint *)(*(int *)((int)map + 0xc) + 4 + uVar1 * 8);
    iVar2 = pdb_map_find((c1xx_pdb_map *)&stack0xffffffcc,key,local_40);
    if (iVar2 == 0) {
      iset_remove((c1xx_pdb_array *)&stack0xfffffff0,local_40[0]);
      iset_add((c1xx_pdb_iset *)&stack0xffffffe4,local_40[0]);
      local_34[local_40[0]] = key;
      local_28[local_40[0]].first = value_word0_2;
      local_28[local_40[0]].second = value;
      map_pair_grow_if_full(&stack0xffffffcc);
    }
    else {
      local_28[local_40[0]].first = value_word0_2;
      local_28[local_40[0]].second = value;
    }
  }
LAB_104a306d:
  array_swap((c1xx_pdb_array *)((int)map + 0x18),(c1xx_pdb_array *)&stack0xffffffe4);
  array_swap((c1xx_pdb_array *)((int)map + 0x24),(c1xx_pdb_array *)&stack0xfffffff0);
  array_swap(map,(c1xx_pdb_array *)&stack0xffffffcc);
  array_swap((c1xx_pdb_array *)((int)map + 0xc),(c1xx_pdb_array *)&stack0xffffffd8);
  value_word0 = *(uint *)((int)map + 0x30);
  *(uint *)((int)map + 0x30) = saved_count;
  saved_count = value_word0;
  map_destroy((c1xx_pdb_map *)&stack0xffffffcc);
  return 1;
}

