c1_node * expr_new_reference_temporary(c1_type *type)

{
  uint entity;
  c1_node *pcVar1;
  c1_type *pcVar2;
  
  pcVar2 = type;
  entity = sym_new_local_key();
  pcVar1 = tree_new_leaf_9c(entity,pcVar2);
  pcVar2 = type_pointer_with_qualifiers(type,0);
  pcVar1 = tree_new_cast(pcVar2,pcVar1);
  return pcVar1;
}

