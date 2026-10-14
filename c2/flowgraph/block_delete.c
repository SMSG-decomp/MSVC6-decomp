void __fastcall block_delete(c2_function *fn,c2_block *b)

{
  c2_tuple *t;
  c2_sched_edge *pcVar1;
  c2_cfg *pcVar2;
  c2_block *pcVar3;
  c2_sched_edge *pcVar4;
  
  t = b->end;
  tuple_unlink(t);
  node_free((c2_node *)t);
  pcVar4 = (c2_sched_edge *)b->succs;
  while (pcVar4 != (c2_sched_edge *)0x0) {
    pcVar1 = pcVar4->next_succ;
    cfg_edge_remove((int)fn->cfg,pcVar4);
    pcVar4 = pcVar1;
  }
  pcVar4 = (c2_sched_edge *)b->preds;
  while (pcVar4 != (c2_sched_edge *)0x0) {
    pcVar1 = pcVar4->next_pred;
    cfg_edge_remove((int)fn->cfg,pcVar4);
    pcVar4 = pcVar1;
  }
  if (b->next != (c2_block *)0x0) {
    b->next->head = b->head;
    b->head->u14 = (c2_tuple_u14)b->next;
  }
  if (b->dominators != (c2_bitvec *)0x0) {
    bitset_header_free(b->dominators);
  }
  pcVar2 = fn->cfg;
  pcVar3 = b->prev;
  if (pcVar3 == (c2_block *)0x0) {
    pcVar2->first = b->next;
  }
  else {
    pcVar3->next = b->next;
  }
  if (b->next != (c2_block *)0x0) {
    b->next->prev = pcVar3;
    b->next = pcVar2->free_blocks;
    pcVar2->free_blocks = b;
    return;
  }
  pcVar2->last = pcVar3;
  b->next = pcVar2->free_blocks;
  pcVar2->free_blocks = b;
  return;
}

