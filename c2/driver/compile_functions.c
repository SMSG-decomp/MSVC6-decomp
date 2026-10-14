void compile_functions(void)

{
  bool bVar1;
  bool bVar2;
  c2_fe_symbol *pcVar3;
  uint16_t uVar4;
  c2_function *fn;
  c2_fe_symbol **ppcVar5;
  c2_incr_function_record *pcVar6;
  int iVar7;
  c2_fe_symbol *pcVar8;
  
  if (g_pdb_il_mode == 0) {
    g_exp_il_file = open_il_file(g_opt_il_path,"ex","rb","exp il");
    g_sym_il_file = open_il_file(g_opt_il_path,"sy","rb","sym il");
  }
  else {
    iVar7 = pdb_il_open_function_streams();
    if (iVar7 == 0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\main.c",0x297);
    }
    pcVar8 = g_function_list;
    if (g_opt_incremental != 0) {
      while (pcVar8 != (c2_fe_symbol *)0x0) {
        pcVar6 = arena_alloc(0,0x10);
        pcVar8->incr = pcVar6;
        uVar4 = pdb_il_module_version(pcVar8->id,pcVar8->sym_offset);
        pcVar8 = pcVar8->next_function;
        pcVar6->il_version = uVar4;
      }
    }
  }
  emit_object_prologue();
  if (g_opt_vol < 7) {
    g_inline_size_limit = 0x10 << ((byte)g_opt_vol & 0x1f);
  }
  else {
    g_inline_size_limit = 1000;
  }
  do {
    while( true ) {
      bVar2 = false;
      ppcVar5 = &g_function_list;
      pcVar8 = g_function_list;
      while( true ) {
        if (pcVar8 == (c2_fe_symbol *)0x0) {
          g_cur_func_sym = pcVar8;
          return;
        }
        if (((pcVar8->fn_flags & 0x20) != 0) && ((pcVar8->fn_flags & 2) == 0)) break;
        ppcVar5 = &pcVar8->next_function;
        pcVar8 = pcVar8->next_function;
      }
      g_cur_func_sym = pcVar8;
      pcVar8->fn_flags = pcVar8->fn_flags | 2;
      *ppcVar5 = pcVar8->next_function;
      bVar1 = bVar2;
      if (((g_opt_incremental != 0) &&
          (pcVar3 = pcVar8, pcVar8->next_function = g_incr_compiled_functions,
          g_incr_compiled_functions = pcVar3, g_coff_incremental_update != 0)) &&
         ((((pcVar8->fn_flags & 0x800) != 0 || (pcVar8->incr->sections == (c2_coff_fn_section *)0x0)
           ) || (iVar7 = incr_function_deps_changed(pcVar8), pcVar8 = g_cur_func_sym, bVar1 = true,
                iVar7 != 0)))) {
        pcVar6 = pcVar8->incr;
        pcVar6->symbol_deps = (c2_incr_id_cell *)0x0;
        pcVar6->callees = (c2_incr_id_cell *)0x0;
        bVar1 = bVar2;
      }
      if (pcVar8 == (c2_fe_symbol *)0x0) {
        return;
      }
      if (!bVar1) break;
      incr_function_prepare_data();
    }
    function_reset_state();
    g_backend_state = 2;
    abort_poll();
    fn = read_function_il(g_cur_func_sym);
    g_cur_line = 0;
    g_cur_function = fn;
    set_current_scope(fn->scope);
    if ((fn->flags & 0x800) != 0) {
      g_opt_global = 0;
    }
    g_eh_guard_local = (c2_symbol *)0x0;
    if ((fn->fsym->attrs & 0x1000) != 0) {
      abort_poll();
      seh_lower_try_regions(fn);
      g_cur_line = 0;
    }
    if (((fn->flags & 0x10000) != 0) || ((fn->fsym->fn_flags & 0x400) != 0)) {
      abort_poll();
      cxx_eh_begin_function(fn,0);
      cxx_eh_lower_scopes(fn);
      cxx_eh_merge_adjacent_try_blocks(fn);
      g_cur_line = 0;
    }
    if ((g_opt_global != 0) && ((fn->flags & 1) != 0)) {
      iVar7 = inline_asm_has_external_jumps(fn);
      if (iVar7 != 0) {
        g_opt_global = 0;
      }
      g_cur_line = 0;
    }
    abort_poll();
    inline_function_calls(fn);
    g_cur_line = 0;
    g_reading_function = fn;
    if ((fn->flags & 0x18000) == 0) {
      if ((((fn->fsym->attrs & 0x1000) != 0) && (g_opt_global != 0)) && (g_opt_basic == 0)) {
        seh_mark_try_region_memory_ops(fn);
      }
    }
    else {
      if (g_opt_eh_enabled != 0) {
        abort_poll();
        cxx_eh_number_states_if_needed(fn);
      }
      g_cur_line = 0;
      if ((fn->flags & 0x18000) != 0) {
        abort_poll();
        cxx_eh_lower_state_transitions(fn);
      }
    }
    g_cur_line = 0;
    if (g_opt_vb_float_checks != 0) {
      vb_insert_float_error_checks(fn);
    }
    g_cur_line = 0;
    if (g_opt_global == 0) {
      if (g_opt_dlp != 0) {
        abort_poll();
        dlp_instrument_function(fn);
      }
      g_cur_line = 0;
      if ((g_opt_cap != 0) || (g_opt_fastcap != 0)) {
        abort_poll();
        cap_instrument_function(fn);
      }
      g_cur_line = 0;
      if ((g_opt_basic == 0) &&
         (((fn->flags & 1) == 0 || (iVar7 = inline_asm_has_external_jumps(fn), iVar7 == 0)))) {
        abort_poll();
        coalesce_label_runs(fn);
        cfg_rebuild_basic_eh(fn);
        cfg_dfs_rpo(fn);
        mark_constant_branch_dead_edges(fn);
        warn_missing_return_value(fn);
        warn_uninitialized_locals(fn);
        cfg_reset_single_block(fn);
        goto LAB_1075856d;
      }
    }
    else {
      abort_poll();
      cfg_rebuild(fn);
      g_cur_line = 0;
      abort_poll();
      compute_alias_classes(fn);
      g_cur_line = 0;
      if ((g_opt_basic != 0) && ((fn->fsym->attrs & 0x1000) != 0)) {
        basic_function_pass(fn);
      }
      g_cur_line = 0;
      abort_poll();
      eliminate_tail_recursion(fn);
      g_cur_line = 0;
      abort_poll();
      optimize_flow_graph_initial(fn,1);
      g_cur_line = 0;
      abort_poll();
      optimize_expression_trees(fn,1);
      g_cur_line = 0;
      purge_unreferenced_temps(fn);
      abort_poll();
      cfg_dfs_rpo(fn);
      mark_constant_branch_dead_edges(fn);
      warn_missing_return_value(fn);
      if (g_opt_basic == 0) {
        warn_uninitialized_locals(fn);
      }
      g_cur_line = 0;
      abort_poll();
      globopt_run(fn);
      g_cur_line = 0;
      purge_unreferenced_temps(fn);
      g_cur_line = 0;
      abort_poll();
      optimize_expression_trees(fn,2);
      g_cur_line = 0;
      if (g_opt_dlp != 0) {
        abort_poll();
        dlp_instrument_function(fn);
      }
      g_cur_line = 0;
      if ((g_opt_cap != 0) || (g_opt_fastcap != 0)) {
        abort_poll();
        cap_instrument_function(fn);
      }
      g_cur_line = 0;
      abort_poll();
      pass_narrow_byte_lanes(fn);
      g_cur_line = 0;
      abort_poll();
      pass_mark_register_candidates(fn);
      g_cur_line = 0;
      abort_poll();
      pass_form_read_modify_write(fn);
      g_cur_line = 0;
      abort_poll();
      pass_sizeopt(fn);
      g_cur_line = 0;
      abort_poll();
      pass_remove_redundant_branches(fn);
      g_cur_line = 0;
      pass_if_convert(fn);
LAB_1075856d:
      g_cur_line = 0;
    }
    if ((fn->fsym->attrs & 0x1000) != 0) {
      seh_create_record_and_scopetable(fn);
      g_cur_line = 0;
    }
    if (g_opt_global != 0) {
      abort_poll();
      pass_strength_reduce_mul_div(fn);
      g_cur_line = 0;
    }
    abort_poll();
    pass_select_address_modes(fn);
    g_cur_line = 0;
    if (g_opt_global != 0) {
      abort_poll();
      pass_merge_return_tails(fn);
    }
    g_cur_line = 0;
    abort_poll();
    pass_lower_function(fn);
    g_cur_line = 0;
    assign_parameter_homes(fn);
    g_cur_line = 0;
    if (g_opt_global != 0) {
      abort_poll();
      pass_machine_peephole(fn);
      g_cur_line = 0;
      abort_poll();
      cfg_rebuild(fn);
      g_cur_line = 0;
      abort_poll();
      cfg_reanalyze(fn,1);
      g_cur_line = 0;
      abort_poll();
      duplicate_exit_block_into_predecessors(fn);
      g_cur_line = 0;
      abort_poll();
      build_live_ranges(fn);
      g_cur_line = 0;
      abort_poll();
      choose_frame_pointer_mode(fn);
      g_cur_line = 0;
      abort_poll();
      global_color_registers(fn);
    }
    g_cur_line = 0;
    abort_poll();
    local_color_registers(fn);
    g_cur_line = 0;
    if ((g_opt_global != 0) && (g_opt_favor_speed != 0)) {
      abort_poll();
      split_memory_operands_g5(fn);
    }
    g_cur_line = 0;
    abort_poll();
    stack_frame_layout_pass(fn);
    g_cur_line = 0;
    abort_poll();
    compute_frame_size(fn);
    g_cur_line = 0;
    if ((g_opt_basic != 0) && (g_opt_global != 0)) {
      vb_merge_entry_zero_stores(fn);
    }
    g_cur_line = 0;
    abort_poll();
    generate_prolog_epilog(fn);
    g_cur_line = 0;
    g_label_merge_class1 = 0;
    abort_poll();
    if (g_opt_global != 0) {
      cfg_reset_single_block(fn);
      g_cur_line = 0;
    }
    if ((fn->flags & 0x800) == 0) {
      jump_optimize(fn);
    }
    g_cur_line = 0;
    abort_poll();
    final_lowering_peepholes(fn);
    g_cur_line = 0;
    g_jumpopt_no_crossjump = 0;
    if ((fn->fsym->attrs & 0x1000) != 0) {
      seh_lower_local_unwinds(fn);
    }
    if (g_opt_global != 0) {
      abort_poll();
      jump_optimize(fn);
      g_cur_line = 0;
      abort_poll();
      block_mover(fn);
      g_cur_line = 0;
      abort_poll();
      coalesce_label_runs(fn);
      remove_dead_labels(fn);
      remove_unreachable_after_terminators(fn);
      g_cur_line = 0;
      if (g_opt_global != 0) {
        abort_poll();
        late_register_value_cse(fn);
        g_cur_line = 0;
        if ((((fn->fsym->attrs & 0x1000) == 0) &&
            (((fn->flags & 0x10000) == 0 || (g_opt_eh_enabled != 0)))) ||
           (g_opt_force_schedule != 0)) {
          abort_poll();
          schedule_instructions(fn,0);
        }
        g_cur_line = 0;
        if (g_opt_favor_speed != 0) {
          abort_poll();
          post_schedule_merge_moves(fn);
        }
        g_cur_line = 0;
        abort_poll();
        late_stack_temp_forwarding(fn);
        g_cur_line = 0;
      }
    }
    if ((fn->flags & 0x10) == 0) {
      g_esp_adjust_params = 0;
      if ((fn->flags & 0x600000) != 0) goto LAB_10758836;
      g_esp_adjust_locals = 0;
      if (g_opt_global != 0) {
        clear_frame_operand_adjustments(fn);
      }
    }
    else {
      g_esp_adjust_params = 1;
LAB_10758836:
      g_esp_adjust_locals = 1;
      abort_poll();
      compute_esp_depth_adjustments(fn);
      g_cur_line = 0;
    }
    abort_poll();
    lower_switch_pseudo_ops(fn);
    g_cur_line = 0;
    if (g_opt_penter_hook != 0) {
      abort_poll();
      insert_penter_call(fn);
    }
    g_cur_line = 0;
    abort_poll();
    emit_function(fn);
    g_cur_line = 0;
    abort_poll();
    function_cleanup();
  } while( true );
}

