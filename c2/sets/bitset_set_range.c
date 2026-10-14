void __fastcall bitset_set_range(c2_bitset *dst,uint32_t nsyms)

{
  byte bVar1;
  c2_bitset_chunk *pcVar2;
  uint uVar3;
  c2_bitset_chunk *after;
  c2_bitset_chunk *after_00;
  int iVar4;
  uint uVar5;
  
  after = (c2_bitset_chunk *)0x0;
  uVar5 = 0;
  pcVar2 = dst->chunks;
  uVar3 = nsyms + 0x1f >> 5;
  if (1 < uVar3) {
    iVar4 = uVar3 - 1;
    after_00 = after;
    do {
      after = pcVar2;
      if (after == (c2_bitset_chunk *)0x0) {
        after = bitset_chunk_insert_after(dst,after_00);
      }
      after->base = uVar5;
      uVar5 = uVar5 + 0x20;
      after->bits = 0xffffffff;
      pcVar2 = after->next;
      iVar4 = iVar4 + -1;
      after_00 = after;
    } while (iVar4 != 0);
  }
  if (uVar5 < nsyms) {
    if (pcVar2 == (c2_bitset_chunk *)0x0) {
      pcVar2 = bitset_chunk_insert_after(dst,after);
    }
    pcVar2->base = uVar5;
    do {
      bVar1 = (byte)uVar5;
      uVar5 = uVar5 + 1;
      pcVar2->bits = pcVar2->bits | 1 << (bVar1 & 0x1f);
    } while (uVar5 < nsyms);
  }
  return;
}

