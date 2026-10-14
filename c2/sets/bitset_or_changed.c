uint32_t __fastcall bitset_or_changed(c2_bitset *dst,c2_bitset *src)

{
  uint uVar1;
  uint32_t uVar2;
  uint32_t *puVar3;
  uint uVar4;
  c2_bitset_chunk *pcVar5;
  c2_bitset_chunk *pcVar6;
  c2_bitset_chunk *pcVar7;
  c2_bitset *pcVar8;
  c2_bitset_chunk *chunk;
  uint local_4;
  
  pcVar6 = dst->chunks;
  if (pcVar6 == (c2_bitset_chunk *)0x0) {
    pcVar6 = src->chunks;
    pcVar7 = (c2_bitset_chunk *)0x0;
    pcVar5 = (c2_bitset_chunk *)0x0;
    if (pcVar6 != (c2_bitset_chunk *)0x0) {
      do {
        if (pcVar5 == (c2_bitset_chunk *)0x0) {
          pcVar7 = bitset_chunk_insert_after(dst,pcVar7);
          chunk = pcVar5;
        }
        else {
          chunk = pcVar5->next;
          pcVar7 = pcVar5;
        }
        pcVar7->base = pcVar6->base;
        puVar3 = &pcVar6->bits;
        pcVar6 = pcVar6->next;
        pcVar7->bits = *puVar3;
        pcVar5 = chunk;
      } while (pcVar6 != (c2_bitset_chunk *)0x0);
      while (chunk != (c2_bitset_chunk *)0x0) {
        pcVar6 = chunk->next;
        bitset_chunk_remove(dst,chunk);
        chunk = pcVar6;
      }
    }
    return 1;
  }
  pcVar7 = src->chunks;
  local_4 = 0;
  pcVar8 = dst;
  while( true ) {
    if (pcVar6 == (c2_bitset_chunk *)0x0) {
      if (pcVar7 != (c2_bitset_chunk *)0x0) {
        local_4 = 1;
        do {
          pcVar6 = bitset_chunk_alloc(dst);
          puVar3 = &pcVar7->base;
          uVar2 = pcVar7->bits;
          pcVar7 = pcVar7->next;
          pcVar6->base = *puVar3;
          pcVar8->chunks = pcVar6;
          pcVar6->bits = uVar2;
          pcVar8 = (c2_bitset *)&pcVar6->next;
        } while (pcVar7 != (c2_bitset_chunk *)0x0);
      }
      return local_4;
    }
    if (pcVar7 == (c2_bitset_chunk *)0x0) break;
    uVar1 = pcVar7->base;
    if (pcVar6->base < uVar1) {
      pcVar8 = (c2_bitset *)&pcVar6->next;
      pcVar6 = pcVar6->next;
    }
    else {
      pcVar5 = pcVar6;
      if (pcVar6->base != uVar1) {
        pcVar5 = bitset_chunk_alloc(dst);
        pcVar5->base = uVar1;
        pcVar5->next = pcVar6;
        pcVar8->chunks = pcVar5;
      }
      uVar1 = pcVar5->bits;
      uVar4 = pcVar7->bits | uVar1;
      pcVar7 = pcVar7->next;
      pcVar5->bits = uVar4;
      pcVar8 = (c2_bitset *)&pcVar5->next;
      local_4 = local_4 | uVar4 ^ uVar1;
      pcVar6 = *(c2_bitset_chunk **)pcVar8;
    }
  }
  return local_4;
}

