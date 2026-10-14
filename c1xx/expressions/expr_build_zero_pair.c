c1_node * __cdecl expr_build_zero_pair(void)

{
  c1_node *pcVar1;
  c1_node *object;
  longlong zero_value;
  
  zero_value._0_4_ = 0;
  zero_value._4_4_ = 0;
  pcVar1 = tree_new_constant(g_type_int,&zero_value,g_expr_arena_index);
  object = tree_new_constant(g_type_int,&zero_value,g_expr_arena_index);
  pcVar1 = expr_build_throw_intrinsic_call(object,pcVar1);
  return pcVar1;
}

