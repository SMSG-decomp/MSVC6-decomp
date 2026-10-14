void __fastcall fold_child_loop_iv_reinit(c2_loop *loop)

{
  c2_loop *loop_00;
  c2_tuple *candidate;
  c2_loop *child_loop;
  
  loop_00 = loop->inner;
  do {
    if (loop_00 == (c2_loop *)0x0) {
      return;
    }
    if ((loop_00->u30).iv_update_clones != (c2_list_cell *)0x0) {
      child_loop = loop_00;
      reset_iv_worklists();
      collect_iv_candidates(loop_00,5);
      candidate = iv_worklist_pop();
      if (candidate != (c2_tuple *)0x0) {
        fold_child_loop_iv_reinit_tail(loop_00,candidate,child_loop,loop);
        return;
      }
    }
    loop_00 = loop_00->next;
  } while( true );
}

