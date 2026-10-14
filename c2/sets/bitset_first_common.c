uint32_t __fastcall bitset_first_common(c2_bitset *a,c2_bitset *b)

{
  c2_bitset_chunk *pcVar1;
  c2_bitset_chunk *pcVar2;
  uint uVar3;
  uint32_t uVar4;
  uint32_t n;
  c2_bitset_chunk *pcVar5;
  uint uVar6;
  
  pcVar5 = (c2_bitset_chunk *)0x0;
  if (b->chunks != (c2_bitset_chunk *)0x0) {
    for (pcVar1 = a->chunks; pcVar1 != (c2_bitset_chunk *)0x0; pcVar1 = pcVar1->next) {
      pcVar2 = b->chunks;
      uVar3 = pcVar1->base;
      uVar6 = pcVar1->bits;
      if ((uVar3 < pcVar2->base) ||
         ((pcVar5 == (c2_bitset_chunk *)0x0 && (pcVar5 = pcVar2, pcVar2 == (c2_bitset_chunk *)0x0)))
         ) {
        pcVar5 = (c2_bitset_chunk *)0x0;
      }
      else {
        do {
          if (pcVar5->base == uVar3) {
            if ((pcVar5 != (c2_bitset_chunk *)0x0) && ((pcVar5->bits & uVar6) != 0)) {
              while (uVar6 != 0) {
                n = 0;
                do {
                  if ((uVar6 & 1 << ((byte)n & 0x1f)) != 0) {
                    if (n != 0xffffffff) {
                      n = uVar3 + n;
                      uVar6 = uVar6 & ~(1 << ((byte)n & 0x1f));
                    }
                    goto LAB_10711fca;
                  }
                  n = n + 1;
                } while (n < 0x20);
                n = 0xffffffff;
LAB_10711fca:
                uVar4 = bitset_test(b,n);
                if (uVar4 != 0) {
                  return n;
                }
              }
            }
            goto LAB_10711f94;
          }
          pcVar5 = pcVar5->next;
        } while (pcVar5 != (c2_bitset_chunk *)0x0);
        pcVar5 = (c2_bitset_chunk *)0x0;
      }
LAB_10711f94:
    }
  }
  return 0xffffffff;
}

