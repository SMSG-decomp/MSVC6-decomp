void __cdecl lex_skip_whitespace_refill(uint comment_flag,uint comment_mask)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  
  pbVar3 = g_input_ptr;
code_r0x10462720:
  g_input_ptr = pbVar3;
  iVar2 = lex_buffer_refill();
  pbVar3 = g_input_ptr;
  if ((iVar2 == 1) && (*g_input_ptr == 0)) {
    return;
  }
  do {
    g_input_ptr = pbVar3;
    pbVar3 = g_input_ptr + 1;
    switch(g_char_class[*g_input_ptr]) {
    case '\0':
      goto code_r0x10462720;
    case '\x03':
      bVar1 = *pbVar3;
      g_input_ptr = g_input_ptr + 2;
      if (g_char_class[bVar1] == '\0') {
        bVar1 = lex_next_significant_char(bVar1);
      }
      if (bVar1 == 0x2f) {
        g_compile_flags_c4 = g_compile_flags_c4 | comment_flag;
        pp_output_copy_comment();
        g_compile_flags_c4 = g_compile_flags_c4 & comment_mask;
        pbVar3 = g_input_ptr;
      }
      else {
        bVar1 = g_input_ptr[-1];
        if (g_char_class[bVar1] == '\0') {
          bVar1 = lex_next_significant_char(bVar1);
        }
        if (bVar1 == 0x2a) {
          g_compile_flags_c4 = g_compile_flags_c4 | comment_flag;
          if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
            pp_skip_block_comment();
            g_compile_flags_c4 = g_compile_flags_c4 & comment_mask;
            pbVar3 = g_input_ptr;
          }
          else {
            pp_output_skip_comment();
            g_compile_flags_c4 = g_compile_flags_c4 & comment_mask;
            pbVar3 = g_input_ptr;
          }
        }
        else {
          g_input_ptr = g_input_ptr + -1;
          pbVar3 = g_input_ptr;
        }
      }
      break;
    case '\x05':
      return;
    case '#':
      g_input_ptr = pbVar3;
      lex_skip_mbcs_trail_byte();
      pbVar3 = g_input_ptr;
    }
  } while( true );
}

