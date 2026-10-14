c1_node * __cdecl expr_convert_operands_to_common_type(c1_node *node,c1_node *left,c1_node *right)

{
  c1_type *pcVar1;
  
  pcVar1 = conv_check_conditional_operands(node->op,&left,&right);
  if ((left != (c1_node *)0x0) && (right != (c1_node *)0x0)) {
    node->type = pcVar1;
    node->left = left;
    node->right = right;
    return node;
  }
  return (c1_node *)0x0;
}

