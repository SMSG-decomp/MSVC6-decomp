uint __cdecl lex_scan_pp_number_text(byte *buffer)

{
  byte c;
  byte *pbVar1;
  
  pbVar1 = buffer;
  while( true ) {
    while( true ) {
      c = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
      if (g_char_class[c] == '\0') {
        c = lex_next_significant_char(c);
      }
      if ((g_char_flags[c] & 4) == 0) break;
      *pbVar1 = c;
      pbVar1 = pbVar1 + 1;
    }
    if (((c != 0x2b) && (c != 0x2d)) || ((pbVar1[-1] & 0xdf) != 0x45)) break;
    *pbVar1 = c;
    pbVar1 = pbVar1 + 1;
  }
  g_input_ptr = g_input_ptr + -1;
  *pbVar1 = 0;
  return (uint)(pbVar1 + (1 - (int)buffer));
}

