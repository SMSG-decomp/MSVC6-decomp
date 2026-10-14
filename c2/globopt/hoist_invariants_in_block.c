void __fastcall hoist_invariants_in_block(c2_block *block,c2_loop *loop,c2_function *fn)

{
  bool bVar1;
  uint32_t uVar2;
  c2_edge *pcVar3;
  c2_tuple *t;
  c2_tuple *pcVar4;
  
  if (loop->first == block) {
    pcVar3 = block->preds;
    if (pcVar3 != (c2_edge *)0x0) {
      do {
        if (block->loop == pcVar3->from->loop) {
          bitset_copy((block->u58).set,pcVar3->from->set5c);
          break;
        }
        pcVar3 = pcVar3->next_pred;
      } while (pcVar3 != (c2_edge *)0x0);
    }
    for (pcVar3 = block->preds; pcVar3 != (c2_edge *)0x0; pcVar3 = pcVar3->next_pred) {
      if (block->loop == pcVar3->from->loop) {
        bitset_and((block->u58).set,pcVar3->from->set5c);
      }
    }
  }
  else {
    pcVar3 = block->preds;
    if (pcVar3 != (c2_edge *)0x0) {
      bitset_copy((block->u58).set,pcVar3->from->set5c);
      for (pcVar3 = pcVar3->next_pred; pcVar3 != (c2_edge *)0x0; pcVar3 = pcVar3->next_pred) {
        bitset_and((block->u58).set,pcVar3->from->set5c);
      }
    }
  }
  g_cur_avail_set = block->set5c;
  bitset_copy(g_cur_avail_set,(block->u58).set);
  uVar2 = block_dominates_loop_exits(block,loop);
  pcVar4 = block->end;
  bVar1 = false;
  t = block->head->next;
  if (t != pcVar4) {
    do {
      g_next_tuple_cursor = t->next;
      if ((t->flags & 1) != 0) {
        if (t->line != 0) {
          g_current_line_abs = fn->line_base + (uint)t->line;
          g_cur_line = t->line;
        }
        if (t->kind == '\f') {
          bVar1 = true;
        }
        if ((uVar2 == 0) || (t = try_hoist_invariant_tuple(t,loop), t != (c2_tuple *)0x0)) {
          avail_transfer_tuple(t);
        }
      }
      t = g_next_tuple_cursor;
    } while (g_next_tuple_cursor != pcVar4);
    if ((bVar1) && (pcVar4 = block_first_assignment(block->head), pcVar4 == (c2_tuple *)0x0)) {
      g_flowgraph_dirty = 1;
    }
  }
  return;
}

