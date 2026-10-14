c1_node * __cdecl expr_new_shared_temporary(c1_node *right)

{
  c1_node *pcVar1;
  c1_node *right_00;
  
  if (g_shared_temporary_key == 0) {
    g_shared_temporary_key = sym_new_local_key();
  }
  pcVar1 = tree_new_leaf_9c(g_shared_temporary_key,right->type);
  right_00 = tree_new_leaf_9c(g_shared_temporary_key,right->type);
  pcVar1 = tree_new_binary('4',pcVar1,right);
  pcVar1 = tree_new_node('7',pcVar1,right_00,right->type);
  return pcVar1;
}

