void __cdecl lex_line_comment_copy_or_skip(void)

{
  byte bVar1;
  c1_u8 cVar2;
  byte *pbVar3;
  
  if (g_opt_C_keep_comments == 0) {
    lex_skip_line_comment();
    return;
  }
  fwrite(";",2,1,(FILE *)g_pp_output_stream);
LAB_104b93b5:
  while( true ) {
    bVar1 = *g_input_ptr;
    pbVar3 = g_input_ptr + 1;
    cVar2 = g_char_class[bVar1];
    if (cVar2 != '\0') break;
    g_input_ptr = pbVar3;
    lex_buffer_refill();
  }
  if (cVar2 == '\x01') goto LAB_104b940d;
  if (cVar2 == '\x05') {
    return;
  }
  goto LAB_104b93e6;
LAB_104b940d:
  g_input_ptr = pbVar3;
  if (bVar1 != 0xd) {
LAB_104b93e6:
    g_input_ptr = pbVar3;
    g_pp_output_stream[1] = g_pp_output_stream[1] + -1;
    if (g_pp_output_stream[1] < 0) {
      _flsbuf((uint)bVar1,(FILE *)g_pp_output_stream);
    }
    else {
      *(byte *)*g_pp_output_stream = bVar1;
      *g_pp_output_stream = *g_pp_output_stream + 1;
    }
  }
  goto LAB_104b93b5;
}

