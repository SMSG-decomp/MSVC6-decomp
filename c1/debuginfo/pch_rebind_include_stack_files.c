void __cdecl pch_rebind_include_stack_files(void)

{
  fe_line_map_row *pfVar1;
  fe_input_file *pfVar2;
  int iVar3;
  
  if (-1 < g_include_depth) {
    iVar3 = g_include_depth + 1;
    pfVar2 = g_input_file;
    do {
      if (g_line_map_cached_row.position == g_token_position) {
        pfVar1 = &g_line_map_cached_row;
      }
      else {
        pfVar1 = pp_line_map_find_entry(&g_line_map,g_token_position);
      }
      iVar3 = iVar3 + -1;
      pfVar2->file = pfVar1->file;
      pfVar2 = pfVar2->next;
    } while (iVar3 != 0);
  }
  return;
}

