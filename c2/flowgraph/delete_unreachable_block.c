void __fastcall delete_unreachable_block(c2_function *fn,c2_block *block)

{
  uint8_t uVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  c2_sched_edge *pcVar4;
  c2_cfg *pcVar5;
  c2_block *pcVar6;
  c2_sched_edge *pcVar7;
  c2_tuple *t;
  
  pcVar2 = block->end;
  t = block->head->next;
  while (t != pcVar2) {
    pcVar3 = t->next;
    uVar1 = t->kind;
    if (uVar1 == '\x11') {
      branch_free(t);
      t = pcVar3;
    }
    else if (uVar1 == '\x13') {
      switch_free(t);
      t = pcVar3;
    }
    else if (uVar1 == '\x1a') {
      label_delete(t);
      t = pcVar3;
    }
    else {
      tuple_unlink_free(t);
      t = pcVar3;
    }
  }
  pcVar2 = block->end;
  tuple_unlink(pcVar2);
  node_free((c2_node *)pcVar2);
  pcVar7 = (c2_sched_edge *)block->succs;
  while (pcVar7 != (c2_sched_edge *)0x0) {
    pcVar4 = pcVar7->next_succ;
    cfg_edge_remove((int)fn->cfg,pcVar7);
    pcVar7 = pcVar4;
  }
  pcVar7 = (c2_sched_edge *)block->preds;
  while (pcVar7 != (c2_sched_edge *)0x0) {
    pcVar4 = pcVar7->next_pred;
    cfg_edge_remove((int)fn->cfg,pcVar7);
    pcVar7 = pcVar4;
  }
  if (block->next != (c2_block *)0x0) {
    block->next->head = block->head;
    block->head->u14 = (c2_tuple_u14)block->next;
  }
  if (block->dominators != (c2_bitvec *)0x0) {
    bitset_header_free(block->dominators);
  }
  pcVar5 = fn->cfg;
  pcVar6 = block->prev;
  if (pcVar6 == (c2_block *)0x0) {
    pcVar5->first = block->next;
  }
  else {
    pcVar6->next = block->next;
  }
  if (block->next == (c2_block *)0x0) {
    pcVar5->last = pcVar6;
    block->next = pcVar5->free_blocks;
    pcVar5->free_blocks = block;
    return;
  }
  block->next->prev = pcVar6;
  block->next = pcVar5->free_blocks;
  pcVar5->free_blocks = block;
  return;
}

