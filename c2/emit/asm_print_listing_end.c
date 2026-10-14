void asm_print_listing_end(void)

{
  g_asm_current_segment = (c2_fe_symbol *)asm_print_segment_end(g_asm_current_segment);
  asm_printf("END");
  g_asm_column = 0;
  asm_printf(g_asm_newline);
  return;
}

