void __fastcall mark_referenced_symbols(c2_node *node)

{
  byte *pbVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  int iVar4;
  c2_node *node_00;
  
  do {
    if (node == (c2_node *)0x0) {
      return;
    }
    switch(g_mark_referenced_symbols_case_by_kind[node->kind]) {
    case 0:
      uVar3 = node[1].op;
      *(byte *)(uVar3 + 6) = *(byte *)(uVar3 + 6) | 2;
      uVar2 = *(uint32_t *)&node[1].kind;
      if ((uVar2 != uVar3) && (*(char *)(uVar2 + 4) != '\x02')) {
        *(byte *)(uVar2 + 6) = *(byte *)(uVar2 + 6) | 2;
      }
      break;
    case 1:
      pbVar1 = (byte *)(node[1].op + 6);
      *pbVar1 = *pbVar1 | 2;
      break;
    case 3:
      goto switchD_1070b95d_caseD_3;
    case 4:
      if (node->op == 0x1a0) {
        uVar3 = (node[2].next)->op;
        if ((uVar3 != 0) && (iVar4 = *(int *)(uVar3 + 0x34), iVar4 != 0)) {
          node_00 = *(c2_node **)(**(int **)(iVar4 + 8) + 0x1c);
          goto LAB_1070b99a;
        }
      }
      else if (node->op == 0x1ab) goto switchD_1070b95d_caseD_5;
      goto switchD_1070b95d_caseD_3;
    case 5:
switchD_1070b95d_caseD_5:
      node_00 = node[2].next;
LAB_1070b99a:
      mark_referenced_symbols(node_00);
switchD_1070b95d_caseD_3:
      if (*(c2_node **)&node[1].kind != (c2_node *)0x0) {
        mark_referenced_symbols(*(c2_node **)&node[1].kind);
      }
      if ((c2_node *)node[1].rank_or_prev != (c2_node *)0x0) {
        mark_referenced_symbols((c2_node *)node[1].rank_or_prev);
      }
    }
    node = node->next;
  } while( true );
}

