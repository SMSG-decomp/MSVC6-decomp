void __fastcall decl_combine_type_specifiers(undefined4 *state)

{
  ushort code;
  char *pcVar1;
  char *pcVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  bool bVar6;
  
  if (state[0xc] != 0) {
    diag_error(0x274,state[0xd],g_token_spelling[*(byte *)*state]);
    return;
  }
  code = *(ushort *)(state + 0x10);
  uVar3 = (ushort)g_tree_op_to_il_op[*(byte *)*state];
  if (code == 0) {
    *(ushort *)(state + 0x10) = uVar3;
    return;
  }
  uVar4 = (ushort)(code & 0x3000);
  uVar5 = (ushort)(uVar3 & 0x3000);
  if ((uVar4 != 0) && (uVar5 != 0)) {
    if ((uVar5 & uVar4) == 0) {
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
    *(ushort *)(state + 0x10) = code | uVar3;
    return;
  }
  if (uVar5 != 0) {
    if (((((code & 0x10) == 0) || (((byte)code & 0x15) == 0x15)) || ((code & 0xfff) == 0x10)) &&
       ((code & 0x400) == 0)) {
      pcVar1 = type_keyword_text(code);
      diag_warning(1,0x4c,(uVar3 & 0x3000) >> 0xd | 0x18,pcVar1);
      return;
    }
    *(ushort *)(state + 0x10) = code | uVar3;
    return;
  }
  uVar3 = uVar3 & 0xfff;
  switch(code & 0xfff) {
  case 0x10:
  case 0x11:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x28:
    break;
  case 0x12:
    bVar6 = uVar3 != 0x13 || *(char *)(state + 0x11) != '\0';
    uVar4 = uVar4 | 0x12;
LAB_104590c3:
    *(ushort *)(state + 0x10) = uVar4;
    *(undefined1 *)(state + 0x11) = 1;
    goto LAB_10407874;
  case 0x13:
    if (uVar3 == 0x12) {
      *(ushort *)(state + 0x10) = uVar4 | 0x12;
      *(undefined1 *)(state + 0x11) = 1;
      return;
    }
    if (uVar3 == 0x14) {
      *(ushort *)(state + 0x10) = uVar4 | 0x14;
      *(undefined1 *)(state + 0x11) = 1;
      return;
    }
    break;
  case 0x14:
    bVar6 = *(char *)(state + 0x11) != '\0';
    switch(uVar3) {
    case 0x13:
      uVar4 = uVar4 | 0x14;
      goto LAB_104590c3;
    default:
      goto decl_check_illegal_token_pair;
    case 0x26:
      diag_warning(1,0xd7);
      *(undefined2 *)(state + 0x10) = 0x27;
      break;
    case 0x27:
      *(undefined2 *)(state + 0x10) = 0x28;
    }
LAB_10407874:
    if (!bVar6) {
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
      *(undefined2 *)(state + 0x10) = 0x27;
      return;
    }
    break;
  case 0x27:
    if (uVar3 == 0x14) {
      *(undefined2 *)(state + 0x10) = 0x28;
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

