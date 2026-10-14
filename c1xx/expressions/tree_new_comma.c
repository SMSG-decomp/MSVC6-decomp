c1_node * __cdecl tree_new_comma(c1_node *left,c1_node *right)

{
  c1_node *pcVar1;
  
  if (left == (c1_node *)0x0) {
    return right;
  }
  pcVar1 = tree_new_binary_typed_right('7',left,right);
  return pcVar1;
}

