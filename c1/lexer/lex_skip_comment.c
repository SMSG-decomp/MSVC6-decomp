byte __cdecl lex_skip_comment(byte c)

{
  c1_u8 cVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  
  do {
    if (c == 0x2f) {
      if ((g_ms_extensions == '\0') && (g_pch_option_block == 0)) {
        bVar3 = *g_input_ptr;
        g_input_ptr = g_input_ptr + 1;
        if (g_char_class[bVar3] == '\0') {
          bVar3 = lex_next_significant_char(bVar3);
        }
        if (bVar3 == 0x2f) {
          bVar3 = *g_input_ptr;
          g_input_ptr = g_input_ptr + 1;
          if (g_char_class[bVar3] == '\0') {
            bVar3 = lex_next_significant_char(bVar3);
          }
          if (bVar3 != 0x2a) {
            g_input_ptr = g_input_ptr + -1;
            diag_warning(4,1);
            goto lex_skip_comment_check_slash_star;
          }
          diag_warning(4,0xb3);
          if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
            g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
            pp_skip_block_comment();
          }
          else {
            g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
            pp_output_skip_comment();
          }
          g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
        }
        else {
          bVar3 = g_input_ptr[-1];
          if (g_char_class[bVar3] == '\0') {
            bVar3 = lex_next_significant_char(bVar3);
          }
          if (bVar3 == 0x2a) {
LAB_106095cb:
            if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
              g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
              pp_skip_block_comment();
              g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
              bVar2 = true;
            }
            else {
              g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
              pp_output_skip_comment();
              g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
              bVar2 = true;
            }
            goto LAB_10609614;
          }
          g_input_ptr = g_input_ptr + -1;
        }
LAB_10609693:
        bVar2 = false;
      }
      else {
        bVar3 = *g_input_ptr;
        g_input_ptr = g_input_ptr + 1;
        if (g_char_class[bVar3] == '\0') {
          bVar3 = lex_next_significant_char(bVar3);
        }
        if (bVar3 != 0x2f) {
          bVar3 = g_input_ptr[-1];
          if (g_char_class[bVar3] == '\0') {
            bVar3 = lex_next_significant_char(bVar3);
          }
          if (bVar3 == 0x2a) goto LAB_106095cb;
          g_input_ptr = g_input_ptr + -1;
          goto LAB_10609693;
        }
lex_skip_comment_check_slash_star:
        g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
        pp_output_copy_comment();
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
        bVar2 = true;
      }
LAB_10609614:
      if (!bVar2) {
        return 0x2f;
      }
    }
    else if (c == 0x5c) {
      iVar4 = lex_line_splice();
      if (iVar4 == 0) {
        return 0x5c;
      }
    }
    else {
      if ((c != 0) && (c != 0x1a)) {
        return c;
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
      return c;
    }
  } while( true );
}

