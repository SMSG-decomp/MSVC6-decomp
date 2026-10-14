void __fastcall cfg_reanalyze(c2_function *fn,int mode)

{
  insert_prolog_epilog_markers(fn);
  cfg_remove_unreachable_blocks(fn);
  cfg_number_blocks(fn);
  cfg_compute_dominators(fn);
  optimize_loops_and_layout(fn,0);
  if (mode != 0) {
    remove_duplicate_edges(fn);
  }
  return;
}

