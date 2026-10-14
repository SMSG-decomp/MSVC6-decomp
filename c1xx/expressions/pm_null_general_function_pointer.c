c1_node * __cdecl pm_null_general_function_pointer(c1_type *type)

{
  c1_node *pcVar1;
  c1_node *right2;
  c1_node *right;
  int value;
  
  pcVar1 = tree_new_int_constant(-1);
  value = 0;
  right2 = tree_new_int_constant(0);
  right = tree_new_null_member_pointer(type);
  pcVar1 = pm_spill_general_function_pointer(type,right,right2,value,pcVar1);
  return pcVar1;
}

