void merge_aliased_symbols_into_class_sets(void)

{
  byte bVar1;
  c2_symbol *pcVar2;
  c2_alias_conflict *pcVar3;
  c2_bitset_chunk *pcVar4;
  c2_bitset_chunk *pcVar5;
  c2_bitset *bs;
  uint32_t id;
  c2_symbol *pcVar6;
  
  bs = bitset_new(6);
  id = bitset_iter_next(g_aliased_syms);
  while (id != 0xffffffff) {
    pcVar6 = symbol_by_id(id);
    bitset_clear_all(bs);
    for (pcVar2 = pcVar6; pcVar2 != (c2_symbol *)0x0; pcVar2 = pcVar2->part_next) {
      bitset_set(bs,pcVar2->id);
    }
    for (pcVar3 = g_alias_conflicts[(pcVar6->fe->u3e).alias_class];
        pcVar3 != (c2_alias_conflict *)0x0; pcVar3 = pcVar3->next) {
      if (g_alias_class_member_sets[pcVar3->cls] != (c2_bitset *)0x0) {
        bitset_or(g_alias_class_member_sets[pcVar3->cls],bs);
      }
    }
    id = bitset_iter_next((c2_bitset *)0x0);
  }
  if (bs == (c2_bitset *)0x0) {
    return;
  }
  pcVar4 = bs->chunks;
  if (pcVar4 != (c2_bitset_chunk *)0x0) {
    bVar1 = bs->arena;
    if (g_bitset_chunk_free_head[bVar1] == (c2_bitset_chunk *)0x0) {
      g_bitset_chunk_free_head[bVar1] = pcVar4;
    }
    else {
      g_bitset_chunk_free_tail[bVar1]->next = pcVar4;
    }
    do {
      pcVar5 = pcVar4;
      if (pcVar5 == (c2_bitset_chunk *)0x0) goto LAB_107028a0;
      pcVar4 = pcVar5->next;
    } while (pcVar5->next != (c2_bitset_chunk *)0x0);
    g_bitset_chunk_free_tail[bVar1] = pcVar5;
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

