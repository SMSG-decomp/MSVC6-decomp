int __fastcall bitvec_equal(c2_bitvec *a,c2_bitvec *b)

{
  uint uVar1;
  int iVar2;
  uint32_t *puVar3;
  
  if (((b->nbits ^ a->nbits) & 0xffffff) != 0) {
    return 0;
  }
  puVar3 = b->words;
  uVar1 = (a->nbits & 0xffffff) + 0x1f >> 5;
  if (uVar1 != 0) {
    iVar2 = (int)a->words - (int)puVar3;
    do {
      if (*(uint32_t *)(iVar2 + (int)puVar3) != *puVar3) {
        return 0;
      }
      puVar3 = puVar3 + 1;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return 1;
}

