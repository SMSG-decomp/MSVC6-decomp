void __fastcall propagate_loop_local_availability(c2_block *b,int is_first,uint32_t *changed)

{
  c2_bitset *pcVar1;
  c2_loop *pcVar2;
  c2_block *pcVar3;
  c2_edge *pcVar4;
  
  pcVar4 = b->preds;
  if (is_first == 0) {
    if (pcVar4 != (c2_edge *)0x0) {
      pcVar1 = (b->u58).set;
      bitset_copy(pcVar1,pcVar4->from->set5c);
      for (pcVar4 = pcVar4->next_pred; pcVar4 != (c2_edge *)0x0; pcVar4 = pcVar4->next_pred) {
        bitset_and(pcVar1,pcVar4->from->set5c);
      }
    }
  }
  else if (pcVar4 != (c2_edge *)0x0) {
    pcVar3 = pcVar4->from;
    pcVar2 = b->loop;
    if (pcVar3->loop != pcVar2) {
      pcVar4 = pcVar4->next_pred;
      pcVar3 = pcVar4->from;
    }
    pcVar1 = (b->u58).set;
    bitset_copy(pcVar1,pcVar3->set5c);
    for (pcVar4 = pcVar4->next_pred; pcVar4 != (c2_edge *)0x0; pcVar4 = pcVar4->next_pred) {
      if (pcVar4->from->loop == pcVar2) {
        bitset_and(pcVar1,pcVar4->from->set5c);
      }
    }
  }
  apply_dataflow_transfer(b->set5c,g_loop_local_gen,(b->u58).set,b->live,changed);
  return;
}

