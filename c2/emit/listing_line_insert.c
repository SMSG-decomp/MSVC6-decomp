void __fastcall listing_line_insert(uint32_t line)

{
  c2_listing_line **ppcVar1;
  c2_listing_line *pcVar2;
  c2_listing_line *pcVar3;
  
  if ((g_listing_line_list == (c2_listing_line *)0x0) || (line < g_listing_line_list->line)) {
    g_listing_line_cursor = arena_alloc(4,8);
    g_listing_line_cursor->line = line;
    g_listing_line_cursor->next = g_listing_line_list;
    g_listing_line_list = g_listing_line_cursor;
  }
  else {
    if (line < g_listing_line_cursor->line) {
      g_listing_line_cursor = g_listing_line_list;
    }
    pcVar2 = g_listing_line_cursor->next;
    while ((pcVar3 = pcVar2, pcVar3 != (c2_listing_line *)0x0 && (pcVar3->line <= line))) {
      g_listing_line_cursor = pcVar3;
      pcVar2 = pcVar3->next;
    }
    if (g_listing_line_cursor->line != line) {
      pcVar3 = arena_alloc(4,8);
      pcVar2 = g_listing_line_cursor;
      pcVar3->line = line;
      ppcVar1 = &g_listing_line_cursor->next;
      g_listing_line_cursor = pcVar3;
      pcVar3->next = *ppcVar1;
      pcVar2->next = pcVar3;
      return;
    }
  }
  return;
}

