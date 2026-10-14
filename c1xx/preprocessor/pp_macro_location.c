void __cdecl pp_macro_location(int n)

{
  int b;
  ushort *line_row;
  
  b = g_macro_invocation_line;
  if (g_line_map_cached_row.position == g_token_position) {
    line_row = (ushort *)&g_line_map_cached_row;
  }
  else {
    line_row = (ushort *)pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  g_lex_position = g_lex_position + 1;
  vector_push_triple((int *)&g_line_map,g_lex_position,b,(int)((c1_line_map_row *)line_row)->file);
  g_token_position = g_lex_position;
  diag_fatal_simple(n);
}

