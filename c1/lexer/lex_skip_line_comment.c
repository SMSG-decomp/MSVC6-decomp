void __cdecl lex_skip_line_comment(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  
  do {
    do {
      while( true ) {
        bVar1 = *g_input_ptr;
        bVar2 = g_char_flags[bVar1];
        pbVar3 = g_input_ptr;
        while( true ) {
          g_input_ptr = pbVar3 + 1;
          if ((bVar2 & 0x40) == 0) break;
          bVar1 = *g_input_ptr;
          bVar2 = g_char_flags[bVar1];
          pbVar3 = g_input_ptr;
        }
        if (bVar1 == 10) {
          g_input_ptr = pbVar3;
          return;
        }
        if (g_char_class[bVar1] == '\0') break;
        if (g_char_class[bVar1] == '#') {
          lex_skip_line_comment_fragment();
          return;
        }
      }
      iVar4 = lex_buffer_refill();
    } while (iVar4 != 1);
    if (*g_input_ptr == 0) {
      return;
    }
  } while (bVar1 != 0x5c);
  lex_skip_line_comment_fragment_2();
  return;
}

