void __fastcall listing_begin(char *title)

{
  if ((g_opt_S == 0) && (g_opt_listing_code_bytes == 0)) {
    g_listing_on = 0;
    return;
  }
  g_listing_on = 1;
  g_asm_comment_char = asm_listing_comment_char();
  asm_print_listing_header(title);
  return;
}

