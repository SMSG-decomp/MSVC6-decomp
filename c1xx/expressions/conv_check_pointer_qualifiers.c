int __cdecl
conv_check_pointer_qualifiers(uint op,ushort target_quals,ushort source_quals,int rank_flag)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = op & 0xff;
  switch(g_token_class[uVar2]) {
  case '4':
  case 'p':
  case 't':
  case '}':
    break;
  default:
    return 2;
  case '6':
  case 'n':
  case '|':
    return 1;
  }
  if ((((target_quals ^ source_quals) & 0x3e0) != 0) && ((source_quals & 0x3e0) != 0)) {
    bVar1 = false;
    if (((target_quals & 0x40) == 0) && ((source_quals & 0x40) != 0)) {
      diag_error(0x10c,uVar2,0x30);
      bVar1 = true;
    }
    if (((target_quals & 0x20) == 0) && ((source_quals & 0x20) != 0)) {
      diag_error(0x10c,uVar2,0x2f);
      return 0;
    }
    if (bVar1) {
      return 0;
    }
  }
  return 2 - (uint)(rank_flag != 0);
}

