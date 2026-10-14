c1_u8 * __cdecl pp_include_open_and_push(byte *file,char angle)

{
  int iVar1;
  ushort *line_row;
  byte *token;
  c1_u8 *pcVar2;
  
  iVar1 = pp_include_open_file_2(file,angle);
  token = g_token_newline;
  if (-1 < iVar1) {
    if (g_line_map_cached_row.position == g_token_position) {
      line_row = (ushort *)&g_line_map_cached_row;
    }
    else {
      line_row = (ushort *)pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    token = pp_include_directive_token((int)((c1_line_map_row *)line_row)->file);
    if ((g_compile_flags_c8 & 0x4000000) != 0) {
      pragma_process_saved_tokens(token);
      pcVar2 = token_new_position_marker(0);
      return pcVar2;
    }
  }
  return token;
}

