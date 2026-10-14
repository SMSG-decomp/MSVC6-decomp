void __fastcall bitset_andnot(c2_bitset *dst,c2_bitset *src)

{
  uint32_t *puVar1;
  c2_bitset_chunk *chunk;
  c2_bitset_chunk *pcVar2;
  uint uVar3;
  c2_bitset_chunk *pcVar4;
  
  pcVar4 = src->chunks;
  chunk = dst->chunks;
  do {
    while( true ) {
      if ((chunk == (c2_bitset_chunk *)0x0) || (pcVar4 == (c2_bitset_chunk *)0x0)) {
        return;
      }
      if (pcVar4->base <= chunk->base) break;
LAB_10702b2e:
      chunk = chunk->next;
    }
    if (chunk->base == pcVar4->base) {
      puVar1 = &pcVar4->bits;
      pcVar4 = pcVar4->next;
      uVar3 = chunk->bits & ~*puVar1;
      chunk->bits = uVar3;
      if (uVar3 != 0) goto LAB_10702b2e;
      pcVar2 = chunk->next;
      bitset_chunk_remove(dst,chunk);
      chunk = pcVar2;
    }
    else {
      pcVar4 = pcVar4->next;
    }
  } while( true );
}

