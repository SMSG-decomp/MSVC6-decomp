void __cdecl pp_define_parse_formals(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte *name;
  byte *pbVar4;
  byte *pbVar5;
  short n;
  uint ch;
  
LAB_1044d98c:
  name = g_define_text_ptr + 1;
  pbVar5 = name;
LAB_1044d994:
  do {
    bVar2 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
  } while (g_char_class[bVar2] == '\x01');
  if ((g_char_flags[bVar2] & 0x20) == 0) {
    bVar2 = lex_skip_comment(bVar2);
  }
  ch = (uint)bVar2;
  switch(g_char_class[ch]) {
  case '\x06':
  case '\a':
    if (name != pbVar5) {
      diag_error(10,ch);
    }
    *pbVar5 = bVar2;
    pbVar4 = pbVar5 + 1;
    do {
      while( true ) {
        bVar2 = *g_input_ptr;
        bVar1 = g_char_flags[bVar2];
        while (g_input_ptr = g_input_ptr + 1, (bVar1 & 3) != 0) {
          *pbVar4 = bVar2;
          pbVar4 = pbVar4 + 1;
          bVar2 = *g_input_ptr;
          bVar1 = g_char_flags[bVar2];
        }
        if (bVar2 != 0) break;
        iVar3 = file_read_or_fatal();
        if (iVar3 != 0) {
          pp_macro_location(4);
        }
      }
    } while ((bVar2 == 0x5c) && (iVar3 = lex_line_splice(), iVar3 != 0));
    g_input_ptr = g_input_ptr + -1;
    pbVar5 = pbVar4 + 1;
    *pbVar4 = 0;
    goto LAB_1044d994;
  default:
    diag_error(10,ch);
    goto LAB_1044d994;
  case '\x1b':
  case '\x1c':
    break;
  }
  if (name < pbVar5) {
    iVar3 = pp_define_find_formal(name);
    if (iVar3 < 1) {
      *g_define_text_ptr = (char)pbVar5 - (char)g_define_text_ptr;
      g_define_formal_count = g_define_formal_count + 1;
      g_define_text_ptr = pbVar5;
      goto LAB_1044dac5;
    }
    n = 9;
  }
  else {
    if (bVar2 != 0x2c) {
      if (0 < g_define_formal_count) {
        pp_define_check_formals_token(ch,bVar2);
        return;
      }
      goto LAB_1044dac5;
    }
    n = 10;
    name = (byte *)0x2c;
  }
  diag_error(n,name);
LAB_1044dac5:
  if (bVar2 == 0x29) {
    return;
  }
  goto LAB_1044d98c;
}

