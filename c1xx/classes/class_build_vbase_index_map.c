void __cdecl class_build_vbase_index_map(c1_vbase_map_key *entry,c1_symbol *table)

{
  char cVar1;
  c1_vbase_vector *pcVar2;
  c1_u8 *values;
  c1_u8 cVar3;
  c1_type *pcVar4;
  uint uVar5;
  c1_symbol *pcVar6;
  c1_vbase_vector *pcVar7;
  uint local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  c1_vbase_vector *local_18;
  short local_14;
  char local_4;
  
  pcVar4 = type_int();
  values = g_arenas[5].cur;
  cVar1 = (char)pcVar4->code;
  while (cVar1 < '\0') {
    pcVar4 = pcVar4->base;
    cVar1 = (char)pcVar4->code;
  }
  local_28 = (uint)(char)(&g_type_rank_table)[(byte)pcVar4->code & 0xf];
  if (entry->reverse == '\0') {
    pcVar6 = entry->cls_b;
  }
  else {
    pcVar6 = entry->cls_a;
  }
  pcVar2 = ((pcVar6->detail).cls)->vbases;
  if (pcVar2 == (c1_vbase_vector *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (uint)pcVar2->count;
  }
  local_20 = uVar5 + 1;
  g_arenas[5].cur = g_arenas[5].cur + local_20 * 4;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (entry->reverse != '\0') {
    cVar3 = class_vbase_get_info
                      (entry->cls_a,entry->cls_b,&local_24,(int *)&local_30,(c1_type **)0x0);
    *(uint *)values = -(uint)(cVar3 != '\0') & local_30;
    if (entry->reverse != '\0') {
      pcVar6 = entry->cls_a;
      goto LAB_104b3038;
    }
  }
  pcVar6 = entry->cls_b;
LAB_104b3038:
  pcVar2 = ((pcVar6->detail).cls)->vbases;
  local_4 = pcVar2 != (c1_vbase_vector *)0x0;
  pcVar7 = local_18;
  if ((bool)local_4) {
    pcVar7 = pcVar2;
    local_14 = 0;
  }
  while (((local_4 != '\0' && (pcVar7 != (c1_vbase_vector *)0x0)) &&
         ((int)local_14 < (int)(uint)pcVar7->count))) {
    pcVar6 = pcVar7->data[local_14]->base;
    class_virtual_base_info(pcVar6,entry->cls_b,&local_24,(int *)&local_30,(c1_type **)0x0);
    cVar3 = class_vbase_get_info(pcVar6,entry->cls_a,&local_1c,(int *)&local_2c,(c1_type **)0x0);
    if (cVar3 == '\0') {
      local_2c = 0;
    }
    if (entry->reverse == '\0') {
      *(uint *)(values + (local_30 / local_28) * 4) = local_2c;
      local_14 = local_14 + 1;
    }
    else {
      *(uint *)(values + (local_2c / local_28) * 4) = local_30;
      local_14 = local_14 + 1;
    }
  }
  init_emit_int_table(table,(int *)values,local_20);
  return;
}

