void __cdecl include_record_set_name(c1xx_browse_record *rec)

{
  char *pcVar1;
  int *position;
  
  rec->flags = rec->flags | 2;
  position = &g_region_source_position;
  if (g_use_instantiation_position == '\0') {
    position = &g_token_position;
  }
  pcVar1 = pp_position_file_name(position);
  pcVar1 = mem_xstrdup(pcVar1);
  rec->name = pcVar1;
  rec->name_record = (fe_name *)0x0;
  return;
}

