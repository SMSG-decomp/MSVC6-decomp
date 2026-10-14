void __fastcall line_map_clear_cached_row(c1_line_map_state *map)

{
  (map->cached).position = 0;
  (map->cached).line = 0;
  (map->cached).file = (fe_file_record *)0x0;
  return;
}

