void __fastcall solve_local_init_dataflow(c2_block *block)

{
  c2_block *pcVar1;
  c2_edge *pcVar2;
  c2_bitset *b;
  bool bVar3;
  c2_bitset *pcVar4;
  int iVar5;
  c2_block *pcVar6;
  
  for (pcVar1 = block; pcVar1 != (c2_block *)0x0; pcVar1 = pcVar1->prev) {
    pcVar4 = bitset_clone(pcVar1->ue);
    pcVar1->live_in = pcVar4;
    pcVar4 = bitset_new(6);
    pcVar1->live_out = pcVar4;
  }
  pcVar4 = bitset_new(6);
  pcVar1 = block->prev;
  do {
    bVar3 = false;
    pcVar6 = pcVar1;
    if (pcVar1 == (c2_block *)0x0) break;
    do {
      bitset_clear_all(pcVar4);
      for (pcVar2 = pcVar6->succs; pcVar2 != (c2_edge *)0x0; pcVar2 = pcVar2->next_succ) {
        bitset_or(pcVar4,pcVar2->to->live_in);
      }
      b = pcVar6->live_out;
      iVar5 = bitset_equal(pcVar4,b);
      if (iVar5 == 0) {
        bitset_copy(b,pcVar4);
        bitset_assign_diff_union(pcVar6->live_in,pcVar4,pcVar6->de,pcVar6->ue);
        bVar3 = true;
      }
      pcVar6 = pcVar6->prev;
    } while (pcVar6 != (c2_block *)0x0);
  } while (bVar3);
  bitset_free(pcVar4);
  return;
}

