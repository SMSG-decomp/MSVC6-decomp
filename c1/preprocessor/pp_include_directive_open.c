c1_u8 * __cdecl pp_include_directive_open(byte *name,char angle)

{
  int iVar1;
  fe_line_map_row *pfVar2;
  c1_token *pcVar3;
  
  iVar1 = pp_include_open_file_2(name,angle);
  if (iVar1 < 0) {
    return g_token_newline;
  }
  if (g_line_map_cached_row.position != g_token_position) {
    pfVar2 = pp_line_map_find_entry(&g_line_map,g_token_position);
    pcVar3 = pp_include_directive_token((int)pfVar2->file);
    return &pcVar3->code;
  }
  pcVar3 = pp_include_directive_token((int)g_line_map_cached_row.file);
  return &pcVar3->code;
}

