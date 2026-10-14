c1_node * __cdecl expr_build_eh_state_update(c1_node *left,c1_node *right,c1_symbol *sym)

{
  int value;
  c1_node *pcVar1;
  c1_node *left_00;
  
  if (left == (c1_node *)0x0) {
    left = tree_new_int_constant(0);
  }
  if (right == (c1_node *)0x0) {
    right = tree_new_int_constant(0);
  }
  value = eh_check_state_count(sym);
  pcVar1 = tree_new_binary('7',left,right);
  left_00 = tree_new_int_constant(value);
  pcVar1 = tree_new_binary_typed_right(0xc1,left_00,pcVar1);
  return pcVar1;
}

