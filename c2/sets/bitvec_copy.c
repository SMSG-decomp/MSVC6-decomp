void __fastcall bitvec_copy(c2_bitvec *vec,c2_bitvec *vec2)

{
  uint uVar1;
  uint32_t *puVar2;
  uint32_t *puVar3;
  
  puVar3 = vec->words;
  puVar2 = vec2->words;
  uVar1 = (vec2->nbits & 0xffffff) + 0x1f >> 5;
  if (uVar1 != 0) {
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}

