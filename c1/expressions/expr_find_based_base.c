c1_node * __cdecl expr_find_based_base(c1_node *node)

{
  c1_u8 cVar1;
  
  while( true ) {
    if (node == (c1_node *)0x0) {
      return (c1_node *)0x0;
    }
    cVar1 = node->op;
    if ((cVar1 != '4') && (cVar1 != '7')) break;
    node = node->right;
  }
  if (cVar1 != ']') {
    return (c1_node *)0x0;
  }
  return node->right;
}

