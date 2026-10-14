c2_bitset_chunk * __fastcall bitset_clear_all(c2_bitset *bs)

{
  byte bVar1;
  c2_bitset_chunk *pcVar2;
  c2_bitset_chunk *pcVar3;
  
  pcVar3 = bs->chunks;
  if (pcVar3 != (c2_bitset_chunk *)0x0) {
    bVar1 = bs->arena;
    if (g_bitset_chunk_free_head[bVar1] == (c2_bitset_chunk *)0x0) {
      g_bitset_chunk_free_head[bVar1] = pcVar3;
    }
    else {
      g_bitset_chunk_free_tail[bVar1]->next = pcVar3;
    }
    if (pcVar3 != (c2_bitset_chunk *)0x0) {
      while (pcVar2 = pcVar3->next, pcVar2 != (c2_bitset_chunk *)0x0) {
        pcVar3 = pcVar2;
        if (pcVar2 == (c2_bitset_chunk *)0x0) {
          bs->chunks = (c2_bitset_chunk *)0x0;
          return (c2_bitset_chunk *)0x0;
        }
      }
      g_bitset_chunk_free_tail[bVar1] = pcVar3;
    }
    bs->chunks = (c2_bitset_chunk *)0x0;
  }
  return pcVar3;
}

