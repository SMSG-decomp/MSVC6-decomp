void __cdecl lex_scan_string_literal_body(byte wide,char quote)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  int arena;
  byte *mbchar;
  byte *pbVar6;
  size_t mb_len;
  byte *pbVar7;
  int local_4;
  char *pcVar5;
  
  local_4 = 0;
  g_yylval = (uint)g_string_literal_cur;
  g_yylval_word1 =
       CONCAT22(wide & 0xff01 | g_yylval_word1._2_2_ & 0xfffc,(undefined2)g_yylval_word1);
  mbchar = (byte *)g_string_literal_cur;
  if (g_opt_E_preprocess != 0) {
    wide = 0;
  }
LAB_1040ce7f:
  bVar1 = *g_input_ptr;
  uVar4 = (uint)bVar1;
  pbVar6 = g_input_ptr + 1;
  pbVar7 = mbchar;
  switch(g_char_class[uVar4]) {
  case '\0':
    goto switchD_1040ceb0_caseD_0;
  case '\x05':
    if (g_opt_E_preprocess == 0) {
      diag_error(1);
    }
    if (mbchar[-1] == 0xd) {
      pbVar7 = mbchar + -1;
    }
    uVar4 = (uint)(ushort)(short)quote;
    pbVar6 = g_input_ptr;
  case '\x15':
  case '\x16':
    g_input_ptr = pbVar6;
    pbVar6 = g_input_ptr;
    if (uVar4 == (int)quote) {
      if ((byte *)0x104de253 < pbVar7) {
        diag_error(0x1a);
        pbVar7 = &g_string_literal_buffer;
      }
      *pbVar7 = 0;
      if (wide == 0) {
        sVar2 = (short)(pbVar7 + (1 - (int)mbchar)) + (short)mbchar;
      }
      else {
        pcVar5 = lex_check_string_length((char *)mbchar,(size_t)(pbVar7 + (1 - (int)mbchar)));
        sVar2 = (short)pcVar5;
      }
      uVar4 = g_yylval_word1;
      g_yylval_word1 = CONCAT22(g_yylval_word1._2_2_,sVar2 - (short)g_yylval);
      if ((uVar4 & 0x20000) != 0) {
        lex_warn_pascal_string_length((int *)&g_yylval);
      }
      if ((g_token_arena_index == 5) ||
         (arena = g_token_arena_index, (g_compile_flags_c8 & 0x2000000) != 0)) {
        arena = 0;
      }
      lex_copy_text_to_arena
                ((c1_string_value *)&g_yylval,(c1_u8 *)g_yylval,g_yylval_word1 & 0xffff,arena);
      g_string_literal_cur = &g_string_literal_buffer;
      return;
    }
    break;
  case '#':
    g_input_ptr = pbVar6;
    if ((byte *)0x104de253 < mbchar) {
      diag_error(0x1a);
      pbVar7 = &g_string_literal_buffer;
    }
    *pbVar7 = bVar1;
    bVar1 = lex_skip_mbcs_trail_byte();
    uVar4 = (uint)bVar1;
    pbVar7 = pbVar7 + 1;
    pbVar6 = g_input_ptr;
  }
  goto switchD_1040ceb0_caseD_1;
switchD_1040ceb0_caseD_0:
  g_input_ptr = pbVar6;
  uVar3 = lex_buffer_refill();
  if ((uVar3 & 0xffffffaf) == 0) {
    pbVar6 = g_input_ptr;
    if ((((uVar3 & 0x10) != 0) && ((g_compile_flags_c4 & 0x2000) == 0)) && (g_opt_E_preprocess == 0)
       ) {
      bVar1 = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
      if (g_char_class[bVar1] == '\0') {
        bVar1 = lex_next_significant_char(bVar1);
      }
      uVar4 = lex_scan_escape_sequence(bVar1,(uint)wide);
      pbVar6 = g_input_ptr;
      if (wide == 0) {
        if (quote == '\'') {
          local_4 = local_4 + 1;
        }
      }
      else if ((ushort)uVar4 != ((ushort)uVar4 & 0xff)) {
        if ((byte *)0x104de253 < mbchar) {
          diag_error(0x1a);
          mbchar = &g_string_literal_buffer;
        }
        *mbchar = (byte)uVar4;
        mbchar[1] = (byte)(uVar4 >> 8);
        mbchar = mbchar + 2;
        goto LAB_1040ce7f;
      }
    }
switchD_1040ceb0_caseD_1:
    g_input_ptr = pbVar6;
    if ((byte *)0x104de253 < pbVar7) {
      diag_error(0x1a);
      pbVar7 = &g_string_literal_buffer;
    }
    bVar1 = (byte)uVar4;
    if (local_4 == 0) {
      *pbVar7 = bVar1;
      pbVar7[1] = 0;
      mb_len = (int)(pbVar7 + 1) - (int)mbchar;
      if (wide == 0) {
        mbchar = mbchar + mb_len;
      }
      else {
        mbchar = (byte *)lex_check_string_length((char *)mbchar,mb_len);
      }
    }
    else if (local_4 < 2) {
      *pbVar7 = bVar1;
      mbchar = pbVar7 + 1;
    }
    else {
      memmove(g_string_literal_cur + 1,g_string_literal_cur,(int)pbVar7 - (int)g_string_literal_cur)
      ;
      *g_string_literal_cur = bVar1;
      mbchar = pbVar7 + 1;
    }
  }
  goto LAB_1040ce7f;
}

