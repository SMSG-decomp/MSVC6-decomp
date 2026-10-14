longlong _allrem(uint32_t lo,int32_t hi,uint32_t dlo,int32_t dhi)

{
  ulonglong uVar1;
  longlong lVar2;
  uint low_half;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  
  bVar12 = hi < 0;
  if (bVar12) {
    bVar11 = lo != 0;
    lo = -lo;
    hi = -(uint)bVar11 - hi;
  }
  uVar10 = (uint)bVar12;
  if (dhi < 0) {
    bVar12 = dlo != 0;
    dlo = -dlo;
    dhi = -(uint)bVar12 - dhi;
  }
  low_half = lo;
  uVar3 = dlo;
  uVar4 = hi;
  uVar8 = dhi;
  if (dhi == 0) {
    iVar5 = (int)(((ulonglong)(uint)hi % (ulonglong)dlo << 0x20 | (ulonglong)lo) % (ulonglong)dlo);
    iVar6 = 0;
    if ((int)(uVar10 - 1) < 0) goto LAB_10651066;
  }
  else {
    do {
      uVar9 = uVar8 >> 1;
      uVar3 = (uint)(CONCAT14((uVar8 & 1) != 0,uVar3) >> 1);
      uVar7 = uVar4 >> 1;
      low_half = (uint)(CONCAT14((uVar4 & 1) != 0,low_half) >> 1);
      uVar4 = uVar7;
      uVar8 = uVar9;
    } while (uVar9 != 0);
    uVar1 = CONCAT44(uVar7,low_half) / (ulonglong)uVar3;
    uVar3 = (int)uVar1 * dhi;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)dlo;
    uVar8 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar4 = (uint)lVar2;
    uVar7 = uVar8 + uVar3;
    if (((CARRY4(uVar8,uVar3)) || ((uint)hi < uVar7)) || (((uint)hi <= uVar7 && (lo < uVar4)))) {
      bVar12 = uVar4 < dlo;
      uVar4 = uVar4 - dlo;
      uVar7 = (uVar7 - dhi) - (uint)bVar12;
    }
    iVar5 = uVar4 - lo;
    iVar6 = (uVar7 - hi) - (uint)(uVar4 < lo);
    if (-1 < (int)(uVar10 - 1)) goto LAB_10651066;
  }
  bVar12 = iVar5 != 0;
  iVar5 = -iVar5;
  iVar6 = -(uint)bVar12 - iVar6;
LAB_10651066:
  return CONCAT44(iVar6,iVar5);
}

