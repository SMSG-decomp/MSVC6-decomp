c1_node * __cdecl eh_build_state_table(c1_node *list,c1_node *src)

{
  char *pcVar1;
  c1_node *pcVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int local_c;
  void **cell;
  void **entry_cell;
  void **cell_2;
  void **cell_3;
  
  iVar6 = -1;
  local_c = 1000;
  pcVar2 = tree_copy_to_arena(src,0);
  if (((pcVar2->kind & 7) == 7) && (pcVar2->op == 0xc5)) {
    for (cell_2 = pcVar2->right; cell_2 != (void **)0x0; cell_2 = *cell_2) {
      pcVar1 = cell_2[1];
      if (*pcVar1 == -0x3f) {
        iVar3 = eh_check_state_count((c1_symbol *)0x0);
        if (iVar6 == -1) {
          iVar6 = iVar3;
        }
        g_eh_state_table[iVar3].kind = (uint)(*(ushort *)(*(int *)(pcVar1 + 0x10) + 0x14) >> 0xc);
        g_eh_state_table[iVar3].source_number = *(int *)(*(int *)(pcVar1 + 0x10) + 0x10);
        if (g_eh_state_table[iVar3].source_number < local_c) {
          local_c = g_eh_state_table[iVar3].source_number;
        }
        *(int *)(*(int *)(pcVar1 + 0x10) + 0x10) = iVar3;
      }
    }
    iVar3 = g_eh_current_state;
    for (cell_3 = pcVar2->right; cell_3 != (void **)0x0; cell_3 = *cell_3) {
      pcVar1 = cell_3[1];
      if ((*pcVar1 != -0x3f) &&
         (uVar7 = *(ushort *)(pcVar1 + 0x14) & 0xfff, iVar4 = iVar6,
         (*(ushort *)(pcVar1 + 0x14) & 0xfff) != 0)) {
        do {
          if (iVar4 <= iVar3) {
            piVar5 = &g_eh_state_table[iVar4].kind;
            do {
              if (*piVar5 == (uint)(*(ushort *)(pcVar1 + 0x14) >> 0xc)) break;
              iVar4 = iVar4 + 1;
              piVar5 = piVar5 + 4;
            } while (iVar4 <= iVar3);
          }
          if (g_eh_state_table[iVar4].unwound != '\x01') {
            g_eh_state_table[iVar4].unwound = '\x01';
            *(int *)(pcVar1 + 0x10) = iVar4;
            uVar7 = uVar7 - 1;
            iVar3 = g_eh_current_state;
          }
          iVar4 = iVar4 + 1;
        } while (uVar7 != 0);
      }
    }
    if (0 < iVar6) {
      g_eh_state_table[iVar6 + -1].source_number = local_c + -1;
    }
    pcVar2 = pcVar2->left;
  }
  if (((pcVar2->kind & 7) == 7) && (pcVar2->op == 0xb7)) {
    uVar7 = g_next_entity_id;
    for (cell = pcVar2->right; g_next_entity_id = uVar7, cell != (void **)0x0; cell = *cell) {
      if (0x7ffffffe < uVar7) {
        diag_fatal_simple(0x37);
      }
      g_next_entity_id = uVar7 + 1;
      for (entry_cell = cell[1]; entry_cell != (void **)0x0; entry_cell = *entry_cell) {
        *(uint *)((int)entry_cell[1] + 0x10) = uVar7;
      }
      uVar7 = g_next_entity_id;
    }
    pcVar2 = pcVar2->left;
  }
  if (((pcVar2->kind & 7) == 7) && (pcVar2->op == 0xb6)) {
    eh_build_throw_info(pcVar2->right,1);
    pcVar2 = pcVar2->left;
  }
  pcVar2 = tree_append_list_item(list,pcVar2,4);
  return pcVar2;
}

