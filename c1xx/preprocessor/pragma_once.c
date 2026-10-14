void __cdecl pragma_once(void)

{
  bool bVar1;
  ushort *line_row;
  uint *puVar2;
  
  if (g_include_depth != 0) {
    bVar1 = pp_include_top_is_pseudo_file();
    if (!bVar1) {
      if (g_line_map_cached_row.position == g_token_position) {
        line_row = (ushort *)&g_line_map_cached_row;
      }
      else {
        line_row = (ushort *)pp_line_map_find_entry(&g_line_map,g_token_position);
      }
      puVar2 = &((c1_line_map_row *)line_row)->file->entity;
      *puVar2 = *puVar2 & 0xffffff | 0x1000000;
    }
  }
  return;
}

