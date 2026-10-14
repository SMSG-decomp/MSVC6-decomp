int __fastcall lex_line_number_of_position(int *pos)

{
  fe_line_map_row *pfVar1;
  
  if (g_line_map_cached_row.position != *pos) {
    pfVar1 = pp_line_map_find_entry(&g_line_map,*pos);
    return (pfVar1->line - pfVar1->position) + *pos;
  }
  return (g_line_map_cached_row.line - g_line_map_cached_row.position) + *pos;
}

