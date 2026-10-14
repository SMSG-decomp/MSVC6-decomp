void __fastcall optimize_loop_nest(c2_loop *loop,c2_function *fn)

{
  c2_loop *loop_00;
  c2_block *block;
  
  for (loop_00 = loop->inner; loop_00 != (c2_loop *)0x0; loop_00 = loop_00->next) {
    optimize_loop_nest(loop_00,fn);
  }
  check_loop_optimizable(loop);
  if ((loop->flags & 9) == 0) {
    if (((int)loop->last->rpo - (int)loop->first->rpo) + 1 <= g_opt_loop) {
      propagate_temp_copies_in_loop(loop);
      recompute_loop_liveness(loop,1);
    }
    prepare_loop_hoisting_sets(loop);
    g_preheader_avail_exprs = loop->preheader->set54;
    set_preheader_insert_point(loop);
    g_hoisting_in_loop = 1;
    block = loop->first;
    if (block != loop->last->next) {
      do {
        if ((block->flags & 0x2000000) == 0) {
          hoist_invariants_in_block(block,loop,fn);
        }
        block = block->next;
      } while (block != loop->last->next);
    }
    g_hoisting_in_loop = 0;
    if (((int)loop->last->rpo - (int)loop->first->rpo) + 1 <= g_opt_loop) {
      optimize_loop_induction_variables(loop,fn);
    }
  }
  return;
}

