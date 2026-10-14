void __fastcall recse_preheader(c2_loop *loop,c2_function *fn)

{
  c2_block *block;
  c2_edge *pcVar1;
  bool bVar2;
  c2_tuple *t;
  c2_tuple *pcVar3;
  c2_tuple *pcVar4;
  
  block = loop->preheader;
  fold_block_tuples(block,fn);
  rehash_block_tuples(block,1);
  g_cse_full_mode = 0;
  if ((block->flags & 0x2000000) == 0) {
    pcVar1 = block->preds;
    if (pcVar1 != (c2_edge *)0x0) {
      bitset_copy(block->set50,pcVar1->from->set54);
      for (pcVar1 = pcVar1->next_pred; pcVar1 != (c2_edge *)0x0; pcVar1 = pcVar1->next_pred) {
        bitset_and(block->set50,pcVar1->from->set54);
      }
    }
    g_cur_avail_set = block->set54;
    bitset_copy(g_cur_avail_set,block->set50);
    pcVar4 = block->end;
    bVar2 = false;
    pcVar3 = block->head->next;
    while (t = pcVar3, t != pcVar4) {
      g_next_tuple_cursor = t->next;
      pcVar3 = g_next_tuple_cursor;
      if ((t->flags & 1) != 0) {
        if (t->line != 0) {
          g_current_line_abs = fn->line_base + (uint)t->line;
          g_cur_line = t->line;
        }
        if (t->kind == '\f') {
          bVar2 = true;
        }
        cse_tuple(t,block,fn);
        pcVar3 = g_next_tuple_cursor;
      }
    }
    if (g_jump_threading_enabled != 0) {
      thread_jumps_at_block_end(block,fn);
    }
    if ((bVar2) && (pcVar4 = block_first_assignment(block->head), pcVar4 == (c2_tuple *)0x0)) {
      g_flowgraph_dirty = 1;
    }
  }
  return;
}

