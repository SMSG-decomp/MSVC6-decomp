c1_node * fold_float_constant_logical_and(void)

{
  int iVar1;
  c1_node *pcVar2;
  void *in_stack_00000020;
  void *in_stack_00000024;
  
  iVar1 = float_const_compare_mask(6,in_stack_00000020,&g_float_zero);
  if (iVar1 != 0) {
    iVar1 = float_const_compare_mask(6,in_stack_00000024,&g_float_zero);
    if (iVar1 != 0) {
      g_constant_value = 1;
      goto LAB_1046a5da;
    }
  }
  g_constant_value = 0;
LAB_1046a5da:
  g_constant_value_high = 0;
  pcVar2 = tree_new_constant(g_type_int,&g_constant_value,g_expr_arena_index);
  return pcVar2;
}

