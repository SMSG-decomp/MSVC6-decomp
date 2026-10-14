int __cdecl
conv_warn_different_qualifiers
          (c1_u8 op,c1_u16 target_qualifiers,c1_u16 source_qualifiers,int relaxed,int unused)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = (uint)op;
  switch((&g_token_class)[uVar2]) {
  case 0x34:
  case 0x70:
  case 0x74:
  case 0x7d:
    break;
  default:
    return 2;
  case 0x36:
  case 0x6e:
  case 0x7c:
    return 1;
  }
  if ((((target_qualifiers ^ source_qualifiers) & 0x3e0) != 0) && ((source_qualifiers & 0x3e0) != 0)
     ) {
    bVar1 = false;
    if (((target_qualifiers & 0x40) == 0) && ((source_qualifiers & 0x40) != 0)) {
      diag_warning(1,0x5a,uVar2,0x30);
      bVar1 = true;
    }
    if (((target_qualifiers & 0x20) == 0) && ((source_qualifiers & 0x20) != 0)) {
      diag_warning(1,0x5a,uVar2,0x2f);
      return 0;
    }
    if (bVar1) {
      return 0;
    }
  }
  return 2 - (uint)(relaxed != 0);
}

