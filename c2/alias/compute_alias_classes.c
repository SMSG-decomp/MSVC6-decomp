void __fastcall compute_alias_classes(c2_function *fn)

{
  c2_block *pcVar1;
  uint32_t nscopes;
  uint32_t uVar2;
  uint32_t nrefs;
  uint32_t scope_cls_end;
  c2_bitset *pcVar3;
  c2_bitset *params;
  c2_bitset *dst;
  c2_symbol **syms;
  c2_alias_intrin_block *blocks;
  c2_alias_call_effect *local_14;
  c2_alias_call_effect *local_4;
  
  attach_pseudo_call_results(fn);
  arena_reset(4);
  arena_reset(6);
  g_frame_offsets_assigned = 0;
  g_alias_analysis_overflow = 0;
  pcVar1 = fn->cfg->first;
  nscopes = count_tuples_and_scan_calls(pcVar1->head);
  g_alias_class_count = nscopes + 3;
  if ((fn->flags & 0x40) != 0) {
    pcVar3 = bitset_new(6);
    params = bitset_new(6);
    uVar2 = alias_number_symbols(pcVar3,params);
    dst = bitset_clone(params);
    bitset_andnot(dst,pcVar3);
    syms = arena_alloc(4,uVar2 * 4);
    blocks = alias_block_local_sets(pcVar1,uVar2,pcVar3,syms,dst);
    solve_availability(pcVar1,0);
    solve_block_liveness(fn->cfg->last);
    local_4 = alias_collect_call_effects(blocks,pcVar3,uVar2,syms);
    local_14 = alias_attach_call_memory_effects(pcVar1,local_4,uVar2,pcVar3,params,syms,dst);
    bitset_free(pcVar3);
    bitset_free(params);
    bitset_free(dst);
  }
  g_alias_class_skip_index = g_alias_class_count;
  uVar2 = assign_symbol_alias_classes(g_opt_assume_no_alias,g_alias_analysis_overflow);
  if (g_alias_analysis_overflow != 0) {
    alias_fallback_collect_exposed(fn);
  }
  g_alias_symbol_class_count = g_alias_class_count;
  pcVar1 = fn->cfg->first;
  nrefs = number_exposed_symbol_refs(pcVar1->head,uVar2);
  g_alias_ref_table = build_block_alias_sets(pcVar1,uVar2,nrefs);
  g_alias_synth_class_symbols = (c2_symbol *)0x0;
  g_alias_call_records = (c2_alias_call_record *)0x0;
  g_alias_loadv_class = 0;
  g_alias_exposed_ref_count = nrefs;
  scope_cls_end =
       compute_alias_points_to(pcVar1,nscopes,g_opt_assume_no_alias,g_assume_no_alias_across_calls);
  g_alias_pointee_class_base = scope_cls_end;
  if (g_opt_assume_no_alias != 0) {
    nrefs = alias_refine_no_alias_oa(nrefs);
  }
  if (g_opt_bzalign != 0) {
    alias_expand_unknown_pointees(nrefs);
  }
  propagate_alias_sets(uVar2,nrefs,g_opt_assume_no_alias);
  if (g_opt_assume_no_alias != 0) {
    alias_refine_pointer_offsets_oa(nrefs);
  }
  prune_unexposed_alias_members();
  reserve_alias_class_ids();
  build_alias_class_tables
            (scope_cls_end,nscopes,uVar2,g_alias_symbol_number_count,g_opt_assume_no_alias);
  if ((fn->flags & 0x40) != 0) {
    alias_build_class_symbol_sets(local_4,local_14,g_alias_symbol_number_count);
  }
  pcVar3 = alias_collect_field_classes
                     (pcVar1->head,g_alias_class_count,g_alias_symbol_class_count,
                      g_opt_assume_no_alias);
  build_alias_conflict_lists(pcVar3,g_alias_class_max,g_alias_class_count);
  arena_reset(4);
  arena_reset(6);
  expand_call_pseudo_results(fn);
  g_alias_tables_valid = 1;
  return;
}

