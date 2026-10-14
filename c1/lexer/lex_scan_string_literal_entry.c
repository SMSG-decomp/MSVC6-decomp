void __cdecl lex_scan_string_literal_entry(c1_u8 wide,char quote)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  byte *text;
  byte *pbVar7;
  size_t len;
  byte *pbVar8;
  int local_4;
  uint uVar5;
  char *pcVar6;
  
  local_4 = 0;
  g_yylval = (uint)g_string_literal_cur;
  g_yylval_word1 =
       CONCAT22(wide & 0xff01 | g_yylval_word1._2_2_ & 0xfffc,(undefined2)g_yylval_word1);
  text = (byte *)g_string_literal_cur;
  if (g_opt_E_preprocess != 0) {
    wide = '\0';
  }
LAB_1060b0f3:
  bVar1 = *g_input_ptr;
  uVar5 = (uint)bVar1;
  pbVar7 = g_input_ptr + 1;
  pbVar8 = text;
  switch(g_char_class[uVar5]) {
  case '\0':
    goto switchD_1060b124_caseD_0;
  case '\x05':
    if (g_opt_E_preprocess == 0) {
      diag_error(1);
    }
    if (text[-1] == 0xd) {
      pbVar8 = text + -1;
    }
    uVar5 = (uint)(ushort)(short)quote;
    pbVar7 = g_input_ptr;
  case '\x15':
  case '\x16':
    g_input_ptr = pbVar7;
    pbVar7 = g_input_ptr;
    if (uVar5 == (int)quote) {
      if ((byte *)0x1066918f < pbVar8) {
        diag_error(0x1a);
        pbVar8 = &g_string_literal_buffer;
      }
      *pbVar8 = 0;
      if (wide == 0) {
        sVar3 = (short)(pbVar8 + (1 - (int)text)) + (short)text;
      }
      else {
        pcVar6 = lex_check_string_length((char *)text,(size_t)(pbVar8 + (1 - (int)text)));
        sVar3 = (short)pcVar6;
      }
      uVar5 = g_yylval_word1;
      g_yylval_word1 = CONCAT22(g_yylval_word1._2_2_,sVar3 - (short)g_yylval);
      if ((uVar5 & 0x20000) != 0) {
        lex_warn_pascal_string_length((c1_string_value *)&g_yylval);
      }
      lex_copy_text_to_arena
                ((c1_string_value *)&g_yylval,(c1_u8 *)g_yylval,g_yylval_word1 & 0xffff,
                 -(uint)(g_token_arena_index != 3) & g_token_arena_index);
      g_string_literal_cur = &g_string_literal_buffer;
      return;
    }
    break;
  case '#':
    g_input_ptr = pbVar7;
    if ((byte *)0x1066918f < text) {
      diag_error(0x1a);
      pbVar8 = &g_string_literal_buffer;
    }
    *pbVar8 = bVar1;
    bVar1 = lex_skip_mbcs_trail_byte();
    uVar5 = (uint)bVar1;
    pbVar8 = pbVar8 + 1;
    pbVar7 = g_input_ptr;
  }
  goto switchD_1060b124_caseD_1;
switchD_1060b124_caseD_0:
  g_input_ptr = pbVar7;
  uVar4 = lex_buffer_refill();
  if ((uVar4 & 0xffffffaf) == 0) {
    pbVar7 = g_input_ptr;
    if ((((uVar4 & 0x10) != 0) && ((g_compile_flags_c4 & 0x2000) == 0)) && (g_opt_E_preprocess == 0)
       ) {
      bVar1 = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
      if (g_char_class[bVar1] == '\0') {
        bVar1 = lex_next_significant_char(bVar1);
      }
      uVar2 = lex_scan_escape_sequence(bVar1,(uint)wide);
      uVar5 = (uint)uVar2;
      pbVar7 = g_input_ptr;
      if (wide == 0) {
        if (quote == '\'') {
          local_4 = local_4 + 1;
        }
      }
      else if (uVar2 != (uVar2 & 0xff)) {
        if ((byte *)0x1066918f < text) {
          diag_error(0x1a);
          text = &g_string_literal_buffer;
        }
        *text = (byte)uVar2;
        text[1] = (byte)(uVar2 >> 8);
        text = text + 2;
        goto LAB_1060b0f3;
      }
    }
switchD_1060b124_caseD_1:
    g_input_ptr = pbVar7;
    if ((byte *)0x1066918f < pbVar8) {
      diag_error(0x1a);
      pbVar8 = &g_string_literal_buffer;
    }
    bVar1 = (byte)uVar5;
    if (local_4 == 0) {
      *pbVar8 = bVar1;
      pbVar8[1] = 0;
      len = (int)(pbVar8 + 1) - (int)text;
      if (wide == 0) {
        text = text + len;
      }
      else {
        text = (byte *)lex_check_string_length((char *)text,len);
      }
    }
    else if (local_4 < 2) {
      *pbVar8 = bVar1;
      text = pbVar8 + 1;
    }
    else {
      memmove(g_string_literal_cur + 1,g_string_literal_cur,(int)pbVar8 - (int)g_string_literal_cur)
      ;
      *g_string_literal_cur = bVar1;
      text = pbVar8 + 1;
    }
  }
  goto LAB_1060b0f3;
}

