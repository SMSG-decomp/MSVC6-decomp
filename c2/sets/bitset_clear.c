void __fastcall bitset_clear(c2_bitset *bs,uint32_t n)

{
  c2_bitset_chunk *chunk;
  uint uVar1;
  
  chunk = bs->chunks;
  if (chunk != (c2_bitset_chunk *)0x0) {
    while (chunk->base < (n & 0xffffffe0)) {
      chunk = chunk->next;
      if (chunk == (c2_bitset_chunk *)0x0) {
        return;
      }
    }
    if (((chunk->base == (n & 0xffffffe0)) && (chunk != (c2_bitset_chunk *)0x0)) &&
       (uVar1 = chunk->bits & ~(1 << ((byte)n & 0x1f)), chunk->bits = uVar1, uVar1 == 0)) {
      bitset_chunk_remove(bs,chunk);
    }
  }
  return;
}

