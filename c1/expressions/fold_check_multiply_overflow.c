uint __cdecl
fold_check_multiply_overflow(uint a_lo,int a_hi,uint b_lo,int b_hi,int is_unsigned,uint size)

{
  char cVar1;
  int iVar2;
  uint32_t lo;
  byte count;
  int iVar3;
  uint32_t hi;
  uint uVar4;
  uint32_t dlo;
  int iVar5;
  uint32_t dhi;
  uint uVar6;
  longlong lVar7;
  uint64_t uVar8;
  longlong lVar9;
  longlong lVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  
  uVar4 = a_lo;
  cVar1 = (char)size;
  if (is_unsigned == 0) {
    dlo = a_lo;
    dhi = a_hi;
    if (a_hi < 0) {
      dlo = -a_lo;
      dhi = -(a_hi + (uint)(a_lo != 0));
    }
    if (b_hi < 0) {
      a_lo = -b_lo;
      iVar5 = -(b_hi + (uint)(b_lo != 0));
    }
    else {
      a_lo = b_lo;
      iVar5 = b_hi;
    }
    if ((a_hi < 0) || ((a_hi < 1 && (uVar4 == 0)))) {
      iVar3 = 0;
    }
    else {
      iVar3 = 1;
    }
    if ((b_hi < 0) || ((b_hi < 1 && (b_lo == 0)))) {
      iVar2 = 0;
    }
    else {
      iVar2 = 1;
    }
    if (iVar2 == iVar3) {
      lVar7 = _allshl(cVar1 * '\b' - 1,0xffffffff,0xffffffff);
      lo = ~(uint)lVar7;
      hi = ~(uint)((ulonglong)lVar7 >> 0x20);
    }
    else {
      lVar7 = _allshl(cVar1 * '\b' - 1,0xffffffff,0xffffffff);
      lo = ~(uint)lVar7 + 1;
      hi = ~(uint)((ulonglong)lVar7 >> 0x20) + (uint)(0xfffffffe < ~(uint)lVar7);
    }
    if ((dlo != 0 || dhi != 0) && (uVar8 = _aulldiv(lo,hi,dlo,dhi), uVar8 < CONCAT44(iVar5,a_lo))) {
      return 1;
    }
  }
  else {
    lVar7 = _allshl(cVar1 * '\b' - 1,0xffffffff,0xffffffff);
    uVar6 = ~(uint)((ulonglong)lVar7 >> 0x20);
    lVar9 = _allshl(1,~(uint)lVar7,uVar6);
    count = ('\b' - cVar1) * '\b';
    lVar10 = _allshl(count,a_lo,a_hi);
    uVar11 = _aullshr(count,(uint)((ulonglong)lVar10 >> 0x20),(uint)lVar10);
    lVar10 = _allshl(count,b_lo,b_hi);
    uVar12 = _aullshr(count,(uint)((ulonglong)lVar10 >> 0x20),(uint)lVar10);
    uVar4 = (uint)(uVar12 >> 0x20);
    if (uVar11 != 0) {
      uVar8 = _aulldiv((uint)lVar9 | ~(uint)lVar7,(uint)((ulonglong)lVar9 >> 0x20) | uVar6,
                       (uint32_t)uVar11,(uint32_t)(uVar11 >> 0x20));
      uVar6 = (uint)(uVar8 >> 0x20);
      if (uVar6 <= uVar4) {
        if (uVar4 != uVar6) {
          return 1;
        }
        if ((uint)uVar8 < (uint)uVar12) {
          return 1;
        }
      }
    }
  }
  return 0;
}

