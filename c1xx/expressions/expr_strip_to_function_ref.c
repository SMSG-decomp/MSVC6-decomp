c1_node * __cdecl expr_strip_to_function_ref(c1_node *node,uint *how)

{
  *how = 0;
  if (node->op == '1') {
    node = node->left;
    *how = 2;
  }
  if (node->op == 'S') {
    node = node->right;
    *how = *how | 4;
  }
  if (node->op == '=') {
    node = node->left;
    *how = *how | 8;
  }
  if (node->op != 0x93) {
    return (c1_node *)((uint)node & (node->op != '\x06') - 1);
  }
  return (c1_node *)0x0;
}

