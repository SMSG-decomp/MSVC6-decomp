void __cdecl lex_skip_to_char(byte quote)

{
  uint uVar1;
  byte *pbVar2;
  
  pbVar2 = g_input_ptr;
  do {
    g_input_ptr = pbVar2;
    pbVar2 = g_input_ptr + 1;
    switch(g_char_class[*g_input_ptr]) {
    case '\0':
      g_input_ptr = pbVar2;
      uVar1 = lex_buffer_refill();
      pbVar2 = g_input_ptr;
      if ((uVar1 & 0x10) != 0) {
        g_input_ptr = g_input_ptr + 1;
        pbVar2 = g_input_ptr;
      }
      break;
    case '\x05':
      return;
    case '\x15':
    case '\x16':
      if (*g_input_ptr == quote) {
        g_input_ptr = pbVar2;
        return;
      }
      break;
    case '#':
      g_input_ptr = pbVar2;
      lex_skip_mbcs_trail_byte();
      pbVar2 = g_input_ptr;
    }
  } while( true );
}

