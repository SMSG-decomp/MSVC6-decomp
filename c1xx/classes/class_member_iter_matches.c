uint __fastcall class_member_iter_matches(c1_member_iter *iter)

{
  byte bVar1;
  uint3 uVar3;
  uint uVar2;
  
  uVar3 = (uint3)((uint)iter->filter >> 8);
  switch(iter->filter) {
  case 0:
    return CONCAT31(uVar3,1);
  case 1:
    bVar1 = *(byte *)((int)iter->current + -8) & 0x1f;
    if (((bVar1 != 3) && (bVar1 != 2)) || (uVar2 = 1, (*(byte *)((int)iter->current + -5) & 1) != 0)
       ) {
      return 0;
    }
    break;
  case 2:
    bVar1 = *(byte *)((int)iter->current + -8) & 0x1f;
    if (bVar1 == 0x11) {
      return 1;
    }
    if (bVar1 == 8) {
      return 1;
    }
    return 0;
  case 3:
    return (uint)((*(byte *)((int)iter->current + -8) & 0x1f) == 4);
  default:
    uVar2 = (uint)uVar3 << 8;
    break;
  case 5:
    bVar1 = *(byte *)((int)iter->current + -8) & 0x1f;
    if ((bVar1 != 0x11) && (bVar1 != 8)) {
      return 0;
    }
    if ((*(byte *)((int)iter->current + -7) & 0x40) != 0) {
      return 1;
    }
    return 0;
  }
  return uVar2;
}

