uint __cdecl pp_define_check_paste(byte ch,byte *out,int stringize,uint ch_cell,int charize)

{
  c1_u8 cVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte *out_00;
  byte *pbVar5;
  uint uStack00000018;
  
  g_input_ptr = g_input_ptr + -1;
  diag_error(0xa1);
LAB_1043850c:
  out_00 = out;
  if (g_macro_text_buffer_limit <= out_00) {
    pp_define_check_size((uint)out_00,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit);
  }
  pbVar5 = out_00;
  out = out_00;
  switch(g_char_class[ch_cell & 0xff]) {
  case '\0':
    uVar3 = lex_buffer_refill();
    if ((uVar3 & 0x50) != 0) {
      if ((uVar3 & 0x10) != 0) {
        *out_00 = ch;
        pbVar5 = out_00 + 1;
        ch = *g_input_ptr;
        g_input_ptr = g_input_ptr + 1;
        if (g_char_class[ch] == '\0') {
          ch = lex_next_significant_char(ch);
        }
        uStack00000018 = (uint)ch;
        if ((0x14 < g_char_class[uStack00000018]) && (g_char_class[uStack00000018] < 0x17)) {
          diag_error(0x127,uStack00000018);
          do {
            ch = *g_input_ptr;
            g_input_ptr = g_input_ptr + 1;
          } while (g_char_class[ch] == '\x01');
          if ((g_char_flags[ch] & 0x20) == 0) {
            ch = lex_skip_comment(ch);
          }
          goto LAB_104384d4;
        }
      }
      goto switchD_10438538_caseD_2;
    }
    break;
  case '\x01':
    goto switchD_10438538_caseD_1;
  default:
    goto switchD_10438538_caseD_2;
  case '\x03':
    bVar2 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    if (g_char_class[bVar2] == '\0') {
      bVar2 = lex_next_significant_char(bVar2);
    }
    if (bVar2 == 0x2f) {
      g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
      pp_output_copy_comment();
    }
    else {
      bVar2 = g_input_ptr[-1];
      if (g_char_class[bVar2] == '\0') {
        bVar2 = lex_next_significant_char(bVar2);
      }
      if (bVar2 != 0x2a) {
        g_input_ptr = g_input_ptr + -1;
        goto switchD_10438538_caseD_2;
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
    goto switchD_10438538_caseD_1;
  case '\x05':
    g_input_ptr = g_input_ptr + -1;
    pbVar5 = g_define_text_ptr;
    if (g_ms_extensions == '\0') {
      pbVar5 = g_macro_text_buffer;
    }
    if (out_00 == pbVar5) {
      return 0;
    }
    if (g_macro_text_buffer_limit <= out_00) {
      pp_define_check_size((uint)out_00,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit);
    }
    *out_00 = 0;
    out_00[1] = 0x44;
    return (uint)(out_00 + 1 + (1 - (int)g_define_text_ptr));
  case '\x06':
  case '\a':
    goto switchD_10438538_caseD_6;
  case '\v':
    cVar1 = g_char_class[*g_input_ptr];
    while (g_input_ptr = g_input_ptr + 1, cVar1 == '\0') {
      uVar3 = lex_buffer_refill();
      if ((uVar3 & 0xffffffaf) == 0) goto LAB_104385e4;
      cVar1 = g_char_class[*g_input_ptr];
    }
    if (cVar1 == '\v') goto code_r0x1043857c;
    if (cVar1 == '\"') {
      if ((0 < g_define_formal_count) && (g_ms_extensions != '\0')) {
        charize = 1;
LAB_10438603:
        do {
          ch = *g_input_ptr;
          g_input_ptr = g_input_ptr + 1;
        } while (g_char_class[ch] == '\x01');
        if ((g_char_flags[ch] & 0x20) == 0) {
          ch = lex_skip_comment(ch);
        }
        ch_cell = CONCAT31(ch_cell._1_3_,ch);
        if ((g_char_flags[ch] & 1) != 0) {
switchD_10438538_caseD_6:
          do {
            do {
              if (g_macro_text_buffer_limit <= out) {
                pp_define_check_size
                          ((uint)out,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit);
              }
              *out = ch;
              out = out + 1;
              ch = *g_input_ptr;
              g_input_ptr = g_input_ptr + 1;
              ch_cell = CONCAT31(ch_cell._1_3_,ch);
              uVar3 = (uint)ch;
            } while ((g_char_flags[uVar3] & 3) != 0);
            do {
              if ((g_char_class[uVar3] != '\0') ||
                 (uVar3 = lex_buffer_refill(), (uVar3 & 0xffffffaf) == 0)) {
                if (0 < g_define_formal_count) {
                  *out = 0;
                  iVar4 = pp_define_find_formal(out_00);
                  if (iVar4 < 1) {
                    if ((charize != 0) || (stringize != 0)) {
                      diag_error(0xa2);
                    }
                    stringize = 0;
                    charize = 0;
                  }
                  else {
                    bVar2 = (byte)iVar4;
                    if (stringize == 0) {
                      if (charize == 0) {
                        *out_00 = 1;
                        out_00[1] = bVar2;
                        stringize = 0;
                        charize = 0;
                        out = out_00 + 2;
                      }
                      else {
                        *out_00 = 3;
                        out_00[1] = bVar2;
                        stringize = 0;
                        charize = 0;
                        out = out_00 + 2;
                      }
                    }
                    else {
                      *out_00 = 2;
                      out_00[1] = bVar2;
                      stringize = 0;
                      charize = 0;
                      out = out_00 + 2;
                    }
                  }
                }
                goto LAB_1043850c;
              }
              ch = *g_input_ptr;
              g_input_ptr = g_input_ptr + 1;
              ch_cell = CONCAT31(ch_cell._1_3_,ch);
              uVar3 = (uint)ch;
            } while ((g_char_flags[uVar3] & 3) == 0);
          } while( true );
        }
        stringize = 0;
        charize = 0;
        diag_error(0xa2);
        goto LAB_1043850c;
      }
      *out_00 = 0x23;
      out_00 = out_00 + 1;
      ch = g_input_ptr[-1];
    }
    else {
LAB_104385e4:
      if (0 < g_define_formal_count) {
        stringize = 1;
        g_input_ptr = g_input_ptr + -1;
        goto LAB_10438603;
      }
      *out_00 = 0x23;
      out_00 = out_00 + 1;
      ch = g_input_ptr[-1];
    }
LAB_104384d4:
    ch_cell = CONCAT31(ch_cell._1_3_,ch);
    out = out_00;
    goto LAB_1043850c;
  case '\x15':
  case '\x16':
    out_00 = pp_copy_quoted_text(out_00,(uint *)&g_macro_text_buffer_limit,(byte)ch_cell);
    break;
  case '!':
    diag_error(0x12,ch_cell & 0xff);
    break;
  case '#':
    *out_00 = ch;
    ch = lex_skip_mbcs_trail_byte();
    pbVar5 = out_00 + 1;
    goto switchD_10438538_caseD_2;
  }
LAB_104384fb:
  ch = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  ch_cell = CONCAT31(ch_cell._1_3_,ch);
  out = out_00;
  goto LAB_1043850c;
code_r0x1043857c:
  if (out_00 == g_define_text_ptr) {
    diag_error(0xa0);
  }
  else {
    if (out_00[-1] == 0x20) {
      out_00 = out_00 + -1;
    }
    do {
      ch = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
    } while (g_char_class[ch] == '\x01');
    if ((g_char_flags[ch] & 0x20) == 0) {
      ch = lex_skip_comment(ch);
    }
    ch_cell = CONCAT31(ch_cell._1_3_,ch);
    out = out_00;
    if (ch == 10) {
      uVar3 = pp_define_check_paste(10,out_00,stringize,ch_cell,charize);
      return uVar3;
    }
  }
  goto LAB_1043850c;
switchD_10438538_caseD_1:
  do {
    ch = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
  } while (g_char_class[ch] == '\x01');
  if ((g_char_flags[ch] & 0x20) == 0) {
    ch = lex_skip_comment(ch);
  }
  ch_cell = CONCAT31(ch_cell._1_3_,ch);
  if (ch != 10) {
    *out_00 = 0x20;
    out = out_00 + 1;
  }
  goto LAB_1043850c;
switchD_10438538_caseD_2:
  *pbVar5 = ch;
  out_00 = pbVar5 + 1;
  goto LAB_104384fb;
}

