void __fastcall split_range_at_block_entries(c2_live_range *lr)

{
  c2_block *pcVar1;
  uint32_t n;
  c2_tuple *pcVar2;
  uint32_t uVar3;
  c2_tuple *pos;
  c2_block *pcVar4;
  
  pcVar1 = lr->last_block;
  pcVar4 = lr->first_block;
  n = lr->id;
  while( true ) {
    uVar3 = bitset_test(pcVar4->live_in,n);
    if (uVar3 != 0) {
      pcVar2 = pcVar4->head->next;
      pos = pcVar4->head;
      if (pcVar2->kind == '\x1a') {
        pos = pcVar2;
      }
      insert_split_marker_after(pos,n);
      pcVar4->flags = pcVar4->flags | 0x40000;
    }
    if (pcVar4 == pcVar1) break;
    pcVar4 = pcVar4->next;
  }
  return;
}

