longlong _allrem(uint lo,int hi,uint dlo,int dhi)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint low_half;
  uint low_half_2;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint low_half_3;
  uint low_half_4;
  uint uVar9;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  uint uVar10;
  
  bVar13 = hi < 0;
  if (bVar13) {
    bVar12 = lo != 0;
    lo = -lo;
    hi = -(uint)bVar12 - hi;
  }
  uVar11 = (uint)bVar13;
  if (dhi < 0) {
    bVar13 = dlo != 0;
    dlo = -dlo;
    dhi = -(uint)bVar13 - dhi;
  }
  uVar3 = lo;
  uVar4 = dlo;
  uVar7 = hi;
  uVar10 = dhi;
  if (dhi == 0) {
    iVar5 = (int)(((ulonglong)(uint)hi % (ulonglong)dlo << 0x20 | (ulonglong)lo) % (ulonglong)dlo);
    iVar6 = 0;
    if ((int)(uVar11 - 1) < 0) goto LAB_104bb745;
  }
  else {
    do {
      uVar9 = uVar10 >> 1;
      uVar4 = (uint)(CONCAT14((uVar10 & 1) != 0,uVar4) >> 1);
      uVar8 = uVar7 >> 1;
      uVar3 = (uint)(CONCAT14((uVar7 & 1) != 0,uVar3) >> 1);
      uVar7 = uVar8;
      uVar10 = uVar9;
    } while (uVar9 != 0);
    uVar1 = CONCAT44(uVar8,uVar3) / (ulonglong)uVar4;
    low_half = (int)uVar1 * dhi;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)dlo;
    low_half_3 = (uint)((ulonglong)lVar2 >> 0x20);
    low_half_2 = (uint)lVar2;
    low_half_4 = low_half_3 + low_half;
    if (((CARRY4(low_half_3,low_half)) || ((uint)hi < low_half_4)) ||
       (((uint)hi <= low_half_4 && (lo < low_half_2)))) {
      bVar13 = low_half_2 < dlo;
      low_half_2 = low_half_2 - dlo;
      low_half_4 = (low_half_4 - dhi) - (uint)bVar13;
    }
    iVar5 = low_half_2 - lo;
    iVar6 = (low_half_4 - hi) - (uint)(low_half_2 < lo);
    if (-1 < (int)(uVar11 - 1)) goto LAB_104bb745;
  }
  bVar13 = iVar5 != 0;
  iVar5 = -iVar5;
  iVar6 = -(uint)bVar13 - iVar6;
LAB_104bb745:
  return CONCAT44(iVar6,iVar5);
}

