void __cdecl eh_except_emit_filter(c1_node *node)

{
  if (g_seh_finally_depth < 1) {
    il_emit_pragma_or_segment_record(0x24);
    il_emit_expression_tree(node);
    il_emit_tuple(0x8d,node);
    g_seh_except_depth = g_seh_except_depth + 1;
    return;
  }
  diag_error(0x2be);
  g_seh_except_depth = g_seh_except_depth + 1;
  return;
}

