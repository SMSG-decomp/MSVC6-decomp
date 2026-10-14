void __cdecl pp_skip_line_tokens(char lead_class,c1_fputc_fn fputc_fn)

{
  byte bVar1;
  uint uVar2;
  
  lex_skip_mbcs_trail_byte();
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
          pp_skip_line_whitespace_fragment_newline(lead_class,fputc_fn);
          return;
        }
      }
      if (uVar2 == 0x2a) break;
      if (g_char_class[uVar2] == lead_class) {
        pp_skip_line_tokens(lead_class,fputc_fn);
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
        if (g_char_class[uVar2] == lead_class) {
          lex_skip_mbcs_trail_byte();
        }
        g_input_ptr = g_input_ptr + -1;
        break;
      }
      uVar2 = lex_buffer_refill();
    } while ((uVar2 & 0x10) == 0);
  } while( true );
}

