c1_node * __cdecl pm_null_vi_data_pointer(c1_type *type)

{
  c1_node *pcVar1;
  c1_node *right;
  
  pcVar1 = tree_new_int_constant(-1);
  right = tree_new_int_constant(0);
  pcVar1 = pm_spill_vi_data_pointer(type,right,pcVar1);
  return pcVar1;
}

