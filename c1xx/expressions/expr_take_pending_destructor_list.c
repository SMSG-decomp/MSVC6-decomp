c1_value_cell * __cdecl expr_take_pending_destructor_list(void)

{
  c1_flow_state *pcVar1;
  c1_u8 *pcVar2;
  c1_u8 *pcVar3;
  c1_node *pcVar4;
  c1_u8 *pcVar5;
  c1_u8 *pcVar6;
  c1_u8 *pcVar7;
  c1_arena *pcVar8;
  c1_value_cell *pcVar9;
  c1_value_cell *pcVar10;
  
  pcVar10 = (c1_value_cell *)0x0;
  if (g_flow_state_abandoned != '\0') {
    return (c1_value_cell *)0x0;
  }
  if (g_flow_state_top != (c1_flow_state *)0x0) {
    while ((pcVar1 = g_flow_state_top, g_flow_state_top->kind == 0xd &&
           ((g_flow_state_top->flags & 3) == 0))) {
      if (((byte)g_compile_flags_cc & 0x10) == 0) {
        pcVar3 = g_arenas[4].cur + 8;
        pcVar9 = (c1_value_cell *)g_arenas[4].cur;
        pcVar2 = g_arenas[0].cur;
        if (g_arenas[4].end < pcVar3) {
          pcVar8 = g_arenas + 4;
          g_arenas[4].cur = pcVar3;
          goto LAB_104a42fd;
        }
      }
      else {
        pcVar2 = g_arenas[0].cur + 8;
        pcVar9 = (c1_value_cell *)g_arenas[0].cur;
        pcVar3 = g_arenas[4].cur;
        if (g_arenas[0].end < pcVar2) {
          pcVar8 = g_arenas;
          g_arenas[0].cur = pcVar2;
LAB_104a42fd:
          arena_grow(pcVar8);
          pcVar2 = g_arenas[0].cur;
          pcVar3 = g_arenas[4].cur;
        }
      }
      g_arenas[4].cur = pcVar3;
      g_arenas[0].cur = pcVar2;
      pcVar9->next = pcVar10;
      if (((byte)g_compile_flags_cc & 0x10) == 0) {
        pcVar5 = g_arenas[4].cur + 8;
        pcVar2 = g_arenas[4].cur;
        pcVar3 = g_arenas[0].cur;
        if (g_arenas[4].end < pcVar5) {
          pcVar8 = g_arenas + 4;
          g_arenas[4].cur = pcVar5;
          goto LAB_104a4331;
        }
      }
      else {
        pcVar3 = g_arenas[0].cur + 8;
        pcVar2 = g_arenas[0].cur;
        pcVar5 = g_arenas[4].cur;
        if (g_arenas[0].end < pcVar3) {
          pcVar8 = g_arenas;
          g_arenas[0].cur = pcVar3;
LAB_104a4331:
          arena_grow(pcVar8);
          pcVar3 = g_arenas[0].cur;
          pcVar5 = g_arenas[4].cur;
        }
      }
      g_arenas[4].cur = pcVar5;
      g_arenas[0].cur = pcVar3;
      pcVar4 = tree_new_int_constant(pcVar1->word18);
      *(c1_node **)(pcVar2 + 4) = pcVar4;
      if (((byte)g_compile_flags_cc & 0x10) == 0) {
        pcVar6 = g_arenas[4].cur + 8;
        pcVar3 = g_arenas[4].cur;
        pcVar5 = g_arenas[0].cur;
        if (g_arenas[4].end < pcVar6) {
          pcVar8 = g_arenas + 4;
          g_arenas[4].cur = pcVar6;
          goto LAB_104a4370;
        }
      }
      else {
        pcVar5 = g_arenas[0].cur + 8;
        pcVar3 = g_arenas[0].cur;
        pcVar6 = g_arenas[4].cur;
        if (g_arenas[0].end < pcVar5) {
          pcVar8 = g_arenas;
          g_arenas[0].cur = pcVar5;
LAB_104a4370:
          arena_grow(pcVar8);
          pcVar5 = g_arenas[0].cur;
          pcVar6 = g_arenas[4].cur;
        }
      }
      g_arenas[4].cur = pcVar6;
      g_arenas[0].cur = pcVar5;
      *(c1_u8 **)pcVar2 = pcVar3;
      pcVar4 = tree_new_int_constant(pcVar1->word1c);
      *(c1_node **)(pcVar3 + 4) = pcVar4;
      if (((byte)g_compile_flags_cc & 0x10) == 0) {
        pcVar7 = g_arenas[4].cur + 8;
        pcVar5 = g_arenas[4].cur;
        pcVar6 = g_arenas[0].cur;
        if (g_arenas[4].end < pcVar7) {
          pcVar8 = g_arenas + 4;
          g_arenas[4].cur = pcVar7;
          goto LAB_104a43b1;
        }
      }
      else {
        pcVar6 = g_arenas[0].cur + 8;
        pcVar5 = g_arenas[0].cur;
        pcVar7 = g_arenas[4].cur;
        if (g_arenas[0].end < pcVar6) {
          pcVar8 = g_arenas;
          g_arenas[0].cur = pcVar6;
LAB_104a43b1:
          arena_grow(pcVar8);
          pcVar6 = g_arenas[0].cur;
          pcVar7 = g_arenas[4].cur;
        }
      }
      g_arenas[4].cur = pcVar7;
      g_arenas[0].cur = pcVar6;
      *(c1_u8 **)pcVar3 = pcVar5;
      *(void **)(pcVar5 + 4) = pcVar1->subject;
      pcVar9->value = (int)pcVar2;
      func_flow_state_pop_record();
      pcVar10 = pcVar9;
      if (g_flow_state_top == (c1_flow_state *)0x0) {
        return pcVar9;
      }
    }
    if ((g_flow_state_top != (c1_flow_state *)0x0) && (g_flow_state_top->kind == 0x3e)) {
      func_flow_state_pop_record();
    }
  }
  return pcVar10;
}

