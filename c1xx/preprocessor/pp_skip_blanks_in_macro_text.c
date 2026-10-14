int __cdecl pp_skip_blanks_in_macro_text(void)

{
  c1_u8 cVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  
  iVar5 = 0;
  g_compile_flags_c4 = g_compile_flags_c4 & 0xffbfffff;
  g_macro_blanks_skipped = 0;
  do {
    while( true ) {
      pbVar4 = g_input_ptr + 1;
      cVar1 = g_char_class[*g_input_ptr];
      if (cVar1 == '\0') break;
      if (cVar1 != '\x01') {
        if (cVar1 != '\x05') goto LAB_10409c6f;
        if ((g_compile_flags_c4 & 0x8000) != 0) goto LAB_10409c7f;
        g_lex_position = g_lex_position + 1;
        g_token_position = g_lex_position;
        if (g_opt_E_preprocess != 0) {
          bVar2 = *g_input_ptr;
          g_input_ptr = pbVar4;
          fputc((uint)bVar2,g_pp_output_stream);
          pbVar4 = g_input_ptr;
        }
        g_input_ptr = pbVar4;
        g_compile_flags_c4 = g_compile_flags_c4 | 0x400000;
        pbVar4 = g_input_ptr;
      }
      g_input_ptr = pbVar4;
      g_macro_blanks_skipped = 1;
    }
    g_input_ptr = pbVar4;
    uVar3 = lex_buffer_refill();
    if ((uVar3 & 10) != 0) goto LAB_10409c7f;
    pbVar4 = g_input_ptr;
  } while ((uVar3 & 0xffffffaf) != 0);
LAB_10409c6f:
  g_input_ptr = pbVar4;
  iVar5 = 1;
  g_input_ptr = g_input_ptr + -1;
LAB_10409c7f:
  if (g_macro_blanks_skipped != 0) {
    if (g_macro_text_buffer_limit <= g_macro_text_cursor) {
      pp_define_check_size
                ((uint)g_macro_text_cursor,(int)g_macro_text_buffer,
                 (int *)&g_macro_text_buffer_limit);
    }
    if ((g_macro_text_buffer < g_macro_text_cursor) && (g_macro_text_cursor[-1] != ' ')) {
      *g_macro_text_cursor = ' ';
      g_macro_text_cursor = g_macro_text_cursor + 1;
    }
  }
  return iVar5;
}

