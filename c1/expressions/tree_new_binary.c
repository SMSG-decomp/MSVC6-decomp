c1_node * __cdecl tree_new_binary(c1_u8 op,c1_node *left,c1_node *right)

{
  c1_node *pcVar1;
  
  pcVar1 = tree_new_node(op,left,right,left->type);
  return pcVar1;
}

