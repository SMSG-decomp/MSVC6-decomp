void __fastcall optimize_flow_graph_initial(c2_function *fn,int mode)

{
  c2_block *pcVar1;
  uint32_t uVar2;
  uint uVar3;
  uint uVar4;
  
  insert_prolog_epilog_markers(fn);
  cfg_remove_unreachable_blocks(fn);
  cfg_relayout_rpo(fn);
  cfg_number_blocks(fn);
  cfg_compute_dominators(fn);
  uVar4 = 0;
  uVar2 = flow_graph_has_back_edge(fn);
  if (uVar2 == 0) {
    fn->loops = (c2_loop *)0x0;
  }
  else {
    cfg_compute_reach_sets(fn);
    uVar4 = cfg_find_loops(fn,mode);
    cfg_free_reach_sets(fn);
  }
  for (pcVar1 = fn->cfg->first; pcVar1 != (c2_block *)0x0; pcVar1 = pcVar1->next) {
    pcVar1->flags = pcVar1->flags & 0xf7ffffff;
  }
  uVar2 = compact_loops_recursive(fn->loops,fn);
  if (uVar2 != 0) {
    uVar4 = 1;
    cfg_number_blocks(fn);
    uVar2 = loop_body_is_scattered(fn);
    if (uVar2 != 0) {
      free_dominators(fn);
      cfg_number_blocks(fn);
      cfg_compute_dominators(fn);
      cfg_compute_reach_sets(fn);
      cfg_find_loops(fn,0);
      cfg_free_reach_sets(fn);
      uVar2 = compact_loops_recursive(fn->loops,fn);
      if (uVar2 != 0) {
        cfg_number_blocks(fn);
      }
    }
  }
  g_loop_latch_split_changed = 0;
  if ((fn->loops != (c2_loop *)0x0) &&
     (make_distinct_outer_latches(fn->loops,fn), g_loop_latch_split_changed != 0)) {
    uVar4 = 1;
    cfg_number_blocks(fn);
  }
  if (mode != 0) {
    uVar2 = invert_loops_recursive(fn->loops,fn);
    uVar4 = uVar4 | uVar2;
  }
  uVar3 = simplify_flow_graph(fn);
  uVar4 = uVar4 | uVar3;
  if (fn->loops != (c2_loop *)0x0) {
    set_loop_depths(fn->loops,1);
    uVar2 = create_preheaders_recursive(fn->loops,fn);
    uVar4 = uVar4 | uVar2;
    if (mode != 0) {
      cfg_remove_unreachable_blocks(fn);
    }
  }
  if (uVar4 != 0) {
    free_dominators(fn);
    cfg_number_blocks(fn);
    cfg_compute_dominators(fn);
  }
  return;
}

