uint64_t lldiv_helper(uint32_t lo,uint32_t hi,uint32_t dlo,uint32_t dhi)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint32_t uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar10;
  char cVar11;
  uint uVar9;
  
  cVar11 = (int)hi < 0;
  if ((bool)cVar11) {
    bVar10 = lo != 0;
    lo = -lo;
    hi = -(uint)bVar10 - hi;
  }
  if ((int)dhi < 0) {
    cVar11 = cVar11 + '\x01';
    bVar10 = dlo != 0;
    dlo = -dlo;
    dhi = -(uint)bVar10 - dhi;
  }
  uVar5 = lo;
  uVar3 = dlo;
  uVar7 = hi;
  uVar9 = dhi;
  if (dhi == 0) {
    uVar3 = hi / dlo;
    iVar4 = (int)(((ulonglong)hi % (ulonglong)dlo << 0x20 | (ulonglong)lo) / (ulonglong)dlo);
  }
  else {
    do {
      uVar8 = uVar9 >> 1;
      uVar3 = (uint)(CONCAT14((uVar9 & 1) != 0,uVar3) >> 1);
      uVar6 = uVar7 >> 1;
      uVar5 = (uint32_t)(CONCAT14((uVar7 & 1) != 0,uVar5) >> 1);
      uVar7 = uVar6;
      uVar9 = uVar8;
    } while (uVar8 != 0);
    uVar1 = CONCAT44(uVar6,uVar5) / (ulonglong)uVar3;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)dlo * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar7 = uVar3 + iVar4 * dhi;
    if (((CARRY4(uVar3,iVar4 * dhi)) || (hi < uVar7)) || ((hi <= uVar7 && (lo < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  if (cVar11 == '\x01') {
    bVar10 = iVar4 != 0;
    iVar4 = -iVar4;
    uVar3 = -(uint)bVar10 - uVar3;
  }
  return CONCAT44(uVar3,iVar4);
}

