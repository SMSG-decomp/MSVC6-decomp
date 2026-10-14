void __cdecl pp_line_output_reset(void)

{
  ushort *line_row;
  
  file_seek_current_source(0);
  if (g_line_map_cached_row.position == g_token_position) {
    line_row = (ushort *)&g_line_map_cached_row;
  }
  else {
    line_row = (ushort *)pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  g_lex_position = g_lex_position + 1;
  vector_push_triple((int *)&g_line_map,g_lex_position,0,(int)((c1_line_map_row *)line_row)->file);
  g_token_position = g_lex_position;
  g_input_file->position = g_lex_position;
  g_pp_cond_depth = g_input_file->cond_depth;
  g_input_ptr = g_input_file->buffer;
  g_input_file->last_read = 0;
  g_input_file->block_offset = 0;
  g_input_file->flags = g_input_file->flags & 0xfe;
  g_input_file->flags = g_input_file->flags & 0xfb;
  file_read_or_fatal();
  g_input_ptr = g_input_ptr + -1;
  *g_input_ptr = 10;
  return;
}

