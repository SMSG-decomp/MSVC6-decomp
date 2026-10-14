void __fastcall allocate_x87_live_ranges(c2_function *fn)

{
  c2_live_range *pcVar1;
  c2_bitset *on_stack;
  c2_bitset *dst;
  c2_bitset *spared;
  c2_live_range *pcVar2;
  int32_t iVar3;
  
  on_stack = bitset_new(6);
  dst = bitset_clone(g_class_candidates[1]);
  spared = x87_tag_depths_and_split_at_calls(fn,g_class_candidates[1]);
  x87_score_live_ranges(fn,g_class_candidates[1]);
  pcVar2 = x87_queue_live_ranges(g_class_candidates[1],(c2_live_range *)0x0);
  pcVar2 = x87_prune_unprofitable_ranges(fn,pcVar2,spared);
  while (pcVar2 != (c2_live_range *)0x0) {
    if (spared != (c2_bitset *)0x0) {
      pcVar2 = x87_drop_ranges_from_queue(pcVar2,spared);
      split_live_ranges_at_markers(fn,spared,1);
      bitset_or(dst,g_class_candidates[1]);
      x87_score_live_ranges(fn,g_class_candidates[1]);
      pcVar2 = x87_queue_live_ranges(g_class_candidates[1],pcVar2);
      pcVar2 = x87_prune_unprofitable_ranges(fn,pcVar2,(c2_bitset *)0x0);
      if (pcVar2 == (c2_live_range *)0x0) break;
    }
    pcVar1 = (pcVar2->u14).queue_next;
    if (pcVar1 != (c2_live_range *)0x0) {
      pcVar1->queue_prev = (c2_live_range *)0x0;
    }
    iVar3 = x87_range_fits_stack(fn,pcVar2,on_stack);
    if (iVar3 == 0) {
      (pcVar2->u14).queue_next = pcVar1;
      if (pcVar1 != (c2_live_range *)0x0) {
        pcVar1->queue_prev = pcVar2;
      }
      spared = bitset_new(6);
      bitset_set(spared,pcVar2->id);
    }
    else {
      pcVar2->colour = g_reg_symbols + 0x1f;
      bitset_set(on_stack,pcVar2->id);
      spared = x87_commit_range_to_stack(fn,pcVar2,on_stack,dst);
      pcVar2 = pcVar1;
    }
  }
  x87_promote_loop_values();
  x87_block_stack_cleanup(fn,dst,on_stack);
  bitset_free(on_stack);
  bitset_free(dst);
  fold_x87_copy_sequences(fn);
  return;
}

