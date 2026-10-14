void __cdecl pp_capture_directive_text(void)

{
  byte c;
  byte bVar1;
  uint uVar2;
  bool bVar3;
  byte bVar4;
  uint local_10;
  
  do {
    c = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
  } while (g_char_class[c] == '\x01');
  if ((g_char_flags[c] & 0x20) == 0) {
    c = lex_skip_comment(c);
  }
  local_10 = (uint)c;
  uVar2 = 0;
  bVar4 = 0;
  block_list_rewind(g_pch_directive_text_blocks);
LAB_104612b3:
  switch(g_char_class[local_10]) {
  case '\0':
    lex_put_string_byte(c,g_pch_directive_text_blocks);
    c = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    break;
  case '\x01':
    goto switchD_104612d2_caseD_1;
  case '\x03':
    bVar1 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    if (g_char_class[bVar1] == '\0') {
      bVar1 = lex_next_significant_char(bVar1);
    }
    if (bVar1 == 0x2f) {
      g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
      pp_output_copy_comment();
    }
    else {
      bVar1 = g_input_ptr[-1];
      if (g_char_class[bVar1] == '\0') {
        bVar1 = lex_next_significant_char(bVar1);
      }
      if (bVar1 != 0x2a) {
        g_input_ptr = g_input_ptr + -1;
        break;
      }
      if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
        g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
        pp_skip_block_comment();
      }
      else {
        g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
        pp_output_skip_comment();
      }
    }
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
switchD_104612d2_caseD_1:
    if (bVar4 != 0) break;
    do {
      c = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
    } while (g_char_class[c] == '\x01');
    if ((g_char_flags[c] & 0x20) == 0) {
      c = lex_skip_comment(c);
    }
    local_10 = (uint)c;
    if (c != 10) {
      lex_put_string_byte(0x20,g_pch_directive_text_blocks);
    }
    goto LAB_104612b3;
  case '\x05':
    lex_put_string_byte(c,g_pch_directive_text_blocks);
    g_input_ptr = g_input_ptr + -1;
    return;
  case '\x15':
    bVar3 = uVar2 != 2;
    uVar2 = -(uint)bVar3 & 2;
    bVar4 = -bVar3 & 2;
    break;
  case '\x16':
    bVar4 = uVar2 != 1;
    uVar2 = (uint)bVar4;
  }
  lex_put_string_byte(c,g_pch_directive_text_blocks);
  c = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  local_10 = (uint)c;
  goto LAB_104612b3;
}

