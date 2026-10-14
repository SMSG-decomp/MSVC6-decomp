byte * __cdecl pp_copy_quoted_text(byte *out,uint *limit,byte quote)

{
  byte bVar1;
  uint uVar2;
  byte *cursor;
  
  *out = quote;
  cursor = out + 1;
LAB_1060995c:
  if ((byte *)*limit <= cursor) {
    pp_define_check_size((uint)cursor,(int)g_macro_text_buffer,(int *)limit);
  }
  bVar1 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  switch(g_char_class[bVar1]) {
  case '\0':
    uVar2 = lex_buffer_refill();
    if ((uVar2 & 0x50) == 0) goto LAB_1060995c;
    if ((uVar2 & 0x10) != 0) {
      *cursor = g_input_ptr[-1];
      bVar1 = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
      if (g_char_class[bVar1] != '\0') goto LAB_10609957;
      bVar1 = lex_next_significant_char(bVar1);
      cursor[1] = bVar1;
      cursor = cursor + 2;
      goto LAB_1060995c;
    }
    break;
  case '\x05':
    diag_error(1);
    g_input_ptr = g_input_ptr + -1;
    bVar1 = quote;
LAB_10609906:
    *cursor = bVar1;
    return cursor + 1;
  case '\x15':
  case '\x16':
    if (bVar1 != quote) goto LAB_1060990f;
    goto LAB_10609906;
  case '#':
    *cursor = bVar1;
    bVar1 = lex_skip_mbcs_trail_byte();
LAB_10609957:
    cursor = cursor + 1;
  }
  *cursor = bVar1;
  cursor = cursor + 1;
  goto LAB_1060995c;
LAB_1060990f:
  *cursor = bVar1;
  cursor = cursor + 1;
  goto LAB_1060995c;
}

