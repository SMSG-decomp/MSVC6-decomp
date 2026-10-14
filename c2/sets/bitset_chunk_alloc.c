c2_bitset_chunk * __fastcall bitset_chunk_alloc(c2_bitset *dst)

{
  c2_bitset_chunk **ppcVar1;
  c2_bitset_chunk *pcVar2;
  uint arena;
  c2_bitset_chunk *pcVar3;
  c2_bitset_chunk *pcVar4;
  
  arena = (uint)dst->arena;
  pcVar3 = g_bitset_chunk_free_head[arena];
  ppcVar1 = g_bitset_chunk_free_head + arena;
  if (pcVar3 == (c2_bitset_chunk *)0x0) {
    pcVar3 = arena_alloc(arena,0x30);
    pcVar4 = pcVar3 + 1;
    if (*ppcVar1 == (c2_bitset_chunk *)0x0) {
      *ppcVar1 = pcVar4;
      g_bitset_chunk_free_tail[arena] = pcVar4;
    }
    if (pcVar4 <= pcVar3 + 3) {
      do {
        pcVar2 = g_bitset_chunk_free_tail[arena];
        g_bitset_chunk_free_tail[arena] = pcVar4;
        pcVar2->next = pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (pcVar4 <= pcVar3 + 3);
    }
  }
  else {
    *ppcVar1 = pcVar3->next;
  }
  pcVar3->base = 0;
  pcVar3->next = (c2_bitset_chunk *)0x0;
  pcVar3->bits = 0;
  return pcVar3;
}

