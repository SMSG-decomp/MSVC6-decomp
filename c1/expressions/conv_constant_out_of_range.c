int __cdecl
conv_constant_out_of_range(uint size,int target_unsigned,int source_unsigned,uint lo,uint hi)

{
  char cVar1;
  uint uVar2;
  bool bVar3;
  longlong lVar4;
  longlong lVar5;
  
  cVar1 = (char)size;
  if (target_unsigned != 0) {
    if (((source_unsigned == 0) && ((int)hi < 1)) && ((int)hi < 0)) {
      bVar3 = lo != 0;
      lo = -lo;
      hi = -(hi + bVar3);
    }
    lVar4 = _allshl(cVar1 * '\b' - 1,0xffffffff,0xffffffff);
    uVar2 = ~(uint)((ulonglong)lVar4 >> 0x20);
    lVar5 = _allshl(1,~(uint)lVar4,uVar2);
    uVar2 = (uint)((ulonglong)lVar5 >> 0x20) | uVar2;
    if ((uVar2 <= hi) && ((uVar2 < hi || (((uint)lVar5 | ~(uint)lVar4) < lo)))) {
      return 1;
    }
    return 0;
  }
  if (source_unsigned == 0) {
    lVar4 = _allshl(cVar1 * '\b' - 1,0xffffffff,0xffffffff);
    uVar2 = ~(uint)((ulonglong)lVar4 >> 0x20);
    if (((int)uVar2 <= (int)hi) && (((int)uVar2 < (int)hi || (~(uint)lVar4 < lo)))) {
      return 1;
    }
    if (CONCAT44(hi,lo) < lVar4) {
      return 1;
    }
  }
  else {
    lVar4 = _allshl(cVar1 * '\b' - 1,0xffffffff,0xffffffff);
    uVar2 = ~(uint)((ulonglong)lVar4 >> 0x20);
    lVar5 = _allshl(1,~(uint)lVar4,uVar2);
    uVar2 = (uint)((ulonglong)lVar5 >> 0x20) | uVar2;
    if (uVar2 <= hi) {
      if (hi != uVar2) {
        return 1;
      }
      if (((uint)lVar5 | ~(uint)lVar4) < lo) {
        return 1;
      }
    }
  }
  return 0;
}

