void __fastcall bitvec_clear_words(c2_bitvec *vec)

{
  uint uVar1;
  uint32_t *puVar2;
  
  puVar2 = vec->words;
  uVar1 = (vec->nbits & 0xffffff) + 0x1f >> 5;
  if (uVar1 != 0) {
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
  }
  return;
}

