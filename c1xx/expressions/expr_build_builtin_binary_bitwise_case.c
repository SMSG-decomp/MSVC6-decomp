c1_node * __cdecl
expr_build_builtin_binary_bitwise_case
          (c1_node *node,uint op,c1_node *left_orig,uint op_index,c1_node *right_orig,c1_node *left,
          c1_node *right)

{
  c1_type *pcVar1;
  c1_node *pcVar2;
  
  if ((((g_op_flags_table[left_orig->op] & 8) != 0) && ((left_orig->flags & 2) == 0)) ||
     (((g_op_flags_table[right_orig->op] & 8) != 0 && ((right_orig->flags & 2) == 0)))) {
    diag_warning(3,0x22a,op_index);
  }
  pcVar1 = conv_usual_arithmetic((c1_u8)op,left->type,right->type);
  node->type = pcVar1;
  pcVar2 = expr_check_binary_operand_types(node);
  pcVar2 = fold_binary_constants(pcVar2,left,right);
  return pcVar2;
}

