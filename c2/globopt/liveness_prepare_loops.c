void __fastcall liveness_prepare_loops(c2_block *block,c2_block *b)

{
  c2_block *pcVar1;
  c2_block *pcVar2;
  c2_edge *pcVar3;
  
  pcVar1 = block->prev;
  for (pcVar2 = b; pcVar2 != pcVar1; pcVar2 = pcVar2->prev) {
    if ((pcVar2->flags & 0x4000000) == 0) {
      liveness_init_block_sets(pcVar2);
    }
  }
  pcVar1 = block->prev;
  pcVar2 = b;
  do {
    if (pcVar2 == pcVar1) {
      for (; b != pcVar1; b = b->prev) {
        liveness_block_transfer(b,(uint32_t *)&stack0xfffffffc);
      }
      return;
    }
    if (((pcVar2->loop != (c2_loop *)0x0) && ((pcVar2->loop->flags & 1) == 0)) &&
       (pcVar3 = pcVar2->preds, pcVar3 != (c2_edge *)0x0)) {
      do {
        if ((pcVar2->rpo <= pcVar3->from->rpo) && (pcVar3->from->succs->next_succ != (c2_edge *)0x0)
           ) {
          bitset_copy((pcVar2->avail_out).set,g_partial_overlap_syms);
          break;
        }
        pcVar3 = pcVar3->next_pred;
      } while (pcVar3 != (c2_edge *)0x0);
    }
    pcVar2 = pcVar2->prev;
  } while( true );
}

