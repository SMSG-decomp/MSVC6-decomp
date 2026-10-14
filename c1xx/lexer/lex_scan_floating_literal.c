c1_u8 * __cdecl lex_scan_floating_literal(byte *digits_end)

{
  c1_u8 *pcVar1;
  c1_type *pcVar2;
  byte *pbVar3;
  byte bVar4;
  uint uVar5;
  c1_arena *pcVar6;
  c1_u8 *pcVar7;
  int iVar8;
  uint *src_2;
  uint *src;
  c1_type *pcVar9;
  uint *puVar10;
  c1xx_float_const value;
  
  bVar4 = lex_getc();
  if ((g_opt_xc != 0) && (g_macro_rescan_level == 0)) {
    diag_warning(1,0xc);
    g_opt_xc = 0;
  }
  if ((g_char_class[bVar4] == '\x1d') || (bVar4 == 0x2e)) {
    do {
      *digits_end = bVar4;
      digits_end = digits_end + 1;
      if (&g_string_literal_buffer < digits_end) {
        diag_fatal_simple(0x40);
      }
      bVar4 = lex_getc();
    } while (g_char_class[bVar4] == '\x1d');
  }
  if ((bVar4 & 0xdf) == 0x45) {
    *digits_end = bVar4;
    bVar4 = lex_getc();
    if ((bVar4 == 0x2b) || (pbVar3 = digits_end + 1, bVar4 == 0x2d)) {
      digits_end[1] = bVar4;
      bVar4 = lex_getc();
      pbVar3 = digits_end + 2;
    }
    digits_end = pbVar3;
    if (g_char_class[bVar4] == '\x1d') {
      do {
        *digits_end = bVar4;
        digits_end = digits_end + 1;
        bVar4 = lex_getc();
      } while (g_char_class[bVar4] == '\x1d');
    }
    else {
      if (g_macro_rescan_level == 0) {
        diag_error(0x15,(uint)bVar4);
      }
      *digits_end = 0x30;
      digits_end = digits_end + 1;
    }
  }
  pcVar2 = g_type_long_double;
  pcVar9 = g_type_float;
  if ((bVar4 & 0xdf) == 0x46) {
    *digits_end = bVar4;
    digits_end = digits_end + 1;
  }
  else if ((bVar4 & 0xdf) == 0x4c) {
    *digits_end = bVar4;
    digits_end = digits_end + 1;
    pcVar9 = pcVar2;
  }
  else {
    g_input_ptr = g_input_ptr + -1;
    pcVar9 = g_type_double;
  }
  if ((g_char_flags[*g_input_ptr] & 1) != 0) {
    diag_error(0x3b,0x4d,0x132);
  }
  *digits_end = 0;
  if (g_macro_rescan_level < 1) {
    if (((g_opt_E_preprocess == 0) && ((g_compile_flags_c4 & 0x800000) == 0)) ||
       ((g_compile_flags_c4 & 0x4000) != 0)) {
      uVar5 = float_const_from_string((char *)g_number_digit_buffer,&value);
      if ((char)uVar5 != '\0') {
        diag_error(0xb1);
        value.mantissa_lo = g_float_zero.mantissa_lo;
        value.mantissa_hi = g_float_zero.mantissa_hi;
        value.sign_exponent = g_float_zero.sign_exponent;
        value.size = g_float_zero.size;
      }
      g_yylval = (uint)pcVar9;
      _g_yylval_word2 = record3_new_from((int *)&value,0);
      if (g_token_arena_index == 0) {
        if (g_pool_default_left < 0x30) {
          pool_reserve((c1xx_pool *)&g_pool_default,0x30);
        }
        g_pool_default_left = g_pool_default_left - 0x30;
        pcVar7 = g_pool_default;
        g_pool_default = g_pool_default + 0x30;
      }
      else {
        pcVar6 = g_arenas + g_token_arena_index;
        pcVar7 = pcVar6->cur;
        pcVar1 = g_arenas[g_token_arena_index].end;
        pcVar6->cur = pcVar7 + 0x30;
        if (pcVar1 < pcVar7 + 0x30) {
          arena_grow(pcVar6);
        }
      }
    }
    else {
      if ((g_token_arena_index == 5) ||
         (iVar8 = g_token_arena_index, (g_compile_flags_c8 & 0x2000000) != 0)) {
        iVar8 = 0;
      }
      lex_copy_text_to_arena
                ((c1_string_value *)&g_yylval,g_number_digit_buffer,(uint)(digits_end + -0x104dd9d3)
                 ,iVar8);
      if (g_token_arena_index == 0) {
        if (g_pool_default_left < 0x30) {
          pool_reserve((c1xx_pool *)&g_pool_default,0x30);
        }
        g_pool_default_left = g_pool_default_left - 0x30;
        pcVar7 = g_pool_default;
        g_pool_default = g_pool_default + 0x30;
      }
      else {
        pcVar6 = g_arenas + g_token_arena_index;
        pcVar7 = pcVar6->cur;
        pcVar1 = g_arenas[g_token_arena_index].end;
        pcVar6->cur = pcVar7 + 0x30;
        if (pcVar1 < pcVar7 + 0x30) {
          arena_grow(pcVar6);
        }
      }
    }
    if (pcVar7 != (c1_u8 *)0x0) {
      *pcVar7 = 'e';
      src_2 = &g_yylval;
      puVar10 = (uint *)(pcVar7 + 8);
      for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar10 = *src_2;
        src_2 = src_2 + 1;
        puVar10 = puVar10 + 1;
      }
      return pcVar7;
    }
  }
  else {
    g_macro_text_cursor = digits_end + 1;
    if (g_token_arena_index == 0) {
      pcVar7 = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      pcVar6 = g_arenas + g_token_arena_index;
      pcVar7 = pcVar6->cur;
      pcVar1 = g_arenas[g_token_arena_index].end;
      pcVar6->cur = pcVar7 + 0x30;
      if (pcVar1 < pcVar7 + 0x30) {
        arena_grow(pcVar6);
      }
    }
    if (pcVar7 != (c1_u8 *)0x0) {
      *pcVar7 = 0x88;
      src = &g_yylval;
      puVar10 = (uint *)(pcVar7 + 8);
      for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar10 = *src;
        src = src + 1;
        puVar10 = puVar10 + 1;
      }
      return pcVar7;
    }
  }
  return (c1_u8 *)0x0;
}

