uint32_t __fastcall bitset_test(c2_bitset *bs,uint32_t n)

{
  c2_bitset_chunk *pcVar1;
  
  pcVar1 = bs->chunks;
  while( true ) {
    if (pcVar1 == (c2_bitset_chunk *)0x0) {
      return 0;
    }
    if ((n & 0xffffffe0) <= pcVar1->base) break;
    pcVar1 = pcVar1->next;
  }
  if (pcVar1->base != (n & 0xffffffe0)) {
    return 0;
  }
  if (pcVar1 == (c2_bitset_chunk *)0x0) {
    return 0;
  }
  return 1 << ((byte)n & 0x1f) & pcVar1->bits;
}

