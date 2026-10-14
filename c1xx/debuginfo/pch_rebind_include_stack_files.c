void __cdecl pch_rebind_include_stack_files(void)

{
  ushort *line_row;
  fe_input_file *pfVar1;
  int iVar2;
  
  if (-1 < g_include_depth) {
    iVar2 = g_include_depth + 1;
    pfVar1 = g_input_file;
    do {
      if (g_line_map_cached_row.position == g_token_position) {
        line_row = (ushort *)&g_line_map_cached_row;
      }
      else {
        line_row = (ushort *)pp_line_map_find_entry(&g_line_map,g_token_position);
      }
      iVar2 = iVar2 + -1;
      pfVar1->file = ((c1_line_map_row *)line_row)->file;
      pfVar1 = pfVar1->next;
    } while (iVar2 != 0);
  }
  return;
}

