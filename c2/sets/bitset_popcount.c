int __fastcall bitset_popcount(c2_bitset *bs)

{
  c2_bitset_chunk *pcVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = 0;
  for (pcVar1 = bs->chunks; pcVar1 != (c2_bitset_chunk *)0x0; pcVar1 = pcVar1->next) {
    uVar3 = pcVar1->bits;
    if (uVar3 == 0) {
      iVar4 = 0;
    }
    else {
      uVar3 = (uVar3 >> 1 & 0x55555555) + (uVar3 & 0x55555555);
      uVar3 = (uVar3 >> 2 & 0x33333333) + (uVar3 & 0x33333333);
      uVar3 = (uVar3 >> 4 & 0xf0f0f0f) + (uVar3 & 0xf0f0f0f);
      uVar3 = (uVar3 >> 8 & 0xff00ff) + (uVar3 & 0xff00ff);
      iVar4 = (uVar3 >> 0x10) + (uVar3 & 0xffff);
    }
    iVar2 = iVar2 + iVar4;
  }
  return iVar2;
}

