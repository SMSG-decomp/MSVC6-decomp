void __fastcall bitvec_fill(c2_bitvec *vec,int nbits)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  uint *puVar8;
  
  puVar8 = vec->words;
  iVar7 = (nbits + 0x1fU >> 5) - 1;
  iVar2 = 0;
  puVar6 = puVar8;
  if (iVar7 != 0) {
    puVar6 = puVar8 + iVar7;
    for (iVar4 = iVar7; iVar2 = iVar7, iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar8 = 0xffffffff;
      puVar8 = puVar8 + 1;
    }
  }
  uVar5 = nbits + iVar2 * -0x20;
  if (uVar5 == 0x20) {
    *puVar6 = 0xffffffff;
    return;
  }
  if ((uVar5 != 0) && (uVar3 = 0, uVar5 != 0)) {
    do {
      bVar1 = (byte)uVar3;
      uVar3 = uVar3 + 1;
      *puVar6 = *puVar6 | 1 << (bVar1 & 0x1f);
    } while (uVar3 < uVar5);
  }
  return;
}

