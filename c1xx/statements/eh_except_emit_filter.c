void __cdecl eh_except_emit_filter(c1_node *filter)

{
  if (0 < g_seh_finally_depth) {
    diag_error(0x2be);
    g_seh_except_depth = g_seh_except_depth + 1;
    return;
  }
  il_emit_pragma_or_segment_record(0x24);
  il_emit_expression_tree(filter);
  il_emit_tuple(0x8d,filter);
  g_seh_except_depth = g_seh_except_depth + 1;
  return;
}

