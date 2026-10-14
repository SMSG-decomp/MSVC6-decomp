c1_node * __cdecl expr_warn_operator_precedence(c1_node *node,c1_node *left,c1_node *right)

{
  c1_node *pcVar1;
  
  diag_warning(3,0x22a);
  node->left = left;
  node->type = left->type;
  pcVar1 = expr_check_binary_operand_types(node);
  pcVar1 = fold_binary_constant_expression(pcVar1,left,right);
  return pcVar1;
}

