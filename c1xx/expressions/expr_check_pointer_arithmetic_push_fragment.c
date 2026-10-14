c1_node * __cdecl expr_check_pointer_arithmetic_push_fragment(c1_type *right_type,uint op_cell)

{
  diag_error_C2296_or_C2297((c1_u8)op_cell,2,right_type);
  return (c1_node *)0x0;
}

