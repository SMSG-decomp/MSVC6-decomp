void __cdecl pp_macro_collect_argument_text(fe_macro *macro,int formal_count)

{
  bool bVar1;
  uchar *puVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  short *text;
  uint uVar6;
  byte *pbVar7;
  uint *start;
  byte *pbVar8;
  char local_1d;
  int local_1c;
  uint local_18;
  uint slash_next_char;
  uint star_check_char;
  uint slash_next_char_2;
  uint star_check_char_2;
  byte *local_4;
  
  *g_macro_text_cursor = g_input_ptr[-1];
  g_macro_text_cursor = g_macro_text_cursor + 1;
  local_1c = 0;
  local_4 = g_macro_arg_cursor;
LAB_1060bd00:
  if (g_macro_text_buffer_limit <= g_macro_text_cursor) {
    pp_define_check_size
              ((uint)g_macro_text_cursor,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit)
    ;
  }
  do {
    iVar5 = pp_skip_blanks_in_macro_text();
    if (iVar5 == 0) goto LAB_1060bfbd;
    start = (uint *)g_macro_text_cursor;
    if (*g_input_ptr != 0x2f) goto LAB_1060bd2e;
    if ((g_ms_extensions == '\0') && (g_pch_option_block == 0)) {
      g_input_ptr = g_input_ptr + 1;
      bVar3 = lex_get_char();
      if (bVar3 == 0x2f) {
        bVar3 = lex_get_char();
        if (bVar3 != 0x2a) {
          g_input_ptr = g_input_ptr + -1;
          diag_warning(4,1);
          goto LAB_10629af9;
        }
        diag_warning(4,0xb3);
        g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
        pp_block_comment_dispatch();
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
      }
      else {
        g_input_ptr = g_input_ptr + -1;
        bVar3 = lex_get_char();
        if (bVar3 == 0x2a) {
          g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
          pp_block_comment_dispatch();
          goto LAB_10629aa5;
        }
LAB_10629be6:
        g_input_ptr = g_input_ptr + -1;
      }
      bVar1 = false;
    }
    else {
      bVar3 = g_input_ptr[1];
      slash_next_char = CONCAT31(slash_next_char._1_3_,bVar3);
      g_input_ptr = g_input_ptr + 2;
      if (g_char_class[bVar3] == '\0') {
        bVar3 = lex_next_significant_char(bVar3);
      }
      if (bVar3 != 0x2f) {
        bVar3 = g_input_ptr[-1];
        star_check_char = CONCAT31(star_check_char._1_3_,bVar3);
        if (g_char_class[bVar3] == '\0') {
          bVar3 = lex_next_significant_char(bVar3);
        }
        if (bVar3 == 0x2a) {
          if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
            g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
            pp_skip_block_comment();
          }
          else {
            g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
            pp_output_skip_comment();
          }
          goto LAB_10629aa5;
        }
        goto LAB_10629be6;
      }
LAB_10629af9:
      g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
      pp_output_copy_comment();
LAB_10629aa5:
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
      bVar1 = true;
    }
    start = (uint *)g_macro_text_cursor;
  } while (bVar1);
  *g_macro_text_cursor = '/';
  g_macro_text_cursor = g_macro_text_cursor + 1;
LAB_1060bd2e:
  local_1d = '\0';
  pbVar7 = g_input_ptr;
LAB_1060bd38:
  g_input_ptr = pbVar7;
  puVar2 = g_macro_text_cursor;
  pbVar7 = g_macro_arg_cursor;
  bVar3 = *g_input_ptr;
  local_18 = CONCAT31(local_18._1_3_,bVar3);
  pbVar8 = g_input_ptr + 1;
  g_macro_arg_cursor = pbVar7;
  g_macro_text_cursor = puVar2;
  switch(g_char_class[bVar3]) {
  case '\0':
    g_input_ptr = pbVar8;
    uVar6 = lex_buffer_refill();
    if ((uVar6 & 10) != 0) {
      return;
    }
    g_macro_arg_cursor = pbVar7;
    g_macro_text_cursor = puVar2;
    pbVar8 = g_input_ptr;
    pbVar7 = g_input_ptr;
    if ((uVar6 & 0x50) == 0) goto LAB_1060bd38;
    break;
  case '\x01':
  case '\x05':
    goto switchD_1060bd72_caseD_1;
  case '\x03':
    if ((g_ms_extensions == '\0') && (g_pch_option_block == 0)) {
      g_input_ptr = pbVar8;
      bVar4 = lex_get_char();
      if (bVar4 == 0x2f) {
        bVar4 = lex_get_char();
        if (bVar4 != 0x2a) {
          g_input_ptr = g_input_ptr + -1;
          diag_warning(4,1);
          goto LAB_1060bdb0;
        }
        diag_warning(4,0xb3);
        if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
          g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
          pp_skip_block_comment();
          g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
        }
        else {
          g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
          pp_output_skip_comment();
          g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
        }
      }
      else {
        g_input_ptr = g_input_ptr + -1;
        bVar4 = lex_get_char();
        if (bVar4 == 0x2a) {
          g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
          pp_block_comment_dispatch();
          goto LAB_1060bdc4;
        }
LAB_10629cd6:
        g_input_ptr = g_input_ptr + -1;
      }
      bVar1 = false;
    }
    else {
      bVar4 = *pbVar8;
      slash_next_char_2 = CONCAT31(slash_next_char_2._1_3_,bVar4);
      g_input_ptr = g_input_ptr + 2;
      if (g_char_class[bVar4] == '\0') {
        bVar4 = lex_next_significant_char(bVar4);
      }
      if (bVar4 != 0x2f) {
        bVar4 = g_input_ptr[-1];
        star_check_char_2 = CONCAT31(star_check_char_2._1_3_,bVar4);
        if (g_char_class[bVar4] == '\0') {
          bVar4 = lex_next_significant_char(bVar4);
        }
        if (bVar4 == 0x2a) {
          if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
            g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
            pp_skip_block_comment();
          }
          else {
            g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
            pp_output_skip_comment();
          }
          goto LAB_1060bdc4;
        }
        goto LAB_10629cd6;
      }
LAB_1060bdb0:
      g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
      pp_output_copy_comment();
LAB_1060bdc4:
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
      bVar1 = true;
    }
    pbVar8 = g_input_ptr;
    if (bVar1) {
      if ((g_macro_text_buffer < g_macro_text_cursor) &&
         (pbVar7 = g_input_ptr, g_macro_text_cursor[-1] == ' ')) goto LAB_1060bd38;
      bVar3 = 0x20;
    }
    break;
  case '\x04':
    local_1c = local_1c + 1;
    break;
  case '\x06':
  case '\a':
    g_input_ptr = pbVar8;
    *g_macro_text_cursor = bVar3;
    bVar3 = *g_input_ptr;
    local_18 = CONCAT31(local_18._1_3_,bVar3);
    bVar4 = g_char_flags[bVar3];
    pbVar7 = g_input_ptr;
    while( true ) {
      g_input_ptr = pbVar7 + 1;
      g_macro_text_cursor = g_macro_text_cursor + 1;
      if ((bVar4 & 3) == 0) break;
      if (g_macro_text_buffer_limit <= g_macro_text_cursor) {
        pp_define_check_size
                  ((uint)g_macro_text_cursor,(int)g_macro_text_buffer,
                   (int *)&g_macro_text_buffer_limit);
      }
      *g_macro_text_cursor = bVar3;
      bVar3 = *g_input_ptr;
      local_18 = CONCAT31(local_18._1_3_,bVar3);
      bVar4 = g_char_flags[bVar3];
      pbVar7 = g_input_ptr;
    }
    if (g_char_class[local_18 & 0xff] == '&') {
      local_1d = '\x01';
      pbVar8 = g_input_ptr;
      goto switchD_1060bd72_caseD_26;
    }
    goto LAB_1060bd38;
  case '\x15':
  case '\x16':
    g_input_ptr = pbVar8;
    g_macro_text_cursor =
         pp_copy_quoted_text(g_macro_text_cursor,(uint *)&g_macro_text_buffer_limit,bVar3);
    pbVar7 = g_input_ptr;
    goto LAB_1060bd38;
  case '\x1b':
    g_input_ptr = pbVar8;
    if (local_1c == 0) goto LAB_1060bca3;
    break;
  case '\x1c':
    local_1c = local_1c + -1;
    g_input_ptr = pbVar8;
    if (local_1c < 0) goto LAB_1060bca3;
    break;
  case '&':
switchD_1060bd72_caseD_26:
    g_input_ptr = pbVar8;
    text = pp_macro_formal_argument_text(&local_1d);
    pp_macro_text_append_string((uchar *)text);
    pbVar7 = g_input_ptr;
    goto LAB_1060bd38;
  case '\'':
    g_input_ptr = pbVar8;
    pbVar7 = (byte *)pp_macro_argument_text();
    pp_macro_stringize(0x22,pbVar7);
    pbVar7 = g_input_ptr;
    goto LAB_1060bd38;
  case '(':
    g_input_ptr = pbVar8;
    pbVar7 = (byte *)pp_macro_argument_text();
    pp_macro_stringize(0x27,pbVar7);
    pbVar7 = g_input_ptr;
    goto LAB_1060bd38;
  }
  g_input_ptr = pbVar8;
  *g_macro_text_cursor = bVar3;
  g_macro_text_cursor = g_macro_text_cursor + 1;
  pbVar7 = g_input_ptr;
  goto LAB_1060bd38;
switchD_1060bd72_caseD_1:
  iVar5 = pp_skip_blanks_in_macro_text();
  pbVar7 = g_input_ptr;
  if (iVar5 == 0) goto LAB_1060bca3;
  goto LAB_1060bd38;
LAB_1060bca3:
  if (((g_macro_text_buffer <= g_macro_text_cursor + -2) &&
      (g_char_class[g_macro_text_cursor[-1]] == '\x01')) &&
     (g_char_class[g_macro_text_cursor[-2]] != ')')) {
    g_macro_text_cursor = g_macro_text_cursor + -1;
  }
  if (start < g_macro_text_cursor) {
    g_macro_arg_count = g_macro_arg_count + 1;
    pp_macro_save_expansion(start,(int)g_macro_text_cursor);
  }
  *g_macro_text_cursor = bVar3;
  g_macro_text_cursor = g_macro_text_cursor + 1;
  if (local_1c < 0) goto LAB_1060bfbd;
  goto LAB_1060bd00;
LAB_1060bfbd:
  g_macro_arg_start = local_4;
  if (formal_count < g_macro_arg_count) {
    iVar5 = 2;
  }
  else {
    if (formal_count <= g_macro_arg_count) goto LAB_1060bfdf;
    iVar5 = 3;
  }
  diag_warning(1,iVar5,g_last_name);
LAB_1060bfdf:
  if (macro->def->text[0] == '\0') {
    g_macro_text_cursor = g_macro_expansion_text_start;
    g_macro_arg_cursor = g_macro_arg_start;
    return;
  }
  pp_macro_check_nesting(macro);
  pp_macro_next_text_segment();
  return;
}

