c1_node * __cdecl expr_build_null_guarded(c1_node *ptr,c1_node *expr)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_type *type;
  
  eh_mark_state_nodes_in_tree(expr);
  type = g_type_int;
  pcVar1 = tree_new_int_constant(0);
  pcVar1 = tree_new_node('L',ptr,pcVar1,type);
  pcVar2 = tree_new_int_constant(0);
  pcVar2 = tree_new_binary('6',expr,pcVar2);
  pcVar1 = tree_new_node('V',pcVar1,pcVar2,expr->type);
  return pcVar1;
}

