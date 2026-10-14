void __cdecl
pp_macro_collect_arguments
          (uchar *text_cursor,byte ch,uchar *arg_start,char pasted,int paren_depth,uint cur_char,
          uint saved_c14,uint saved_c10,uint saved_c0c,uint saved_c08,uchar *saved_level,int macro,
          int nformals)

{
  byte bVar1;
  byte bVar2;
  short *text;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  
  pbVar4 = g_input_ptr;
code_r0x1040ff7c:
  g_input_ptr = pbVar4;
  pbVar4 = g_macro_arg_cursor;
  uVar3 = lex_buffer_refill();
  if ((uVar3 & 10) != 0) {
    return;
  }
  g_macro_arg_cursor = pbVar4;
  g_macro_text_cursor = text_cursor;
  pbVar4 = g_input_ptr;
  if ((uVar3 & 0x50) == 0) goto LAB_1040fd44;
switchD_1040fd7d_caseD_2:
  g_input_ptr = pbVar4;
  *g_macro_text_cursor = ch;
  g_macro_text_cursor = g_macro_text_cursor + 1;
  pbVar4 = g_input_ptr;
LAB_1040fd44:
  g_input_ptr = pbVar4;
  ch = *g_input_ptr;
  cur_char = CONCAT31(cur_char._1_3_,ch);
  pbVar4 = g_input_ptr + 1;
  text_cursor = g_macro_text_cursor;
  switch(g_char_class[ch]) {
  case '\0':
    goto code_r0x1040ff7c;
  case '\x01':
  case '\x05':
    iVar5 = pp_skip_blanks_in_macro_text();
    pbVar4 = g_input_ptr;
    if (iVar5 != 0) goto LAB_1040fd44;
    break;
  default:
    goto switchD_1040fd7d_caseD_2;
  case '\x03':
    bVar2 = *pbVar4;
    saved_c0c = CONCAT31(saved_c0c._1_3_,bVar2);
    g_input_ptr = g_input_ptr + 2;
    if (g_char_class[bVar2] == '\0') {
      bVar2 = lex_next_significant_char(bVar2);
    }
    if (bVar2 == 0x2f) {
      g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
      pp_output_copy_comment();
    }
    else {
      bVar2 = g_input_ptr[-1];
      saved_c08 = CONCAT31(saved_c08._1_3_,bVar2);
      if (g_char_class[bVar2] == '\0') {
        bVar2 = lex_next_significant_char(bVar2);
      }
      if (bVar2 != 0x2a) {
        g_input_ptr = g_input_ptr + -1;
        *g_macro_text_cursor = ch;
        g_macro_text_cursor = g_macro_text_cursor + 1;
        pbVar4 = g_input_ptr;
        goto LAB_1040fd44;
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
       (pbVar4 = g_input_ptr, g_macro_text_cursor[-1] != ' ')) {
      *g_macro_text_cursor = ' ';
      g_macro_text_cursor = g_macro_text_cursor + 1;
      pbVar4 = g_input_ptr;
    }
    goto LAB_1040fd44;
  case '\x04':
    g_input_ptr = pbVar4;
    *g_macro_text_cursor = ch;
    paren_depth = paren_depth + 1;
    g_macro_text_cursor = g_macro_text_cursor + 1;
    pbVar4 = g_input_ptr;
    goto LAB_1040fd44;
  case '\x06':
  case '\a':
    g_input_ptr = pbVar4;
    *g_macro_text_cursor = ch;
    bVar2 = *g_input_ptr;
    cur_char = CONCAT31(cur_char._1_3_,bVar2);
    bVar1 = g_char_flags[bVar2];
    pbVar4 = g_input_ptr;
    while( true ) {
      g_input_ptr = pbVar4 + 1;
      g_macro_text_cursor = g_macro_text_cursor + 1;
      if ((bVar1 & 3) == 0) break;
      if (g_macro_text_buffer_limit <= g_macro_text_cursor) {
        pp_define_check_size
                  ((uint)g_macro_text_cursor,(int)g_macro_text_buffer,
                   (int *)&g_macro_text_buffer_limit);
      }
      *g_macro_text_cursor = bVar2;
      bVar2 = *g_input_ptr;
      cur_char = CONCAT31(cur_char._1_3_,bVar2);
      bVar1 = g_char_flags[bVar2];
      pbVar4 = g_input_ptr;
    }
    if (g_char_class[cur_char & 0xff] == '&') {
      pasted = '\x01';
      pp_macro_collect_arguments_formal_case
                (arg_start,'\x01',paren_depth,cur_char,saved_c14,saved_c10,saved_c0c,saved_c08,
                 saved_level,macro,nformals);
      return;
    }
    goto LAB_1040fd44;
  case '\x15':
  case '\x16':
    g_input_ptr = pbVar4;
    g_macro_text_cursor =
         pp_copy_quoted_text(g_macro_text_cursor,(uint *)&g_macro_text_buffer_limit,ch);
    pbVar4 = g_input_ptr;
    goto LAB_1040fd44;
  case '\x1b':
    g_input_ptr = pbVar4;
    if (paren_depth != 0) {
      *g_macro_text_cursor = ch;
      g_macro_text_cursor = g_macro_text_cursor + 1;
      pbVar4 = g_input_ptr;
      goto LAB_1040fd44;
    }
    break;
  case '\x1c':
    paren_depth = paren_depth + -1;
    g_input_ptr = pbVar4;
    if (-1 < paren_depth) {
      *g_macro_text_cursor = ch;
      g_macro_text_cursor = g_macro_text_cursor + 1;
      pbVar4 = g_input_ptr;
      goto LAB_1040fd44;
    }
    break;
  case '&':
    g_input_ptr = pbVar4;
    text = pp_macro_formal_argument_text(&pasted);
    pp_macro_text_append_string((uchar *)text);
    pbVar4 = g_input_ptr;
    goto LAB_1040fd44;
  case '\'':
    g_input_ptr = pbVar4;
    pbVar4 = (byte *)pp_macro_argument_text();
    pp_macro_stringize(0x22,pbVar4);
    pbVar4 = g_input_ptr;
    goto LAB_1040fd44;
  case '(':
    goto switchD_1040fd7d_caseD_28;
  }
  if (((g_macro_text_buffer <= g_macro_text_cursor + -2) &&
      (g_char_class[g_macro_text_cursor[-1]] == '\x01')) &&
     (g_char_class[g_macro_text_cursor[-2]] != ')')) {
    g_macro_text_cursor = g_macro_text_cursor + -1;
  }
  if (arg_start < g_macro_text_cursor) {
    g_macro_arg_count = g_macro_arg_count + 1;
    pp_macro_save_expansion((uint *)arg_start,(int)g_macro_text_cursor);
  }
  *g_macro_text_cursor = ch;
  g_macro_text_cursor = g_macro_text_cursor + 1;
  if (paren_depth < 0) {
LAB_1040fdeb:
    g_macro_arg_start = saved_level;
    if (nformals < g_macro_arg_count) {
      iVar5 = 2;
    }
    else {
      if (nformals <= g_macro_arg_count) goto LAB_1040fe0c;
      iVar5 = 3;
    }
    diag_warning(1,iVar5,g_last_name);
LAB_1040fe0c:
    if (*(char *)(*(int *)(macro + 4) + 0xc) == '\0') {
      g_macro_arg_cursor = g_macro_arg_start;
      g_macro_text_cursor = g_macro_expansion_text_start;
      return;
    }
    pp_macro_check_nesting((fe_macro *)macro);
    pp_macro_next_text_segment();
    return;
  }
  if (g_macro_text_buffer_limit <= g_macro_text_cursor) {
    pp_define_check_size
              ((uint)g_macro_text_cursor,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit)
    ;
  }
  while( true ) {
    while( true ) {
      iVar5 = pp_skip_blanks_in_macro_text();
      if (iVar5 == 0) goto LAB_1040fdeb;
      arg_start = g_macro_text_cursor;
      if (*g_input_ptr != 0x2f) goto LAB_1040fd3f;
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
    arg_start = g_macro_text_cursor;
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
LAB_1040fd3f:
  pasted = '\0';
  pbVar4 = g_input_ptr;
  goto LAB_1040fd44;
switchD_1040fd7d_caseD_28:
  g_input_ptr = pbVar4;
  pbVar4 = (byte *)pp_macro_argument_text();
  pp_macro_stringize(0x27,pbVar4);
  pbVar4 = g_input_ptr;
  goto LAB_1040fd44;
}

