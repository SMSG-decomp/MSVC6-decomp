char * __fastcall pp_position_file_name(int *position)

{
  fe_line_map_row *pfVar1;
  char *pcVar2;
  void *local_14;
  undefined *puStack_10;
  sehtable_entry *psStack_c;
  int try_level;
  
  try_level = -1;
  psStack_c = &g_pp_position_file_name_scopetable;
  puStack_10 = &_except_handler3;
  local_14 = ExceptionList;
  if (g_line_map_cached_row.position == *position) {
    pfVar1 = &g_line_map_cached_row;
    ExceptionList = &local_14;
  }
  else {
    ExceptionList = &local_14;
    pfVar1 = pp_line_map_find_entry(&g_line_map,*position);
  }
  try_level = 0;
  if ((pfVar1 != (fe_line_map_row *)0x0) && (pfVar1->file != (fe_file_record *)0x0)) {
    ExceptionList = local_14;
    return pfVar1->file->name->text;
  }
  pcVar2 = misc_string_get(0x133);
  ExceptionList = local_14;
  return pcVar2;
}

