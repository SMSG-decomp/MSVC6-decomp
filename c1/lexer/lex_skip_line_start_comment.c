int __cdecl lex_skip_line_start_comment(void)

{
  byte bVar1;
  
  bVar1 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  if (g_char_class[bVar1] == '\0') {
    bVar1 = lex_next_significant_char(bVar1);
  }
  if (bVar1 == 0x2f) {
    g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
    pp_output_copy_comment();
  }
  else {
    bVar1 = g_input_ptr[-1];
    if (g_char_class[bVar1] == '\0') {
      bVar1 = lex_next_significant_char(bVar1);
    }
    if (bVar1 != 0x2a) {
      g_input_ptr = g_input_ptr + -1;
      return 0;
    }
    if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
      g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
      pp_skip_block_comment();
    }
    else {
      g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
      pp_output_skip_comment();
    }
  }
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
  return 1;
}

