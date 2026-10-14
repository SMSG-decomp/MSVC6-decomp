byte * __cdecl
pp_define_scan_replacement(c1_u8 ch,byte *cursor,int stringize_pending,int charize_pending)

{
  c1_u8 cVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint in_stack_00000010;
  uint uStack00000018;
  
  g_input_ptr = g_input_ptr + -1;
  diag_error(0xa1);
LAB_1060e445:
  pbVar6 = cursor;
  if (g_macro_text_buffer_limit <= pbVar6) {
    pp_define_check_size((uint)pbVar6,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit);
  }
  pbVar7 = pbVar6;
  cursor = pbVar6;
  switch(g_char_class[in_stack_00000010 & 0xff]) {
  case '\0':
    uVar5 = lex_buffer_refill();
    if ((uVar5 & 0x50) != 0) {
      if ((uVar5 & 0x10) != 0) {
        *pbVar6 = ch;
        pbVar7 = pbVar6 + 1;
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
          goto LAB_1060e411;
        }
      }
      goto switchD_1060e471_caseD_2;
    }
    break;
  case '\x01':
switchD_1060e471_caseD_1:
    do {
      ch = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
    } while (g_char_class[ch] == '\x01');
    if ((g_char_flags[ch] & 0x20) == 0) {
      ch = lex_skip_comment(ch);
    }
    in_stack_00000010 = CONCAT31(in_stack_00000010._1_3_,ch);
    if (ch != 10) {
      *pbVar6 = 0x20;
      cursor = pbVar6 + 1;
    }
    goto LAB_1060e445;
  default:
    goto switchD_1060e471_caseD_2;
  case '\x03':
    if ((g_ms_extensions == '\0') && (g_pch_option_block == 0)) {
      bVar3 = lex_get_char();
      if (bVar3 == 0x2f) {
        bVar3 = *g_input_ptr;
        g_input_ptr = g_input_ptr + 1;
        if (g_char_class[bVar3] == '\0') {
          bVar3 = lex_next_significant_char(bVar3);
        }
        if (bVar3 != 0x2a) {
          g_input_ptr = g_input_ptr + -1;
          diag_warning(4,1);
          goto LAB_10629478;
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
        bVar3 = g_input_ptr[-1];
        if (g_char_class[bVar3] == '\0') {
          bVar3 = lex_next_significant_char(bVar3);
        }
        if (bVar3 == 0x2a) {
LAB_1060e7bc:
          if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
            g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
            pp_skip_block_comment();
          }
          else {
            g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
            pp_output_skip_comment();
          }
          goto LAB_1060e7dd;
        }
        g_input_ptr = g_input_ptr + -1;
      }
LAB_1060e756:
      bVar2 = false;
    }
    else {
      bVar3 = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
      if (g_char_class[bVar3] == '\0') {
        bVar3 = lex_next_significant_char(bVar3);
      }
      if (bVar3 != 0x2f) {
        bVar3 = g_input_ptr[-1];
        if (g_char_class[bVar3] == '\0') {
          bVar3 = lex_next_significant_char(bVar3);
        }
        if (bVar3 == 0x2a) goto LAB_1060e7bc;
        g_input_ptr = g_input_ptr + -1;
        goto LAB_1060e756;
      }
LAB_10629478:
      g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
      pp_output_copy_comment();
LAB_1060e7dd:
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
      bVar2 = true;
    }
    if (bVar2) goto switchD_1060e471_caseD_1;
    goto switchD_1060e471_caseD_2;
  case '\x05':
    g_input_ptr = g_input_ptr + -1;
    pbVar7 = g_define_text_ptr;
    if (g_ms_extensions == '\0') {
      pbVar7 = g_macro_text_buffer;
    }
    if (pbVar6 == pbVar7) {
      return (byte *)0x0;
    }
    if (g_macro_text_buffer_limit <= pbVar6) {
      pp_define_check_size((uint)pbVar6,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit);
    }
    *pbVar6 = 0;
    pbVar6[1] = 0x44;
    return pbVar6 + 1 + (1 - (int)g_define_text_ptr);
  case '\x06':
  case '\a':
    goto switchD_1060e471_caseD_6;
  case '\v':
    cVar1 = g_char_class[*g_input_ptr];
    while (g_input_ptr = g_input_ptr + 1, cVar1 == '\0') {
      uVar5 = lex_buffer_refill();
      if ((uVar5 & 0xffffffaf) == 0) goto LAB_1060e56a;
      cVar1 = g_char_class[*g_input_ptr];
    }
    if (cVar1 == '\v') goto code_r0x1060e505;
    if (cVar1 == '\"') {
      if ((0 < g_define_formal_count) && (g_ms_extensions != '\0')) {
        charize_pending = 1;
LAB_1060e589:
        do {
          ch = *g_input_ptr;
          g_input_ptr = g_input_ptr + 1;
        } while (g_char_class[ch] == '\x01');
        if ((g_char_flags[ch] & 0x20) == 0) {
          ch = lex_skip_comment(ch);
        }
        in_stack_00000010 = CONCAT31(in_stack_00000010._1_3_,ch);
        if ((g_char_flags[ch] & 1) != 0) {
switchD_1060e471_caseD_6:
          do {
            do {
              if (g_macro_text_buffer_limit <= cursor) {
                pp_define_check_size
                          ((uint)cursor,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit);
              }
              *cursor = ch;
              cursor = cursor + 1;
              ch = *g_input_ptr;
              g_input_ptr = g_input_ptr + 1;
              in_stack_00000010 = CONCAT31(in_stack_00000010._1_3_,ch);
              uVar5 = (uint)ch;
            } while ((g_char_flags[uVar5] & 3) != 0);
            do {
              if ((g_char_class[uVar5] != '\0') ||
                 (uVar5 = lex_buffer_refill(), (uVar5 & 0xffffffaf) == 0)) {
                if (0 < g_define_formal_count) {
                  *cursor = 0;
                  iVar4 = pp_define_find_formal(pbVar6);
                  if (iVar4 < 1) {
                    if ((charize_pending != 0) || (stringize_pending != 0)) {
                      diag_error(0xa2);
                    }
                    stringize_pending = 0;
                    charize_pending = 0;
                  }
                  else {
                    bVar3 = (byte)iVar4;
                    if (stringize_pending == 0) {
                      if (charize_pending == 0) {
                        *pbVar6 = 1;
                        pbVar6[1] = bVar3;
                        stringize_pending = 0;
                        charize_pending = 0;
                        cursor = pbVar6 + 2;
                      }
                      else {
                        *pbVar6 = 3;
                        pbVar6[1] = bVar3;
                        stringize_pending = 0;
                        charize_pending = 0;
                        cursor = pbVar6 + 2;
                      }
                    }
                    else {
                      *pbVar6 = 2;
                      pbVar6[1] = bVar3;
                      stringize_pending = 0;
                      charize_pending = 0;
                      cursor = pbVar6 + 2;
                    }
                  }
                }
                goto LAB_1060e445;
              }
              ch = *g_input_ptr;
              g_input_ptr = g_input_ptr + 1;
              in_stack_00000010 = CONCAT31(in_stack_00000010._1_3_,ch);
              uVar5 = (uint)ch;
            } while ((g_char_flags[uVar5] & 3) == 0);
          } while( true );
        }
        stringize_pending = 0;
        charize_pending = 0;
        diag_error(0xa2);
        goto LAB_1060e445;
      }
      *pbVar6 = 0x23;
      pbVar6 = pbVar6 + 1;
      ch = g_input_ptr[-1];
    }
    else {
LAB_1060e56a:
      if (0 < g_define_formal_count) {
        stringize_pending = 1;
        g_input_ptr = g_input_ptr + -1;
        goto LAB_1060e589;
      }
      *pbVar6 = 0x23;
      pbVar6 = pbVar6 + 1;
      ch = g_input_ptr[-1];
    }
LAB_1060e411:
    in_stack_00000010 = CONCAT31(in_stack_00000010._1_3_,ch);
    cursor = pbVar6;
    goto LAB_1060e445;
  case '\x15':
  case '\x16':
    pbVar6 = pp_copy_quoted_text(pbVar6,(uint *)&g_macro_text_buffer_limit,(byte)in_stack_00000010);
    break;
  case '!':
    diag_error(0x12,in_stack_00000010 & 0xff);
    break;
  case '#':
    *pbVar6 = ch;
    ch = lex_skip_mbcs_trail_byte();
    pbVar7 = pbVar6 + 1;
switchD_1060e471_caseD_2:
    *pbVar7 = ch;
    pbVar6 = pbVar7 + 1;
  }
  ch = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  in_stack_00000010 = CONCAT31(in_stack_00000010._1_3_,ch);
  cursor = pbVar6;
  goto LAB_1060e445;
code_r0x1060e505:
  if (pbVar6 == g_define_text_ptr) {
    diag_error(0xa0);
  }
  else {
    if (pbVar6[-1] == 0x20) {
      pbVar6 = pbVar6 + -1;
    }
    do {
      ch = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
    } while (g_char_class[ch] == '\x01');
    if ((g_char_flags[ch] & 0x20) == 0) {
      ch = lex_skip_comment(ch);
    }
    in_stack_00000010 = CONCAT31(in_stack_00000010._1_3_,ch);
    cursor = pbVar6;
    if (ch == 10) {
      pbVar6 = pp_define_scan_replacement('\n',pbVar6,stringize_pending,charize_pending);
      return pbVar6;
    }
  }
  goto LAB_1060e445;
}

