c1_node * __cdecl tree_strip_address_of(c1_node *node)

{
  if (node->op == '1') {
    node = node->left;
  }
  return node;
}

