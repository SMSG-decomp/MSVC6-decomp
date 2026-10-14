void __cdecl pp_define_body_fragment(uint ch)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  uint uStack0000000c;
  
  uStack0000000c = ch;
  pbVar4 = g_input_ptr;
code_r0x10628ecf:
  g_input_ptr = pbVar4;
  uVar3 = lex_buffer_refill();
  pbVar4 = g_input_ptr;
  if ((uVar3 & 0xffffffaf) == 0) {
switchD_1060e329_caseD_10628edf:
    g_input_ptr = pbVar4;
    uStack0000000c = uStack0000000c & 0xff;
LAB_10628ee6:
    diag_error(8,uStack0000000c);
    pp_define_directive();
    return;
  }
  do {
    bVar2 = *g_input_ptr;
    uStack0000000c = (uint)bVar2;
    pbVar4 = g_input_ptr + 1;
    switch(g_char_class[bVar2]) {
    case '\0':
      goto code_r0x10628ecf;
    case '\x01':
      g_input_ptr = pbVar4;
      if (bVar2 != 0xd) {
code_r0x1060e335:
        pbVar4 = pp_define_body();
        if (g_ms_extensions != '\0') {
          pp_define_finish(g_define_text_ptr,(uint)pbVar4,g_define_formal_count);
          return;
        }
        pp_define_finish(g_macro_text_buffer,
                         (uint)(pbVar4 + ((int)g_define_text_ptr - (int)g_macro_text_buffer)),
                         g_define_formal_count);
        return;
      }
      break;
    default:
      goto switchD_1060e329_caseD_10628edf;
    case '\x03':
      if ((g_ms_extensions == '\0') && (g_pch_option_block == 0)) {
        bVar2 = *pbVar4;
        g_input_ptr = g_input_ptr + 2;
        if (g_char_class[bVar2] == '\0') {
          bVar2 = lex_next_significant_char(bVar2);
        }
        if (bVar2 == 0x2f) {
          bVar2 = *g_input_ptr;
          g_input_ptr = g_input_ptr + 1;
          if (g_char_class[bVar2] == '\0') {
            bVar2 = lex_next_significant_char(bVar2);
          }
          if (bVar2 != 0x2a) {
            g_input_ptr = g_input_ptr + -1;
            diag_warning(4,1);
            goto LAB_10628ffa;
          }
          diag_warning(4,0xb3);
          if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
            g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
            pp_skip_block_comment();
          }
          else {
            g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
            pp_output_skip_comment();
          }
          g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
        }
        else {
          bVar2 = g_input_ptr[-1];
          if (g_char_class[bVar2] == '\0') {
            bVar2 = lex_next_significant_char(bVar2);
          }
          if (bVar2 == 0x2a) {
LAB_106290f6:
            if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
              g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
              pp_skip_block_comment();
            }
            else {
              g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
              pp_output_skip_comment();
            }
            goto LAB_1062900e;
          }
          g_input_ptr = g_input_ptr + -1;
        }
LAB_10628fa9:
        bVar1 = false;
      }
      else {
        bVar2 = *pbVar4;
        g_input_ptr = g_input_ptr + 2;
        if (g_char_class[bVar2] == '\0') {
          bVar2 = lex_next_significant_char(bVar2);
        }
        if (bVar2 != 0x2f) {
          bVar2 = g_input_ptr[-1];
          if (g_char_class[bVar2] == '\0') {
            bVar2 = lex_next_significant_char(bVar2);
          }
          if (bVar2 == 0x2a) goto LAB_106290f6;
          g_input_ptr = g_input_ptr + -1;
          goto LAB_10628fa9;
        }
LAB_10628ffa:
        g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
        pp_output_copy_comment();
LAB_1062900e:
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
        bVar1 = true;
      }
      if (bVar1) goto code_r0x1060e335;
      uStack0000000c = 0x2f;
      goto LAB_10628ee6;
    case '\x04':
      g_input_ptr = pbVar4;
      pp_define_parse_formals();
      if (g_define_formal_count == 0) {
        g_define_formal_count = -1;
        pp_define_directive();
        return;
      }
      goto code_r0x1060e335;
    case '\x05':
      pp_define_finish((c1_u8 *)0x0,0,0);
      return;
    }
  } while( true );
}

