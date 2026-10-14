char __cdecl expr_find_result_temporary(c1_node *expr,c1_node **found)

{
  byte *pbVar1;
  int iVar2;
  c1_node *pcVar3;
  char *pcVar4;
  byte bVar5;
  
  while( true ) {
    if (expr == (c1_node *)0x0) {
      return '\0';
    }
    if (expr->op != 0xc1) break;
    expr = *(c1_node **)((int)expr->right + 0x10);
  }
  if (expr->op != 'p') {
    return '\0';
  }
  pcVar4 = expr->left;
  if ((*pcVar4 == -0x67) && (**(char **)(pcVar4 + 0x10) == '\x06')) {
    pbVar1 = *(byte **)(*(char **)(pcVar4 + 0x10) + 0x10);
    bVar5 = *pbVar1 & 0x1f;
    if (((bVar5 == 7) || (bVar5 == 8)) && ((pbVar1[1] & 0x10) == 0x10)) {
      iVar2 = *(int *)(pcVar4 + 0x14);
      goto LAB_1041cadf;
    }
  }
  if ((pcVar4 != (char *)0x0) && (*pcVar4 == '7')) {
    pcVar4 = *(char **)(pcVar4 + 0x14);
  }
  if ((**(ushort **)(*(int *)(pcVar4 + 4) + 4) & 0x200) == 0) {
    return '\0';
  }
  iVar2 = *(int *)((int)expr->right + 8);
LAB_1041cadf:
  pcVar3 = *(c1_node **)(iVar2 + 0x10);
  if (pcVar3->op == 'd') {
    pcVar3 = pcVar3->left;
  }
  if (pcVar3->op != 0x9c) {
    return '\0';
  }
  *found = pcVar3;
  return '\x01';
}

