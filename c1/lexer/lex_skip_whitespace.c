void lex_skip_whitespace(void)

{
  c1_u8 cVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  
  pbVar4 = g_input_ptr;
  do {
    g_input_ptr = pbVar4;
    pbVar4 = g_input_ptr + 1;
    switch(g_char_class[*g_input_ptr]) {
    case '\0':
      g_input_ptr = pbVar4;
      iVar3 = lex_buffer_refill();
      pbVar4 = g_input_ptr;
      if ((iVar3 == 1) && (*g_input_ptr == 0)) {
        return;
      }
      break;
    case '\x03':
      if ((g_ms_extensions == '\0') && (g_pch_option_block == 0)) {
        bVar2 = *pbVar4;
        g_input_ptr = g_input_ptr + 2;
        if (g_char_class[bVar2] == '\0') {
          bVar2 = lex_next_significant_char(bVar2);
        }
        if (bVar2 != 0x2f) {
          bVar2 = g_input_ptr[-1];
          cVar1 = g_char_class[bVar2];
          goto joined_r0x1062dbdc;
        }
        bVar2 = *g_input_ptr;
        g_input_ptr = g_input_ptr + 1;
        if (g_char_class[bVar2] == '\0') {
          bVar2 = lex_next_significant_char(bVar2);
        }
        if (bVar2 != 0x2a) {
          g_input_ptr = g_input_ptr + -1;
          diag_warning(4,1);
          goto lex_skip_line_comment_check;
        }
        diag_warning(4,0xb3);
      }
      else {
        bVar2 = *pbVar4;
        g_input_ptr = g_input_ptr + 2;
        if (g_char_class[bVar2] == '\0') {
          bVar2 = lex_next_significant_char(bVar2);
        }
        if (bVar2 == 0x2f) {
lex_skip_line_comment_check:
          g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
          pp_output_copy_comment();
          g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
          pbVar4 = g_input_ptr;
          break;
        }
        bVar2 = g_input_ptr[-1];
        cVar1 = g_char_class[bVar2];
joined_r0x1062dbdc:
        if (cVar1 == '\0') {
          bVar2 = lex_next_significant_char(bVar2);
        }
        if (bVar2 != 0x2a) {
          g_input_ptr = g_input_ptr + -1;
          pbVar4 = g_input_ptr;
          break;
        }
      }
      if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
        g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
        pp_skip_block_comment();
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
        pbVar4 = g_input_ptr;
      }
      else {
        g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
        pp_output_skip_comment();
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
        pbVar4 = g_input_ptr;
      }
      break;
    case '\x05':
      return;
    case '#':
      g_input_ptr = pbVar4;
      lex_skip_mbcs_trail_byte();
      pbVar4 = g_input_ptr;
    }
  } while( true );
}

