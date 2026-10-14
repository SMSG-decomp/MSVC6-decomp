uint __cdecl lex_scan_escape_sequence(byte c,int wide)

{
  c1_u8 cVar1;
  byte bVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  undefined2 uVar7;
  int iVar6;
  uint extraout_EAX;
  uint3 extraout_var;
  undefined3 extraout_var_00;
  undefined2 extraout_var_02;
  uint extraout_EAX_00;
  undefined2 extraout_var_03;
  undefined3 extraout_var_01;
  char cVar8;
  undefined4 unaff_EBX;
  undefined4 ebx;
  int iVar9;
  short sVar10;
  
  bVar2 = c;
  _c = (uint)c;
  uVar5 = (uint)bVar2;
  if ((g_char_flags[uVar5] & 8) == 0) {
    ebx = CONCAT31((int3)((uint)unaff_EBX >> 8),bVar2);
    do {
      uVar4 = uVar5 - 0x22;
      cVar8 = (char)ebx;
      uVar7 = (undefined2)(uVar4 >> 0x10);
      switch(uVar5) {
      case 0x22:
      case 0x27:
code_r0x10426520:
        return CONCAT31((int3)(uVar4 >> 8),cVar8) & 0xffff00ff;
      default:
        if (g_char_class[_c] != '#') {
          diag_warning(1,0x81,(int)cVar8);
          uVar3 = lex_scan_escape_sequence_return_char(ebx);
          return CONCAT31(extraout_var_01,uVar3);
        }
        bVar2 = *g_input_ptr;
        while (g_input_ptr = g_input_ptr + 1, bVar2 == 0) {
          lex_buffer_refill();
          bVar2 = *g_input_ptr;
        }
        diag_warning(1,0x81,(uint)CONCAT11(cVar8,bVar2));
        return CONCAT22(extraout_var_03,CONCAT11(cVar8,bVar2));
      case 0x3f:
        uVar4 = lex_trigraph();
        if ((uVar4 & 0xffffffbf) == 0) goto code_r0x10426520;
        bVar2 = *g_input_ptr;
        cVar1 = g_char_class[bVar2];
        break;
      case 0x5c:
        iVar9 = lex_line_splice();
        uVar4 = 0;
        if (iVar9 == 0) goto code_r0x10426520;
        bVar2 = *g_input_ptr;
        cVar1 = g_char_class[bVar2];
        break;
      case 0x61:
        return CONCAT22(uVar7,7);
      case 0x62:
        return CONCAT22(uVar7,8);
      case 0x66:
        return CONCAT22(uVar7,0xc);
      case 0x6e:
        return CONCAT22(uVar7,10);
      case 0x72:
        return CONCAT22(uVar7,0xd);
      case 0x74:
        return CONCAT22(uVar7,9);
      case 0x76:
        return CONCAT22(uVar7,0xb);
      case 0x78:
        uVar5 = 0;
        bVar2 = *g_input_ptr;
        g_input_ptr = g_input_ptr + 1;
        if (g_char_class[bVar2] == '\0') {
          bVar2 = lex_next_significant_char(bVar2);
        }
        _c = (uint)bVar2;
        if ((g_char_flags[bVar2] & 2) == 0) {
          diag_error(0x99);
          uVar4 = extraout_EAX_00;
        }
        else {
          do {
            iVar9 = lex_hex_digit_value(_c);
            uVar5 = uVar5 * 0x10 + iVar9;
            bVar2 = *g_input_ptr;
            uVar4 = CONCAT31((int3)((uint)iVar9 >> 8),bVar2);
            g_input_ptr = g_input_ptr + 1;
            if (g_char_class[bVar2] == '\0') {
              bVar2 = lex_next_significant_char(bVar2);
              uVar4 = CONCAT31(extraout_var_00,bVar2);
            }
            _c = uVar4 & 0xff;
          } while ((g_char_flags[bVar2] & 2) != 0);
        }
        if ((wide == 0) && (uVar4 = uVar5 & 0xff, uVar5 != uVar4)) {
          sVar10 = 0x16;
LAB_10463ab2:
          diag_error(sVar10,uVar5);
          uVar7 = extraout_var_02;
        }
        else {
          uVar7 = (undefined2)(uVar4 >> 0x10);
          if (uVar5 != (uVar5 & 0xffff)) {
            sVar10 = 0xbc;
            goto LAB_10463ab2;
          }
        }
        g_input_ptr = g_input_ptr + -1;
        if (wide != 0) {
          return CONCAT22(uVar7,(short)uVar5);
        }
        goto LAB_104265e4;
      }
      g_input_ptr = g_input_ptr + 1;
      if (cVar1 == '\0') {
        bVar2 = lex_next_significant_char(bVar2);
      }
      ebx = CONCAT31((int3)((uint)ebx >> 8),bVar2);
      _c = (uint)bVar2;
      uVar5 = (uint)bVar2;
    } while ((g_char_flags[uVar5] & 8) == 0);
  }
  iVar9 = 1;
  uVar5 = lex_hex_digit_value(_c);
  bVar2 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  if (g_char_class[bVar2] == '\0') {
    bVar2 = lex_next_significant_char(bVar2);
  }
  _c = (uint)bVar2;
  do {
    if ((g_char_flags[_c] & 8) == 0) break;
    iVar6 = lex_hex_digit_value(_c);
    uVar5 = iVar6 + uVar5 * 8;
    iVar9 = iVar9 + 1;
    bVar2 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    if (g_char_class[bVar2] == '\0') {
      bVar2 = lex_next_significant_char(bVar2);
    }
    _c = (uint)bVar2;
  } while (iVar9 < 3);
  uVar4 = g_opt_E_preprocess;
  if (g_opt_E_preprocess != 0) goto LAB_104265ce;
  if ((wide == 0) && (uVar4 = uVar5 & 0xff, uVar5 != uVar4)) {
    sVar10 = 0x16;
LAB_10463979:
    diag_error(sVar10,uVar5);
    uVar4 = extraout_EAX;
  }
  else if (uVar5 != (uVar5 & 0xffff)) {
    sVar10 = 0xbc;
    goto LAB_10463979;
  }
  if (g_char_class[_c] == '\x1d') {
    diag_warning(4,0x7d);
    uVar4 = (uint)extraout_var << 8;
  }
LAB_104265ce:
  uVar7 = (undefined2)(uVar4 >> 0x10);
  g_input_ptr = g_input_ptr + -1;
  if (wide != 0) {
    return CONCAT22(uVar7,(short)uVar5);
  }
LAB_104265e4:
  return CONCAT22(uVar7,(short)(char)uVar5);
}

