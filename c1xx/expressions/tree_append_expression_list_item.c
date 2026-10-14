c1_node * __cdecl tree_append_expression_list_item(c1_node *right,c1_node *node)

{
  c1_value_cell *dtors;
  c1_node *pcVar1;
  
  if (node == (c1_node *)0x0) {
    return right;
  }
  dtors = expr_take_pending_destructor_list();
  if (dtors != (c1_value_cell *)0x0) {
    node = tree_new_initializer_dtor_list(node,dtors);
  }
  pcVar1 = tree_new_node('`',node,right,(c1_type *)0x0);
  if (right == (c1_node *)0x0) {
    pcVar1->link = pcVar1;
    node->link = pcVar1;
    return pcVar1;
  }
  pcVar1->link = right->link;
  right->link = pcVar1;
  node->link = pcVar1;
  return pcVar1;
}

