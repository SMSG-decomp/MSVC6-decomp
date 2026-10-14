void __fastcall warn_uninitialized_locals(c2_function *fn)

{
  c2_cfg *pcVar1;
  c2_block *first;
  int loop_aware;
  int nlocals;
  c2_bitset *set;
  
  loop_aware = g_opt_global;
  nlocals = number_trackable_locals();
  if (nlocals != 0) {
    g_uninit_local_symbols = arena_alloc(4,nlocals * 4 + 4);
    compute_block_local_defs_uses(fn,nlocals);
    pcVar1 = fn->cfg;
    solve_local_init_dataflow(pcVar1->last);
    first = pcVar1->first;
    if (first->live_in->chunks != (c2_bitset_chunk *)0x0) {
      solve_reaching_defs_loop_aware(first,loop_aware);
      set = bitset_clone(first->live_in);
      warn_uninit_intersect_sets(first);
      if (loop_aware != 0) {
        cfg_compute_reach_sets(fn);
      }
      report_uninitialized_uses(fn,set,nlocals,loop_aware);
      bitset_free(set);
      cfg_free_reach_sets(fn);
    }
    arena_reset(4);
    arena_reset(6);
  }
  return;
}

