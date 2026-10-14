void __cdecl browse_record_set_file(c1_browse_record *rec)

{
  char *pcVar1;
  
  pcVar1 = pp_position_file_name(&g_token_position);
  pcVar1 = mem_xstrdup(pcVar1);
  rec->name = pcVar1;
  rec->name_record = (void *)0x0;
  return;
}

