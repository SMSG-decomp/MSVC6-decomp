void __fastcall solve_availability(c2_block *first,int restrict_to_live)

{
  c2_block *pcVar1;
  c2_edge *pcVar2;
  bool bVar3;
  c2_bitset *pcVar4;
  int iVar5;
  c2_block *pcVar6;
  
  for (pcVar1 = first; pcVar1 != (c2_block *)0x0; pcVar1 = pcVar1->next) {
    pcVar4 = bitset_new(6);
    (pcVar1->avail_in).set = pcVar4;
    pcVar4 = bitset_clone(pcVar1->de);
    (pcVar1->avail_out).set = pcVar4;
  }
  pcVar4 = bitset_new(6);
  pcVar1 = first->next;
  do {
    bVar3 = false;
    pcVar6 = pcVar1;
    if (pcVar1 == (c2_block *)0x0) break;
    do {
      bitset_clear_all(pcVar4);
      for (pcVar2 = pcVar6->preds; pcVar2 != (c2_edge *)0x0; pcVar2 = pcVar2->next_pred) {
        bitset_or(pcVar4,(pcVar2->from->avail_out).set);
      }
      if (restrict_to_live != 0) {
        bitset_and(pcVar4,pcVar6->live_in);
      }
      iVar5 = bitset_equal(pcVar4,(pcVar6->avail_in).set);
      if (iVar5 == 0) {
        bitset_copy((pcVar6->avail_in).set,pcVar4);
        bitset_assign_diff_union((pcVar6->avail_out).set,pcVar4,pcVar6->kill,pcVar6->de);
        bVar3 = true;
      }
      pcVar6 = pcVar6->next;
    } while (pcVar6 != (c2_block *)0x0);
  } while (bVar3);
  bitset_free(pcVar4);
  return;
}

