void __cdecl pp_block_comment_dispatch(void)

{
  code *fputc_fn;
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  
  fputc_fn = fputc_exref;
  if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
    do {
      while( true ) {
        while( true ) {
          while( true ) {
            uVar2 = (uint)*g_input_ptr;
            bVar1 = g_char_flags[uVar2];
            while (g_input_ptr = g_input_ptr + 1, (bVar1 & 0x40) != 0) {
              uVar2 = (uint)*g_input_ptr;
              bVar1 = g_char_flags[uVar2];
            }
            if (uVar2 != 0) break;
            lex_buffer_refill();
          }
          if (uVar2 != 10) break;
          g_lex_position = g_lex_position + 1;
          g_token_position = g_lex_position;
          if (g_opt_E_preprocess != 0) {
            pp_skip_line_whitespace_fragment_newline('#',fputc_fn);
            return;
          }
        }
        if (uVar2 == 0x2a) break;
        if (g_char_class[uVar2] == '#') {
          pp_skip_line_tokens('#',fputc_fn);
          return;
        }
      }
      do {
        while( true ) {
          bVar1 = *g_input_ptr;
          while( true ) {
            uVar2 = (uint)bVar1;
            g_input_ptr = g_input_ptr + 1;
            if (uVar2 != 0x2a) break;
            bVar1 = *g_input_ptr;
          }
          if (uVar2 == 0x2f) {
            return;
          }
          if (uVar2 != 0) break;
          lex_buffer_refill();
        }
        if (uVar2 != 0x5c) {
          if (g_char_class[uVar2] == '#') {
            lex_skip_mbcs_trail_byte();
          }
          g_input_ptr = g_input_ptr + -1;
          break;
        }
        uVar2 = lex_buffer_refill();
      } while ((uVar2 & 0x10) == 0);
    } while( true );
  }
  fwrite("/*",2,1,g_pp_output_stream);
LAB_1045bc66:
  bVar1 = *g_input_ptr;
  uVar2 = (uint)bVar1;
  pbVar4 = g_input_ptr + 1;
  switch(g_char_class[uVar2]) {
  case '\0':
    if (*g_input_ptr != 0x3f) {
      if (*g_input_ptr == 0x5c) {
        g_input_ptr = pbVar4;
        putchar(0x5c);
        lex_line_splice();
      }
      else {
        g_input_ptr = pbVar4;
        lex_buffer_refill();
      }
      goto LAB_1045bc66;
    }
    g_input_ptr = pbVar4;
    uVar3 = lex_trigraph();
    pbVar4 = g_input_ptr;
    if ((uVar3 & 0x40) == 0) goto LAB_1045bc66;
    break;
  case '\x01':
    g_input_ptr = pbVar4;
    if (bVar1 != 0xd) {
      fputc(uVar2,g_pp_output_stream);
    }
    goto LAB_1045bc66;
  case '\x05':
    g_lex_position = g_lex_position + 1;
    g_token_position = g_lex_position;
    break;
  case '\b':
    goto switchD_1045bc95_caseD_8;
  }
  g_input_ptr = pbVar4;
  fputc(uVar2,g_pp_output_stream);
  goto LAB_1045bc66;
switchD_1045bc95_caseD_8:
  bVar1 = *pbVar4;
  g_input_ptr = g_input_ptr + 2;
  if (g_char_class[bVar1] == '\0') {
    bVar1 = lex_next_significant_char(bVar1);
  }
  if (bVar1 == 0x2f) {
    fwrite("*/",2,1,g_pp_output_stream);
    return;
  }
  g_input_ptr = g_input_ptr + -1;
  fputc(uVar2,g_pp_output_stream);
  goto LAB_1045bc66;
}

