void __fastcall asm_print_source_lines(uint32_t line)

{
  uint line_00;
  int iVar1;
  int iVar2;
  char local_100 [256];
  
  if ((g_listing_line_cursor != (c2_listing_line *)0x0) &&
     (g_listing_line_list != (c2_listing_line *)0x0)) {
    line_00 = listing_line_lookup(line);
    g_asm_column = 0;
    asm_printf(g_asm_newline);
    while (line_00 = line_00 + 1, line_00 <= line) {
      iVar1 = listing_read_source_line(local_100,line_00);
      if (local_100[0] == '\0') {
        return;
      }
      iVar2 = asm_printf("; %-5lu: %s",line_00,local_100);
      g_asm_column = g_asm_column + iVar2;
      while ((iVar1 != 0 && (local_100[0] != '\0'))) {
        iVar1 = listing_read_source_line(local_100,line_00);
        iVar2 = asm_printf("%s",local_100);
        g_asm_column = g_asm_column + iVar2;
      }
    }
    g_asm_column = 0;
    asm_printf(g_asm_newline);
  }
  return;
}

