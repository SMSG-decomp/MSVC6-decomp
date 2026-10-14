void __cdecl pp_macro_collect_arguments_text(fe_macro *macro,int nformals)

{
  byte *saved_level;
  uchar *puVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  short *text;
  uint uVar5;
  uint *start;
  byte *pbVar6;
  int iVar7;
  uint cur_char;
  uint saved_c14;
  uint saved_c10;
  uint saved_c0c;
  uint saved_c08;
  byte *saved_arg_cursor;
  byte *saved_2e54;
  
  *g_macro_text_cursor = g_input_ptr[-1];
  saved_level = g_macro_arg_cursor;
  g_macro_text_cursor = g_macro_text_cursor + 1;
  iVar7 = 0;
LAB_1040fd0f:
  if (g_macro_text_buffer_limit <= g_macro_text_cursor) {
    pp_define_check_size
              ((uint)g_macro_text_cursor,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit)
    ;
  }
  while( true ) {
    while( true ) {
      iVar4 = pp_skip_blanks_in_macro_text();
      if (iVar4 == 0) goto LAB_1040fdeb;
      pbVar6 = g_input_ptr;
      start = (uint *)g_macro_text_cursor;
      if (*g_input_ptr != 0x2f) goto LAB_1040fd44;
      bVar2 = g_input_ptr[1];
      saved_c14 = CONCAT31(saved_c14._1_3_,bVar2);
      g_input_ptr = g_input_ptr + 2;
      if (g_char_class[bVar2] == '\0') {
        bVar2 = lex_next_significant_char(bVar2);
      }
      if (bVar2 != 0x2f) break;
      g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
      pp_output_copy_comment();
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
    }
    bVar2 = g_input_ptr[-1];
    saved_c10 = CONCAT31(saved_c10._1_3_,bVar2);
    if (g_char_class[bVar2] == '\0') {
      bVar2 = lex_next_significant_char(bVar2);
    }
    start = (uint *)g_macro_text_cursor;
    if (bVar2 != 0x2a) break;
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
  g_input_ptr = g_input_ptr + -1;
  *g_macro_text_cursor = '/';
  g_macro_text_cursor = g_macro_text_cursor + 1;
  pbVar6 = g_input_ptr;
LAB_1040fd44:
  do {
    g_input_ptr = pbVar6;
    puVar1 = g_macro_text_cursor;
    saved_2e54 = g_macro_arg_cursor;
    bVar2 = *g_input_ptr;
    cur_char = CONCAT31(cur_char._1_3_,bVar2);
    pbVar6 = g_input_ptr + 1;
    switch(g_char_class[bVar2]) {
    case '\0':
      g_input_ptr = pbVar6;
      uVar5 = lex_buffer_refill();
      if ((uVar5 & 10) != 0) {
        return;
      }
      g_macro_arg_cursor = saved_2e54;
      g_macro_text_cursor = puVar1;
      pbVar6 = g_input_ptr;
      if ((uVar5 & 0x50) == 0) break;
    default:
      g_input_ptr = pbVar6;
      g_macro_arg_cursor = saved_2e54;
      g_macro_text_cursor = puVar1;
      *puVar1 = bVar2;
      g_macro_text_cursor = g_macro_text_cursor + 1;
      pbVar6 = g_input_ptr;
      break;
    case '\x01':
    case '\x05':
      goto switchD_1040fd7d_caseD_1;
    case '\x03':
      bVar3 = *pbVar6;
      saved_c0c = CONCAT31(saved_c0c._1_3_,bVar3);
      g_input_ptr = g_input_ptr + 2;
      if (g_char_class[bVar3] == '\0') {
        bVar3 = lex_next_significant_char(bVar3);
      }
      if (bVar3 == 0x2f) {
        g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
        pp_output_copy_comment();
      }
      else {
        bVar3 = g_input_ptr[-1];
        saved_c08 = CONCAT31(saved_c08._1_3_,bVar3);
        if (g_char_class[bVar3] == '\0') {
          bVar3 = lex_next_significant_char(bVar3);
        }
        if (bVar3 != 0x2a) {
          g_input_ptr = g_input_ptr + -1;
          *g_macro_text_cursor = bVar2;
          g_macro_text_cursor = g_macro_text_cursor + 1;
          pbVar6 = g_input_ptr;
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
      if ((g_macro_text_cursor <= g_macro_text_buffer) ||
         (pbVar6 = g_input_ptr, g_macro_text_cursor[-1] != ' ')) {
        *g_macro_text_cursor = ' ';
        g_macro_text_cursor = g_macro_text_cursor + 1;
        pbVar6 = g_input_ptr;
      }
      break;
    case '\x04':
      g_input_ptr = pbVar6;
      *g_macro_text_cursor = bVar2;
      iVar7 = iVar7 + 1;
      g_macro_text_cursor = g_macro_text_cursor + 1;
      pbVar6 = g_input_ptr;
      break;
    case '\x06':
    case '\a':
      g_input_ptr = pbVar6;
      *g_macro_text_cursor = bVar2;
      bVar2 = *g_input_ptr;
      cur_char = CONCAT31(cur_char._1_3_,bVar2);
      bVar3 = g_char_flags[bVar2];
      pbVar6 = g_input_ptr;
      while( true ) {
        g_input_ptr = pbVar6 + 1;
        g_macro_text_cursor = g_macro_text_cursor + 1;
        if ((bVar3 & 3) == 0) break;
        if (g_macro_text_buffer_limit <= g_macro_text_cursor) {
          pp_define_check_size
                    ((uint)g_macro_text_cursor,(int)g_macro_text_buffer,
                     (int *)&g_macro_text_buffer_limit);
        }
        *g_macro_text_cursor = bVar2;
        bVar2 = *g_input_ptr;
        cur_char._1_3_ = (undefined3)(cur_char >> 8);
        cur_char = CONCAT31(cur_char._1_3_,bVar2);
        bVar3 = g_char_flags[bVar2];
        pbVar6 = g_input_ptr;
      }
      if (g_char_class[cur_char & 0xff] == '&') {
        pp_macro_collect_arguments_formal_case
                  ((uchar *)start,'\x01',iVar7,cur_char,saved_c14,saved_c10,saved_c0c,saved_c08,
                   saved_level,(int)macro,nformals);
        return;
      }
      break;
    case '\x15':
    case '\x16':
      g_input_ptr = pbVar6;
      g_macro_text_cursor =
           pp_copy_quoted_text(g_macro_text_cursor,(uint *)&g_macro_text_buffer_limit,bVar2);
      pbVar6 = g_input_ptr;
      break;
    case '\x1b':
      g_input_ptr = pbVar6;
      if (iVar7 == 0) goto LAB_1040fd93;
      *g_macro_text_cursor = bVar2;
      g_macro_text_cursor = g_macro_text_cursor + 1;
      pbVar6 = g_input_ptr;
      break;
    case '\x1c':
      iVar7 = iVar7 + -1;
      g_input_ptr = pbVar6;
      if (iVar7 < 0) goto LAB_1040fd93;
      *g_macro_text_cursor = bVar2;
      g_macro_text_cursor = g_macro_text_cursor + 1;
      pbVar6 = g_input_ptr;
      break;
    case '&':
      g_input_ptr = pbVar6;
      text = pp_macro_formal_argument_text(&stack0xffffffe3);
      pp_macro_text_append_string((uchar *)text);
      pbVar6 = g_input_ptr;
      break;
    case '\'':
      g_input_ptr = pbVar6;
      pbVar6 = (byte *)pp_macro_argument_text();
      pp_macro_stringize(0x22,pbVar6);
      pbVar6 = g_input_ptr;
      break;
    case '(':
      g_input_ptr = pbVar6;
      pbVar6 = (byte *)pp_macro_argument_text();
      pp_macro_stringize(0x27,pbVar6);
      pbVar6 = g_input_ptr;
    }
  } while( true );
switchD_1040fd7d_caseD_1:
  iVar4 = pp_skip_blanks_in_macro_text();
  pbVar6 = g_input_ptr;
  if (iVar4 == 0) goto LAB_1040fd93;
  goto LAB_1040fd44;
LAB_1040fd93:
  if (((g_macro_text_buffer <= g_macro_text_cursor + -2) &&
      (g_char_class[g_macro_text_cursor[-1]] == '\x01')) &&
     (g_char_class[g_macro_text_cursor[-2]] != ')')) {
    g_macro_text_cursor = g_macro_text_cursor + -1;
  }
  if (start < g_macro_text_cursor) {
    g_macro_arg_count = g_macro_arg_count + 1;
    pp_macro_save_expansion(start,(int)g_macro_text_cursor);
  }
  *g_macro_text_cursor = bVar2;
  g_macro_text_cursor = g_macro_text_cursor + 1;
  if (iVar7 < 0) goto LAB_1040fdeb;
  goto LAB_1040fd0f;
LAB_1040fdeb:
  g_macro_arg_start = saved_level;
  if (nformals < g_macro_arg_count) {
    iVar7 = 2;
  }
  else {
    if (nformals <= g_macro_arg_count) goto LAB_1040fe0c;
    iVar7 = 3;
  }
  diag_warning(1,iVar7,g_last_name);
LAB_1040fe0c:
  if (macro->def->text[0] == '\0') {
    g_macro_text_cursor = g_macro_expansion_text_start;
    g_macro_arg_cursor = g_macro_arg_start;
    return;
  }
  pp_macro_check_nesting(macro);
  pp_macro_next_text_segment();
  return;
}

