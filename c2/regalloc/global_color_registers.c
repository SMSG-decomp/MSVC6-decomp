void __fastcall global_color_registers(c2_function *fn)

{
  c2_bitset *pcVar1;
  c2_bitset *dst;
  c2_bitset *pcVar2;
  c2_bitset *split_set;
  int iVar3;
  c2_live_range *lr;
  int iVar4;
  int reg_class;
  c2_bitset *local_10;
  
  if ((g_class_candidates[0]->chunks == (c2_bitset_chunk *)0x0) &&
     (g_class_candidates[1]->chunks == (c2_bitset_chunk *)0x0)) {
    arena_reset(4);
    arena_reset(6);
    g_no_global_candidates = 1;
    fold_x87_copy_sequences(fn);
    return;
  }
  g_no_global_candidates = 0;
  g_split_node_free = (void *)0x0;
  g_split_cell_free = (void *)0x0;
  g_rename_cell_free = (void *)0x0;
  g_split_uf_cell_free = (c2_split_uf_cell *)0x0;
  g_ra_block_count = 0;
  g_colour_queue = (c2_live_range *)0x0;
  g_copy_related_ranges = bitset_new(6);
  coalesce_copy_live_ranges(fn,g_class_candidates);
  forward_substitute_single_def_ranges(fn,g_class_candidates[0]);
  init_block_register_sets(fn);
  if ((g_class_candidates[1]->chunks == (c2_bitset_chunk *)0x0) &&
     ((((fn->flags & 8) == 0 || (g_fp_loop_list == (c2_loop *)0x0)) ||
      (g_opt_float_consistency != 0)))) {
    fold_x87_copy_sequences(fn);
  }
  else {
    allocate_x87_live_ranges(fn);
  }
  choose_frame_pointer_mode(fn);
  g_class_register_count[0] = count_allocatable_int_registers(fn);
  reg_class = 1;
  iVar4 = 0;
  do {
    pcVar1 = *(c2_bitset **)((int)g_class_candidates + iVar4 + 4);
    if (pcVar1->chunks != (c2_bitset_chunk *)0x0) {
      pcVar1 = mark_register_pressure_splits
                         (fn,reg_class,pcVar1,*(int *)((int)g_class_register_count + iVar4 + 4));
      score_live_ranges(fn,reg_class,*(c2_bitset **)((int)g_class_candidates + iVar4 + 4));
      prune_low_use_live_ranges
                (fn,reg_class,*(c2_bitset **)((int)g_class_candidates + iVar4 + 4),pcVar1);
      if ((pcVar1 != (c2_bitset *)0x0) && (pcVar1->chunks == (c2_bitset_chunk *)0x0)) {
        bitset_free(pcVar1);
        pcVar1 = (c2_bitset *)0x0;
      }
      dst = bitset_clone(*(c2_bitset **)((int)g_class_candidates + iVar4 + 4));
      bitset_clear_all(*(c2_bitset **)((int)g_class_candidates + iVar4 + 4));
      local_10 = build_colour_queue(fn,reg_class,pcVar1);
      pcVar1 = bitset_new(6);
      while (g_colour_queue != (c2_live_range *)0x0) {
        lr = g_colour_queue;
        if (local_10 == (c2_bitset *)0x0) {
LAB_107208a2:
          g_colour_queue = (lr->u14).queue_next;
          if (g_colour_queue != (c2_live_range *)0x0) {
            g_colour_queue->queue_prev = (c2_live_range *)0x0;
          }
          if ((lr->weight < 1) &&
             (((lr->weight != 0 || (lr->first_block != lr->last_block)) ||
              ((lr->sym->cls == '\r' || ((lr->refcount < 3 || (g_opt_favor_speed == 0)))))))) {
            local_10 = handle_unprofitable_live_range(lr,fn,reg_class);
          }
          else if (((lr->flags5 & 4) == 0) &&
                  (iVar3 = try_substitute_before_colouring(lr), iVar3 != 0)) {
            if (lr->allowed != (c2_bitset *)0x0) {
              g_colour_queue = insert_live_range_by_priority(lr,g_colour_queue);
            }
          }
          else {
            if (lr->allowed->chunks == (c2_bitset_chunk *)0x0) {
              local_10 = split_uncolourable_live_range(lr,reg_class);
            }
            else {
              bitset_set(pcVar1,lr->id);
              pcVar2 = bitset_new(6);
              split_set = build_interference_and_pressure_splits
                                    (fn,lr,reg_class,dst,pcVar2,pcVar1,
                                     *(int *)((int)g_class_register_count + iVar4 + 4));
              choose_register_for_live_range(lr,reg_class,pcVar2);
              local_10 = propagate_colour_to_neighbours(fn,reg_class,lr,pcVar2,split_set);
            }
          }
        }
        else {
          g_colour_queue = remove_flagged_from_queue(g_colour_queue);
          split_live_ranges_at_markers(fn,local_10,reg_class);
          local_10 = (c2_bitset *)0x0;
          bitset_or(dst,*(c2_bitset **)((int)g_class_candidates + iVar4 + 4));
          score_live_ranges(fn,reg_class,*(c2_bitset **)((int)g_class_candidates + iVar4 + 4));
          prune_low_use_live_ranges
                    (fn,reg_class,*(c2_bitset **)((int)g_class_candidates + iVar4 + 4),
                     (c2_bitset *)0x0);
          g_colour_queue =
               requeue_split_pieces
                         (*(c2_bitset **)((int)g_class_candidates + iVar4 + 4),g_colour_queue);
          bitset_clear_all(*(c2_bitset **)((int)g_class_candidates + iVar4 + 4));
          pcVar2 = g_ranges_pending_removal;
          if (g_colour_queue == (c2_live_range *)0x0) break;
          lr = g_colour_queue;
          if (g_ranges_pending_removal == (c2_bitset *)0x0) goto LAB_107208a2;
          g_ranges_pending_removal = (c2_bitset *)0x0;
          local_10 = pcVar2;
        }
      }
      bitset_free(pcVar1);
      bitset_free(dst);
    }
    iVar4 = iVar4 + -4;
    reg_class = reg_class + -1;
    if (iVar4 < -4) {
      rewrite_live_range_operands(fn);
      arena_reset(4);
      arena_reset(6);
      return;
    }
  } while( true );
}

