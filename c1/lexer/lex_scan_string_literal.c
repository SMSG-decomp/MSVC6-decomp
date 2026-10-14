void lex_scan_string_literal(uint ebx,byte *edi,byte *esi)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  byte *pbVar6;
  uint unaff_EBP;
  size_t len;
  byte *pbVar7;
  int in_stack_00000014;
  char in_stack_0000001c;
  char in_stack_00000020;
  char *pcVar5;
  
  pbVar6 = g_input_ptr;
code_r0x1060afb0:
  g_input_ptr = pbVar6;
  pbVar6 = g_input_ptr;
  if ((ebx & 0xffff) == (int)in_stack_00000020) {
    if ((byte *)0x1066918f < esi) {
      diag_error(0x1a);
      esi = &g_string_literal_buffer;
    }
    *esi = 0;
    if (in_stack_0000001c == '\0') {
      sVar3 = (short)(esi + (1 - (int)edi)) + (short)edi;
    }
    else {
      pcVar5 = lex_check_string_length((char *)edi,(size_t)(esi + (1 - (int)edi)));
      sVar3 = (short)pcVar5;
    }
    uVar4 = g_yylval_word1;
    g_yylval_word1 = CONCAT22(g_yylval_word1._2_2_,sVar3 - (short)g_yylval);
    if ((uVar4 & 0x20000) != 0) {
      lex_warn_pascal_string_length((c1_string_value *)&g_yylval);
    }
    lex_copy_text_to_arena
              ((c1_string_value *)&g_yylval,(c1_u8 *)g_yylval,g_yylval_word1 & 0xffff,
               -(uint)(g_token_arena_index != 3) & g_token_arena_index);
    g_string_literal_cur = &g_string_literal_buffer;
    return;
  }
  do {
    g_input_ptr = pbVar6;
    if ((byte *)0x1066918f < esi) {
      diag_error(0x1a);
      esi = &g_string_literal_buffer;
    }
    bVar1 = (byte)ebx;
    if (in_stack_00000014 == 0) {
      *esi = bVar1;
      esi[1] = 0;
      len = (int)(esi + 1) - (int)edi;
      if (in_stack_0000001c == '\0') {
        edi = edi + len;
      }
      else {
        edi = (byte *)lex_check_string_length((char *)edi,len);
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
LAB_1060b0f3:
    bVar1 = *g_input_ptr;
    ebx = (uint)bVar1;
    pbVar6 = g_input_ptr + 1;
    esi = edi;
    switch(g_char_class[ebx]) {
    case '\0':
      g_input_ptr = pbVar6;
      uVar4 = lex_buffer_refill();
      if ((uVar4 & 0xffffffaf) == 0) {
        pbVar6 = g_input_ptr;
        if ((((uVar4 & 0x10) == 0) || ((g_compile_flags_c4 & 0x2000) != 0)) ||
           (g_opt_E_preprocess != 0)) break;
        bVar1 = *g_input_ptr;
        g_input_ptr = g_input_ptr + 1;
        if (g_char_class[bVar1] == '\0') {
          bVar1 = lex_next_significant_char(bVar1);
        }
        uVar2 = lex_scan_escape_sequence(bVar1,unaff_EBP & 0xff);
        ebx = (uint)uVar2;
        pbVar6 = g_input_ptr;
        if (in_stack_0000001c == '\0') {
          if (in_stack_00000020 == '\'') {
            in_stack_00000014 = in_stack_00000014 + 1;
          }
          break;
        }
        if (uVar2 == (uVar2 & 0xff)) break;
        if ((byte *)0x1066918f < edi) {
          diag_error(0x1a);
          edi = &g_string_literal_buffer;
        }
        *edi = (byte)uVar2;
        edi[1] = (byte)(uVar2 >> 8);
        edi = edi + 2;
      }
      goto LAB_1060b0f3;
    case '\x05':
      if (g_opt_E_preprocess == 0) {
        diag_error(1);
      }
      if (edi[-1] == 0xd) {
        esi = edi + -1;
      }
      ebx = (uint)(ushort)(short)in_stack_00000020;
      pbVar6 = g_input_ptr;
    case '\x15':
    case '\x16':
      goto code_r0x1060afb0;
    case '#':
      pbVar7 = edi;
      g_input_ptr = pbVar6;
      if ((byte *)0x1066918f < edi) {
        diag_error(0x1a);
        pbVar7 = &g_string_literal_buffer;
      }
      *pbVar7 = bVar1;
      bVar1 = lex_skip_mbcs_trail_byte();
      ebx = (uint)bVar1;
      esi = pbVar7 + 1;
      pbVar6 = g_input_ptr;
    }
  } while( true );
}

