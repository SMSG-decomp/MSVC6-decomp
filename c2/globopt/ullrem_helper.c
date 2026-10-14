uint64_t ullrem_helper(uint32_t lo,uint32_t hi,uint32_t dlo,uint32_t dhi)

{
  ulonglong uVar1;
  longlong lVar2;
  uint32_t uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  
  uVar3 = lo;
  uVar5 = dhi;
  uVar10 = hi;
  uVar4 = dlo;
  if (dhi == 0) {
    iVar7 = (int)(((ulonglong)hi % (ulonglong)dlo << 0x20 | (ulonglong)lo) % (ulonglong)dlo);
    iVar8 = 0;
  }
  else {
    do {
      uVar6 = uVar5 >> 1;
      uVar4 = (uint)(CONCAT14((uVar5 & 1) != 0,uVar4) >> 1);
      uVar9 = uVar10 >> 1;
      uVar3 = (uint32_t)(CONCAT14((uVar10 & 1) != 0,uVar3) >> 1);
      uVar5 = uVar6;
      uVar10 = uVar9;
    } while (uVar6 != 0);
    uVar1 = CONCAT44(uVar9,uVar3) / (ulonglong)uVar4;
    uVar4 = (int)uVar1 * dhi;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)dlo;
    uVar10 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar5 = (uint)lVar2;
    uVar6 = uVar10 + uVar4;
    if (((CARRY4(uVar10,uVar4)) || (hi < uVar6)) || ((hi <= uVar6 && (lo < uVar5)))) {
      bVar11 = uVar5 < dlo;
      uVar5 = uVar5 - dlo;
      uVar6 = (uVar6 - dhi) - (uint)bVar11;
    }
    iVar7 = -(uVar5 - lo);
    iVar8 = -(uint)(uVar5 - lo != 0) - ((uVar6 - hi) - (uint)(uVar5 < lo));
  }
  return CONCAT44(iVar8,iVar7);
}

