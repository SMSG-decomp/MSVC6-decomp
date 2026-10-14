void __fastcall decl_combine_type_specifiers(c1_specifier_state *spec)

{
  ushort code;
  char *pcVar1;
  char *pcVar2;
  ushort uVar3;
  ushort uVar4;
  c1_u16 cVar5;
  ushort uVar6;
  bool bVar7;
  
  if (spec->named_type != (c1_type *)0x0) {
    diag_error(0x274,(spec->named).sym,g_token_spelling[spec->token->code]);
    return;
  }
  code = spec->basic_type;
  uVar3 = (ushort)g_tree_op_to_il_op[spec->token->code];
  if (code == 0) {
    spec->basic_type = uVar3;
    return;
  }
  uVar4 = (ushort)(code & 0x3000);
  uVar6 = (ushort)(uVar3 & 0x3000);
  if ((uVar4 != 0) && (uVar6 != 0)) {
    if ((uVar6 & uVar4) == 0) {
      diag_error(0x2a);
      return;
    }
    diag_warning(1,0x72);
    return;
  }
  if (uVar4 == code) {
    if (((((uVar3 & 0x10) == 0) || (((byte)uVar3 & 0x15) == 0x15)) || ((uVar3 & 0xfff) == 0x10)) &&
       ((uVar3 & 0x400) == 0)) {
      pcVar1 = type_keyword_text(uVar3);
      diag_warning(1,0x4c,(code & 0x3000) >> 0xd | 0x18,pcVar1);
      return;
    }
    spec->basic_type = code | uVar3;
    return;
  }
  if (uVar6 != 0) {
    if (((((code & 0x10) == 0) || (((byte)code & 0x15) == 0x15)) || ((code & 0xfff) == 0x10)) &&
       ((code & 0x400) == 0)) {
      pcVar1 = type_keyword_text(code);
      diag_warning(1,0x4c,(uVar3 & 0x3000) >> 0xd | 0x18,pcVar1);
      return;
    }
    spec->basic_type = code | uVar3;
    return;
  }
  uVar3 = uVar3 & 0xfff;
  switch(code & 0xfff) {
  case 0x11:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x28:
    break;
  case 0x12:
    bVar7 = uVar3 != 0x13 || spec->size_keyword != '\0';
    cVar5 = uVar4 | 0x12;
LAB_10606688:
    spec->basic_type = cVar5;
    spec->size_keyword = '\x01';
    goto LAB_106066ca;
  case 0x13:
    if (uVar3 == 0x12) {
      spec->basic_type = uVar4 | 0x12;
      spec->size_keyword = '\x01';
      return;
    }
    if (uVar3 == 0x14) {
      spec->basic_type = uVar4 | 0x14;
      spec->size_keyword = '\x01';
      return;
    }
    break;
  case 0x14:
    bVar7 = spec->size_keyword != '\0';
    switch(uVar3) {
    case 0x13:
      cVar5 = uVar4 | 0x14;
      goto LAB_10606688;
    default:
      goto decl_check_illegal_token_pair;
    case 0x26:
      diag_warning(1,0xd7);
      spec->basic_type = 0x27;
      break;
    case 0x27:
      spec->basic_type = 0x28;
    }
LAB_106066ca:
    if (!bVar7) {
      return;
    }
    break;
  default:
    if ((code & 0x300) == 0) {
      if ((code & 0x40) == 0) {
        return;
      }
      diag_error(0x78);
      return;
    }
    break;
  case 0x26:
    if (uVar3 == 0x14) {
      diag_warning(1,0xd8);
      spec->basic_type = 0x27;
      return;
    }
    break;
  case 0x27:
    if (uVar3 == 0x14) {
      spec->basic_type = 0x28;
      return;
    }
  }
decl_check_illegal_token_pair:
  pcVar1 = type_keyword_text(uVar3);
  pcVar2 = type_keyword_text(code & 0xfff);
  diag_error(0x278,pcVar2,pcVar1);
  decl_check_illegal_token_pair_fragment();
  return;
}

