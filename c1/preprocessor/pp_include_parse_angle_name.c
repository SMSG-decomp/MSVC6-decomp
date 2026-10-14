char * __cdecl pp_include_parse_angle_name(char report)

{
  code *pcVar1;
  byte bVar2;
  byte *end;
  byte *pbVar3;
  
  do {
    bVar2 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
  } while (g_char_class[bVar2] == '\x01');
  if ((g_char_flags[bVar2] & 0x20) == 0) {
    bVar2 = lex_skip_comment(bVar2);
  }
  end = &g_string_literal_buffer;
  pcVar1 = _mbctype_exref;
  if (bVar2 == 10) {
    g_input_ptr = g_input_ptr + -1;
    if (report != '\0') {
      diag_error(0xc);
      return (char *)0x0;
    }
  }
  else {
    while( true ) {
      _mbctype_exref = pcVar1;
      if (bVar2 == 0x3e) {
        if (end != &g_string_literal_buffer) {
          end = str_find_trailing_space(&g_string_literal_buffer,end);
        }
        *end = 0;
        return &g_string_literal_buffer;
      }
      if (bVar2 == 10) break;
      *end = bVar2;
      pbVar3 = end + 1;
      if (((byte)pcVar1[bVar2 + 1] & 4) != 0) {
        bVar2 = lex_skip_mbcs_trail_byte();
        *pbVar3 = bVar2;
        pbVar3 = end + 2;
      }
      bVar2 = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
      end = pbVar3;
      pcVar1 = _mbctype_exref;
      if (g_char_class[bVar2] == '\0') {
        bVar2 = lex_next_significant_char(bVar2);
        pcVar1 = _mbctype_exref;
      }
    }
    g_input_ptr = g_input_ptr + -1;
    if (report != '\0') {
      diag_error(0xd);
    }
  }
  return (char *)0x0;
}

