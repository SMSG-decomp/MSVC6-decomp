void __fastcall line_map_clear_cached_row(c1_lex_position_record *position_record)

{
  (position_record->cached_row).position = 0;
  (position_record->cached_row).line = 0;
  (position_record->cached_row).file = (fe_file_record *)0x0;
  return;
}

