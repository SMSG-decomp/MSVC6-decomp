c1_u8 * __cdecl
lex_scan_integer_literal_radix_suffix
          (uint suffix,byte next_char,byte *digits_end,int radix,c1_type *type,longlong value)

{
  char cVar1;
  ushort uVar2;
  c1_u8 *pcVar3;
  c1_type *pcVar4;
  c1_arena *a;
  c1_u8 *pcVar5;
  int iVar6;
  uint hi;
  byte bVar7;
  uint *puVar8;
  uint *puVar9;
  longlong lVar10;
  
  switch(suffix & 0xdf) {
  case 0x42:
    radix = 2;
    break;
  case 0x44:
    radix = 10;
    break;
  case 0x48:
    radix = 0x10;
    break;
  case 0x4f:
  case 0x51:
    radix = 8;
  }
  bVar7 = next_char & 0xdf;
  if (bVar7 == 0x4c) {
    bVar7 = lex_getc();
    type = g_type_unsigned_long;
    if ((bVar7 & 0xdf) != 0x55) {
      g_input_ptr = g_input_ptr + -1;
      type = g_type_long;
    }
  }
  else if ((g_integral_max_bytes < 1) || (bVar7 != 0x49)) {
    if (bVar7 == 0x55) {
      bVar7 = lex_getc();
      type = g_type_unsigned_long;
      if ((bVar7 & 0xdf) != 0x4c) {
        if ((g_integral_max_bytes < 1) || ((bVar7 & 0xdf) != 0x49)) {
          g_input_ptr = g_input_ptr + -1;
          type = g_type_unsigned_int;
        }
        else {
          type = lex_scan_sized_int_suffix('\x01');
        }
      }
    }
    else {
      g_input_ptr = g_input_ptr + -1;
    }
  }
  else {
    type = lex_scan_sized_int_suffix('\0');
  }
  if ((g_char_flags[*g_input_ptr] & 1) != 0) {
    diag_error(0x3b,0x4d,0x132);
  }
  *digits_end = 0;
  if ((int)(digits_end + -0x104dd9d3) < 2) {
    lVar10 = 0;
    value._0_4_ = 0;
  }
  else {
    lVar10 = lex_scan_integer_constant(g_number_digit_buffer,(int)(digits_end + -0x104dd9d4),radix);
    value._0_4_ = (uint)lVar10;
  }
  hi = (uint)((ulonglong)lVar10 >> 0x20);
  value = CONCAT44(hi,(uint)value);
  cVar1 = (char)type->code;
  pcVar4 = type;
  while (cVar1 < '\0') {
    pcVar4 = pcVar4->base;
    cVar1 = (char)pcVar4->code;
  }
  uVar2 = pcVar4->code;
  if (0x2013 < uVar2) {
    switch(uVar2) {
    case 0x2014:
      type = lex_unsigned_long_literal_type((uint *)&value);
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
      iVar6 = 0;
      value._0_4_ = 0;
      goto LAB_104631e1;
    }
    goto switchD_1040a77d_caseD_15;
  }
  if (uVar2 == 0x2013) {
    type = lex_unsigned_literal_type((uint *)&value);
    goto switchD_1040a77d_caseD_15;
  }
  switch(uVar2) {
  case 0x13:
    if (radix == 10) {
      type = lex_decimal_literal_type((uint *)&value);
    }
    else {
      type = lex_hex_octal_literal_type((uint *)&value);
    }
    break;
  case 0x14:
    type = lex_long_literal_type((uint *)&value);
    break;
  case 0x19:
    iVar6 = (uint)value << 0x18;
    value._0_4_ = iVar6 >> 0x18;
    iVar6 = iVar6 >> 0x1f;
    goto LAB_104631e1;
  case 0x1a:
    iVar6 = (uint)value << 0x10;
    value._0_4_ = iVar6 >> 0x10;
    iVar6 = iVar6 >> 0x1f;
LAB_104631e1:
    value = CONCAT44(iVar6,(uint)value);
    break;
  case 0x1b:
    value = (longlong)(int)(uint)value;
    break;
  case 0x1d:
    lVar10 = _allshl(0xc0,(uint)value,hi);
    value = _allshr(0xc0,(int)((ulonglong)lVar10 >> 0x20),(uint)lVar10);
  }
switchD_1040a77d_caseD_15:
  _g_yylval_word3 = value._4_4_;
  _g_yylval_word2 = (uint)value;
  g_yylval = (uint)type;
  if (g_token_arena_index == 0) {
    if (g_pool_default_left < 0x30) {
      pool_reserve((c1xx_pool *)&g_pool_default,0x30);
    }
    g_pool_default_left = g_pool_default_left - 0x30;
    pcVar5 = g_pool_default;
    g_pool_default = g_pool_default + 0x30;
  }
  else {
    a = g_arenas + g_token_arena_index;
    pcVar5 = a->cur;
    pcVar3 = g_arenas[g_token_arena_index].end;
    a->cur = pcVar5 + 0x30;
    if (pcVar3 < pcVar5 + 0x30) {
      arena_grow(a);
    }
  }
  if (pcVar5 != (c1_u8 *)0x0) {
    *pcVar5 = 'e';
    puVar8 = &g_yylval;
    puVar9 = (uint *)(pcVar5 + 8);
    for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar9 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
    }
    return pcVar5;
  }
  return (c1_u8 *)0x0;
}

