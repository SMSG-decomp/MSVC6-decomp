void __fastcall bitvec_and(c2_bitvec *dst,c2_bitvec *src)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = dst->words;
  uVar2 = (src->nbits & 0xffffff) + 0x1f >> 5;
  if (uVar2 != 0) {
    iVar3 = (int)src->words - (int)puVar1;
    do {
      *puVar1 = *puVar1 & *(uint *)(iVar3 + (int)puVar1);
      puVar1 = puVar1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}

