void __cdecl pch_directive_reopen_source(void)

{
  ushort *line_row;
  char *file;
  ushort *line_row_2;
  int b;
  uint hash;
  int mode;
  int arg;
  int report;
  
  if (g_line_map_cached_row.position == g_token_position) {
    line_row = (ushort *)&g_line_map_cached_row;
  }
  else {
    line_row = (ushort *)pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  b = (((c1_line_map_row *)line_row)->line - ((c1_line_map_row *)line_row)->position) +
      g_token_position;
  block_list_rewind(g_pch_directive_text_blocks);
  if (g_injected_text_list != g_pch_directive_text_blocks) {
    free_list_destroy((c1_byte_block_list **)&g_injected_text_list);
    g_injected_text_list = g_pch_directive_text_blocks;
  }
  report = 0;
  arg = 0;
  mode = 2;
  hash = 0;
  file = pp_position_file_name(&g_token_position);
  file_open_or_fatal(file,hash,mode,arg,report);
  if (g_line_map_cached_row.position == g_token_position) {
    line_row_2 = (ushort *)&g_line_map_cached_row;
  }
  else {
    line_row_2 = (ushort *)pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  g_lex_position = g_lex_position + 1;
  vector_push_triple((int *)&g_line_map,g_lex_position,b,(int)((c1_line_map_row *)line_row_2)->file)
  ;
  g_token_position = g_lex_position;
  g_input_ptr = g_input_ptr + 1;
  return;
}

