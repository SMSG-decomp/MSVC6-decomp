void __cdecl stmt_emit_merged_expression(c1_node *tree)

{
  if (tree != (c1_node *)0x0) {
    eh_merge_state_markers(tree);
    stmt_emit_expression(tree);
  }
  return;
}

