c1_node * __cdecl expr_assignment_as_lvalue(c1_node *left)

{
  c1_u8 op;
  char cVar1;
  c1_node *pcVar2;
  uint entity;
  c1_node *pcVar3;
  c1_node *left_00;
  c1_node *pcVar4;
  c1_type *pcVar5;
  void *visitor_vtable;
  int visitor_mask;
  
  if ((left == (c1_node *)0x0) || (pcVar2 = left->left, pcVar2 == (c1_node *)0x0)) {
    return (c1_node *)0x0;
  }
  op = left->op;
  pcVar4 = left->right;
  visitor_mask = 0xff;
  visitor_vtable = &g_side_effect_visitor_vtable;
  cVar1 = tree_has_side_effects((c1_tree_visitor *)&visitor_vtable,pcVar2);
  if ((cVar1 != '\0') && (pcVar2->op != '\x06')) {
    pcVar5 = pcVar2->type;
    entity = sym_new_local_key();
    pcVar3 = tree_new_leaf_9c(entity,pcVar5);
    left_00 = tree_new_binary_typed_right('4',pcVar3,pcVar2);
    pcVar4 = tree_new_binary_typed_right(op,left_00,pcVar4);
    pcVar3 = tree_copy_to_arena(pcVar3,0);
    pcVar3 = tree_new_unary('=',pcVar2->type,pcVar3);
    pcVar2 = tree_new_node('7',pcVar4,pcVar3,pcVar2->type);
    return pcVar2;
  }
  pcVar5 = pcVar2->type;
  pcVar2 = tree_copy_to_arena(pcVar2,0);
  pcVar2 = tree_new_node('7',left,pcVar2,pcVar5);
  return pcVar2;
}

