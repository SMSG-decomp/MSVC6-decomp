int __fastcall bitvec_is_empty(c2_bitvec *v)

{
  uint uVar1;
  uint32_t *puVar2;
  
  puVar2 = v->words;
  uVar1 = (v->nbits & 0xffffff) + 0x1f >> 5;
  while( true ) {
    if (uVar1 == 0) {
      return 1;
    }
    if (*puVar2 != 0) break;
    uVar1 = uVar1 - 1;
    puVar2 = puVar2 + 1;
  }
  return 0;
}

