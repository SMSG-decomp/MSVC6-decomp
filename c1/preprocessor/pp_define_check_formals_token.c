void __cdecl pp_define_check_formals_token(uint ch,byte cur_ch)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  short n;
  byte *name;
  
code_r0x10629177:
  n = 10;
  name = (byte *)ch;
LAB_1062916a:
  diag_error(n,name);
LAB_1060ea16:
  if (cur_ch == 0x29) {
    return;
  }
  name = g_define_text_ptr + 1;
  pbVar5 = name;
LAB_1060e8e5:
  do {
    cur_ch = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
  } while (g_char_class[cur_ch] == '\x01');
  if ((g_char_flags[cur_ch] & 0x20) == 0) {
    cur_ch = lex_skip_comment(cur_ch);
  }
  ch = (uint)cur_ch;
  switch(*(byte *)(ch + 0x1065d008)) {
  case 6:
  case 7:
    if (name != pbVar5) {
      diag_error(10,ch);
    }
    *pbVar5 = cur_ch;
    pbVar4 = pbVar5 + 1;
    do {
      while( true ) {
        bVar1 = *g_input_ptr;
        bVar2 = g_char_flags[bVar1];
        while (g_input_ptr = g_input_ptr + 1, (bVar2 & 3) != 0) {
          *pbVar4 = bVar1;
          pbVar4 = pbVar4 + 1;
          bVar1 = *g_input_ptr;
          bVar2 = g_char_flags[bVar1];
        }
        if (bVar1 != 0) break;
        iVar3 = file_read_or_fatal();
        if (iVar3 != 0) {
          pp_macro_location(4);
        }
      }
    } while ((bVar1 == 0x5c) && (iVar3 = lex_line_splice(), iVar3 != 0));
    g_input_ptr = g_input_ptr + -1;
    pbVar5 = pbVar4 + 1;
    *pbVar4 = 0;
    goto LAB_1060e8e5;
  default:
    diag_error(10,ch);
    goto LAB_1060e8e5;
  case 0x1b:
  case 0x1c:
    break;
  }
  if (pbVar5 <= name) {
    if (cur_ch == 0x2c) goto code_r0x10629177;
    if (0 < g_define_formal_count) {
      pp_define_check_formals_token(ch,cur_ch);
      return;
    }
    goto LAB_1060ea16;
  }
  iVar3 = pp_define_find_formal(name);
  if (iVar3 < 1) {
    *g_define_text_ptr = (char)pbVar5 - (char)g_define_text_ptr;
    g_define_formal_count = g_define_formal_count + 1;
    g_define_text_ptr = pbVar5;
    goto LAB_1060ea16;
  }
  n = 9;
  goto LAB_1062916a;
}

