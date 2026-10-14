int __fastcall const_leading_zero_bits(c2_operand *k)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (k->u18).lo;
  iVar1 = 0;
  switch(k->type & 0xfff) {
  case 1:
    uVar3 = uVar2 & 0xff;
    if (uVar3 == 0) {
      return 8;
    }
    if ((uVar2 & 0x80) == 0) {
      do {
        uVar3 = uVar3 << 1;
        iVar1 = iVar1 + 1;
      } while ((uVar3 & 0x80) == 0);
      return iVar1;
    }
    break;
  case 2:
    uVar3 = uVar2 & 0xffff;
    if (uVar3 == 0) {
      return 0x10;
    }
    if ((uVar2 & 0x8000) == 0) {
      do {
        uVar3 = uVar3 << 1;
        iVar1 = iVar1 + 1;
      } while ((uVar3 & 0x8000) == 0);
      return iVar1;
    }
    break;
  case 4:
    if (uVar2 == 0) {
      return 0x20;
    }
    for (; (uVar2 & 0x80000000) == 0; uVar2 = uVar2 << 1) {
      iVar1 = iVar1 + 1;
    }
    break;
  case 0x10:
    return 0;
  }
  return iVar1;
}

