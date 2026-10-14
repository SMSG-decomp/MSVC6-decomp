int __fastcall lex_line_number_of_position(int *pos)

{
  c1_line_map_row *pcVar1;
  
  if (g_line_map_cached_row.position != *pos) {
    pcVar1 = pp_line_map_find_entry(&g_line_map,*pos);
    return (pcVar1->line - pcVar1->position) + *pos;
  }
  return (g_line_map_cached_row.line - g_line_map_cached_row.position) + *pos;
}

