void __fastcall globopt_restore_temp_destinations(c2_function *fn)

{
  c2_cfg *pcVar1;
  
  pcVar1 = fn->cfg;
  g_liveness_mode = 0;
  clear_block_liveness_visited(pcVar1->first,pcVar1->last);
  g_partial_overlap_syms = collect_partially_overlapping_symbols(6);
  liveness_prepare_loops(pcVar1->first,pcVar1->last);
  restore_temp_destinations(fn);
  bitset_free(g_partial_overlap_syms);
  return;
}

