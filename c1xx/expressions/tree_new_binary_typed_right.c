c1_node * __cdecl tree_new_binary_typed_right(c1_u8 op,c1_node *left,c1_node *right)

{
  c1_node *pcVar1;
  
  pcVar1 = tree_new_node(op,left,right,right->type);
  return pcVar1;
}

