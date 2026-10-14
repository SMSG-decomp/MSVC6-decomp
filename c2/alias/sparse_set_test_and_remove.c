uint32_t __fastcall sparse_set_test_and_remove(c2_bitset *set,uint32_t n)

{
  c2_bitset_chunk *chunk;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  chunk = set->chunks;
  while( true ) {
    if (chunk == (c2_bitset_chunk *)0x0) {
      return 0;
    }
    if ((n & 0xffffffe0) <= chunk->base) break;
    chunk = chunk->next;
  }
  if (chunk->base != (n & 0xffffffe0)) {
    return 0;
  }
  if (chunk == (c2_bitset_chunk *)0x0) {
    return 0;
  }
  uVar1 = chunk->bits;
  uVar3 = 1 << ((byte)n & 0x1f);
  uVar2 = ~uVar3 & uVar1;
  chunk->bits = uVar2;
  if (uVar2 == 0) {
    bitset_chunk_remove(set,chunk);
  }
  return uVar3 & uVar1;
}

