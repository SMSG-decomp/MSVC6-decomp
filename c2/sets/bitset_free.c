void __fastcall bitset_free(c2_bitset *bs)

{
  byte bVar1;
  c2_bitset_chunk *pcVar2;
  c2_bitset_chunk *pcVar3;
  
  if (bs == (c2_bitset *)0x0) {
    return;
  }
  pcVar2 = bs->chunks;
  if (pcVar2 != (c2_bitset_chunk *)0x0) {
    bVar1 = bs->arena;
    if (g_bitset_chunk_free_head[bVar1] == (c2_bitset_chunk *)0x0) {
      g_bitset_chunk_free_head[bVar1] = pcVar2;
    }
    else {
      g_bitset_chunk_free_tail[bVar1]->next = pcVar2;
    }
    do {
      pcVar3 = pcVar2;
      if (pcVar3 == (c2_bitset_chunk *)0x0) goto LAB_107028a0;
      pcVar2 = pcVar3->next;
    } while (pcVar3->next != (c2_bitset_chunk *)0x0);
    g_bitset_chunk_free_tail[bVar1] = pcVar3;
LAB_107028a0:
    bs->chunks = (c2_bitset_chunk *)0x0;
  }
  bVar1 = bs->arena;
  if (g_bitset_free_head[bVar1] == (c2_bitset *)0x0) {
    g_bitset_free_head[bVar1] = bs;
  }
  else {
    g_bitset_free_tail[bVar1]->chunks = (c2_bitset_chunk *)bs;
  }
  g_bitset_free_tail[bVar1] = bs;
  bs->chunks = (c2_bitset_chunk *)0x0;
  bs->nbits = bs->nbits & 0xff000000;
  return;
}

