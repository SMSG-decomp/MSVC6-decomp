int __cdecl fold_add_overflows(uint a_lo,int a_hi,uint b_lo,int b_hi,int is_unsigned,uint size)

{
  char cVar1;
  bool bVar2;
  byte count;
  uint hi;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  
  cVar1 = (char)size;
  if (is_unsigned == 0) {
    if (-1 < b_hi != -1 < a_hi) {
      return 0;
    }
    if ((a_hi < 1) && ((a_hi < 0 || (a_lo == 0)))) {
      bVar2 = true;
      lVar4 = _allshl(cVar1 * '\b' - 1,0xffffffff,0xffffffff);
    }
    else {
      bVar2 = false;
      lVar4 = _allshl(cVar1 * '\b' - 1,0xffffffff,0xffffffff);
      lVar4 = CONCAT44(~(uint)((ulonglong)lVar4 >> 0x20),~(uint)lVar4);
    }
    lVar4 = lVar4 - CONCAT44(a_hi,a_lo);
    if (bVar2) {
      if (lVar4 <= CONCAT44(b_hi,b_lo)) {
        return 0;
      }
    }
    else if (CONCAT44(b_hi,b_lo) <= lVar4) {
      return 0;
    }
  }
  else {
    lVar4 = _allshl(cVar1 * '\b' - 1,0xffffffff,0xffffffff);
    count = ('\b' - cVar1) * '\b';
    hi = ~(uint)((ulonglong)lVar4 >> 0x20);
    lVar5 = _allshl(count,a_lo,a_hi);
    uVar6 = _aullshr(count,(uint)((ulonglong)lVar5 >> 0x20),(uint)lVar5);
    lVar5 = _allshl(1,~(uint)lVar4,hi);
    uVar3 = (uint)lVar5 | ~(uint)lVar4;
    lVar4 = _allshl(count,b_lo,b_hi);
    uVar7 = _aullshr(count,(uint)((ulonglong)lVar4 >> 0x20),(uint)lVar4);
    if (uVar7 <= CONCAT44((((uint)((ulonglong)lVar5 >> 0x20) | hi) - (int)(uVar6 >> 0x20)) -
                          (uint)(uVar3 < (uint)uVar6),uVar3 - (uint)uVar6)) {
      return 0;
    }
  }
  return 1;
}

