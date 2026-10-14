void __cdecl pp_output_skip_comment_slow_char(uint c,byte *input,void *put_char_to,void *put_char)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  
  pbVar1 = g_input_ptr;
code_r0x1062eee2:
  g_input_ptr = pbVar1;
  if (input[-1] != 0x3f) {
    if (input[-1] == 0x5c) {
      (*put_char)(0x5c);
      lex_line_splice();
      goto LAB_10628385;
    }
    lex_buffer_refill();
    goto LAB_10628385;
  }
  uVar3 = lex_trigraph();
  pbVar1 = g_input_ptr;
  if ((uVar3 & 0x40) == 0) goto LAB_10628385;
switchD_106283b4_caseD_2:
  g_input_ptr = pbVar1;
  (*put_char_to)(c,g_pp_output_stream);
LAB_10628385:
  do {
    bVar2 = *g_input_ptr;
    c = (uint)bVar2;
    input = g_input_ptr + 1;
    pbVar1 = input;
    switch(g_char_class[c]) {
    case '\0':
      goto code_r0x1062eee2;
    case '\x01':
      g_input_ptr = input;
      if (bVar2 != 0xd) {
        (*put_char_to)(c,g_pp_output_stream);
      }
      break;
    default:
      goto switchD_106283b4_caseD_2;
    case '\x05':
      g_lex_position = g_lex_position + 1;
      g_token_position = g_lex_position;
      pbVar1 = input;
      goto switchD_106283b4_caseD_2;
    case '\b':
      bVar2 = *input;
      g_input_ptr = g_input_ptr + 2;
      if (g_char_class[bVar2] == '\0') {
        bVar2 = lex_next_significant_char(bVar2);
      }
      if (bVar2 == 0x2f) {
        fwrite("*/",2,1,g_pp_output_stream);
        return;
      }
      g_input_ptr = g_input_ptr + -1;
      (*put_char_to)(c,g_pp_output_stream);
    }
  } while( true );
}

