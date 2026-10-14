c1_node * __cdecl tree_new_offset(c1_node *left,int value,c1_type *type)

{
  c1_node *pcVar1;
  
  pcVar1 = tree_new_int_constant(value);
  pcVar1 = tree_new_node('S',left,pcVar1,type);
  return pcVar1;
}

