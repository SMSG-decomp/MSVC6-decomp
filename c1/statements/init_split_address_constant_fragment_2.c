int __cdecl init_split_address_constant_fragment_2(c1_node *node,void **symbol)

{
  *symbol = node->left;
  return 1;
}

