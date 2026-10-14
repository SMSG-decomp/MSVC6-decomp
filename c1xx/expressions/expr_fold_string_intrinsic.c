int __cdecl expr_fold_string_intrinsic(c1_node *call)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  c1_node *pcVar4;
  c1_node *item;
  uint uVar5;
  c1_node *intrinsic;
  
  iVar2 = *(int *)((int)call->left + 0x10);
  if (((((iVar2 == 0xa4) || (iVar2 == 0xa7)) && (pcVar4 = call->right, pcVar4 != (c1_node *)0x0)) &&
      ((pcVar3 = pcVar4->left, pcVar3 != (char *)0x0 &&
       ((*pcVar3 != 'd' || (pcVar3 = *(char **)(pcVar3 + 0x10), pcVar3 != (char *)0x0)))))) &&
     ((*pcVar3 == '\a' && ((pcVar3[0x16] & 1U) == 0)))) {
    if (iVar2 == 0xa7) {
      uVar5 = 0xffffffff;
      pcVar3 = *(char **)(pcVar3 + 0x10);
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      pcVar4 = tree_new_int_constant(~uVar5 - 1);
      il_emit_expression_tree(pcVar4);
      return 1;
    }
    uVar5 = 0xffffffff;
    pcVar3 = *(char **)(pcVar3 + 0x10);
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    item = tree_new_int_constant(~uVar5);
    pcVar4 = tree_append_list_item(pcVar4,item,2);
    intrinsic = call->left;
    call->right = pcVar4;
    intrinsic->left = (void *)0xac;
    intrinsic->right = (void *)0x0;
  }
  return 0;
}

