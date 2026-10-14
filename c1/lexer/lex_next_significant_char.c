byte __cdecl lex_next_significant_char(byte c)

{
  uint uVar1;
  
  if (g_char_class[c] == '\x1a') {
    return c;
  }
  while( true ) {
    while ((c == 0 && (g_macro_rescan_level < 1))) {
      lex_buffer_refill();
      c = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
    }
    if (g_char_class[c] != '\0') {
      return c;
    }
    if (c == 0x3f) {
      uVar1 = lex_trigraph();
      uVar1 = uVar1 & 0xffffffbf;
    }
    else {
      if (c != 0x5c) {
        return c;
      }
      uVar1 = lex_line_splice();
    }
    if (uVar1 == 0) break;
    c = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
  }
  return c;
}

