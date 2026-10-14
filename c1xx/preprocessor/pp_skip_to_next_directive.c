char __cdecl pp_skip_to_next_directive(void)

{
  byte bVar1;
  
  if ((((g_compile_flags_c8 & 0x32000000) == 0) &&
      (((((g_compile_flags_c8 & 0x40000000) == 0 || (((byte)g_compile_flags_cc & 8) != 0)) ||
        ((g_compile_flags_c4 & 0x200) != 0)) && (((byte)g_compile_flags_cc & 0x10) == 0)))) &&
     (((g_compile_flags_c8 & 0x4000000) == 0 || ((g_compile_flags_c4 & 0x8000) != 0)))) {
    g_context_arena_index = 5;
    g_expr_arena_index = g_context_arena_index;
    if (((byte)g_compile_flags_cc & 1) != 0) {
      g_expr_arena_index = 4;
      g_context_arena_index = g_expr_arena_index;
    }
  }
  else {
    g_expr_arena_index = 0;
    g_context_arena_index = g_expr_arena_index;
  }
  do {
    bVar1 = g_char_flags[*g_input_ptr];
    while ((bVar1 & 0x80) == 0) {
      bVar1 = g_char_flags[g_input_ptr[1]];
      g_input_ptr = g_input_ptr + 1;
    }
    do {
      bVar1 = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
    } while (g_char_class[bVar1] == '\x01');
    if ((g_char_flags[bVar1] & 0x20) == 0) {
      bVar1 = lex_skip_comment(bVar1);
    }
    switch(g_char_class[bVar1]) {
    case '\x05':
      g_lex_position = g_lex_position + 1;
      g_token_position = g_lex_position;
      if (g_opt_E_preprocess != 0) {
        fputc(10,g_pp_output_stream);
      }
      do {
        bVar1 = *g_input_ptr;
        g_input_ptr = g_input_ptr + 1;
      } while (g_char_class[bVar1] == '\x01');
      if ((g_char_flags[bVar1] & 0x20) == 0) {
        bVar1 = lex_skip_comment(bVar1);
      }
      if (bVar1 == 0x23) {
        do {
          bVar1 = *g_input_ptr;
          g_input_ptr = g_input_ptr + 1;
        } while (g_char_class[bVar1] == '\x01');
        if ((g_char_flags[bVar1] & 0x20) == 0) {
          bVar1 = lex_skip_comment(bVar1);
        }
        if ((g_char_flags[bVar1] & 1) != 0) {
          lex_scan_identifier(bVar1);
          if (((g_compile_flags_c8 & 0x32000000) == 0) &&
             (((((g_compile_flags_c8 & 0x40000000) == 0 || (((byte)g_compile_flags_cc & 8) != 0)) ||
               ((g_compile_flags_c4 & 0x200) != 0)) &&
              ((((byte)g_compile_flags_cc & 0x10) == 0 &&
               (((g_compile_flags_c8 & 0x4000000) == 0 || ((g_compile_flags_c4 & 0x8000) != 0)))))))
             ) {
            g_context_arena_index = 5;
            if (((byte)g_compile_flags_cc & 1) != 0) {
              g_context_arena_index = 4;
            }
          }
          else {
            g_context_arena_index = 0;
          }
          g_expr_arena_index = g_context_arena_index;
          bVar1 = pp_directive_lookup_name(g_last_name->text);
          return bVar1;
        }
      }
      g_input_ptr = g_input_ptr + -1;
      break;
    case '\x15':
    case '\x16':
      lex_skip_to_char(bVar1);
      break;
    case '#':
      lex_skip_mbcs_trail_byte();
    }
  } while( true );
}

