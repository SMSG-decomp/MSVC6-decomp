void __cdecl expr_collect_temporary_leaves(int *list,c1_node *node)

{
  byte bVar1;
  c1_u8 *pcVar2;
  c1_u8 *pcVar3;
  c1_arena *pcVar4;
  int *piVar5;
  int *piVar6;
  uint *arg;
  uint *arg_list;
  
  if (node == (c1_node *)0x0) {
    return;
  }
  do {
    bVar1 = node->kind & 7;
    if (bVar1 == 2) {
      expr_collect_temporary_leaves(list,node->left);
      node = node->right;
    }
    else {
      if (bVar1 != 1) {
        if (bVar1 != 7) {
          if ((node->kind & 7) != 4) {
            return;
          }
          if (node->op != 0x9c) {
            return;
          }
          piVar5 = (int *)*list;
          if (piVar5 == (int *)0x0) goto LAB_10419f5c;
          break;
        }
        if (node->op < 0xb5) {
          return;
        }
        if (0xb6 < node->op) {
          return;
        }
        for (arg_list = node->right; arg_list != (uint *)0x0; arg_list = (uint *)*arg_list) {
          for (arg = (uint *)arg_list[1]; arg != (uint *)0x0; arg = (uint *)*arg) {
            expr_collect_temporary_leaves(list,(c1_node *)arg[1]);
          }
        }
      }
      node = node->left;
    }
    if (node == (c1_node *)0x0) {
      return;
    }
  } while( true );
  while (piVar5 = (int *)*piVar5, piVar5 != (int *)0x0) {
    if (*(void **)(*(int *)(piVar5[1] + 4) + 0x10) == node->left) {
      if (piVar5 != (int *)0x0) goto LAB_10419f93;
      break;
    }
  }
LAB_10419f5c:
  if (((byte)g_compile_flags_cc & 0x10) == 0) {
    pcVar3 = g_arenas[4].cur + 8;
    piVar5 = (int *)g_arenas[4].cur;
    pcVar2 = g_arenas[0].cur;
    if (g_arenas[4].end < pcVar3) {
      pcVar4 = g_arenas + 4;
      g_arenas[4].cur = pcVar3;
      goto LAB_104a3f10;
    }
  }
  else {
    pcVar2 = g_arenas[0].cur + 8;
    piVar5 = (int *)g_arenas[0].cur;
    pcVar3 = g_arenas[4].cur;
    if (g_arenas[0].end < pcVar2) {
      pcVar4 = g_arenas;
      g_arenas[0].cur = pcVar2;
LAB_104a3f10:
      arena_grow(pcVar4);
      pcVar2 = g_arenas[0].cur;
      pcVar3 = g_arenas[4].cur;
    }
  }
  g_arenas[4].cur = pcVar3;
  g_arenas[0].cur = pcVar2;
  *piVar5 = *list;
  *list = (int)piVar5;
  piVar5[1] = 0;
LAB_10419f93:
  if (((byte)g_compile_flags_cc & 0x10) == 0) {
    pcVar3 = g_arenas[4].cur + 8;
    piVar6 = (int *)g_arenas[4].cur;
    pcVar2 = g_arenas[0].cur;
    if (pcVar3 <= g_arenas[4].end) goto LAB_10419fbd;
    pcVar4 = g_arenas + 4;
    g_arenas[4].cur = pcVar3;
  }
  else {
    pcVar2 = g_arenas[0].cur + 8;
    piVar6 = (int *)g_arenas[0].cur;
    pcVar3 = g_arenas[4].cur;
    if (pcVar2 <= g_arenas[0].end) goto LAB_10419fbd;
    pcVar4 = g_arenas;
    g_arenas[0].cur = pcVar2;
  }
  arena_grow(pcVar4);
  pcVar2 = g_arenas[0].cur;
  pcVar3 = g_arenas[4].cur;
LAB_10419fbd:
  g_arenas[4].cur = pcVar3;
  g_arenas[0].cur = pcVar2;
  piVar6[1] = (int)node;
  *piVar6 = piVar5[1];
  piVar5[1] = (int)piVar6;
  return;
}

