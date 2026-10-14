void __fastcall prepare_loop_hoisting_sets(c2_loop *loop)

{
  c2_loop_exit *pcVar1;
  c2_edge *pcVar2;
  
  solve_loop_local_availability(loop);
  g_preheader_live_out = loop->first->prev->ue;
  g_preheader_must_set = (loop->first->prev->avail_out).set;
  bitset_clear_all(g_loop_live_out_syms);
  for (pcVar1 = loop->exits; pcVar1 != (c2_loop_exit *)0x0; pcVar1 = pcVar1->next) {
    for (pcVar2 = pcVar1->block->succs; pcVar2 != (c2_edge *)0x0; pcVar2 = pcVar2->next_succ) {
      if (pcVar2->to->loop != loop) {
        bitset_or(g_loop_live_out_syms,pcVar2->to->de);
      }
    }
  }
  collect_loop_kill_set(loop);
  bitset_clear_all(g_hoisted_exprs);
  return;
}

