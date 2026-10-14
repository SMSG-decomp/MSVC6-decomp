void __fastcall listing_collect_lines(c2_function *fn)

{
  c2_listing_source_file *pcVar1;
  c2_tuple *pcVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  g_listing_line_cursor = (c2_listing_line *)0x0;
  g_listing_line_list = (c2_listing_line *)0x0;
  g_listing_seek_mark_offset = 0;
  g_listing_seek_mark_line = 0;
  for (pcVar1 = g_listing_source_files; pcVar1 != (c2_listing_source_file *)0x0;
      pcVar1 = pcVar1->next) {
    pcVar1->lines = (c2_listing_line *)0x0;
  }
  uVar4 = 0;
  g_current_line_abs = 0;
  for (pcVar2 = fn->cfg->first->head; pcVar2 != (c2_tuple *)0x0; pcVar2 = pcVar2->next) {
    if (pcVar2->line != 0) {
      g_current_line_abs = line_to_file_line(fn->line_base + (uint)pcVar2->line,&g_cur_source_file);
      if (g_cur_source_file != g_listing_last_source_name) {
        listing_open_source_file(g_cur_source_file);
        g_listing_last_source_name = g_cur_source_file;
        listing_line_insert(g_current_line_abs - 1);
      }
      uVar3 = g_current_line_abs;
      if (uVar4 != g_current_line_abs) {
        listing_line_insert(g_current_line_abs);
        uVar4 = uVar3;
      }
    }
  }
  return;
}

