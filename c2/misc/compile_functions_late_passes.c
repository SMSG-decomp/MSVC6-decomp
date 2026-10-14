void compile_functions_late_passes(int one,int zero,c2_function *fn)

{
  c2_incr_function_record *pcVar1;
  c2_fe_symbol *pcVar2;
  c2_fe_symbol **ppcVar3;
  int iVar4;
  c2_fe_symbol *fs;
  int iVar5;
  int iVar6;
  uint16_t zero_line;
  
  do {
    zero_line = (uint16_t)zero;
    if (g_opt_force_schedule != zero) goto LAB_107587e2;
    while( true ) {
      if (g_opt_favor_speed != zero) {
        abort_poll();
        post_schedule_merge_moves(fn);
        g_cur_line = zero_line;
      }
      abort_poll();
      late_stack_temp_forwarding(fn);
      g_cur_line = zero_line;
      do {
        do {
          g_esp_adjust_params = one;
          if (((fn->flags & 0x10) == 0) && (g_esp_adjust_params = zero, (fn->flags & 0x600000) == 0)
             ) {
            g_esp_adjust_locals = zero;
            if (g_opt_global != zero) {
              clear_frame_operand_adjustments(fn);
            }
          }
          else {
            g_esp_adjust_locals = one;
            abort_poll();
            compute_esp_depth_adjustments(fn);
            g_cur_line = zero_line;
          }
          abort_poll();
          lower_switch_pseudo_ops(fn);
          if (g_opt_penter_hook != zero) {
            g_cur_line = zero_line;
            abort_poll();
            insert_penter_call(fn);
          }
          g_cur_line = zero_line;
          abort_poll();
          emit_function(fn);
          g_cur_line = zero_line;
          abort_poll();
          function_cleanup();
          while( true ) {
            iVar6 = 0;
            ppcVar3 = &g_function_list;
            fs = g_function_list;
            while( true ) {
              if (fs == (c2_fe_symbol *)zero) {
                g_cur_func_sym = fs;
                return;
              }
              if (((fs->fn_flags & 0x20) != 0) && ((fs->fn_flags & 2) == 0)) break;
              ppcVar3 = &fs->next_function;
              fs = fs->next_function;
            }
            g_cur_func_sym = fs;
            fs->fn_flags = fs->fn_flags | 2;
            *ppcVar3 = fs->next_function;
            iVar5 = iVar6;
            if (((g_opt_incremental != zero) &&
                (pcVar2 = fs, fs->next_function = g_incr_compiled_functions,
                g_incr_compiled_functions = pcVar2, g_coff_incremental_update != zero)) &&
               ((((fs->fn_flags & 0x800) != 0 || (fs->incr->sections == (c2_coff_fn_section *)zero))
                || (iVar4 = incr_function_deps_changed(fs), fs = g_cur_func_sym, iVar5 = one,
                   iVar4 != 0)))) {
              pcVar1 = fs->incr;
              pcVar1->symbol_deps = (c2_incr_id_cell *)zero;
              pcVar1->callees = (c2_incr_id_cell *)zero;
              iVar5 = iVar6;
            }
            if (fs == (c2_fe_symbol *)zero) {
              return;
            }
            if (iVar5 == zero) break;
            incr_function_prepare_data();
          }
          function_reset_state();
          g_backend_state = 2;
          abort_poll();
          fn = read_function_il(g_cur_func_sym);
          g_cur_line = zero_line;
          g_cur_function = fn;
          set_current_scope(fn->scope);
          if ((fn->flags & 0x800) != 0) {
            g_opt_global = zero;
          }
          g_eh_guard_local = (c2_symbol *)zero;
          if ((fn->fsym->attrs & 0x1000) != 0) {
            abort_poll();
            seh_lower_try_regions(fn);
            g_cur_line = zero_line;
          }
          if (((fn->flags & 0x10000) != 0) || ((fn->fsym->fn_flags & 0x400) != 0)) {
            abort_poll();
            cxx_eh_begin_function(fn,0);
            cxx_eh_lower_scopes(fn);
            cxx_eh_merge_adjacent_try_blocks(fn);
            g_cur_line = zero_line;
          }
          if (((g_opt_global != zero) && ((byte)((byte)fn->flags & (byte)one) != 0)) &&
             (iVar6 = inline_asm_has_external_jumps(fn), g_cur_line = zero_line, iVar6 != 0)) {
            g_opt_global = zero;
          }
          abort_poll();
          inline_function_calls(fn);
          g_reading_function = fn;
          if ((fn->flags & 0x18000) == 0) {
            if ((((fn->fsym->attrs & 0x1000) != 0) && (g_opt_global != zero)) &&
               (g_opt_basic == zero)) {
              g_cur_line = zero_line;
              seh_mark_try_region_memory_ops(fn);
            }
          }
          else {
            if (g_opt_eh_enabled != zero) {
              g_cur_line = zero_line;
              abort_poll();
              cxx_eh_number_states_if_needed(fn);
            }
            if ((fn->flags & 0x18000) != 0) {
              g_cur_line = zero_line;
              abort_poll();
              cxx_eh_lower_state_transitions(fn);
            }
          }
          if (g_opt_vb_float_checks != zero) {
            g_cur_line = zero_line;
            vb_insert_float_error_checks(fn);
          }
          if (g_opt_global == zero) {
            if (g_opt_dlp != zero) {
              g_cur_line = zero_line;
              abort_poll();
              dlp_instrument_function(fn);
            }
            if ((g_opt_cap != zero) || (g_opt_fastcap != zero)) {
              g_cur_line = zero_line;
              abort_poll();
              cap_instrument_function(fn);
            }
            g_cur_line = zero_line;
            if ((g_opt_basic == zero) &&
               (((byte)((byte)fn->flags & (byte)one) == 0 ||
                (iVar6 = inline_asm_has_external_jumps(fn), iVar6 == 0)))) {
              abort_poll();
              coalesce_label_runs(fn);
              cfg_rebuild_basic_eh(fn);
              cfg_dfs_rpo(fn);
              mark_constant_branch_dead_edges(fn);
              warn_missing_return_value(fn);
              warn_uninitialized_locals(fn);
              cfg_reset_single_block(fn);
              g_cur_line = zero_line;
            }
          }
          else {
            g_cur_line = zero_line;
            abort_poll();
            cfg_rebuild(fn);
            g_cur_line = zero_line;
            abort_poll();
            compute_alias_classes(fn);
            if ((g_opt_basic != zero) && ((fn->fsym->attrs & 0x1000) != 0)) {
              g_cur_line = zero_line;
              basic_function_pass(fn);
            }
            g_cur_line = zero_line;
            abort_poll();
            eliminate_tail_recursion(fn);
            g_cur_line = zero_line;
            abort_poll();
            optimize_flow_graph_initial(fn,one);
            g_cur_line = zero_line;
            abort_poll();
            optimize_expression_trees(fn,one);
            g_cur_line = zero_line;
            purge_unreferenced_temps(fn);
            abort_poll();
            cfg_dfs_rpo(fn);
            mark_constant_branch_dead_edges(fn);
            warn_missing_return_value(fn);
            if (g_opt_basic == zero) {
              warn_uninitialized_locals(fn);
            }
            g_cur_line = zero_line;
            abort_poll();
            globopt_run(fn);
            g_cur_line = zero_line;
            purge_unreferenced_temps(fn);
            g_cur_line = zero_line;
            abort_poll();
            optimize_expression_trees(fn,2);
            if (g_opt_dlp != zero) {
              g_cur_line = zero_line;
              abort_poll();
              dlp_instrument_function(fn);
            }
            if ((g_opt_cap != zero) || (g_opt_fastcap != zero)) {
              g_cur_line = zero_line;
              abort_poll();
              cap_instrument_function(fn);
            }
            g_cur_line = zero_line;
            abort_poll();
            pass_narrow_byte_lanes(fn);
            g_cur_line = zero_line;
            abort_poll();
            pass_mark_register_candidates(fn);
            g_cur_line = zero_line;
            abort_poll();
            pass_form_read_modify_write(fn);
            g_cur_line = zero_line;
            abort_poll();
            pass_sizeopt(fn);
            g_cur_line = zero_line;
            abort_poll();
            pass_remove_redundant_branches(fn);
            g_cur_line = zero_line;
            pass_if_convert(fn);
            g_cur_line = zero_line;
          }
          if ((fn->fsym->attrs & 0x1000) != 0) {
            seh_create_record_and_scopetable(fn);
            g_cur_line = zero_line;
          }
          if (g_opt_global != zero) {
            abort_poll();
            pass_strength_reduce_mul_div(fn);
            g_cur_line = zero_line;
          }
          abort_poll();
          pass_select_address_modes(fn);
          if (g_opt_global != zero) {
            g_cur_line = zero_line;
            abort_poll();
            pass_merge_return_tails(fn);
          }
          g_cur_line = zero_line;
          abort_poll();
          pass_lower_function(fn);
          g_cur_line = zero_line;
          assign_parameter_homes(fn);
          if (g_opt_global != zero) {
            g_cur_line = zero_line;
            abort_poll();
            pass_machine_peephole(fn);
            g_cur_line = zero_line;
            abort_poll();
            cfg_rebuild(fn);
            g_cur_line = zero_line;
            abort_poll();
            cfg_reanalyze(fn,one);
            g_cur_line = zero_line;
            abort_poll();
            duplicate_exit_block_into_predecessors(fn);
            g_cur_line = zero_line;
            abort_poll();
            build_live_ranges(fn);
            g_cur_line = zero_line;
            abort_poll();
            choose_frame_pointer_mode(fn);
            g_cur_line = zero_line;
            abort_poll();
            global_color_registers(fn);
          }
          g_cur_line = zero_line;
          abort_poll();
          local_color_registers(fn);
          if ((g_opt_global != zero) && (g_opt_favor_speed != zero)) {
            g_cur_line = zero_line;
            abort_poll();
            split_memory_operands_g5(fn);
          }
          g_cur_line = zero_line;
          abort_poll();
          stack_frame_layout_pass(fn);
          g_cur_line = zero_line;
          abort_poll();
          compute_frame_size(fn);
          if ((g_opt_basic != zero) && (g_opt_global != zero)) {
            g_cur_line = zero_line;
            vb_merge_entry_zero_stores(fn);
          }
          g_cur_line = zero_line;
          abort_poll();
          generate_prolog_epilog(fn);
          g_label_merge_class1 = zero;
          g_cur_line = zero_line;
          abort_poll();
          if (g_opt_global != zero) {
            cfg_reset_single_block(fn);
            g_cur_line = zero_line;
          }
          if ((fn->flags & 0x800) == 0) {
            jump_optimize(fn);
          }
          g_cur_line = zero_line;
          abort_poll();
          final_lowering_peepholes(fn);
          g_jumpopt_no_crossjump = zero;
          g_cur_line = zero_line;
          if ((fn->fsym->attrs & 0x1000) != 0) {
            seh_lower_local_unwinds(fn);
          }
        } while (g_opt_global == zero);
        abort_poll();
        jump_optimize(fn);
        g_cur_line = zero_line;
        abort_poll();
        block_mover(fn);
        g_cur_line = zero_line;
        abort_poll();
        coalesce_label_runs(fn);
        remove_dead_labels(fn);
        remove_unreachable_after_terminators(fn);
        g_cur_line = zero_line;
      } while (g_opt_global == zero);
      abort_poll();
      late_register_value_cse(fn);
      g_cur_line = zero_line;
      if (((fn->fsym->attrs & 0x1000) != 0) ||
         (((fn->flags & 0x10000) != 0 && (g_opt_eh_enabled == zero)))) break;
LAB_107587e2:
      abort_poll();
      schedule_instructions(fn,0);
      g_cur_line = zero_line;
    }
  } while( true );
}

