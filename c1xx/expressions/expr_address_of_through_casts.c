char * __cdecl expr_address_of_through_casts(c1_node *node)

{
  c1_node *pcVar1;
  char *pcVar2;
  
  for (; (node->op == 'd' || (node->op == 'v')); node = node->left) {
  }
  if (node->op != '7') {
    pcVar1 = expr_build_address_of(node,2);
    return (char *)pcVar1;
  }
  pcVar2 = expr_address_of_through_casts(node->right);
  node->right = pcVar2;
  node->type = *(c1_type **)(pcVar2 + 4);
  return (char *)node;
}

