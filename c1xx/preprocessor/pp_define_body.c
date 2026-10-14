uint __cdecl pp_define_body(void)

{
  c1_u8 cVar1;
  byte c;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int stringize;
  byte *out;
  byte *pbVar5;
  uint ch_cell;
  int charize;
  uint local_1c;
  
  stringize = 0;
  charize = 0;
  do {
    c = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
  } while (g_char_class[c] == '\x01');
  bVar2 = g_char_flags[c];
  out = g_define_text_ptr;
  do {
    if ((bVar2 & 0x20) == 0) {
      c = lex_skip_comment(c);
    }
LAB_104384d4:
    ch_cell = CONCAT31(ch_cell._1_3_,c);
    pbVar5 = out;
LAB_1043850c:
    out = pbVar5;
    if (g_macro_text_buffer_limit <= out) {
      pp_define_check_size((uint)out,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit);
    }
    pbVar5 = out;
    switch(g_char_class[ch_cell & 0xff]) {
    case '\0':
      uVar3 = lex_buffer_refill();
      if ((uVar3 & 0x50) == 0) goto LAB_104384fb;
      if ((uVar3 & 0x10) == 0) goto switchD_10438538_caseD_2;
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
switchD_10438538_caseD_1:
      do {
        c = *g_input_ptr;
        g_input_ptr = g_input_ptr + 1;
      } while (g_char_class[c] == '\x01');
      if ((g_char_flags[c] & 0x20) == 0) {
        c = lex_skip_comment(c);
      }
      ch_cell = CONCAT31(ch_cell._1_3_,c);
      if (c != 10) {
        *out = 0x20;
        pbVar5 = out + 1;
      }
      goto LAB_1043850c;
    case '\x05':
      g_input_ptr = g_input_ptr + -1;
      pbVar5 = g_define_text_ptr;
      if (g_ms_extensions == '\0') {
        pbVar5 = g_macro_text_buffer;
      }
      if (out == pbVar5) {
        return 0;
      }
      if (g_macro_text_buffer_limit <= out) {
        pp_define_check_size((uint)out,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit);
      }
      *out = 0;
      out[1] = 0x44;
      return (uint)(out + 1 + (1 - (int)g_define_text_ptr));
    case '\x06':
    case '\a':
switchD_10438538_caseD_6:
      do {
        do {
          if (g_macro_text_buffer_limit <= pbVar5) {
            pp_define_check_size
                      ((uint)pbVar5,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit);
          }
          *pbVar5 = c;
          pbVar5 = pbVar5 + 1;
          c = *g_input_ptr;
          g_input_ptr = g_input_ptr + 1;
          ch_cell = CONCAT31(ch_cell._1_3_,c);
          uVar3 = (uint)c;
        } while ((g_char_flags[uVar3] & 3) != 0);
        do {
          if ((g_char_class[uVar3] != '\0') ||
             (uVar3 = lex_buffer_refill(), (uVar3 & 0xffffffaf) == 0)) {
            if (0 < g_define_formal_count) {
              *pbVar5 = 0;
              iVar4 = pp_define_find_formal(out);
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
                    *out = 1;
                    out[1] = bVar2;
                    stringize = 0;
                    charize = 0;
                    pbVar5 = out + 2;
                  }
                  else {
                    *out = 3;
                    out[1] = bVar2;
                    stringize = 0;
                    charize = 0;
                    pbVar5 = out + 2;
                  }
                }
                else {
                  *out = 2;
                  out[1] = bVar2;
                  stringize = 0;
                  charize = 0;
                  pbVar5 = out + 2;
                }
              }
            }
            goto LAB_1043850c;
          }
          c = *g_input_ptr;
          g_input_ptr = g_input_ptr + 1;
          ch_cell = CONCAT31(ch_cell._1_3_,c);
          uVar3 = (uint)c;
        } while ((g_char_flags[uVar3] & 3) == 0);
      } while( true );
    case '\v':
      cVar1 = g_char_class[*g_input_ptr];
      while (g_input_ptr = g_input_ptr + 1, cVar1 == '\0') {
        uVar3 = lex_buffer_refill();
        if ((uVar3 & 0xffffffaf) == 0) goto LAB_104385e4;
        cVar1 = g_char_class[*g_input_ptr];
      }
      if (cVar1 == '\v') goto code_r0x1043857c;
      if (cVar1 == '\"') {
        if ((g_define_formal_count < 1) || (g_ms_extensions == '\0')) {
          *out = 0x23;
          out = out + 1;
          c = g_input_ptr[-1];
          goto LAB_104384d4;
        }
        charize = 1;
      }
      else {
LAB_104385e4:
        if (g_define_formal_count < 1) goto LAB_1045cca6;
        stringize = 1;
        g_input_ptr = g_input_ptr + -1;
      }
      do {
        c = *g_input_ptr;
        g_input_ptr = g_input_ptr + 1;
      } while (g_char_class[c] == '\x01');
      if ((g_char_flags[c] & 0x20) == 0) {
        c = lex_skip_comment(c);
      }
      ch_cell = CONCAT31(ch_cell._1_3_,c);
      if ((g_char_flags[c] & 1) != 0) goto switchD_10438538_caseD_6;
      stringize = 0;
      charize = 0;
      diag_error(0xa2);
      goto LAB_1043850c;
    case '\x15':
    case '\x16':
      out = pp_copy_quoted_text(out,(uint *)&g_macro_text_buffer_limit,(byte)ch_cell);
      goto LAB_104384fb;
    case '!':
      diag_error(0x12,ch_cell & 0xff);
      goto LAB_104384fb;
    case '#':
      *out = c;
      c = lex_skip_mbcs_trail_byte();
      pbVar5 = out + 1;
switchD_10438538_caseD_2:
      *pbVar5 = c;
      out = pbVar5 + 1;
LAB_104384fb:
      c = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
      ch_cell = CONCAT31(ch_cell._1_3_,c);
      pbVar5 = out;
      goto LAB_1043850c;
    }
    *out = c;
    pbVar5 = out + 1;
    c = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    if (g_char_class[c] == '\0') {
      c = lex_next_significant_char(c);
    }
    local_1c = (uint)c;
    if ((g_char_class[local_1c] < 0x15) || (0x16 < g_char_class[local_1c]))
    goto switchD_10438538_caseD_2;
    diag_error(0x127,local_1c);
    do {
      c = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
    } while (g_char_class[c] == '\x01');
    bVar2 = g_char_flags[c];
  } while( true );
code_r0x1043857c:
  if (out == g_define_text_ptr) {
    diag_error(0xa0);
  }
  else {
    if (out[-1] == 0x20) {
      out = out + -1;
    }
    do {
      c = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
    } while (g_char_class[c] == '\x01');
    if ((g_char_flags[c] & 0x20) == 0) {
      c = lex_skip_comment(c);
    }
    ch_cell = CONCAT31(ch_cell._1_3_,c);
    pbVar5 = out;
    if (c == 10) {
      uVar3 = pp_define_check_paste(10,out,stringize,ch_cell,charize);
      return uVar3;
    }
  }
  goto LAB_1043850c;
LAB_1045cca6:
  *out = 0x23;
  out = out + 1;
  c = g_input_ptr[-1];
  goto LAB_104384d4;
}

