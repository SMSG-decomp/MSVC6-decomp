ushort __cdecl lex_scan_escape_sequence(byte c,int wide)

{
  c1_u8 cVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  short sVar7;
  
  uVar4 = (uint)c;
  bVar2 = g_char_flags[uVar4];
  while ((bVar2 & 8) == 0) {
    switch(uVar4) {
    case 0x22:
    case 0x27:
code_r0x1061fe24:
      return (ushort)c;
    default:
      if (g_char_class[c] == '#') {
        bVar2 = *g_input_ptr;
        while (g_input_ptr = g_input_ptr + 1, bVar2 == 0) {
          lex_buffer_refill();
          bVar2 = *g_input_ptr;
        }
        diag_warning(1,0x81,(uint)CONCAT11(c,bVar2));
        return CONCAT11(c,bVar2);
      }
      diag_warning(1,0x81,(int)(char)c);
      uVar3 = lex_scan_escape_sequence_return_char(c);
      return uVar3;
    case 0x3f:
      uVar4 = lex_trigraph();
      if ((uVar4 & 0xffffffbf) == 0) goto code_r0x1061fe24;
      c = *g_input_ptr;
      cVar1 = g_char_class[c];
      break;
    case 0x5c:
      iVar6 = lex_line_splice();
      if (iVar6 == 0) goto code_r0x1061fe24;
      c = *g_input_ptr;
      cVar1 = g_char_class[c];
      break;
    case 0x61:
      return 7;
    case 0x62:
      return 8;
    case 0x66:
      return 0xc;
    case 0x6e:
      return 10;
    case 0x72:
      return 0xd;
    case 0x74:
      return 9;
    case 0x76:
      return 0xb;
    case 0x78:
      uVar4 = 0;
      bVar2 = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
      if (g_char_class[bVar2] == '\0') {
        bVar2 = lex_next_significant_char(bVar2);
      }
      if ((g_char_flags[bVar2] & 2) == 0) {
        diag_error(0x99);
      }
      else {
        do {
          _c = (uint)bVar2;
          iVar6 = lex_hex_digit_value(_c);
          uVar4 = uVar4 * 0x10 + iVar6;
          bVar2 = *g_input_ptr;
          g_input_ptr = g_input_ptr + 1;
          if (g_char_class[bVar2] == '\0') {
            bVar2 = lex_next_significant_char(bVar2);
          }
        } while ((g_char_flags[bVar2] & 2) != 0);
      }
      if ((wide == 0) && (uVar4 != (uVar4 & 0xff))) {
        sVar7 = 0x16;
LAB_1062ed07:
        diag_error(sVar7,uVar4);
      }
      else if (uVar4 != (uVar4 & 0xffff)) {
        sVar7 = 0xbc;
        goto LAB_1062ed07;
      }
      g_input_ptr = g_input_ptr + -1;
      if (wide != 0) {
        return (ushort)uVar4;
      }
      goto LAB_1061ff27;
    }
    g_input_ptr = g_input_ptr + 1;
    if (cVar1 == '\0') {
      c = lex_next_significant_char(c);
    }
    uVar4 = (uint)c;
    bVar2 = g_char_flags[uVar4];
  }
  iVar6 = 1;
  uVar4 = lex_hex_digit_value((uint)c);
  bVar2 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  if (g_char_class[bVar2] == '\0') {
    bVar2 = lex_next_significant_char(bVar2);
  }
  _c = (uint)bVar2;
  do {
    if ((g_char_flags[_c] & 8) == 0) break;
    iVar5 = lex_hex_digit_value(_c);
    uVar4 = iVar5 + uVar4 * 8;
    iVar6 = iVar6 + 1;
    bVar2 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    if (g_char_class[bVar2] == '\0') {
      bVar2 = lex_next_significant_char(bVar2);
    }
    _c = (uint)bVar2;
  } while (iVar6 < 3);
  if (g_opt_E_preprocess != 0) goto LAB_1061ff11;
  if ((wide == 0) && (uVar4 != (uVar4 & 0xff))) {
    sVar7 = 0x16;
LAB_1062ec6f:
    diag_error(sVar7,uVar4);
  }
  else if (uVar4 != (uVar4 & 0xffff)) {
    sVar7 = 0xbc;
    goto LAB_1062ec6f;
  }
  if (g_char_class[_c] == '\x1d') {
    diag_warning(4,0x7d);
  }
LAB_1061ff11:
  g_input_ptr = g_input_ptr + -1;
  if (wide != 0) {
    return (ushort)uVar4;
  }
LAB_1061ff27:
  return (short)(char)uVar4;
}

