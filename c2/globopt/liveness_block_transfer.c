void __fastcall liveness_block_transfer(c2_block *b,uint32_t *changed)

{
  c2_edge *pcVar1;
  c2_block *pcVar2;
  c2_bitset *dst;
  
  pcVar1 = b->succs;
  if (pcVar1 != (c2_edge *)0x0) {
    pcVar2 = pcVar1->to;
    dst = b->ue;
    bitset_copy(dst,pcVar2->de);
    bitset_copy(b->live_in,(pcVar2->avail_out).set);
    for (pcVar1 = pcVar1->next_succ; pcVar1 != (c2_edge *)0x0; pcVar1 = pcVar1->next_succ) {
      pcVar2 = pcVar1->to;
      bitset_or(dst,pcVar2->de);
      bitset_and(b->live_in,(pcVar2->avail_out).set);
    }
  }
  apply_dataflow_transfer(b->de,b->set24,b->ue,b->set28,changed);
  apply_dataflow_transfer((b->avail_out).set,b->kill,b->live_in,(b->avail_in).set,changed);
  return;
}

