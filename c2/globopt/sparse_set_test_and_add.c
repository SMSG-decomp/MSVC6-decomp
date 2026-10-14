uint32_t __fastcall sparse_set_test_and_add(c2_bitset *set,uint32_t bit)

{
  c2_bitset *pcVar1;
  c2_bitset_chunk *pcVar2;
  uint uVar3;
  uint uVar4;
  
  pcVar2 = set->chunks;
  uVar4 = bit & 0xffffffe0;
  pcVar1 = set;
  do {
    if (pcVar2 == (c2_bitset_chunk *)0x0) {
LAB_107441c4:
      pcVar2 = bitset_chunk_alloc(set);
      pcVar2->base = uVar4;
      pcVar2->next = pcVar1->chunks;
      pcVar1->chunks = pcVar2;
LAB_1074419c:
      uVar4 = pcVar2->bits;
      uVar3 = 1 << ((byte)bit & 0x1f);
      pcVar2->bits = uVar4 | uVar3;
      return uVar3 & uVar4;
    }
    if (uVar4 <= pcVar2->base) {
      if (pcVar2->base == uVar4) goto LAB_1074419c;
      goto LAB_107441c4;
    }
    pcVar1 = (c2_bitset *)&pcVar2->next;
    pcVar2 = pcVar2->next;
  } while( true );
}

