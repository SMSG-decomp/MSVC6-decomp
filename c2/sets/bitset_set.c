c2_bitset_chunk * __fastcall bitset_set(c2_bitset *bs,uint32_t n)

{
  c2_bitset *pcVar1;
  c2_bitset_chunk *pcVar2;
  uint uVar3;
  
  pcVar2 = bs->chunks;
  uVar3 = n & 0xffffffe0;
  pcVar1 = bs;
  do {
    if (pcVar2 == (c2_bitset_chunk *)0x0) {
LAB_107018d6:
      pcVar2 = bitset_chunk_alloc(bs);
      pcVar2->base = uVar3;
      pcVar2->next = pcVar1->chunks;
      pcVar1->chunks = pcVar2;
LAB_10701914:
      pcVar2->bits = pcVar2->bits | 1 << ((byte)n & 0x1f);
      return pcVar2;
    }
    if (uVar3 <= pcVar2->base) {
      if (pcVar2->base == uVar3) goto LAB_10701914;
      goto LAB_107018d6;
    }
    pcVar1 = (c2_bitset *)&pcVar2->next;
    pcVar2 = pcVar2->next;
  } while( true );
}

