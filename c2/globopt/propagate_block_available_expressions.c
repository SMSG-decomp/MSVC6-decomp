void __fastcall propagate_block_available_expressions(c2_block *b,uint32_t *changed)

{
  c2_edge *pcVar1;
  c2_bitset *dst;
  
  pcVar1 = b->preds;
  if (pcVar1 != (c2_edge *)0x0) {
    dst = b->set50;
    bitset_copy(dst,pcVar1->from->set54);
    for (pcVar1 = pcVar1->next_pred; pcVar1 != (c2_edge *)0x0; pcVar1 = pcVar1->next_pred) {
      bitset_and(dst,pcVar1->from->set54);
    }
  }
  apply_dataflow_transfer(b->set54,b->live_out,b->set50,b->live,changed);
  return;
}

