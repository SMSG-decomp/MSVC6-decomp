longlong _alldiv(uint lo,int hi,uint dlo,int dhi)

{
  ulonglong uVar1;
  longlong lVar2;
  uint quotient_lo;
  int iVar3;
  uint uVar4;
  uint quotient_lo_4;
  uint uVar5;
  uint uVar6;
  uint quotient_lo_2;
  uint quotient_lo_3;
  uint uVar7;
  bool bVar9;
  char cVar10;
  uint uVar8;
  
  cVar10 = hi < 0;
  if ((bool)cVar10) {
    bVar9 = lo != 0;
    lo = -lo;
    hi = -(uint)bVar9 - hi;
  }
  if (dhi < 0) {
    cVar10 = cVar10 + '\x01';
    bVar9 = dlo != 0;
    dlo = -dlo;
    dhi = -(uint)bVar9 - dhi;
  }
  uVar4 = lo;
  quotient_lo_4 = dlo;
  uVar5 = hi;
  uVar8 = dhi;
  if (dhi == 0) {
    quotient_lo = (uint)hi / dlo;
    iVar3 = (int)(((ulonglong)(uint)hi % (ulonglong)dlo << 0x20 | (ulonglong)lo) / (ulonglong)dlo);
  }
  else {
    do {
      uVar7 = uVar8 >> 1;
      quotient_lo_4 = (uint)(CONCAT14((uVar8 & 1) != 0,quotient_lo_4) >> 1);
      uVar6 = uVar5 >> 1;
      uVar4 = (uint)(CONCAT14((uVar5 & 1) != 0,uVar4) >> 1);
      uVar5 = uVar6;
      uVar8 = uVar7;
    } while (uVar7 != 0);
    uVar1 = CONCAT44(uVar6,uVar4) / (ulonglong)quotient_lo_4;
    iVar3 = (int)uVar1;
    lVar2 = (ulonglong)dlo * (uVar1 & 0xffffffff);
    quotient_lo_2 = (uint)((ulonglong)lVar2 >> 0x20);
    quotient_lo_3 = quotient_lo_2 + iVar3 * dhi;
    if (((CARRY4(quotient_lo_2,iVar3 * dhi)) || ((uint)hi < quotient_lo_3)) ||
       (((uint)hi <= quotient_lo_3 && (lo < (uint)lVar2)))) {
      iVar3 = iVar3 + -1;
    }
    quotient_lo = 0;
  }
  if (cVar10 == '\x01') {
    bVar9 = iVar3 != 0;
    iVar3 = -iVar3;
    quotient_lo = -(uint)bVar9 - quotient_lo;
  }
  return CONCAT44(quotient_lo,iVar3);
}

