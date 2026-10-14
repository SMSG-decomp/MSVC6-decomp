void __cdecl tree_clear_value_link(c1_node *node)

{
  c1_node *leaf;
  
  if (node != (c1_node *)0x0) {
    if (node->op == '=') {
      if (node->right != (void *)0x0) {
        node->right = (void *)0x0;
        return;
      }
    }
    else if (((node->op == 'S') && (leaf = node->right, (leaf->kind & 7) == 4)) &&
            (leaf->right != (void *)0x0)) {
      leaf->right = (void *)0x0;
    }
  }
  return;
}

