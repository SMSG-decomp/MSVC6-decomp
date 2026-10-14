uint64_t _aulldiv(uint32_t lo,uint32_t hi,uint32_t dlo,uint32_t dhi)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint32_t uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar5 = lo;
  uVar9 = dhi;
  uVar7 = hi;
  uVar3 = dlo;
  if (dhi == 0) {
    uVar3 = hi / dlo;
    iVar4 = (int)(((ulonglong)hi % (ulonglong)dlo << 0x20 | (ulonglong)lo) / (ulonglong)dlo);
  }
  else {
    do {
      uVar6 = uVar9 >> 1;
      uVar3 = (uint)(CONCAT14((uVar9 & 1) != 0,uVar3) >> 1);
      uVar8 = uVar7 >> 1;
      uVar5 = (uint32_t)(CONCAT14((uVar7 & 1) != 0,uVar5) >> 1);
      uVar9 = uVar6;
      uVar7 = uVar8;
    } while (uVar6 != 0);
    uVar1 = CONCAT44(uVar8,uVar5) / (ulonglong)uVar3;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)dlo * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar9 = uVar3 + iVar4 * dhi;
    if (((CARRY4(uVar3,iVar4 * dhi)) || (hi < uVar9)) || ((hi <= uVar9 && (lo < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  return CONCAT44(uVar3,iVar4);
}

