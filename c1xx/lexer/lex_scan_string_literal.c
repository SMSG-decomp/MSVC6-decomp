void lex_scan_string_literal(uint ebx,byte *edi,byte *esi)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  int arena;
  byte *pbVar5;
  uint unaff_EBP;
  size_t mb_len;
  byte *pbVar6;
  int in_stack_00000014;
  char in_stack_0000001c;
  char in_stack_00000020;
  char *pcVar4;
  
  pbVar5 = g_input_ptr;
code_r0x1040cd3c:
  g_input_ptr = pbVar5;
  pbVar5 = g_input_ptr;
  if ((ebx & 0xffff) == (int)in_stack_00000020) {
    if ((byte *)0x104de253 < esi) {
      diag_error(0x1a);
      esi = &g_string_literal_buffer;
    }
    *esi = 0;
    if (in_stack_0000001c == '\0') {
      sVar2 = (short)(esi + (1 - (int)edi)) + (short)edi;
    }
    else {
      pcVar4 = lex_check_string_length((char *)edi,(size_t)(esi + (1 - (int)edi)));
      sVar2 = (short)pcVar4;
    }
    uVar3 = g_yylval_word1;
    g_yylval_word1 = CONCAT22(g_yylval_word1._2_2_,sVar2 - (short)g_yylval);
    if ((uVar3 & 0x20000) != 0) {
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
  do {
    g_input_ptr = pbVar5;
    if ((byte *)0x104de253 < esi) {
      diag_error(0x1a);
      esi = &g_string_literal_buffer;
    }
    bVar1 = (byte)ebx;
    if (in_stack_00000014 == 0) {
      *esi = bVar1;
      esi[1] = 0;
      mb_len = (int)(esi + 1) - (int)edi;
      if (in_stack_0000001c == '\0') {
        edi = edi + mb_len;
      }
      else {
        edi = (byte *)lex_check_string_length((char *)edi,mb_len);
      }
    }
    else if (in_stack_00000014 < 2) {
      *esi = bVar1;
      edi = esi + 1;
    }
    else {
      memmove(g_string_literal_cur + 1,g_string_literal_cur,(int)esi - (int)g_string_literal_cur);
      edi = esi + 1;
      *g_string_literal_cur = bVar1;
    }
LAB_1040ce7f:
    bVar1 = *g_input_ptr;
    ebx = (uint)bVar1;
    pbVar5 = g_input_ptr + 1;
    esi = edi;
    switch(g_char_class[ebx]) {
    case '\0':
      g_input_ptr = pbVar5;
      uVar3 = lex_buffer_refill();
      if ((uVar3 & 0xffffffaf) == 0) {
        pbVar5 = g_input_ptr;
        if ((((uVar3 & 0x10) == 0) || ((g_compile_flags_c4 & 0x2000) != 0)) ||
           (g_opt_E_preprocess != 0)) break;
        bVar1 = *g_input_ptr;
        g_input_ptr = g_input_ptr + 1;
        if (g_char_class[bVar1] == '\0') {
          bVar1 = lex_next_significant_char(bVar1);
        }
        ebx = lex_scan_escape_sequence(bVar1,unaff_EBP & 0xff);
        pbVar5 = g_input_ptr;
        if (in_stack_0000001c == '\0') {
          if (in_stack_00000020 == '\'') {
            in_stack_00000014 = in_stack_00000014 + 1;
          }
          break;
        }
        if ((ushort)ebx == ((ushort)ebx & 0xff)) break;
        if ((byte *)0x104de253 < edi) {
          diag_error(0x1a);
          edi = &g_string_literal_buffer;
        }
        *edi = (byte)ebx;
        edi[1] = (byte)(ebx >> 8);
        edi = edi + 2;
      }
      goto LAB_1040ce7f;
    case '\x05':
      if (g_opt_E_preprocess == 0) {
        diag_error(1);
      }
      if (edi[-1] == 0xd) {
        esi = edi + -1;
      }
      ebx = (uint)(ushort)(short)in_stack_00000020;
      pbVar5 = g_input_ptr;
    case '\x15':
    case '\x16':
      goto code_r0x1040cd3c;
    case '#':
      pbVar6 = edi;
      g_input_ptr = pbVar5;
      if ((byte *)0x104de253 < edi) {
        diag_error(0x1a);
        pbVar6 = &g_string_literal_buffer;
      }
      *pbVar6 = bVar1;
      bVar1 = lex_skip_mbcs_trail_byte();
      ebx = (uint)bVar1;
      esi = pbVar6 + 1;
      pbVar5 = g_input_ptr;
    }
  } while( true );
}

