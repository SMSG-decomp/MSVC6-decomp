int32_t __fastcall globopt_run(c2_function *fn)

{
  c2_loop *pcVar1;
  c2_block *pcVar2;
  c2_block *pcVar3;
  c2_block *pcVar4;
  c2_block *pcVar5;
  c2_bitset *pcVar6;
  c2_cse_expr *pcVar7;
  c2_edge *pcVar8;
  bool bVar9;
  c2_bitset *pcVar10;
  uint32_t uVar11;
  uint32_t uVar12;
  c2_symbol *pcVar13;
  int iVar14;
  c2_operand *pcVar15;
  
  globopt_init_expr_tables();
  arena_reset(0xd);
  arena_reset(6);
  arena_reset(3);
  g_compare_alias_tags = 1;
  globopt_reset_symbol_state(fn);
  g_flowgraph_dirty = 0;
  g_need_extra_dce = 0;
  g_touched_temp_list = (c2_symbol *)0xffffffff;
  g_globopt_phase = 0;
  globopt_fold_all_blocks(fn);
  if (g_flowgraph_dirty != 0) {
    rebuild_flow_graph(fn,0);
  }
  globopt_canonicalize_tuples(fn);
  coalesce_temp_copies(fn);
  alloc_block_dataflow_sets(fn,1);
  globopt_dead_code_elim(fn);
  forward_propagate_definitions(fn);
  if (g_flowgraph_dirty != 0) {
    rebuild_flow_graph(fn,0);
  }
  alloc_block_dataflow_sets(fn,5);
  globopt_dead_code_elim(fn);
  if (fn->loops != (c2_loop *)0x0) {
    clear_invariant_operand_marks(fn);
    compute_loop_invariants(fn);
    reassociate_invariant_adds(fn);
    clear_invariant_operand_marks(fn);
  }
  assign_expression_owners(fn);
  insert_branch_value_facts(fn);
  init_list_node_pool();
  g_globopt_phase = 1;
  g_cse_full_mode = 0;
  g_cse_fold_compares = 0;
  g_fold_flag_f120 = 1;
  g_propagate_temp_copies = 1;
  g_jump_threading_enabled = 1;
  pcVar3 = fn->cfg->first;
  while (pcVar3 != (c2_block *)0x0) {
    pcVar1 = pcVar3->loop;
    pcVar2 = pcVar3->next;
    if ((pcVar1 != (c2_loop *)0x0) && (pcVar4 = pcVar1->first, pcVar4 == pcVar3)) {
      pcVar5 = pcVar1->last;
      check_loop_optimizable(pcVar1);
      if ((pcVar1->flags & 1) == 0) {
        if ((g_cse_full_mode == 0) ||
           (g_opt_loop < ((int)pcVar1->last->rpo - (int)pcVar1->first->rpo) + 1)) {
          pcVar10 = bitset_new(4);
          pcVar6 = pcVar1->invariant_syms;
          uVar11 = bitset_iter_next(pcVar1->first->prev->set54);
          while (uVar11 != 0xffffffff) {
            pcVar13 = symbol_by_id(uVar11);
            pcVar7 = (pcVar13->u18).expr;
            uVar12 = pcVar7->op;
            if ((uVar12 == 0x15b) || (iVar14 = is_compare_branch_op(uVar12), iVar14 != 0)) {
              pcVar15 = pcVar7->operands;
              bVar9 = true;
              if (pcVar15 != (c2_operand *)0x0) {
                do {
                  switch(pcVar15->kind) {
                  case '\x01':
                  case '\x02':
                    uVar12 = bitset_test(pcVar6,pcVar15->sym->id);
                    if (uVar12 == 0) goto switchD_10729430_caseD_6;
                    break;
                  case '\x03':
                  case '\x04':
                  case '\x05':
                  case '\a':
                  case '\b':
                  case '\t':
                    break;
                  default:
switchD_10729430_caseD_6:
                    bVar9 = false;
                  }
                  pcVar15 = pcVar15->next;
                } while (pcVar15 != (c2_operand *)0x0);
                if (!bVar9) goto LAB_107293df;
              }
              bitset_set(pcVar10,uVar11);
            }
LAB_107293df:
            uVar11 = bitset_iter_next((c2_bitset *)0x0);
          }
          if (pcVar10->chunks != (c2_bitset_chunk *)0x0) {
            for (pcVar8 = pcVar1->first->preds; pcVar8 != (c2_edge *)0x0; pcVar8 = pcVar8->next_pred
                ) {
              bitset_or(pcVar8->from->set54,pcVar10);
            }
          }
          bitset_free(pcVar10);
        }
        else {
          solve_avail_dataflow_range(pcVar4,pcVar5);
        }
      }
    }
    cse_block(pcVar3,fn);
    pcVar3 = pcVar2;
  }
  reset_list_node_pool();
  g_jump_threading_enabled = 0;
  g_cse_fold_compares = 0;
  delete_status1_fact_tuples(fn);
  if (g_flowgraph_dirty != 0) {
    rebuild_flow_graph(fn,1);
  }
  alloc_block_dataflow_sets(fn,5);
  globopt_dead_code_elim(fn);
  if (fn->loops != (c2_loop *)0x0) {
    g_need_extra_dce = 1;
    globopt_restore_temp_destinations(fn);
    g_need_extra_dce = 0;
    clear_invariant_operand_marks(fn);
    compute_loop_invariants(fn);
    reassociate_invariant_adds(fn);
    clear_invariant_operand_marks(fn);
    rehash_after_reassociation(fn);
  }
  insert_branch_value_facts(fn);
  solve_avail_dataflow_range(fn->cfg->first,fn->cfg->last);
  g_globopt_phase = 2;
  g_cse_full_mode = 0;
  g_propagate_temp_copies = 1;
  g_fold_flag_f120 = 0;
  g_loop_kill_set = sparse_set_alloc_default();
  g_loop_live_out_syms = sparse_set_alloc_default();
  g_hoisted_exprs = sparse_set_alloc_default();
  globopt_loop_phase_init();
  for (pcVar1 = fn->loops; pcVar1 != (c2_loop *)0x0; pcVar1 = pcVar1->next) {
    optimize_loop_nest(pcVar1,fn);
  }
  globopt_loop_phase_free();
  g_globopt_phase = 3;
  insert_branch_value_facts_late(fn);
  lower_eh_copy_markers(fn);
  solve_avail_dataflow_range(fn->cfg->first,fn->cfg->last);
  init_list_node_pool();
  g_propagate_temp_copies = 0;
  g_cse_full_mode = 1;
  g_fold_flag_f120 = 1;
  g_jump_threading_enabled = 1;
  pcVar3 = fn->cfg->first;
  do {
    pcVar2 = pcVar3;
    if (pcVar2 == (c2_block *)0x0) {
      if (g_flowgraph_dirty != 0) {
        rebuild_flow_graph(fn,0);
      }
      reset_list_node_pool();
      delete_status1_fact_tuples(fn);
      delete_status2_fact_tuples(fn);
      alloc_block_dataflow_sets(fn,1);
      globopt_dead_code_elim(fn);
      if (g_flowgraph_dirty != 0) {
        rebuild_flow_graph(fn,0);
        alloc_block_dataflow_sets(fn,1);
      }
      if (g_need_extra_dce != 0) {
        alloc_block_dataflow_sets(fn,1);
        globopt_dead_code_elim(fn);
        if (g_flowgraph_dirty != 0) {
          rebuild_flow_graph(fn,0);
          alloc_block_dataflow_sets(fn,1);
        }
      }
      globopt_restore_temp_destinations(fn);
      globopt_fold_adjacent_copies(fn);
      globopt_finalize_tuples(fn);
      arena_reset(0xd);
      arena_reset(6);
      arena_reset(3);
      g_compare_alias_tags = 0;
      iVar14 = globopt_free_expr_tables();
      return iVar14;
    }
    pcVar1 = pcVar2->loop;
    pcVar3 = pcVar2->next;
    if ((pcVar1 != (c2_loop *)0x0) && (pcVar4 = pcVar1->first, pcVar4 == pcVar2)) {
      pcVar5 = pcVar1->last;
      check_loop_optimizable(pcVar1);
      if ((pcVar1->flags & 1) == 0) {
        if ((g_cse_full_mode == 0) ||
           (g_opt_loop < ((int)pcVar1->last->rpo - (int)pcVar1->first->rpo) + 1)) {
          pcVar10 = bitset_new(4);
          pcVar6 = pcVar1->invariant_syms;
          uVar11 = bitset_iter_next(pcVar1->first->prev->set54);
          while (uVar11 != 0xffffffff) {
            pcVar13 = symbol_by_id(uVar11);
            pcVar7 = (pcVar13->u18).expr;
            uVar12 = pcVar7->op;
            if ((uVar12 == 0x15b) || (iVar14 = is_compare_branch_op(uVar12), iVar14 != 0)) {
              pcVar15 = pcVar7->operands;
              bVar9 = true;
              if (pcVar15 != (c2_operand *)0x0) {
                do {
                  switch(pcVar15->kind) {
                  case '\x01':
                  case '\x02':
                    uVar12 = bitset_test(pcVar6,pcVar15->sym->id);
                    if (uVar12 == 0) goto switchD_10729716_caseD_6;
                    break;
                  case '\x03':
                  case '\x04':
                  case '\x05':
                  case '\a':
                  case '\b':
                  case '\t':
                    break;
                  default:
switchD_10729716_caseD_6:
                    bVar9 = false;
                  }
                  pcVar15 = pcVar15->next;
                } while (pcVar15 != (c2_operand *)0x0);
                if (!bVar9) goto LAB_107296c5;
              }
              bitset_set(pcVar10,uVar11);
            }
LAB_107296c5:
            uVar11 = bitset_iter_next((c2_bitset *)0x0);
          }
          if (pcVar10->chunks != (c2_bitset_chunk *)0x0) {
            for (pcVar8 = pcVar1->first->preds; pcVar8 != (c2_edge *)0x0; pcVar8 = pcVar8->next_pred
                ) {
              bitset_or(pcVar8->from->set54,pcVar10);
            }
          }
          bitset_free(pcVar10);
        }
        else {
          solve_avail_dataflow_range(pcVar4,pcVar5);
        }
      }
    }
    cse_block(pcVar2,fn);
    pcVar1 = pcVar2->loop;
    if ((pcVar1 != (c2_loop *)0x0) && (pcVar1->last == pcVar2)) {
      limit_loop_exit_availability(pcVar1);
    }
  } while( true );
}

