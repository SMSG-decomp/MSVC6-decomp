c2_bitset_chunk * __fastcall bitset_chunk_insert_after(c2_bitset *dst,c2_bitset_chunk *after)

{
  c2_bitset_chunk *pcVar1;
  c2_bitset_chunk *pcVar2;
  
  pcVar2 = bitset_chunk_alloc(dst);
  if (after == (c2_bitset_chunk *)0x0) {
    pcVar1 = dst->chunks;
    dst->chunks = pcVar2;
    pcVar2->next = pcVar1;
    return pcVar2;
  }
  pcVar1 = after->next;
  after->next = pcVar2;
  pcVar2->next = pcVar1;
  return pcVar2;
}

