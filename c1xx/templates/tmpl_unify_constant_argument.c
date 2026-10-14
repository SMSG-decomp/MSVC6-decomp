int __thiscall
tmpl_unify_constant_argument(c1_tmpl_deduction *deduction,c1_node *pattern,c1_node *src)

{
  c1_arg_item *pcVar1;
  int iVar2;
  c1_node *pcVar3;
  
  if (((pattern->op == 'e') && (src->op == 'e')) && ((pattern->flags & 8) != 0)) {
    iVar2 = (*(ushort *)&pattern->left & 0xff) - 1;
    deduction->cur_arg = deduction->args->first;
    if (0 < iVar2) {
      do {
        iVar2 = iVar2 + -1;
        deduction->cur_arg = deduction->cur_arg->next;
      } while (iVar2 != 0);
    }
    pcVar1 = deduction->cur_arg;
    pcVar3 = (pcVar1->value).expr;
    if (pcVar3 == (c1_node *)0x0) {
      pcVar1->kind = pcVar1->kind & 0xfc ^ 1;
      pcVar1 = deduction->cur_arg;
      if (src != (c1_node *)0x0) {
        pcVar3 = tree_copy_to_arena(src,0);
        (pcVar1->value).expr = pcVar3;
        return CONCAT31((int3)((uint)pcVar3 >> 8),1);
      }
      (pcVar1->value).type = (c1_type *)0x0;
      return 1;
    }
    pattern = (c1_node *)&src->left;
    if ((src->left == pcVar3->left) && (pattern = src->right, pattern == pcVar3->right)) {
      return CONCAT31((int3)((uint)pattern >> 8),1);
    }
  }
  return (uint)pattern & 0xffffff00;
}

