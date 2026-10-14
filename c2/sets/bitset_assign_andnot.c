void __fastcall bitset_assign_andnot(c2_bitset *dst,c2_bitset *set,c2_bitset *src)

{
  c2_bitset_chunk *pcVar1;
  uint32_t uVar2;
  uint32_t *puVar3;
  c2_bitset_chunk *after;
  c2_bitset_chunk *chunk;
  
  pcVar1 = set->chunks;
  after = dst->chunks;
  chunk = after;
  while (pcVar1 != (c2_bitset_chunk *)0x0) {
    if (chunk == (c2_bitset_chunk *)0x0) {
      after = bitset_chunk_insert_after(dst,after);
    }
    else {
      after = chunk;
      chunk = chunk->next;
    }
    puVar3 = &pcVar1->base;
    uVar2 = pcVar1->bits;
    pcVar1 = pcVar1->next;
    after->base = *puVar3;
    after->bits = uVar2;
  }
  while (chunk != (c2_bitset_chunk *)0x0) {
    pcVar1 = chunk->next;
    bitset_chunk_remove(dst,chunk);
    chunk = pcVar1;
  }
  bitset_andnot(dst,src);
  return;
}

