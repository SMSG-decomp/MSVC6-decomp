void __cdecl lex_skip_line_comment_check(uint keep_comment_bit,uint keep_comment_mask)

{
  c1_u8 cVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  uint unaff_EBP;
  
code_r0x10609844:
  g_compile_flags_c4 = g_compile_flags_c4 | keep_comment_bit;
  pp_output_copy_comment();
  g_compile_flags_c4 = g_compile_flags_c4 & keep_comment_mask;
  pbVar4 = g_input_ptr;
switchD_1060979e_caseD_1:
  g_input_ptr = pbVar4;
  pbVar4 = g_input_ptr + 1;
  switch(g_char_class[*g_input_ptr]) {
  case '\0':
    g_input_ptr = pbVar4;
    iVar3 = lex_buffer_refill();
    pbVar4 = g_input_ptr;
    if ((iVar3 != 1) || (*g_input_ptr != 0)) goto switchD_1060979e_caseD_1;
    break;
  default:
    goto switchD_1060979e_caseD_1;
  case '\x03':
    if ((g_ms_extensions == '\0') && (g_pch_option_block == 0)) {
      bVar2 = *pbVar4;
      g_input_ptr = g_input_ptr + 2;
      if (g_char_class[bVar2] == '\0') {
        bVar2 = lex_next_significant_char(bVar2);
      }
      if (bVar2 != 0x2f) {
        bVar2 = g_input_ptr[-1];
        cVar1 = g_char_class[bVar2];
        goto joined_r0x1062dbdc;
      }
      bVar2 = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
      if (g_char_class[bVar2] == '\0') {
        bVar2 = lex_next_significant_char(bVar2);
      }
      if (bVar2 != 0x2a) goto code_r0x1062dc31;
      diag_warning(4,0xb3);
    }
    else {
      bVar2 = *pbVar4;
      g_input_ptr = g_input_ptr + 2;
      if (g_char_class[bVar2] == '\0') {
        bVar2 = lex_next_significant_char(bVar2);
      }
      if (bVar2 == 0x2f) goto code_r0x10609844;
      bVar2 = g_input_ptr[-1];
      cVar1 = g_char_class[bVar2];
joined_r0x1062dbdc:
      if (cVar1 == '\0') {
        bVar2 = lex_next_significant_char(bVar2);
      }
      if (bVar2 != 0x2a) {
        g_input_ptr = g_input_ptr + -1;
        pbVar4 = g_input_ptr;
        goto switchD_1060979e_caseD_1;
      }
    }
    g_compile_flags_c4 = g_compile_flags_c4 | keep_comment_bit;
    if ((g_opt_C_keep_comments == 0) || ((unaff_EBP & g_compile_flags_c4) != 0)) {
      pp_skip_block_comment();
      g_compile_flags_c4 = g_compile_flags_c4 & keep_comment_mask;
      pbVar4 = g_input_ptr;
    }
    else {
      pp_output_skip_comment();
      g_compile_flags_c4 = g_compile_flags_c4 & keep_comment_mask;
      pbVar4 = g_input_ptr;
    }
    goto switchD_1060979e_caseD_1;
  case '\x05':
    break;
  case '#':
    goto switchD_1060979e_caseD_23;
  }
  return;
switchD_1060979e_caseD_23:
  g_input_ptr = pbVar4;
  lex_skip_mbcs_trail_byte();
  pbVar4 = g_input_ptr;
  goto switchD_1060979e_caseD_1;
code_r0x1062dc31:
  g_input_ptr = g_input_ptr + -1;
  diag_warning(4,1);
  goto code_r0x10609844;
}

