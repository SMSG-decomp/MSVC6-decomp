void __fastcall bitset_or(c2_bitset *dst,c2_bitset *src)

{
  c2_bitset *pcVar1;
  uint uVar2;
  uint32_t uVar3;
  uint32_t *puVar4;
  c2_bitset_chunk *pcVar5;
  c2_bitset_chunk *pcVar6;
  c2_bitset_chunk *pcVar7;
  c2_bitset_chunk *chunk;
  
  pcVar7 = dst->chunks;
  if (pcVar7 == (c2_bitset_chunk *)0x0) {
    pcVar7 = src->chunks;
    pcVar5 = (c2_bitset_chunk *)0x0;
    pcVar6 = (c2_bitset_chunk *)0x0;
    if (pcVar7 != (c2_bitset_chunk *)0x0) {
      do {
        if (pcVar6 == (c2_bitset_chunk *)0x0) {
          pcVar5 = bitset_chunk_insert_after(dst,pcVar5);
          chunk = pcVar6;
        }
        else {
          chunk = pcVar6->next;
          pcVar5 = pcVar6;
        }
        puVar4 = &pcVar7->base;
        uVar3 = pcVar7->bits;
        pcVar7 = pcVar7->next;
        pcVar5->base = *puVar4;
        pcVar5->bits = uVar3;
        pcVar6 = chunk;
      } while (pcVar7 != (c2_bitset_chunk *)0x0);
      if (chunk != (c2_bitset_chunk *)0x0) {
        do {
          pcVar7 = chunk->next;
          bitset_chunk_remove(dst,chunk);
          chunk = pcVar7;
        } while (pcVar7 != (c2_bitset_chunk *)0x0);
        return;
      }
    }
  }
  else {
    pcVar5 = src->chunks;
    pcVar1 = dst;
    while (pcVar7 != (c2_bitset_chunk *)0x0) {
      if (pcVar5 == (c2_bitset_chunk *)0x0) {
        return;
      }
      uVar2 = pcVar5->base;
      if (pcVar7->base < uVar2) {
        pcVar1 = (c2_bitset *)&pcVar7->next;
        pcVar7 = pcVar7->next;
      }
      else {
        pcVar6 = pcVar7;
        if (uVar2 < pcVar7->base) {
          pcVar6 = bitset_chunk_alloc(dst);
          pcVar6->base = uVar2;
          pcVar6->next = pcVar7;
          pcVar1->chunks = pcVar6;
        }
        puVar4 = &pcVar5->bits;
        pcVar5 = pcVar5->next;
        pcVar1 = (c2_bitset *)&pcVar6->next;
        pcVar6->bits = pcVar6->bits | *puVar4;
        pcVar7 = *(c2_bitset_chunk **)pcVar1;
      }
    }
    while (pcVar5 != (c2_bitset_chunk *)0x0) {
      pcVar7 = bitset_chunk_alloc(dst);
      puVar4 = &pcVar5->base;
      uVar3 = pcVar5->bits;
      pcVar5 = pcVar5->next;
      pcVar7->base = *puVar4;
      pcVar1->chunks = pcVar7;
      pcVar7->bits = uVar3;
      pcVar1 = (c2_bitset *)&pcVar7->next;
    }
  }
  return;
}

