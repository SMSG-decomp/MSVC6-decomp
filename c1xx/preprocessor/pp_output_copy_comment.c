void __cdecl pp_output_copy_comment(void)

{
  byte bVar1;
  byte bVar2;
  c1_u8 cVar3;
  uint _Ch;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  
  if ((g_opt_C_keep_comments != 0) && ((g_compile_flags_c4 & 0x8000) == 0)) {
    fwrite("//",2,1,g_pp_output_stream);
    while( true ) {
      while( true ) {
        while( true ) {
          bVar1 = *g_input_ptr;
          _Ch = (uint)bVar1;
          pbVar6 = g_input_ptr + 1;
          cVar3 = g_char_class[_Ch];
          if (cVar3 != '\0') break;
          if (*g_input_ptr == 0x3f) {
            g_input_ptr = pbVar6;
            uVar5 = lex_trigraph();
            if ((uVar5 & 0x40) != 0) {
              fputc(_Ch,g_pp_output_stream);
            }
          }
          else if (*g_input_ptr == 0x5c) {
            g_input_ptr = pbVar6;
            putchar(0x5c);
            lex_line_splice();
          }
          else {
            g_input_ptr = pbVar6;
            lex_buffer_refill();
          }
        }
        if (cVar3 != '\x01') break;
        g_input_ptr = pbVar6;
        if (bVar1 != 0xd) {
          fputc(_Ch,g_pp_output_stream);
        }
      }
      if (cVar3 == '\x05') break;
      g_input_ptr = pbVar6;
      fputc(_Ch,g_pp_output_stream);
    }
    return;
  }
  while( true ) {
    bVar1 = *g_input_ptr;
    bVar2 = g_char_flags[bVar1];
    pbVar6 = g_input_ptr;
    while( true ) {
      g_input_ptr = pbVar6 + 1;
      if ((bVar2 & 0x40) == 0) break;
      bVar1 = *g_input_ptr;
      bVar2 = g_char_flags[bVar1];
      pbVar6 = g_input_ptr;
    }
    if (bVar1 == 10) break;
    if (g_char_class[bVar1] == '\0') {
      iVar4 = lex_buffer_refill();
      if (iVar4 == 1) {
        if (*g_input_ptr == 0) {
          return;
        }
        if (bVar1 == 0x5c) {
          lex_warn_comment_continuation();
        }
      }
    }
    else if (g_char_class[bVar1] == '#') {
      lex_skip_line_comment_fragment();
      return;
    }
  }
  g_input_ptr = pbVar6;
  return;
}

