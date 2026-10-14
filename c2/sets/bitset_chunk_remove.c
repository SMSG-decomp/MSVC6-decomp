void __fastcall bitset_chunk_remove(c2_bitset *dst,c2_bitset_chunk *chunk)

{
  byte bVar1;
  c2_bitset_chunk *pcVar2;
  c2_bitset_chunk *pcVar3;
  
  bVar1 = dst->arena;
  pcVar2 = dst->chunks;
  do {
    pcVar3 = pcVar2;
    if (pcVar3 == (c2_bitset_chunk *)0x0) goto LAB_10702be8;
    pcVar2 = pcVar3->next;
  } while (pcVar3->next != chunk);
  if (pcVar3 == (c2_bitset_chunk *)0x0) {
LAB_10702be8:
    dst->chunks = chunk->next;
  }
  else {
    pcVar3->next = chunk->next;
  }
  pcVar2 = g_bitset_chunk_free_head[bVar1];
  chunk->next = (c2_bitset_chunk *)0x0;
  if (pcVar2 != (c2_bitset_chunk *)0x0) {
    g_bitset_chunk_free_tail[bVar1]->next = chunk;
    g_bitset_chunk_free_tail[bVar1] = chunk;
    return;
  }
  g_bitset_chunk_free_head[bVar1] = chunk;
  g_bitset_chunk_free_tail[bVar1] = chunk;
  return;
}

