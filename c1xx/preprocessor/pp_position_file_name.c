char * __fastcall pp_position_file_name(int *position)

{
  ushort *line_row;
  char *pcVar1;
  void *local_14;
  void *seh_handler;
  void *seh_scope_table;
  int seh_state;
  
  seh_state = -1;
  seh_scope_table = &g_pp_position_file_name_scopetable;
  seh_handler = &_except_handler3;
  local_14 = ExceptionList;
  if (g_line_map_cached_row.position == *position) {
    line_row = (ushort *)&g_line_map_cached_row;
    ExceptionList = &local_14;
  }
  else {
    ExceptionList = &local_14;
    line_row = (ushort *)pp_line_map_find_entry(&g_line_map,*position);
  }
  seh_state = 0;
  if (((c1_line_map_row *)line_row != (c1_line_map_row *)0x0) &&
     (((c1_line_map_row *)line_row)->file != (fe_file_record *)0x0)) {
    ExceptionList = local_14;
    return ((c1_line_map_row *)line_row)->file->name->text;
  }
  pcVar1 = misc_string_get(0x133);
  ExceptionList = local_14;
  return pcVar1;
}

