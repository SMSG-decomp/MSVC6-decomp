void __fastcall bitset_assign_or(c2_bitset *dst,c2_bitset *src,c2_bitset *extra)

{
  c2_bitset_chunk *pcVar1;
  uint32_t uVar2;
  c2_bitset_chunk *chunk;
  uint32_t *puVar3;
  c2_bitset_chunk *after;
  c2_bitset_chunk *pcVar4;
  
  pcVar1 = src->chunks;
  after = dst->chunks;
  chunk = after;
  while (pcVar1 != (c2_bitset_chunk *)0x0) {
    if (chunk == (c2_bitset_chunk *)0x0) {
      after = bitset_chunk_insert_after(dst,after);
      pcVar4 = chunk;
    }
    else {
      pcVar4 = chunk->next;
      after = chunk;
    }
    puVar3 = &pcVar1->base;
    uVar2 = pcVar1->bits;
    pcVar1 = pcVar1->next;
    after->base = *puVar3;
    after->bits = uVar2;
    chunk = pcVar4;
  }
  while (chunk != (c2_bitset_chunk *)0x0) {
    pcVar1 = chunk->next;
    bitset_chunk_remove(dst,chunk);
    chunk = pcVar1;
  }
  bitset_or(dst,extra);
  return;
}

