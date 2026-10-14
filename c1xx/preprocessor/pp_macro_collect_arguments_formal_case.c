void __cdecl
pp_macro_collect_arguments_formal_case
          (uchar *arg_start,char pasted,int paren_depth,uint cur_char,uint saved_c14,uint saved_c10,
          uint saved_c0c,uint saved_c08,uchar *saved_level,int macro,int nformals)

{
  byte *pbVar1;
  uchar *puVar2;
  byte bVar3;
  byte bVar4;
  short *text;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  
  pbVar6 = g_input_ptr;
code_r0x1040ff5e:
  g_input_ptr = pbVar6;
  text = pp_macro_formal_argument_text(&pasted);
  pp_macro_text_append_string((uchar *)text);
  pbVar6 = g_input_ptr;
LAB_1040fd44:
  g_input_ptr = pbVar6;
  puVar2 = g_macro_text_cursor;
  pbVar1 = g_macro_arg_cursor;
  bVar3 = *g_input_ptr;
  cur_char = CONCAT31(cur_char._1_3_,bVar3);
  pbVar6 = g_input_ptr + 1;
  switch(g_char_class[bVar3]) {
  case '\0':
    g_input_ptr = pbVar6;
    uVar5 = lex_buffer_refill();
    if ((uVar5 & 10) != 0) {
      return;
    }
    g_macro_arg_cursor = pbVar1;
    g_macro_text_cursor = puVar2;
    pbVar6 = g_input_ptr;
    if ((uVar5 & 0x50) != 0) goto switchD_1040fd7d_caseD_2;
    goto LAB_1040fd44;
  case '\x01':
  case '\x05':
    iVar7 = pp_skip_blanks_in_macro_text();
    pbVar6 = g_input_ptr;
    if (iVar7 != 0) goto LAB_1040fd44;
    break;
  default:
switchD_1040fd7d_caseD_2:
    g_input_ptr = pbVar6;
    g_macro_arg_cursor = pbVar1;
    g_macro_text_cursor = puVar2;
    *puVar2 = bVar3;
    g_macro_text_cursor = g_macro_text_cursor + 1;
    pbVar6 = g_input_ptr;
    goto LAB_1040fd44;
  case '\x03':
    bVar4 = *pbVar6;
    saved_c0c = CONCAT31(saved_c0c._1_3_,bVar4);
    g_input_ptr = g_input_ptr + 2;
    if (g_char_class[bVar4] == '\0') {
      bVar4 = lex_next_significant_char(bVar4);
    }
    if (bVar4 == 0x2f) {
      g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
      pp_output_copy_comment();
    }
    else {
      bVar4 = g_input_ptr[-1];
      saved_c08 = CONCAT31(saved_c08._1_3_,bVar4);
      if (g_char_class[bVar4] == '\0') {
        bVar4 = lex_next_significant_char(bVar4);
      }
      if (bVar4 != 0x2a) {
        g_input_ptr = g_input_ptr + -1;
        *g_macro_text_cursor = bVar3;
        g_macro_text_cursor = g_macro_text_cursor + 1;
        pbVar6 = g_input_ptr;
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
       (pbVar6 = g_input_ptr, g_macro_text_cursor[-1] != ' ')) {
      *g_macro_text_cursor = ' ';
      g_macro_text_cursor = g_macro_text_cursor + 1;
      pbVar6 = g_input_ptr;
    }
    goto LAB_1040fd44;
  case '\x04':
    g_input_ptr = pbVar6;
    *g_macro_text_cursor = bVar3;
    paren_depth = paren_depth + 1;
    g_macro_text_cursor = g_macro_text_cursor + 1;
    pbVar6 = g_input_ptr;
    goto LAB_1040fd44;
  case '\x06':
  case '\a':
    g_input_ptr = pbVar6;
    *g_macro_text_cursor = bVar3;
    bVar3 = *g_input_ptr;
    cur_char = CONCAT31(cur_char._1_3_,bVar3);
    bVar4 = g_char_flags[bVar3];
    pbVar6 = g_input_ptr;
    while( true ) {
      g_input_ptr = pbVar6 + 1;
      g_macro_text_cursor = g_macro_text_cursor + 1;
      if ((bVar4 & 3) == 0) break;
      if (g_macro_text_buffer_limit <= g_macro_text_cursor) {
        pp_define_check_size
                  ((uint)g_macro_text_cursor,(int)g_macro_text_buffer,
                   (int *)&g_macro_text_buffer_limit);
      }
      *g_macro_text_cursor = bVar3;
      bVar3 = *g_input_ptr;
      cur_char = CONCAT31(cur_char._1_3_,bVar3);
      bVar4 = g_char_flags[bVar3];
      pbVar6 = g_input_ptr;
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
    g_input_ptr = pbVar6;
    g_macro_text_cursor =
         pp_copy_quoted_text(g_macro_text_cursor,(uint *)&g_macro_text_buffer_limit,bVar3);
    pbVar6 = g_input_ptr;
    goto LAB_1040fd44;
  case '\x1b':
    g_input_ptr = pbVar6;
    if (paren_depth != 0) {
      *g_macro_text_cursor = bVar3;
      g_macro_text_cursor = g_macro_text_cursor + 1;
      pbVar6 = g_input_ptr;
      goto LAB_1040fd44;
    }
    break;
  case '\x1c':
    paren_depth = paren_depth + -1;
    g_input_ptr = pbVar6;
    if (-1 < paren_depth) {
      *g_macro_text_cursor = bVar3;
      g_macro_text_cursor = g_macro_text_cursor + 1;
      pbVar6 = g_input_ptr;
      goto LAB_1040fd44;
    }
    break;
  case '&':
    goto code_r0x1040ff5e;
  case '\'':
    g_input_ptr = pbVar6;
    pbVar6 = (byte *)pp_macro_argument_text();
    pp_macro_stringize(0x22,pbVar6);
    pbVar6 = g_input_ptr;
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
  *g_macro_text_cursor = bVar3;
  g_macro_text_cursor = g_macro_text_cursor + 1;
  if (paren_depth < 0) {
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
    if (*(char *)(*(int *)(macro + 4) + 0xc) == '\0') {
      g_macro_text_cursor = g_macro_expansion_text_start;
      g_macro_arg_cursor = g_macro_arg_start;
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
      iVar7 = pp_skip_blanks_in_macro_text();
      if (iVar7 == 0) goto LAB_1040fdeb;
      arg_start = g_macro_text_cursor;
      if (*g_input_ptr != 0x2f) goto LAB_1040fd3f;
      bVar3 = g_input_ptr[1];
      saved_c14 = CONCAT31(saved_c14._1_3_,bVar3);
      g_input_ptr = g_input_ptr + 2;
      if (g_char_class[bVar3] == '\0') {
        bVar3 = lex_next_significant_char(bVar3);
      }
      if (bVar3 != 0x2f) break;
      g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
      pp_output_copy_comment();
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
    }
    bVar3 = g_input_ptr[-1];
    saved_c10 = CONCAT31(saved_c10._1_3_,bVar3);
    if (g_char_class[bVar3] == '\0') {
      bVar3 = lex_next_significant_char(bVar3);
    }
    arg_start = g_macro_text_cursor;
    if (bVar3 != 0x2a) break;
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
  pbVar6 = g_input_ptr;
  goto LAB_1040fd44;
switchD_1040fd7d_caseD_28:
  g_input_ptr = pbVar6;
  pbVar6 = (byte *)pp_macro_argument_text();
  pp_macro_stringize(0x27,pbVar6);
  pbVar6 = g_input_ptr;
  goto LAB_1040fd44;
}

