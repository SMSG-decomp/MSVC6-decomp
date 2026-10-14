char * __cdecl pp_include_parse_angle_name(char report)

{
  byte bVar1;
  byte *end;
  byte *pbVar2;
  code *mbctype;
  
  do {
    bVar1 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
  } while (g_char_class[bVar1] == '\x01');
  if ((g_char_flags[bVar1] & 0x20) == 0) {
    bVar1 = lex_skip_comment(bVar1);
  }
  end = &g_string_literal_buffer;
  mbctype = _mbctype_exref;
  if (bVar1 == 10) {
    g_input_ptr = g_input_ptr + -1;
    if (report != '\0') {
      diag_error(0xc);
      return (char *)0x0;
    }
  }
  else {
    while( true ) {
      _mbctype_exref = mbctype;
      if (bVar1 == 0x3e) {
        if (end != &g_string_literal_buffer) {
          end = str_find_trailing_space(&g_string_literal_buffer,end);
        }
        *end = 0;
        return &g_string_literal_buffer;
      }
      if (bVar1 == 10) break;
      *end = bVar1;
      pbVar2 = end + 1;
      if (((byte)mbctype[bVar1 + 1] & 4) != 0) {
        bVar1 = lex_skip_mbcs_trail_byte();
        *pbVar2 = bVar1;
        pbVar2 = end + 2;
      }
      bVar1 = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
      end = pbVar2;
      mbctype = _mbctype_exref;
      if (g_char_class[bVar1] == '\0') {
        bVar1 = lex_next_significant_char(bVar1);
        mbctype = _mbctype_exref;
      }
    }
    g_input_ptr = g_input_ptr + -1;
    if (report != '\0') {
      diag_error(0xd);
    }
  }
  return (char *)0x0;
}

