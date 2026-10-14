c1_node * __cdecl expr_build_cast_expression(c1_u8 op,int type_name,c1_node *operand)

{
  c1_node *pcVar1;
  
  if (type_name == 0) {
    return (c1_node *)0x0;
  }
  if (operand != (c1_node *)0x0) {
    if (operand->op != 0x98) {
      pcVar1 = expr_build_cast(op,*(c1_type **)(type_name + 0x14),operand);
      return pcVar1;
    }
    diag_error(0x113,operand->left);
    return (c1_node *)0x0;
  }
  return (c1_node *)0x0;
}

