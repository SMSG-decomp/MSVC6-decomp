c1_node * __cdecl expr_null_member_pointer_value(c1_type *type)

{
  c1_node *pcVar1;
  c1_node *node;
  
  pcVar1 = tree_new_int_constant(0);
  node = tree_new_null_member_pointer(type);
  pcVar1 = expr_member_pointer_cast(type,node,pcVar1);
  return pcVar1;
}

