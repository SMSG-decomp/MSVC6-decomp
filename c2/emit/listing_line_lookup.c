uint32_t __fastcall listing_line_lookup(uint32_t line)

{
  uint uVar1;
  c2_listing_line *pcVar2;
  c2_listing_line *pcVar3;
  
  if (g_listing_line_list->line != line) {
    if (line <= g_listing_line_cursor->line) {
      g_listing_line_cursor = g_listing_line_list;
    }
    uVar1 = g_listing_line_cursor->next->line;
    pcVar2 = g_listing_line_cursor->next;
    while (pcVar3 = pcVar2, uVar1 < line) {
      pcVar2 = pcVar3->next;
      uVar1 = pcVar2->line;
      g_listing_line_cursor = pcVar3;
    }
    return g_listing_line_cursor->line;
  }
  return g_listing_line_list->line - 1;
}

