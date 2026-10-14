c1_token * __cdecl lex_scan_number_token(byte first,int in_asm)

{
  c1_u8 cVar1;
  char cVar2;
  ushort uVar3;
  c1_token *pcVar4;
  c1_type *pcVar5;
  bool bVar6;
  fe_arena *pfVar7;
  c1_token *pcVar8;
  c1_type *pcVar9;
  uint uVar10;
  byte bVar11;
  byte *pbVar12;
  char *digits_end;
  uint *puVar13;
  uint uVar14;
  c1_yystype *pcVar15;
  longlong lVar16;
  ulonglong uVar17;
  int iVar18;
  longlong in_stack_fffffff8;
  
  if (((g_opt_E_preprocess == 0) && ((g_compile_flags_c4 & 0x800000) == 0)) ||
     ((g_compile_flags_c4 & 0x4000) != 0)) {
    bVar6 = false;
  }
  else {
    bVar6 = true;
  }
  digits_end = g_number_digit_buffer;
  if (bVar6) {
    g_number_digit_buffer[0] = first;
    iVar18 = lex_scan_pp_number_text((byte *)(g_number_digit_buffer + 1));
    if (0x7f < iVar18 + 1U) {
      diag_fatal_simple(0x40);
    }
    lex_copy_text_to_arena
              ((c1_string_value *)&g_yylval,(c1_u8 *)g_number_digit_buffer,iVar18 + 1U,
               -(uint)(g_token_arena_index != 3) & g_token_arena_index);
    if (g_token_arena_index == 0) {
      if (g_pool_default.left < 0x20) {
        pool_reserve(&g_pool_default,0x20);
      }
      g_pool_default.left = g_pool_default.left - 0x20;
      pcVar8 = (c1_token *)g_pool_default.cur;
      g_pool_default.cur = g_pool_default.cur + 0x20;
    }
    else {
      pfVar7 = g_arenas + g_token_arena_index;
      pcVar8 = (c1_token *)pfVar7->cur;
      pcVar4 = (c1_token *)g_arenas[g_token_arena_index].end;
      pfVar7->cur = &pcVar8[1].code;
      if (pcVar4 < pcVar8 + 1) {
        arena_grow(pfVar7);
      }
    }
    if (pcVar8 == (c1_token *)0x0) {
      pcVar8 = lex_scan_number_token_fragment();
      return pcVar8;
    }
    goto LAB_106044a0;
  }
  pcVar9 = g_type_int;
  if (first == 0x30) {
    first = lex_getc();
    if ((first & 0xdf) != 0x58) {
      iVar18 = 8;
      g_number_digit_buffer[0] = '0';
      digits_end = g_number_digit_buffer + 1;
      goto LAB_106040fe;
    }
    iVar18 = 0x10;
    first = lex_getc();
    if ((g_char_flags[first] & 2) == 0) {
      diag_error(0x99);
    }
    else {
      do {
        *digits_end = first;
        digits_end = digits_end + 1;
        first = lex_getc();
      } while ((g_char_flags[first] & 2) != 0);
      if (digits_end == g_number_digit_buffer) {
        pcVar8 = (c1_token *)
                 lex_check_hex_digits
                           (first,(byte *)g_number_digit_buffer,iVar18,pcVar9,in_stack_fffffff8);
        return pcVar8;
      }
    }
  }
  else {
    iVar18 = 10;
LAB_106040fe:
    if (in_asm == 0) {
      cVar1 = g_char_class[first];
      while (cVar1 == '\x1d') {
        *digits_end = first;
        digits_end = digits_end + 1;
        first = lex_getc();
        if (&g_string_literal_buffer < digits_end) {
          diag_fatal_simple(0x40);
        }
        cVar1 = g_char_class[first];
      }
      if ((first == 0x2e) || ((first & 0xdf) == 0x45)) {
        g_input_ptr = g_input_ptr + -1;
        pcVar8 = lex_scan_number(digits_end);
        return pcVar8;
      }
    }
    else {
      bVar11 = g_char_flags[first];
      while (uVar14 = (uint)first, (bVar11 & 2) != 0) {
        *digits_end = first;
        digits_end = digits_end + 1;
        first = lex_getc();
        if (&g_string_literal_buffer < digits_end) {
          diag_fatal_simple(0x40);
        }
        bVar11 = g_char_flags[first];
      }
      uVar10 = (uint)(byte)digits_end[-1];
      pbVar12 = g_char_flags + uVar10;
      if (((g_char_flags[uVar10] & 0x10) == 0) || ((first & 0xdf) == 0x48)) {
        pbVar12 = g_char_flags + uVar14;
        uVar10 = uVar14;
        if ((g_char_flags[uVar14] & 0x10) != 0) {
          first = lex_getc();
        }
      }
      else {
        digits_end = digits_end + -1;
      }
      if ((*pbVar12 & 0x10) != 0) {
        pcVar8 = (c1_token *)
                 lex_scan_integer_literal_radix_suffix
                           (uVar10,first,(byte *)digits_end,iVar18,pcVar9,in_stack_fffffff8);
        return pcVar8;
      }
    }
  }
  bVar11 = first & 0xdf;
  if (bVar11 == 0x4c) {
    bVar11 = lex_getc();
    pcVar9 = g_type_unsigned_long;
    if ((bVar11 & 0xdf) != 0x55) {
      g_input_ptr = g_input_ptr + -1;
      pcVar9 = g_type_long;
    }
  }
  else if ((g_integral_max_bytes < 1) || (bVar11 != 0x49)) {
    if (bVar11 == 0x55) {
      bVar11 = lex_getc();
      pcVar9 = g_type_unsigned_long;
      if ((bVar11 & 0xdf) != 0x4c) {
        if ((g_integral_max_bytes < 1) || ((bVar11 & 0xdf) != 0x49)) {
          g_input_ptr = g_input_ptr + -1;
          pcVar9 = g_type_unsigned_int;
        }
        else {
          pcVar9 = lex_scan_sized_int_suffix('\x01');
        }
      }
    }
    else {
      g_input_ptr = g_input_ptr + -1;
    }
  }
  else {
    pcVar9 = lex_scan_sized_int_suffix('\0');
  }
  if ((g_char_flags[*g_input_ptr] & 1) != 0) {
    diag_error(0x3b,0x4d,0x132);
  }
  *digits_end = 0;
  if ((int)(digits_end + -0x1066890f) < 2) {
    lVar16 = 0;
    uVar14 = 0;
  }
  else {
    lVar16 = lex_scan_integer_constant
                       ((byte *)g_number_digit_buffer,(int)(digits_end + -0x10668910),iVar18);
    uVar14 = (uint)lVar16;
  }
  uVar10 = (uint)((ulonglong)lVar16 >> 0x20);
  uVar17 = CONCAT44(uVar10,uVar14);
  cVar2 = (char)pcVar9->code;
  pcVar5 = pcVar9;
  while (cVar2 < '\0') {
    pcVar5 = pcVar5->base;
    cVar2 = (char)pcVar5->code;
  }
  uVar3 = pcVar5->code;
  if (0x2013 < uVar3) {
    switch(uVar3) {
    case 0x2014:
      pcVar9 = lex_unsigned_long_literal_type((uint *)&stack0xfffffff8);
      break;
    case 0x2019:
      uVar17 = (ulonglong)(uVar14 & 0xff);
      break;
    case 0x201a:
      uVar14 = uVar14 & 0xffff;
    case 0x201b:
      uVar17 = (ulonglong)uVar14;
      break;
    case 0x201d:
      iVar18 = 0;
      uVar10 = 0;
      goto LAB_1062e53f;
    }
    goto switchD_1060420e_caseD_15;
  }
  if (uVar3 == 0x2013) {
    pcVar9 = lex_unsigned_literal_type((uint *)&stack0xfffffff8);
    goto switchD_1060420e_caseD_15;
  }
  switch(uVar3) {
  case 0x13:
    if (iVar18 == 10) {
      pcVar9 = lex_decimal_literal_type((uint *)&stack0xfffffff8);
    }
    else {
      pcVar9 = lex_hex_octal_literal_type((uint *)&stack0xfffffff8);
    }
    break;
  case 0x14:
    pcVar9 = lex_long_literal_type((uint *)&stack0xfffffff8);
    break;
  case 0x19:
    uVar10 = (int)(uVar14 << 0x18) >> 0x18;
    iVar18 = (int)(uVar14 << 0x18) >> 0x1f;
    goto LAB_1062e53f;
  case 0x1a:
    uVar10 = (int)(uVar14 << 0x10) >> 0x10;
    iVar18 = (int)(uVar14 << 0x10) >> 0x1f;
LAB_1062e53f:
    uVar17 = CONCAT44(iVar18,uVar10);
    break;
  case 0x1b:
    uVar17 = (ulonglong)(int)uVar14;
    break;
  case 0x1d:
    lVar16 = _allshl(0xc0,uVar14,uVar10);
    uVar17 = _allshr(0xc0,(int)((ulonglong)lVar16 >> 0x20),(uint)lVar16);
  }
switchD_1060420e_caseD_15:
  _g_yylval_word3 = (undefined4)(uVar17 >> 0x20);
  _g_yylval_word2 = (uint)uVar17;
  g_yylval = (uint)pcVar9;
  if (g_token_arena_index == 0) {
    if (g_pool_default.left < 0x20) {
      pool_reserve(&g_pool_default,0x20);
    }
    g_pool_default.left = g_pool_default.left - 0x20;
    pcVar8 = (c1_token *)g_pool_default.cur;
    g_pool_default.cur = g_pool_default.cur + 0x20;
  }
  else {
    pfVar7 = g_arenas + g_token_arena_index;
    pcVar8 = (c1_token *)pfVar7->cur;
    pcVar4 = (c1_token *)g_arenas[g_token_arena_index].end;
    pfVar7->cur = &pcVar8[1].code;
    if (pcVar4 < pcVar8 + 1) {
      arena_grow(pfVar7);
    }
  }
  if (pcVar8 == (c1_token *)0x0) {
    return (c1_token *)0x0;
  }
LAB_106044a0:
  pcVar8->code = 'e';
  puVar13 = &g_yylval;
  pcVar15 = &pcVar8->value;
  for (iVar18 = 6; iVar18 != 0; iVar18 = iVar18 + -1) {
    pcVar15->words[0] = *puVar13;
    puVar13 = puVar13 + 1;
    pcVar15 = (c1_yystype *)((int)pcVar15 + 4);
  }
  return pcVar8;
}

