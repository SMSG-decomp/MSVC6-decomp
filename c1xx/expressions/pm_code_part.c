c1_node * __cdecl pm_code_part(c1_node *left,c1_node *node)

{
  c1_type *type;
  c1_node *pcVar1;
  
  type = type_member_pointer_to(node->type);
  pcVar1 = tree_new_int_constant(0);
  pcVar1 = tree_new_node('S',left,pcVar1,type);
  pcVar1 = tree_new_rvalue(pcVar1);
  return pcVar1;
}

