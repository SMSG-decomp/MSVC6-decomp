int asm_print_file_header(void)

{
  if (g_listing_last_source_name != g_cur_source_file) {
    g_listing_last_source_name = g_cur_source_file;
    asm_printf("; File %s",g_cur_source_file);
    g_asm_column = 0;
    asm_printf(g_asm_newline);
    if (g_opt_listing_source != 0) {
      listing_open_source_file(g_cur_source_file);
    }
    return 1;
  }
  return 0;
}

