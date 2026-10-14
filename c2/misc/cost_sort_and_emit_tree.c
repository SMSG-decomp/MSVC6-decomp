c2_node * __fastcall cost_sort_and_emit_tree(c2_tuple *t)

{
  c2_tuple *t_00;
  c2_node *node;
  c2_node *pcVar1;
  
  t_00 = compute_tree_cost_and_sort(t);
  node = emit_tree_as_tuples(t_00);
  pcVar1 = node;
  if ((1 << (node->kind & 0x1f) & 0xffeU) != 0) {
    pcVar1 = *(c2_node **)(node[1].op + 0x14);
    node_free(node);
  }
  return pcVar1;
}

