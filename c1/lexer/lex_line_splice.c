int __cdecl lex_line_splice(void)

{
  byte bVar1;
  byte *pbVar2;
  
  bVar1 = *g_input_ptr;
  pbVar2 = g_input_ptr;
  do {
    g_input_ptr = pbVar2 + 1;
    if (0xd < bVar1) {
      g_input_ptr = pbVar2;
      return 0;
    }
    if (bVar1 == 0) {
      lex_buffer_refill();
      g_input_ptr[-1] = 0x5c;
    }
    else {
      if (bVar1 == 10) {
        g_lex_position = g_lex_position + 1;
        g_token_position = g_lex_position;
        if (g_opt_E_preprocess != 0) {
          if ((g_compile_flags_c8 & 0x4000) != 0) {
            fputc(0x5c,g_pp_output_stream);
          }
          fputc(10,g_pp_output_stream);
        }
        return 1;
      }
      if (bVar1 != 0xd) {
        g_input_ptr = pbVar2;
        return 0;
      }
    }
    bVar1 = *g_input_ptr;
    pbVar2 = g_input_ptr;
  } while( true );
}

