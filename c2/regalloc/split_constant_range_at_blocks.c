void __fastcall split_constant_range_at_blocks(c2_live_range *lr)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  uint32_t n;
  c2_block *pcVar3;
  c2_tuple *pcVar4;
  uint32_t uVar5;
  c2_tuple *pos;
  c2_block *block;
  c2_edge *pcVar6;
  c2_tuple *t;
  
  block = lr->first_block;
  while( true ) {
    pcVar1 = block->end;
    pcVar2 = block->head;
    while (t = pcVar2, t != pcVar1) {
      pcVar2 = t->next;
      if ((((t->op == 0x163) && ((t->dst->u18).reg == (c2_symbol *)lr)) &&
          ((t->dst->flags11 & 0x80) != 0)) && (pcVar6 = block->succs, pcVar6 != (c2_edge *)0x0)) {
        n = lr->id;
        do {
          pcVar3 = pcVar6->to;
          uVar5 = bitset_test(pcVar3->live_in,n);
          if (uVar5 != 0) {
            pcVar4 = pcVar3->head->next;
            pos = pcVar3->head;
            if (pcVar4->kind == '\x1a') {
              pos = pcVar4;
            }
            insert_split_marker_after(pos,n);
            pcVar3->flags = pcVar3->flags | 0x40000;
            tuple_unlink_free(t);
          }
          pcVar6 = pcVar6->next_succ;
        } while (pcVar6 != (c2_edge *)0x0);
      }
    }
    if (block == lr->last_block) break;
    block = block->next;
  }
  return;
}

