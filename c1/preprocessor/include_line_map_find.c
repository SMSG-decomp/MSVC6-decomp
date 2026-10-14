int * __thiscall include_line_map_find(void *line_map,int line)

{
  fe_line_map_row *pfVar1;
  
  pfVar1 = (fe_line_map_row *)((int)line_map + 0x10);
  if (pfVar1->position != line) {
    pfVar1 = pp_line_map_find_entry((fe_line_map *)((int)line_map + 4),line);
  }
  return &pfVar1->position;
}

