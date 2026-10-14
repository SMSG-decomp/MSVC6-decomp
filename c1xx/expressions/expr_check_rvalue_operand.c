c1_node * __cdecl expr_check_rvalue_operand(c1_node *node)

{
  c1_node *pcVar1;
  
  pcVar1 = expr_build_builtin_unary(0x3d,node);
  return pcVar1;
}

