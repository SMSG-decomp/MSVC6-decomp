c1_node * __cdecl pm_spill_member_pointer_operand(c1_node *node,int part,c1_node **spill)

{
  int iVar1;
  c1_node *pcVar2;
  uint entity;
  c1_node *pcVar3;
  c1_type *pcVar4;
  
  if (part != 0) {
    pcVar2 = tree_copy_to_arena(*spill,0);
    return pcVar2;
  }
  iVar1 = expr_is_reusable_lvalue(node);
  if ((char)iVar1 == '\0') {
    pcVar4 = node->type;
    entity = sym_new_local_key();
    pcVar2 = tree_new_leaf_9c(entity,pcVar4);
    *spill = pcVar2;
    pcVar3 = tree_copy_to_arena(pcVar2,0);
    pcVar3 = tree_new_binary('4',pcVar3,node);
    pcVar2 = tree_new_binary('7',pcVar3,pcVar2);
    return pcVar2;
  }
  pcVar2 = node;
  if (node->op == '7') {
    pcVar2 = node->right;
  }
  pcVar2 = expr_lvalue_address(pcVar2,0);
  *spill = pcVar2;
  if (node->op != '7') {
    pcVar2 = tree_copy_to_arena(pcVar2,0);
    return pcVar2;
  }
  pcVar4 = pcVar2->type;
  pcVar2 = tree_copy_to_arena(pcVar2,0);
  pcVar2 = tree_new_node('7',node->left,pcVar2,pcVar4);
  return pcVar2;
}

