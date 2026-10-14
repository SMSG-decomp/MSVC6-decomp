void __fastcall bitvec_and_not(c2_bitvec *a,c2_bitvec *b)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = a->words;
  uVar2 = (b->nbits & 0xffffff) + 0x1f >> 5;
  if (uVar2 != 0) {
    iVar3 = (int)b->words - (int)puVar1;
    do {
      *puVar1 = *puVar1 & ~*(uint *)(iVar3 + (int)puVar1);
      puVar1 = puVar1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}

