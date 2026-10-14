ulonglong _aullrem(uint lo,uint hi,uint dlo,uint dhi)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint quotient_lo;
  uint quotient_lo_2;
  uint uVar4;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint quotient_lo_3;
  uint quotient_lo_4;
  uint uVar10;
  bool bVar11;
  uint uVar5;
  
  uVar3 = lo;
  uVar5 = dhi;
  uVar8 = hi;
  uVar10 = dlo;
  if (dhi == 0) {
    iVar6 = (int)(((ulonglong)hi % (ulonglong)dlo << 0x20 | (ulonglong)lo) % (ulonglong)dlo);
    iVar7 = 0;
  }
  else {
    do {
      uVar4 = uVar5 >> 1;
      uVar10 = (uint)(CONCAT14((uVar5 & 1) != 0,uVar10) >> 1);
      uVar9 = uVar8 >> 1;
      uVar3 = (uint)(CONCAT14((uVar8 & 1) != 0,uVar3) >> 1);
      uVar5 = uVar4;
      uVar8 = uVar9;
    } while (uVar4 != 0);
    uVar1 = CONCAT44(uVar9,uVar3) / (ulonglong)uVar10;
    quotient_lo = (int)uVar1 * dhi;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)dlo;
    quotient_lo_3 = (uint)((ulonglong)lVar2 >> 0x20);
    quotient_lo_2 = (uint)lVar2;
    quotient_lo_4 = quotient_lo_3 + quotient_lo;
    if (((CARRY4(quotient_lo_3,quotient_lo)) || (hi < quotient_lo_4)) ||
       ((hi <= quotient_lo_4 && (lo < quotient_lo_2)))) {
      bVar11 = quotient_lo_2 < dlo;
      quotient_lo_2 = quotient_lo_2 - dlo;
      quotient_lo_4 = (quotient_lo_4 - dhi) - (uint)bVar11;
    }
    iVar6 = -(quotient_lo_2 - lo);
    iVar7 = -(uint)(quotient_lo_2 - lo != 0) - ((quotient_lo_4 - hi) - (uint)(quotient_lo_2 < lo));
  }
  return CONCAT44(iVar7,iVar6);
}

