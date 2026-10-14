void x87_rewrite_stack_operands_case_m2(int dst_depth,c2_operand *dst)

{
  int iVar1;
  c2_tuple *in_stack_00000020;
  c2_tuple *in_stack_00000024;
  
  iVar1 = g_x87_tos - dst_depth;
  g_x87_tos = g_x87_tos + -2;
  g_x87_stack_ids[iVar1] = dst->rank;
  x87_rewrite_stack_operands_default(dst_depth,in_stack_00000020,in_stack_00000024);
  return;
}

