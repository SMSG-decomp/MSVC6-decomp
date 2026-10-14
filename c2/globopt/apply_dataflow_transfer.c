void __fastcall
apply_dataflow_transfer
          (c2_bitset *dst,c2_bitset *src2,c2_bitset *set,c2_bitset *src,uint32_t *changed)

{
  c2_bitset_chunk *pcVar1;
  uint32_t uVar2;
  c2_bitset_chunk *chunk;
  uint32_t *puVar3;
  c2_bitset *dst_00;
  c2_bitset_chunk *after;
  int iVar4;
  c2_bitset_chunk *pcVar5;
  
  if (*changed != 0) {
    bitset_assign_diff_union(dst,set,src,src2);
    return;
  }
  dst_00 = bitset_new((uint)dst->arena);
  pcVar1 = dst->chunks;
  after = dst_00->chunks;
  chunk = after;
  while (pcVar1 != (c2_bitset_chunk *)0x0) {
    if (chunk == (c2_bitset_chunk *)0x0) {
      after = bitset_chunk_insert_after(dst_00,after);
      pcVar5 = chunk;
    }
    else {
      pcVar5 = chunk->next;
      after = chunk;
    }
    puVar3 = &pcVar1->base;
    uVar2 = pcVar1->bits;
    pcVar1 = pcVar1->next;
    after->base = *puVar3;
    after->bits = uVar2;
    chunk = pcVar5;
  }
  while (chunk != (c2_bitset_chunk *)0x0) {
    pcVar1 = chunk->next;
    bitset_chunk_remove(dst_00,chunk);
    chunk = pcVar1;
  }
  bitset_assign_diff_union(dst,set,src,src2);
  iVar4 = bitset_equal(dst,dst_00);
  *changed = (uint)(iVar4 == 0);
  bitset_free(dst_00);
  return;
}

