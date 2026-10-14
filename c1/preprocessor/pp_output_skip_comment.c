void pp_output_skip_comment(void)

{
  uint _Ch;
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  
  fwrite("/*",2,1,g_pp_output_stream);
LAB_10628385:
  bVar1 = *g_input_ptr;
  _Ch = (uint)bVar1;
  pbVar3 = g_input_ptr + 1;
  switch(g_char_class[_Ch]) {
  case '\0':
    if (*g_input_ptr != 0x3f) {
      if (*g_input_ptr == 0x5c) {
        g_input_ptr = pbVar3;
        putchar(0x5c);
        lex_line_splice();
      }
      else {
        g_input_ptr = pbVar3;
        lex_buffer_refill();
      }
      goto LAB_10628385;
    }
    g_input_ptr = pbVar3;
    uVar2 = lex_trigraph();
    pbVar3 = g_input_ptr;
    if ((uVar2 & 0x40) == 0) goto LAB_10628385;
    break;
  case '\x01':
    g_input_ptr = pbVar3;
    if (bVar1 != 0xd) {
      fputc(_Ch,g_pp_output_stream);
    }
    goto LAB_10628385;
  case '\x05':
    g_lex_position = g_lex_position + 1;
    g_token_position = g_lex_position;
    break;
  case '\b':
    goto switchD_106283b4_caseD_8;
  }
  g_input_ptr = pbVar3;
  fputc(_Ch,g_pp_output_stream);
  goto LAB_10628385;
switchD_106283b4_caseD_8:
  bVar1 = *pbVar3;
  g_input_ptr = g_input_ptr + 2;
  if (g_char_class[bVar1] == '\0') {
    bVar1 = lex_next_significant_char(bVar1);
  }
  if (bVar1 == 0x2f) {
    fwrite("*/",2,1,g_pp_output_stream);
    return;
  }
  g_input_ptr = g_input_ptr + -1;
  fputc(_Ch,g_pp_output_stream);
  goto LAB_10628385;
}

