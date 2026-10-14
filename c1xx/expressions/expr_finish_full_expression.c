int __cdecl expr_finish_full_expression(int tree)

{
  c1_value_cell *dtors;
  void *local_8;
  void *local_4;
  
  local_8 = (void *)0x0;
  local_4 = (void *)0x0;
  if (tree != 0) {
    if (g_flow_state_abandoned == '\0') {
      dtors = expr_take_pending_destructor_list();
      if (dtors != (c1_value_cell *)0x0) {
        tree = (int)tree_new_default_arg_dtor_list((c1_node *)tree,dtors);
      }
      expr_collect_temporary_leaves((int *)&local_8,(c1_node *)tree);
      if (local_8 != (void *)0x0) {
        tree = (int)tree_new_default_arg_key_list((c1_node *)tree,local_8);
      }
      eh_collect_state_markers((int *)&local_4,(c1_node *)tree,'\0');
      if (local_4 != (void *)0x0) {
        tree = (int)tree_new_eh_states_list((c1_node *)tree,local_4);
      }
    }
    return (int)(c1_node *)tree;
  }
  return 0;
}

