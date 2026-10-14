c1_node * __cdecl expr_spill_to_temporary(c1_node **expr)

{
  c1_type *type;
  uint entity;
  c1_node *pcVar1;
  
  type = (*expr)->type;
  entity = sym_new_local_key();
  pcVar1 = tree_new_leaf_9c(entity,type);
  pcVar1 = tree_new_node('4',pcVar1,*expr,type);
  *expr = pcVar1;
  pcVar1 = tree_new_leaf_9c(entity,type);
  pcVar1 = tree_new_unary('=',type,pcVar1);
  pcVar1->kind = pcVar1->kind | 0x20;
  return pcVar1;
}

