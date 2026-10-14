int __fastcall join_or_create_stack_slot(c2_symbol *obj,int bytes)

{
  uint32_t n;
  int iVar1;
  c2_symbol_u34 cVar2;
  c2_bitset **ppcVar3;
  c2_stack_slot *pcVar4;
  int iVar5;
  c2_stack_slot *pcVar6;
  uint32_t uVar7;
  c2_bitset *pcVar8;
  int iVar9;
  int iVar10;
  int local_8;
  
  iVar10 = g_stack_slot_count + -1;
  n = (obj->u38).index;
  if (g_stack_param_slot_count <= iVar10) {
    iVar1 = obj->size;
    iVar9 = iVar10 * 0x14;
    pcVar6 = g_stack_slots;
    do {
      if (((iVar1 <= *(int *)((int)&pcVar6->size + iVar9) * 2) &&
          (uVar7 = bitset_test(*(c2_bitset **)((int)&pcVar6->interference + iVar9),n),
          pcVar6 = g_stack_slots, uVar7 == 0)) &&
         (iVar5 = bitset_intersects(*(c2_bitset **)((int)&g_stack_slots->members + iVar9),
                                    g_stack_interference[n]), pcVar6 = g_stack_slots, iVar5 == 0)) {
        bitset_set(g_stack_slots[iVar10].members,n);
        bitset_or(g_stack_slots[iVar10].interference,g_stack_interference[n]);
        pcVar6 = g_stack_slots;
        g_stack_slots[iVar10].refs =
             (int)&((obj->u34).source_links)->next_of_source + g_stack_slots[iVar10].refs;
        iVar9 = pcVar6[iVar10].size;
        local_8 = bytes;
        if (iVar9 < iVar1) {
          pcVar6[iVar10].size = iVar1;
          local_8 = bytes + (iVar1 - iVar9);
        }
        return local_8;
      }
      iVar10 = iVar10 + -1;
      iVar9 = iVar9 + -0x14;
    } while (g_stack_param_slot_count <= iVar10);
  }
  pcVar8 = bitset_new(6);
  pcVar6 = g_stack_slots;
  iVar10 = g_stack_slot_count;
  g_stack_slots[g_stack_slot_count].interference = pcVar8;
  pcVar8 = bitset_new(6);
  ppcVar3 = g_stack_interference;
  pcVar6[iVar10].members = pcVar8;
  bitset_copy(pcVar6[iVar10].interference,ppcVar3[n]);
  bitset_set(g_stack_slots[g_stack_slot_count].members,n);
  pcVar4 = g_stack_slots;
  iVar1 = g_stack_slot_count;
  cVar2 = obj->u34;
  iVar10 = obj->size;
  pcVar6 = g_stack_slots + g_stack_slot_count;
  g_stack_slot_count = g_stack_slot_count + 1;
  pcVar6->size = iVar10;
  pcVar4[iVar1].refs = (int32_t)cVar2;
  return bytes + iVar10;
}

