byte __cdecl lex_skip_comment(byte c)

{
  c1_u8 cVar1;
  byte bVar2;
  int iVar3;
  
  do {
    if (c == 0x2f) {
      bVar2 = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
      if (g_char_class[bVar2] == '\0') {
        bVar2 = lex_next_significant_char(bVar2);
      }
      if (bVar2 == 0x2f) {
        g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
        pp_output_copy_comment();
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
      }
      else {
        bVar2 = g_input_ptr[-1];
        if (g_char_class[bVar2] == '\0') {
          bVar2 = lex_next_significant_char(bVar2);
        }
        if (bVar2 != 0x2a) {
          g_input_ptr = g_input_ptr + -1;
          return 0x2f;
        }
        if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
          g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
          pp_skip_block_comment();
          g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
        }
        else {
          g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
          pp_output_skip_comment();
          g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
        }
      }
    }
    else if (c == 0x5c) {
      iVar3 = lex_line_splice();
      if (iVar3 == 0) {
        bVar2 = lex_skip_comment_return(0);
        return bVar2;
      }
    }
    else {
      if ((c != 0) && (c != 0x1a)) {
        bVar2 = lex_skip_comment_return(c);
        return bVar2;
      }
      lex_buffer_refill();
    }
    c = *g_input_ptr;
    cVar1 = g_char_class[c];
    while( true ) {
      g_input_ptr = g_input_ptr + 1;
      if (cVar1 != '\x01') break;
      c = *g_input_ptr;
      cVar1 = g_char_class[c];
    }
    if ((g_char_flags[c] & 0x20) != 0) {
      g_input_ptr = g_input_ptr;
      return c;
    }
  } while( true );
}

