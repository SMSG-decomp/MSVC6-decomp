void pp_skip_line_comments(void)

{
  byte c;
  byte bVar1;
  uint uVar2;
  bool bVar3;
  byte bVar4;
  uint local_10;
  
  do {
    c = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
  } while (g_char_class[c] == '\x01');
  if ((g_char_flags[c] & 0x20) == 0) {
    c = lex_skip_comment(c);
  }
  local_10 = (uint)c;
  uVar2 = 0;
  bVar4 = 0;
  block_list_rewind(g_pch_directive_text_blocks);
LAB_1062ca84:
  switch(g_char_class[local_10]) {
  case '\0':
    lex_put_string_byte(c,g_pch_directive_text_blocks);
    c = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    break;
  case '\x01':
switchD_1062caa3_caseD_1:
    if (bVar4 != 0) break;
    do {
      c = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
    } while (g_char_class[c] == '\x01');
    if ((g_char_flags[c] & 0x20) == 0) {
      c = lex_skip_comment(c);
    }
    local_10 = (uint)c;
    if (c != 10) {
      lex_put_string_byte(0x20,g_pch_directive_text_blocks);
    }
    goto LAB_1062ca84;
  case '\x03':
    if ((g_ms_extensions == '\0') && (g_pch_option_block == 0)) {
      bVar1 = lex_get_char();
      if (bVar1 == 0x2f) {
        bVar1 = lex_get_char();
        if (bVar1 != 0x2a) {
          g_input_ptr = g_input_ptr + -1;
          diag_warning(4,1);
          goto LAB_1062cbec;
        }
        diag_warning(4,0xb3);
        if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
          g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
          pp_skip_block_comment();
          g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
          bVar3 = false;
        }
        else {
          g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
          pp_output_skip_comment();
          g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
          bVar3 = false;
        }
      }
      else {
        g_input_ptr = g_input_ptr + -1;
        bVar1 = lex_get_char();
        if (bVar1 == 0x2a) {
          g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
          pp_block_comment_dispatch();
          goto LAB_1062cc61;
        }
        g_input_ptr = g_input_ptr + -1;
        bVar3 = false;
      }
    }
    else {
      bVar1 = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
      if (g_char_class[bVar1] == '\0') {
        bVar1 = lex_next_significant_char(bVar1);
      }
      if (bVar1 == 0x2f) {
LAB_1062cbec:
        g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
        pp_output_copy_comment();
LAB_1062cc61:
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
        bVar3 = true;
      }
      else {
        bVar1 = g_input_ptr[-1];
        if (g_char_class[bVar1] == '\0') {
          bVar1 = lex_next_significant_char(bVar1);
        }
        if (bVar1 == 0x2a) {
          if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
            g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
            pp_skip_block_comment();
          }
          else {
            g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
            pp_output_skip_comment();
          }
          goto LAB_1062cc61;
        }
        g_input_ptr = g_input_ptr + -1;
        bVar3 = false;
      }
    }
    if (bVar3) goto switchD_1062caa3_caseD_1;
    break;
  case '\x05':
    lex_put_string_byte(c,g_pch_directive_text_blocks);
    g_input_ptr = g_input_ptr + -1;
    return;
  case '\x15':
    bVar3 = uVar2 != 2;
    uVar2 = -(uint)bVar3 & 2;
    bVar4 = -bVar3 & 2;
    break;
  case '\x16':
    bVar4 = uVar2 != 1;
    uVar2 = (uint)bVar4;
  }
  lex_put_string_byte(c,g_pch_directive_text_blocks);
  c = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  local_10 = (uint)c;
  goto LAB_1062ca84;
}

