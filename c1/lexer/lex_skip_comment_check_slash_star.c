byte __cdecl
lex_skip_comment_check_slash_star(uint white_class,uint keep_comment_bit,uint keep_comment_mask)

{
  c1_u8 cVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  
code_r0x106095fb:
  g_compile_flags_c4 = g_compile_flags_c4 | keep_comment_bit;
  pp_output_copy_comment();
  g_compile_flags_c4 = g_compile_flags_c4 & keep_comment_mask;
  uVar4 = white_class;
LAB_10609614:
  while( true ) {
    if (uVar4 == 0) {
      return 0x2f;
    }
    while( true ) {
      bVar3 = *g_input_ptr;
      cVar1 = g_char_class[bVar3];
      pbVar2 = g_input_ptr;
      while( true ) {
        g_input_ptr = pbVar2 + 1;
        if (cVar1 != (c1_u8)white_class) break;
        bVar3 = *g_input_ptr;
        cVar1 = g_char_class[bVar3];
        pbVar2 = g_input_ptr;
      }
      if ((g_char_flags[bVar3] & 0x20) != 0) {
        return bVar3;
      }
      if (bVar3 == 0x2f) break;
      if (bVar3 == 0x5c) {
        iVar5 = lex_line_splice();
        if (iVar5 == 0) {
          return 0x5c;
        }
      }
      else {
        if ((bVar3 != 0) && (bVar3 != 0x1a)) {
          return bVar3;
        }
        lex_buffer_refill();
      }
    }
    if ((g_ms_extensions == '\0') && (g_pch_option_block == 0)) break;
    bVar3 = *g_input_ptr;
    g_input_ptr = pbVar2 + 2;
    if (g_char_class[bVar3] == '\0') {
      bVar3 = lex_next_significant_char(bVar3);
    }
    if (bVar3 == 0x2f) goto code_r0x106095fb;
    bVar3 = g_input_ptr[-1];
    if (g_char_class[bVar3] == '\0') {
      bVar3 = lex_next_significant_char(bVar3);
    }
    if (bVar3 != 0x2a) {
      g_input_ptr = g_input_ptr + -1;
      goto LAB_10609693;
    }
LAB_106095cb:
    g_compile_flags_c4 = g_compile_flags_c4 | keep_comment_bit;
    if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
      pp_skip_block_comment();
      g_compile_flags_c4 = g_compile_flags_c4 & keep_comment_mask;
      uVar4 = white_class;
    }
    else {
      pp_output_skip_comment();
      g_compile_flags_c4 = g_compile_flags_c4 & keep_comment_mask;
      uVar4 = white_class;
    }
  }
  bVar3 = *g_input_ptr;
  g_input_ptr = pbVar2 + 2;
  if (g_char_class[bVar3] == '\0') {
    bVar3 = lex_next_significant_char(bVar3);
  }
  if (bVar3 == 0x2f) {
    bVar3 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    if (g_char_class[bVar3] == '\0') {
      bVar3 = lex_next_significant_char(bVar3);
    }
    if (bVar3 != 0x2a) {
      g_input_ptr = g_input_ptr + -1;
      diag_warning(4,white_class);
      goto code_r0x106095fb;
    }
    diag_warning(4,0xb3);
    g_compile_flags_c4 = g_compile_flags_c4 | keep_comment_bit;
    if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
      pp_skip_block_comment();
    }
    else {
      pp_output_skip_comment();
    }
    g_compile_flags_c4 = g_compile_flags_c4 & keep_comment_mask;
  }
  else {
    bVar3 = g_input_ptr[-1];
    if (g_char_class[bVar3] == '\0') {
      bVar3 = lex_next_significant_char(bVar3);
    }
    if (bVar3 == 0x2a) goto LAB_106095cb;
    g_input_ptr = g_input_ptr + -1;
  }
LAB_10609693:
  uVar4 = 0;
  goto LAB_10609614;
}

