void __fastcall globopt_dead_code_elim(c2_function *fn)

{
  c2_block *pcVar1;
  c2_block *block2;
  c2_operand *pcVar2;
  c2_loop *pcVar3;
  c2_edge *pcVar4;
  c2_bitset *dst;
  c2_symbol *pcVar5;
  c2_tuple *pcVar6;
  c2_tuple *t;
  bool bVar7;
  c2_bitset *dst_00;
  c2_bitset *dst_01;
  c2_block *pcVar8;
  c2_tuple *pcVar9;
  uint32_t uVar10;
  
  pcVar1 = fn->cfg->first;
  block2 = fn->cfg->last;
  g_liveness_mode = 0;
  clear_block_liveness_visited(pcVar1,block2);
  if (block2->next == (c2_block *)0x0) {
    bitset_copy(block2->ue,g_exit_used_symbols);
  }
  pcVar1 = pcVar1->prev;
  for (pcVar8 = block2; pcVar8 != pcVar1; pcVar8 = pcVar8->prev) {
    pcVar9 = pcVar8->head->next;
    if (pcVar9 != pcVar8->end) {
      do {
        if ((pcVar9->flags & 1) != 0) {
          for (pcVar2 = pcVar9->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
            if ((1 << (pcVar2->kind & 0x1f) & 6U) == 0) {
              if ((pcVar2->kind == 6) && (pcVar5 = (pcVar2->u18).reg, pcVar5 != (c2_symbol *)0x0)) {
                (pcVar5->u30).globopt.live = '\0';
                (pcVar5->u30).globopt.killed = '\0';
              }
            }
            else {
              pcVar5 = pcVar2->sym;
              (pcVar5->u30).globopt.live = '\0';
              (pcVar5->u30).globopt.killed = '\0';
              pcVar2->flags11 = pcVar2->flags11 & 0xef;
            }
          }
          for (pcVar2 = pcVar9->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
            if ((1 << (pcVar2->kind & 0x1f) & 6U) == 0) {
              if ((pcVar2->kind == 6) && (pcVar5 = (pcVar2->u18).reg, pcVar5 != (c2_symbol *)0x0)) {
                (pcVar5->u30).globopt.live = '\0';
                (pcVar5->u30).globopt.killed = '\0';
              }
            }
            else {
              pcVar5 = pcVar2->sym;
              (pcVar5->u30).globopt.live = '\0';
              (pcVar5->u30).globopt.killed = '\0';
              pcVar2->flags11 = pcVar2->flags11 & 0xef;
            }
          }
        }
        pcVar9 = pcVar9->next;
      } while (pcVar9 != pcVar8->end);
    }
  }
  merge_aliased_symbols_into_class_sets();
  g_pending_memory_stores = (c2_symbol *)0x0;
  dst_00 = bitset_new(6);
  dst_01 = bitset_new(6);
  g_partial_overlap_syms = collect_partially_overlapping_symbols(6);
  for (; block2 != pcVar1; block2 = block2->prev) {
    uVar10 = block_has_back_edge(block2);
    if ((uVar10 != 0) && ((block2->flags & 0x4000000) == 0)) {
      pcVar8 = find_loop_top_block(block2);
      pcVar3 = pcVar8->loop;
      if ((pcVar3 != (c2_loop *)0x0) &&
         ((pcVar3->first == pcVar8 && (pcVar3->preheader != (c2_block *)0x0)))) {
        pcVar8 = pcVar3->preheader;
      }
      liveness_prepare_loops(pcVar8,block2);
    }
    pcVar4 = block2->succs;
    if (pcVar4 != (c2_edge *)0x0) {
      pcVar8 = pcVar4->to;
      dst = block2->ue;
      bitset_copy(dst,pcVar8->de);
      bitset_copy(block2->live_in,(pcVar8->avail_out).set);
      for (pcVar4 = pcVar4->next_succ; pcVar4 != (c2_edge *)0x0; pcVar4 = pcVar4->next_succ) {
        pcVar8 = pcVar4->to;
        bitset_or(dst,pcVar8->de);
        bitset_and(block2->live_in,(pcVar8->avail_out).set);
      }
    }
    bitset_copy(dst_00,block2->ue);
    bitset_copy(dst_01,block2->live_in);
    while (g_pending_memory_stores != (c2_symbol *)0x0) {
      pcVar5 = (g_pending_memory_stores->u28).free_next;
      (g_pending_memory_stores->u30).globopt.killed = '\0';
      g_pending_memory_stores = pcVar5;
    }
    pcVar9 = block2->head;
    bVar7 = false;
    pcVar6 = block2->end->prev;
    while (t = pcVar6, t != pcVar9) {
      pcVar6 = t->prev;
      if ((t->flags & 1) != 0) {
        if (t->kind == '\f') {
          bVar7 = true;
        }
        liveness_transfer_tuple(t,dst_00,dst_01);
      }
    }
    bitset_and(dst_01,g_partial_overlap_syms);
    bitset_copy(block2->de,dst_00);
    bitset_copy((block2->avail_out).set,dst_01);
    if ((bVar7) && (pcVar9 = tuple_next_real_before_boundary(pcVar9), pcVar9 == (c2_tuple *)0x0)) {
      g_flowgraph_dirty = 1;
    }
  }
  bitset_free(dst_00);
  bitset_free(dst_01);
  bitset_free(g_partial_overlap_syms);
  return;
}

