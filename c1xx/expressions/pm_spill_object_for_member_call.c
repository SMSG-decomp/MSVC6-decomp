void __cdecl
pm_spill_object_for_member_call
          (c1_node *node,c1_node **object_out,c1_node **member_out,c1_node **spilled)

{
  char cVar1;
  c1_node *pcVar2;
  uint entity;
  c1_node *right;
  c1_node *pcVar3;
  c1_type *type;
  void *visitor;
  uint visitor_mask;
  
  visitor_mask = 0xff;
  visitor = &g_side_effect_visitor_vtable;
  cVar1 = tree_has_side_effects((c1_tree_visitor *)&visitor,node);
  if (cVar1 == '\0') {
    *object_out = node;
    pcVar2 = tree_copy_to_arena(node,0);
    *member_out = pcVar2;
    return;
  }
  type = node->type;
  entity = sym_new_local_key();
  pcVar2 = tree_new_leaf_9c(entity,type);
  right = tree_new_binary('4',pcVar2,node);
  pcVar3 = tree_copy_to_arena(pcVar2,0);
  pcVar3 = tree_new_rvalue(pcVar3);
  *object_out = pcVar3;
  pcVar2 = tree_copy_to_arena(pcVar2,0);
  pcVar2 = tree_new_rvalue(pcVar2);
  *member_out = pcVar2;
  if (*spilled != (c1_node *)0x0) {
    pcVar2 = tree_new_binary('7',*spilled,right);
    *spilled = pcVar2;
    return;
  }
  *spilled = right;
  return;
}

