uint64_t llrem_helper(uint32_t lo,uint32_t hi,uint32_t dlo,uint32_t dhi)

{
  ulonglong uVar1;
  longlong lVar2;
  uint32_t uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  
  bVar13 = (int)hi < 0;
  if (bVar13) {
    bVar12 = lo != 0;
    lo = -lo;
    hi = -(uint)bVar12 - hi;
  }
  uVar11 = (uint)bVar13;
  if ((int)dhi < 0) {
    bVar13 = dlo != 0;
    dlo = -dlo;
    dhi = -(uint)bVar13 - dhi;
  }
  uVar3 = lo;
  uVar4 = dlo;
  uVar5 = hi;
  uVar9 = dhi;
  if (dhi == 0) {
    iVar6 = (int)(((ulonglong)hi % (ulonglong)dlo << 0x20 | (ulonglong)lo) % (ulonglong)dlo);
    iVar7 = 0;
    if ((int)(uVar11 - 1) < 0) goto LAB_1075038e;
  }
  else {
    do {
      uVar10 = uVar9 >> 1;
      uVar4 = (uint)(CONCAT14((uVar9 & 1) != 0,uVar4) >> 1);
      uVar8 = uVar5 >> 1;
      uVar3 = (uint32_t)(CONCAT14((uVar5 & 1) != 0,uVar3) >> 1);
      uVar5 = uVar8;
      uVar9 = uVar10;
    } while (uVar10 != 0);
    uVar1 = CONCAT44(uVar8,uVar3) / (ulonglong)uVar4;
    uVar4 = (int)uVar1 * dhi;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)dlo;
    uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar5 = (uint)lVar2;
    uVar8 = uVar9 + uVar4;
    if (((CARRY4(uVar9,uVar4)) || (hi < uVar8)) || ((hi <= uVar8 && (lo < uVar5)))) {
      bVar13 = uVar5 < dlo;
      uVar5 = uVar5 - dlo;
      uVar8 = (uVar8 - dhi) - (uint)bVar13;
    }
    iVar6 = uVar5 - lo;
    iVar7 = (uVar8 - hi) - (uint)(uVar5 < lo);
    if (-1 < (int)(uVar11 - 1)) goto LAB_1075038e;
  }
  bVar13 = iVar6 != 0;
  iVar6 = -iVar6;
  iVar7 = -(uint)bVar13 - iVar7;
LAB_1075038e:
  return CONCAT44(iVar7,iVar6);
}

