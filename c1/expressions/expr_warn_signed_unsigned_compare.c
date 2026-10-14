c1_node * __cdecl expr_warn_signed_unsigned_compare(c1_node *right,c1_node *left,c1_node *node)

{
  c1_u8 in_stack_00000010;
  
  diag_warning(3,0x12);
  expr_check_operand_conversion_unless_null(in_stack_00000010,left,right);
  return node;
}

