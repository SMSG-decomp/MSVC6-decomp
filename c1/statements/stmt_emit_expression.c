void __cdecl stmt_emit_expression(c1_node *node)

{
  if (g_error_count == 0) {
    il_emit_pragma_or_segment_record(0x24);
    il_emit_expression_tree(node);
    il_emit_tuple(0x4b,(c1_node *)0x0);
  }
  return;
}

