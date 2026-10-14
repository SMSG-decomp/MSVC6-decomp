int __fastcall bitset_intersects(c2_bitset *a,c2_bitset *b)

{
  c2_bitset_chunk *pcVar1;
  c2_bitset_chunk *pcVar2;
  c2_bitset_chunk *pcVar3;
  c2_bitset_chunk *pcVar4;
  
  pcVar4 = a->chunks;
  pcVar3 = (c2_bitset_chunk *)0x0;
  if (((pcVar4 != (c2_bitset_chunk *)0x0) && (pcVar1 = b->chunks, pcVar1 != (c2_bitset_chunk *)0x0))
     && (pcVar4 != (c2_bitset_chunk *)0x0)) {
    do {
      if (pcVar4->base < pcVar1->base) {
        pcVar3 = (c2_bitset_chunk *)0x0;
      }
      else {
        pcVar2 = pcVar1;
        if (pcVar3 != (c2_bitset_chunk *)0x0) goto LAB_10711ef9;
        while (pcVar3 = pcVar2, pcVar3 != (c2_bitset_chunk *)0x0) {
LAB_10711ef9:
          if (pcVar3->base == pcVar4->base) {
            if ((pcVar3 != (c2_bitset_chunk *)0x0) && ((pcVar3->bits & pcVar4->bits) != 0)) {
              return 1;
            }
            goto LAB_10711f06;
          }
          pcVar2 = pcVar3->next;
        }
        pcVar3 = (c2_bitset_chunk *)0x0;
      }
LAB_10711f06:
      pcVar4 = pcVar4->next;
    } while (pcVar4 != (c2_bitset_chunk *)0x0);
  }
  return 0;
}

