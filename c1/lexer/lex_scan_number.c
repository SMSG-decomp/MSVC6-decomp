c1_token * __cdecl lex_scan_number(char *out)

{
  c1_token *pcVar1;
  c1_type *pcVar2;
  byte *pbVar3;
  byte bVar4;
  uint uVar5;
  fe_arena *pfVar6;
  c1_token *pcVar7;
  int iVar8;
  uint *puVar9;
  c1_type *pcVar10;
  c1_yystype *pcVar11;
  float_const local_c;
  
  bVar4 = lex_getc();
  if ((g_opt_xc != 0) && (g_macro_rescan_level == 0)) {
    diag_warning(1,0xc);
    g_opt_xc = 0;
  }
  if ((g_char_class[bVar4] == '\x1d') || (bVar4 == 0x2e)) {
    do {
      *out = bVar4;
      out = out + 1;
      if (&g_string_literal_buffer < out) {
        diag_fatal_simple(0x40);
      }
      bVar4 = lex_getc();
    } while (g_char_class[bVar4] == '\x1d');
  }
  if ((bVar4 & 0xdf) == 0x45) {
    *out = bVar4;
    bVar4 = lex_getc();
    if ((bVar4 == 0x2b) || (pbVar3 = (byte *)(out + 1), bVar4 == 0x2d)) {
      out[1] = bVar4;
      bVar4 = lex_getc();
      pbVar3 = (byte *)(out + 2);
    }
    out = (char *)pbVar3;
    if (g_char_class[bVar4] == '\x1d') {
      do {
        *out = bVar4;
        out = out + 1;
        bVar4 = lex_getc();
      } while (g_char_class[bVar4] == '\x1d');
    }
    else {
      if (g_macro_rescan_level == 0) {
        diag_error(0x15,(uint)bVar4);
      }
      *out = 0x30;
      out = out + 1;
    }
  }
  pcVar2 = g_type_long_double;
  pcVar10 = g_type_float;
  if ((bVar4 & 0xdf) == 0x46) {
    *out = bVar4;
    out = out + 1;
  }
  else if ((bVar4 & 0xdf) == 0x4c) {
    *out = bVar4;
    out = out + 1;
    pcVar10 = pcVar2;
  }
  else {
    g_input_ptr = g_input_ptr + -1;
    pcVar10 = g_type_double;
  }
  if ((g_char_flags[*g_input_ptr] & 1) != 0) {
    diag_error(0x3b,0x4d,0x132);
  }
  *out = 0;
  if (g_macro_rescan_level < 1) {
    if (((g_opt_E_preprocess == 0) && ((g_compile_flags_c4 & 0x800000) == 0)) ||
       ((g_compile_flags_c4 & 0x4000) != 0)) {
      uVar5 = float_const_from_string(g_number_digit_buffer,&local_c);
      if ((char)uVar5 != '\0') {
        diag_error(0xb1);
        local_c.mantissa_lo = g_float_zero.mantissa_lo;
        local_c.mantissa_hi = g_float_zero.mantissa_hi;
        local_c.sign_exponent = g_float_zero.sign_exponent;
        local_c.size = g_float_zero.size;
      }
      g_yylval = (uint)pcVar10;
      _g_yylval_word2 = record3_new_from((int *)&local_c,0);
      if (g_token_arena_index == 0) {
        if (g_pool_default.left < 0x20) {
          pool_reserve(&g_pool_default,0x20);
        }
        g_pool_default.left = g_pool_default.left - 0x20;
        pcVar7 = (c1_token *)g_pool_default.cur;
        g_pool_default.cur = g_pool_default.cur + 0x20;
      }
      else {
        pfVar6 = g_arenas + g_token_arena_index;
        pcVar7 = (c1_token *)pfVar6->cur;
        pcVar1 = (c1_token *)g_arenas[g_token_arena_index].end;
        pfVar6->cur = &pcVar7[1].code;
        if (pcVar1 < pcVar7 + 1) {
          arena_grow(pfVar6);
        }
      }
    }
    else {
      lex_copy_text_to_arena
                ((c1_string_value *)&g_yylval,(c1_u8 *)g_number_digit_buffer,
                 (uint)(out + -0x1066890f),-(uint)(g_token_arena_index != 3) & g_token_arena_index);
      if (g_token_arena_index == 0) {
        if (g_pool_default.left < 0x20) {
          pool_reserve(&g_pool_default,0x20);
        }
        g_pool_default.left = g_pool_default.left - 0x20;
        pcVar7 = (c1_token *)g_pool_default.cur;
        g_pool_default.cur = g_pool_default.cur + 0x20;
      }
      else {
        pfVar6 = g_arenas + g_token_arena_index;
        pcVar7 = (c1_token *)pfVar6->cur;
        pcVar1 = (c1_token *)g_arenas[g_token_arena_index].end;
        pfVar6->cur = &pcVar7[1].code;
        if (pcVar1 < pcVar7 + 1) {
          arena_grow(pfVar6);
        }
      }
    }
    if (pcVar7 != (c1_token *)0x0) {
      pcVar7->code = 'e';
      puVar9 = &g_yylval;
      pcVar11 = &pcVar7->value;
      for (iVar8 = 6; iVar8 != 0; iVar8 = iVar8 + -1) {
        pcVar11->words[0] = *puVar9;
        puVar9 = puVar9 + 1;
        pcVar11 = (c1_yystype *)((int)pcVar11 + 4);
      }
      return pcVar7;
    }
  }
  else {
    g_macro_text_cursor = (uchar *)(out + 1);
    if (g_token_arena_index == 0) {
      pcVar7 = (c1_token *)pool_alloc_raw(&g_pool_default,0x20);
    }
    else {
      pfVar6 = g_arenas + g_token_arena_index;
      pcVar7 = (c1_token *)pfVar6->cur;
      pcVar1 = (c1_token *)g_arenas[g_token_arena_index].end;
      pfVar6->cur = &pcVar7[1].code;
      if (pcVar1 < pcVar7 + 1) {
        arena_grow(pfVar6);
      }
    }
    if (pcVar7 != (c1_token *)0x0) {
      pcVar7->code = 0x88;
      puVar9 = &g_yylval;
      pcVar11 = &pcVar7->value;
      for (iVar8 = 6; iVar8 != 0; iVar8 = iVar8 + -1) {
        pcVar11->words[0] = *puVar9;
        puVar9 = puVar9 + 1;
        pcVar11 = (c1_yystype *)((int)pcVar11 + 4);
      }
      return pcVar7;
    }
  }
  return (c1_token *)0x0;
}

