c1_u8 * __cdecl lex_scan_integer_literal(byte first,int asm_mode)

{
  c1_u8 cVar1;
  char cVar2;
  ushort uVar3;
  c1_u8 *pcVar4;
  c1_type *pcVar5;
  bool bVar6;
  c1_arena *pcVar7;
  c1_type *pcVar8;
  uint uVar9;
  byte bVar10;
  byte *pbVar11;
  c1_u8 *pcVar12;
  uint *puVar13;
  uint suffix;
  uint *puVar14;
  longlong lVar15;
  int iVar16;
  longlong value;
  
  if (((g_opt_E_preprocess == 0) && ((g_compile_flags_c4 & 0x800000) == 0)) ||
     ((g_compile_flags_c4 & 0x4000) != 0)) {
    bVar6 = false;
  }
  else {
    bVar6 = true;
  }
  pcVar12 = g_number_digit_buffer;
  if (bVar6) {
    g_number_digit_buffer[0] = first;
    uVar9 = lex_scan_pp_number_text(g_number_digit_buffer + 1);
    if (0x7f < uVar9 + 1) {
      diag_fatal_simple(0x40);
    }
    if ((g_token_arena_index == 5) ||
       (iVar16 = g_token_arena_index, (g_compile_flags_c8 & 0x2000000) != 0)) {
      iVar16 = 0;
    }
    lex_copy_text_to_arena((c1_string_value *)&g_yylval,g_number_digit_buffer,uVar9 + 1,iVar16);
    if (g_token_arena_index == 0) {
      if (g_pool_default_left < 0x30) {
        pool_reserve((c1xx_pool *)&g_pool_default,0x30);
      }
      g_pool_default_left = g_pool_default_left - 0x30;
      pcVar12 = g_pool_default;
      g_pool_default = g_pool_default + 0x30;
    }
    else {
      pcVar7 = g_arenas + g_token_arena_index;
      pcVar12 = pcVar7->cur;
      pcVar4 = g_arenas[g_token_arena_index].end;
      pcVar7->cur = pcVar12 + 0x30;
      if (pcVar4 < pcVar12 + 0x30) {
        arena_grow(pcVar7);
      }
    }
    goto joined_r0x1046308e;
  }
  pcVar8 = g_type_int;
  if (first == 0x30) {
    first = lex_getc();
    if ((first & 0xdf) != 0x58) {
      iVar16 = 8;
      g_number_digit_buffer[0] = '0';
      pcVar12 = g_number_digit_buffer + 1;
      goto LAB_1040a66d;
    }
    iVar16 = 0x10;
    first = lex_getc();
    if ((g_char_flags[first] & 2) == 0) {
      diag_error(0x99);
    }
    else {
      do {
        *pcVar12 = first;
        pcVar12 = pcVar12 + 1;
        first = lex_getc();
      } while ((g_char_flags[first] & 2) != 0);
      if (pcVar12 == g_number_digit_buffer) {
        pcVar12 = lex_check_hex_digits(first,g_number_digit_buffer,iVar16,pcVar8,value);
        return pcVar12;
      }
    }
  }
  else {
    iVar16 = 10;
LAB_1040a66d:
    if (asm_mode == 0) {
      cVar1 = g_char_class[first];
      while (cVar1 == '\x1d') {
        *pcVar12 = first;
        pcVar12 = pcVar12 + 1;
        first = lex_getc();
        if (&g_string_literal_buffer < pcVar12) {
          diag_fatal_simple(0x40);
        }
        cVar1 = g_char_class[first];
      }
      if ((first == 0x2e) || ((first & 0xdf) == 0x45)) {
        g_input_ptr = g_input_ptr + -1;
        pcVar12 = lex_scan_floating_literal(pcVar12);
        return pcVar12;
      }
    }
    else {
      bVar10 = g_char_flags[first];
      while (uVar9 = (uint)first, (bVar10 & 2) != 0) {
        *pcVar12 = first;
        pcVar12 = pcVar12 + 1;
        first = lex_getc();
        if (&g_string_literal_buffer < pcVar12) {
          diag_fatal_simple(0x40);
        }
        bVar10 = g_char_flags[first];
      }
      suffix = (uint)pcVar12[-1];
      pbVar11 = g_char_flags + suffix;
      if (((g_char_flags[suffix] & 0x10) == 0) || ((first & 0xdf) == 0x48)) {
        pbVar11 = g_char_flags + uVar9;
        suffix = uVar9;
        if ((g_char_flags[uVar9] & 0x10) != 0) {
          first = lex_getc();
        }
      }
      else {
        pcVar12 = pcVar12 + -1;
      }
      if ((*pbVar11 & 0x10) != 0) {
        pcVar12 = lex_scan_integer_literal_radix_suffix(suffix,first,pcVar12,iVar16,pcVar8,value);
        return pcVar12;
      }
    }
  }
  bVar10 = first & 0xdf;
  if (bVar10 == 0x4c) {
    bVar10 = lex_getc();
    pcVar8 = g_type_unsigned_long;
    if ((bVar10 & 0xdf) != 0x55) {
      g_input_ptr = g_input_ptr + -1;
      pcVar8 = g_type_long;
    }
  }
  else if ((g_integral_max_bytes < 1) || (bVar10 != 0x49)) {
    if (bVar10 == 0x55) {
      bVar10 = lex_getc();
      pcVar8 = g_type_unsigned_long;
      if ((bVar10 & 0xdf) != 0x4c) {
        if ((g_integral_max_bytes < 1) || ((bVar10 & 0xdf) != 0x49)) {
          g_input_ptr = g_input_ptr + -1;
          pcVar8 = g_type_unsigned_int;
        }
        else {
          pcVar8 = lex_scan_sized_int_suffix('\x01');
        }
      }
    }
    else {
      g_input_ptr = g_input_ptr + -1;
    }
  }
  else {
    pcVar8 = lex_scan_sized_int_suffix('\0');
  }
  if ((g_char_flags[*g_input_ptr] & 1) != 0) {
    diag_error(0x3b,0x4d,0x132);
  }
  *pcVar12 = 0;
  if ((int)(pcVar12 + -0x104dd9d3) < 2) {
    lVar15 = 0;
    value._0_4_ = 0;
  }
  else {
    lVar15 = lex_scan_integer_constant(g_number_digit_buffer,(int)(pcVar12 + -0x104dd9d4),iVar16);
    value._0_4_ = (uint)lVar15;
  }
  uVar9 = (uint)((ulonglong)lVar15 >> 0x20);
  value = CONCAT44(uVar9,(uint)value);
  cVar2 = (char)pcVar8->code;
  pcVar5 = pcVar8;
  while (cVar2 < '\0') {
    pcVar5 = pcVar5->base;
    cVar2 = (char)pcVar5->code;
  }
  uVar3 = pcVar5->code;
  if (0x2013 < uVar3) {
    switch(uVar3) {
    case 0x2014:
      pcVar8 = lex_unsigned_long_literal_type((uint *)&value);
      break;
    case 0x2019:
      value = (longlong)((uint)value & 0xff);
      break;
    case 0x201a:
      value._0_4_ = (uint)value & 0xffff;
    case 0x201b:
      value = (longlong)(uint)value;
      break;
    case 0x201d:
      iVar16 = 0;
      value._0_4_ = 0;
      goto LAB_104631e1;
    }
    goto switchD_1040a77d_caseD_15;
  }
  if (uVar3 == 0x2013) {
    pcVar8 = lex_unsigned_literal_type((uint *)&value);
    goto switchD_1040a77d_caseD_15;
  }
  switch(uVar3) {
  case 0x13:
    if (iVar16 == 10) {
      pcVar8 = lex_decimal_literal_type((uint *)&value);
    }
    else {
      pcVar8 = lex_hex_octal_literal_type((uint *)&value);
    }
    break;
  case 0x14:
    pcVar8 = lex_long_literal_type((uint *)&value);
    break;
  case 0x19:
    iVar16 = (uint)value << 0x18;
    value._0_4_ = iVar16 >> 0x18;
    iVar16 = iVar16 >> 0x1f;
    goto LAB_104631e1;
  case 0x1a:
    iVar16 = (uint)value << 0x10;
    value._0_4_ = iVar16 >> 0x10;
    iVar16 = iVar16 >> 0x1f;
LAB_104631e1:
    value = CONCAT44(iVar16,(uint)value);
    break;
  case 0x1b:
    value = (longlong)(int)(uint)value;
    break;
  case 0x1d:
    lVar15 = _allshl(0xc0,(uint)value,uVar9);
    value = _allshr(0xc0,(int)((ulonglong)lVar15 >> 0x20),(uint)lVar15);
  }
switchD_1040a77d_caseD_15:
  _g_yylval_word3 = value._4_4_;
  _g_yylval_word2 = (uint)value;
  g_yylval = (uint)pcVar8;
  if (g_token_arena_index == 0) {
    if (g_pool_default_left < 0x30) {
      pool_reserve((c1xx_pool *)&g_pool_default,0x30);
    }
    g_pool_default_left = g_pool_default_left - 0x30;
    pcVar12 = g_pool_default;
    g_pool_default = g_pool_default + 0x30;
  }
  else {
    pcVar7 = g_arenas + g_token_arena_index;
    pcVar12 = pcVar7->cur;
    pcVar4 = g_arenas[g_token_arena_index].end;
    pcVar7->cur = pcVar12 + 0x30;
    if (pcVar4 < pcVar12 + 0x30) {
      arena_grow(pcVar7);
    }
  }
joined_r0x1046308e:
  if (pcVar12 != (c1_u8 *)0x0) {
    *pcVar12 = 'e';
    puVar13 = &g_yylval;
    puVar14 = (uint *)(pcVar12 + 8);
    for (iVar16 = 10; iVar16 != 0; iVar16 = iVar16 + -1) {
      *puVar14 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar14 = puVar14 + 1;
    }
    return pcVar12;
  }
  return (c1_u8 *)0x0;
}

