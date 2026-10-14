void __cdecl pp_define_check_token(uint ch)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  uint uStack0000000c;
  
  uStack0000000c = ch;
  pbVar3 = g_input_ptr;
code_r0x1045c8fe:
  g_input_ptr = pbVar3;
  uVar2 = lex_buffer_refill();
  pbVar3 = g_input_ptr;
  if ((uVar2 & 0xffffffaf) == 0) {
switchD_104338a0_caseD_2:
    g_input_ptr = pbVar3;
    uStack0000000c = uStack0000000c & 0xff;
LAB_1045c915:
    diag_error(8,uStack0000000c);
    pp_define_directive();
    return;
  }
  do {
    bVar1 = *g_input_ptr;
    uStack0000000c = (uint)bVar1;
    pbVar3 = g_input_ptr + 1;
    switch(g_char_class[bVar1]) {
    case '\0':
      goto code_r0x1045c8fe;
    case '\x01':
      g_input_ptr = pbVar3;
      if (bVar1 != 0xd) {
code_r0x104338ac:
        uVar2 = pp_define_body();
        if (g_ms_extensions != '\0') {
          pp_define_finish(g_define_text_ptr,uVar2,g_define_formal_count);
          return;
        }
        pp_define_finish(g_macro_text_buffer,
                         (uint)(g_define_text_ptr + (uVar2 - (int)g_macro_text_buffer)),
                         g_define_formal_count);
        return;
      }
      break;
    default:
      goto switchD_104338a0_caseD_2;
    case '\x03':
      bVar1 = *pbVar3;
      g_input_ptr = g_input_ptr + 2;
      if (g_char_class[bVar1] == '\0') {
        bVar1 = lex_next_significant_char(bVar1);
      }
      if (bVar1 == 0x2f) {
        g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
        pp_output_copy_comment();
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
        pp_define_directive();
        return;
      }
      bVar1 = g_input_ptr[-1];
      if (g_char_class[bVar1] == '\0') {
        bVar1 = lex_next_significant_char(bVar1);
      }
      if (bVar1 == 0x2a) {
        if ((g_opt_C_keep_comments != 0) && ((g_compile_flags_c4 & 0x8000) == 0)) {
          g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
          pp_output_skip_comment();
          g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
          pp_define_directive();
          return;
        }
        g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
        pp_skip_block_comment();
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
        pp_define_directive();
        return;
      }
      uStack0000000c = 0x2f;
      g_input_ptr = g_input_ptr + -1;
      goto LAB_1045c915;
    case '\x04':
      g_input_ptr = pbVar3;
      pp_define_parse_formals();
      if (g_define_formal_count == 0) {
        g_define_formal_count = -1;
        pp_define_directive();
        return;
      }
      goto code_r0x104338ac;
    case '\x05':
      pp_define_finish((c1_u8 *)0x0,0,0);
      return;
    }
  } while( true );
}

