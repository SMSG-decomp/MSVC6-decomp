void __cdecl pp_macro_stringize(uint quote,byte *text)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  byte *cursor;
  
  bVar2 = false;
  if (text == (byte *)0x0) {
    return;
  }
  *g_macro_text_cursor = (byte)quote;
  cursor = g_macro_text_cursor + 1;
  uVar4 = quote;
  g_macro_text_cursor = cursor;
LAB_10441660:
  do {
    if (g_macro_text_buffer_limit <= cursor) {
      pp_define_check_size((uint)cursor,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit);
      cursor = g_macro_text_cursor;
    }
    bVar1 = *text;
    uVar3 = (uint)g_char_class[bVar1];
    switch(uVar3) {
    case 0:
      if (bVar1 == 0) {
        *cursor = (byte)quote;
        g_macro_text_cursor = g_macro_text_cursor + 1;
        return;
      }
      if ((bVar1 == 0x5c) && (bVar2)) {
        *cursor = 0x5c;
        cursor = g_macro_text_cursor + 1;
        g_macro_text_cursor = cursor;
      }
      break;
    case 0x15:
switchD_1044168d_caseD_15:
      if ((byte)quote != 0x27) goto LAB_10441644;
      break;
    case 0x16:
      if ((byte)quote != 0x22) goto switchD_1044168d_caseD_15;
      *cursor = 0x5c;
      cursor = g_macro_text_cursor + 1;
      g_macro_text_cursor = cursor;
LAB_10441644:
      if (bVar2) {
        if (uVar3 == uVar4) {
          bVar2 = false;
        }
      }
      else {
        bVar2 = true;
        uVar4 = uVar3;
      }
      break;
    case 0x23:
      *cursor = bVar1;
      cursor = g_macro_text_cursor + 1;
      text = text + 1;
      g_macro_text_cursor = cursor;
      break;
    case 0x29:
      goto switchD_1044168d_caseD_29;
    }
    *cursor = *text;
    cursor = g_macro_text_cursor + 1;
    text = text + 1;
    g_macro_text_cursor = cursor;
  } while( true );
switchD_1044168d_caseD_29:
  text = text + 2;
  goto LAB_10441660;
}

