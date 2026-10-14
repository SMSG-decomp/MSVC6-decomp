void __cdecl pragma_once(void)

{
  bool bVar1;
  fe_line_map_row *pfVar2;
  uint *puVar3;
  
  if (g_include_depth != 0) {
    bVar1 = pp_include_top_is_pseudo_file();
    if (!bVar1) {
      if (g_line_map_cached_row.position == g_token_position) {
        pfVar2 = &g_line_map_cached_row;
      }
      else {
        pfVar2 = pp_line_map_find_entry(&g_line_map,g_token_position);
      }
      puVar3 = &pfVar2->file->entity;
      *puVar3 = *puVar3 & 0xffffff | 0x1000000;
    }
  }
  return;
}

