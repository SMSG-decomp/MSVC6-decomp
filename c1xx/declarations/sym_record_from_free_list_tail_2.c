byte * __cdecl
sym_record_from_free_list_tail_2
          (int size_class,int arena_index,void **free_cell,void *name,c1_type *list)

{
  void **ppvVar1;
  byte *pbVar2;
  byte *pbVar3;
  c1_u32 cVar4;
  uint uVar5;
  c1_arena *a;
  void **ppvVar6;
  
  g_symbol_free_lists[size_class] = free_cell[1];
  *free_cell = (void *)0x0;
  ppvVar1 = free_cell + -2;
  free_cell[1] = (void *)0x0;
  cVar4 = g_symbol_size_table[0x12];
  ppvVar6 = ppvVar1;
  for (uVar5 = g_symbol_size_table[0x12] >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *ppvVar6 = (void *)0x0;
    ppvVar6 = ppvVar6 + 1;
  }
  for (uVar5 = cVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(byte *)ppvVar6 = 0;
    ppvVar6 = (void **)((int)ppvVar6 + 1);
  }
  *free_cell = name;
  *(byte *)ppvVar1 = *(byte *)ppvVar1 & 0xf2 | 0x12;
  if (ppvVar1 == (void **)0x0) {
    a = g_arenas + arena_index;
    uVar5 = g_symbol_size_table[0x12] + 3;
    pbVar2 = a->cur;
    pbVar3 = g_arenas[arena_index].end;
    a->cur = pbVar2 + (uVar5 & 0xfffffffc);
    if (pbVar3 < pbVar2 + (uVar5 & 0xfffffffc)) {
      arena_grow(a);
    }
    if (pbVar2 != (byte *)0x0) {
      *pbVar2 = *pbVar2 & 0xf2 | 0x12;
      if (pbVar2 + 8 != (byte *)0x0) {
        *(void **)(pbVar2 + 8) = name;
        pbVar2[0xc] = 0;
        pbVar2[0xd] = 0;
        pbVar2[0xe] = 0;
        pbVar2[0xf] = 0;
      }
      *(c1_type **)(pbVar2 + 0x14) = list;
      return pbVar2;
    }
    pcRam00000014 = list;
    return (byte *)0x0;
  }
  free_cell[3] = list;
  return (byte *)ppvVar1;
}

