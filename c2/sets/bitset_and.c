void __fastcall bitset_and(c2_bitset *dst,c2_bitset *src)

{
  byte bVar1;
  c2_bitset_chunk *pcVar2;
  c2_bitset_chunk *pcVar3;
  uint uVar4;
  c2_bitset_chunk *pcVar5;
  
  pcVar3 = src->chunks;
  pcVar2 = dst->chunks;
  if (pcVar3 == (c2_bitset_chunk *)0x0) {
    pcVar3 = dst->chunks;
    if (pcVar3 != (c2_bitset_chunk *)0x0) {
      bVar1 = dst->arena;
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
            dst->chunks = (c2_bitset_chunk *)0x0;
            return;
          }
        }
        g_bitset_chunk_free_tail[bVar1] = pcVar3;
      }
      dst->chunks = (c2_bitset_chunk *)0x0;
    }
    return;
  }
  do {
    while( true ) {
      while( true ) {
        if (pcVar2 == (c2_bitset_chunk *)0x0) {
          return;
        }
        if (pcVar3 != (c2_bitset_chunk *)0x0) break;
        pcVar5 = pcVar2->next;
        bitset_chunk_remove(dst,pcVar2);
        pcVar2 = pcVar5;
      }
      if (pcVar2->base != pcVar3->base) break;
      pcVar5 = pcVar2->next;
      uVar4 = pcVar2->bits & pcVar3->bits;
      pcVar2->bits = uVar4;
      if (uVar4 == 0) {
        bitset_chunk_remove(dst,pcVar2);
      }
LAB_10702b8e:
      pcVar3 = pcVar3->next;
      pcVar2 = pcVar5;
    }
    pcVar5 = pcVar2;
    if (pcVar3->base <= pcVar2->base) goto LAB_10702b8e;
    pcVar5 = pcVar2->next;
    bitset_chunk_remove(dst,pcVar2);
    pcVar2 = pcVar5;
  } while( true );
}

