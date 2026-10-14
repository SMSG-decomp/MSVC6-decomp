int __fastcall bitset_iter_next(c2_bitset *bs)

{
  uint uVar1;
  
  if (bs == (c2_bitset *)0x0) {
    if (g_bitset_iter_bits == 0) {
      if (g_bitset_iter_chunk == (c2_bitset_chunk *)0x0) {
        return -1;
      }
      g_bitset_iter_chunk = g_bitset_iter_chunk->next;
      if (g_bitset_iter_chunk == (c2_bitset_chunk *)0x0) {
        return -1;
      }
      g_bitset_iter_bits = g_bitset_iter_chunk->bits;
    }
  }
  else {
    g_bitset_iter_chunk = bs->chunks;
    g_bitset_iter_set = bs;
    if (g_bitset_iter_chunk == (c2_bitset_chunk *)0x0) {
      g_bitset_iter_bits = 0;
    }
    else {
      g_bitset_iter_bits = g_bitset_iter_chunk->bits;
    }
  }
  uVar1 = 0;
  do {
    if ((g_bitset_iter_bits & 1 << ((byte)uVar1 & 0x1f)) != 0) {
      if (uVar1 != 0xffffffff) {
        uVar1 = g_bitset_iter_chunk->base + uVar1;
        g_bitset_iter_bits = g_bitset_iter_bits & ~(1 << ((byte)uVar1 & 0x1f));
      }
      return uVar1;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x20);
  return -1;
}

