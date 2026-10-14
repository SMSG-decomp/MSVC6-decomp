char __cdecl pp_macro_scan_identifier(uint first_char)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  byte *cursor;
  byte bVar4;
  uint len;
  uint hash;
  char local_16;
  char local_15;
  uint local_14;
  uint formal_copied;
  uint first_copied;
  uint ident_copied;
  c1_u8 *local_4;
  
  hash = 0;
  local_4 = g_macro_text_cursor;
  local_16 = '\0';
  local_15 = '\x01';
  local_14 = 0xffffffff;
  len = 0;
  cursor = g_macro_text_cursor;
  bVar4 = (byte)first_char;
  while( true ) {
    if (g_char_class[first_char & 0xff] == '&') {
      pbVar3 = (byte *)pp_macro_formal_argument_text(&local_16);
      cursor = g_macro_text_cursor;
      if (pbVar3 != (byte *)0x0) {
        bVar4 = *pbVar3;
        while (cursor = g_macro_text_cursor, bVar4 != 0) {
          if ((g_char_flags[bVar4] & 3) == 0) {
            local_15 = '\0';
          }
          if (g_macro_text_buffer_limit <= g_macro_text_cursor) {
            pp_define_check_size
                      ((uint)g_macro_text_cursor,(int)g_macro_text_buffer,
                       (int *)&g_macro_text_buffer_limit);
          }
          bVar4 = *pbVar3;
          pbVar3 = pbVar3 + 1;
          *g_macro_text_cursor = bVar4;
          bVar4 = *g_macro_text_cursor;
          g_macro_text_cursor = g_macro_text_cursor + 1;
          formal_copied = CONCAT31(formal_copied._1_3_,bVar4);
          hash = (hash >> 4) + hash * 4 + (uint)bVar4;
          len = len + 1;
          bVar4 = *pbVar3;
        }
      }
    }
    else {
      *cursor = bVar4;
      bVar4 = *g_macro_text_cursor;
      g_macro_text_cursor = g_macro_text_cursor + 1;
      first_copied = CONCAT31(first_copied._1_3_,bVar4);
      hash = (hash >> 4) + hash * 4 + (uint)bVar4;
      len = len + 1;
      cursor = g_macro_text_cursor;
    }
    while( true ) {
      bVar4 = *g_input_ptr;
      first_char = CONCAT31(first_char._1_3_,bVar4);
      bVar1 = g_char_flags[bVar4];
      pbVar3 = g_input_ptr;
      while (g_input_ptr = pbVar3 + 1, (bVar1 & 3) != 0) {
        if (g_macro_text_buffer_limit <= cursor) {
          pp_define_check_size
                    ((uint)cursor,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit);
          cursor = g_macro_text_cursor;
        }
        *cursor = bVar4;
        cursor = g_macro_text_cursor + 1;
        ident_copied = CONCAT31(ident_copied._1_3_,*g_macro_text_cursor);
        bVar4 = *g_input_ptr;
        first_char = CONCAT31(first_char._1_3_,bVar4);
        hash = (hash >> 4) + hash * 4 + (uint)*g_macro_text_cursor;
        len = len + 1;
        g_macro_text_cursor = cursor;
        pbVar3 = g_input_ptr;
        bVar1 = g_char_flags[bVar4];
      }
      if (g_char_class[first_char & 0xff] != ')') break;
      local_14 = (uint)*g_input_ptr;
      g_input_ptr = pbVar3 + 2;
    }
    if (g_char_class[first_char & 0xff] != '&') break;
    local_16 = '\x01';
  }
  g_input_ptr = pbVar3;
  if (local_15 == '\0') {
    return '\0';
  }
  if ((local_14 == (int)cursor - (int)local_4) && (local_14 != 0xffffffff)) {
    *cursor = 4;
    g_macro_text_cursor = g_macro_text_cursor + 1;
    *g_macro_text_cursor = (uchar)local_14;
    g_macro_text_cursor = g_macro_text_cursor + 1;
    cVar2 = pp_macro_scan_identifier_return_false();
    return cVar2;
  }
  *cursor = 0;
  g_last_name = name_intern_hashed(local_4,hash,len,(byte *)&first_char);
  return (byte)first_char == '\0';
}

