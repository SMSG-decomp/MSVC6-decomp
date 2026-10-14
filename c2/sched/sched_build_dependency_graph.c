void __fastcall sched_build_dependency_graph(c2_sched_graph *graph,c2_tuple *first,c2_tuple **end)

{
  uint8_t uVar1;
  ushort uVar2;
  c2_symbol *pcVar3;
  uint32_t uVar4;
  c2_operand *pcVar5;
  c2_sched_graph *pcVar6;
  int iVar7;
  c2_symbol_cell *pcVar8;
  c2_sched_node *pcVar9;
  int iVar10;
  c2_sched_edge *e;
  uint uVar11;
  
  sched_dag_reset_state(graph);
  g_sched_dag_entry_node = sched_new_node((c2_tuple *)0x0);
  g_sched_last_barrier = g_sched_dag_entry_node;
  g_sched_dag_entry_node->sflags = g_sched_dag_entry_node->sflags | 8;
  g_sched_dag_state_f178 = 0;
  if (first != *end) {
    do {
      uVar2 = first->line;
      if (uVar2 != 0) {
        g_current_line_abs = g_cur_function->line_base + (uint)uVar2;
        g_cur_line = uVar2;
      }
      pcVar9 = sched_new_node(first);
      switch(first->kind) {
      case '\x0f':
      case '\x11':
      case '\x13':
      case '\x14':
      case '\x15':
      case '\x17':
      case '\x18':
      case '\x19':
      case '\x1a':
switchD_1073aa53_caseD_0:
        sched_make_barrier(pcVar9);
        break;
      case '\x16':
        if (first->op != 0x1bc) goto switchD_1073aa53_caseD_0;
      }
      uVar4 = first->op;
      if (((uVar4 == 0x166) || (uVar4 == 0x9c)) || (uVar4 == 0xb2)) {
        sched_make_barrier(pcVar9);
      }
      else if ((first->flags & 1) != 0) {
        iVar10 = tuple_reads_sources(first);
        if (iVar10 != 0) {
          sched_add_source_deps(pcVar9,first);
        }
        sched_add_dest_deps(pcVar9,&first->next,end);
        if (first->kind == '\x0e') {
          sched_make_barrier(pcVar9);
        }
        uVar11 = 0;
        for (pcVar5 = first->src; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
          switch(pcVar5->kind) {
          case '\x01':
            if (((pcVar5->u18).reg)->cls == '\x02') goto switchD_1073aa53_caseD_2;
            sched_record_reg_use((pcVar5->u18).reg,pcVar9);
            break;
          case '\x02':
switchD_1073aa53_caseD_2:
            pcVar3 = pcVar5->sym;
            uVar1 = pcVar3->cls;
            uVar11 = uVar11 | (pcVar5->flags & 0x40) >> 6;
            if ((((uVar1 != '\x04') && (uVar1 != '\x05')) && (uVar1 != '\x03')) ||
               (((pcVar3->flags5 & 2) != 0 ||
                ((g_frame_offsets_assigned != 0 &&
                 (pcVar8 = stack_slot_aliased_symbols(pcVar3), pcVar8 != (c2_symbol_cell *)0x0))))))
            goto switchD_1073aa53_caseD_6;
            sched_record_reg_use(pcVar3,pcVar9);
            break;
          case '\x06':
switchD_1073aa53_caseD_6:
            uVar11 = uVar11 | (pcVar5->flags & 0x40) >> 6;
          case '\v':
            sched_record_memory_access(&g_sched_load_list,&g_sched_load_list_tail,pcVar5,pcVar9);
            break;
          case '\n':
            iVar10 = bitset_iter_next((c2_bitset *)pcVar5->sym);
            while (iVar10 != -1) {
              sched_record_reg_use(g_reg_symbols + iVar10,pcVar9);
              iVar10 = bitset_iter_next((c2_bitset *)0x0);
            }
          }
        }
        for (pcVar5 = first->dst; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
          switch(pcVar5->kind) {
          case '\x01':
            if (((pcVar5->u18).reg)->cls == '\x02') goto override_jmp_1073a8f4_case_1;
            sched_record_reg_def((pcVar5->u18).reg,pcVar9);
            break;
          case '\x02':
override_jmp_1073a8f4_case_1:
            pcVar3 = pcVar5->sym;
            uVar1 = pcVar3->cls;
            uVar11 = uVar11 | (pcVar5->flags & 0x40) >> 6;
            if (((((uVar1 != '\x04') && (uVar1 != '\x05')) && (uVar1 != '\x03')) ||
                ((pcVar3->flags5 & 2) != 0)) ||
               ((g_frame_offsets_assigned != 0 &&
                (pcVar8 = stack_slot_aliased_symbols(pcVar3), pcVar8 != (c2_symbol_cell *)0x0))))
            goto override_jmp_1073a8f4_case_3;
            sched_record_reg_def(pcVar3,pcVar9);
            break;
          case '\x06':
override_jmp_1073a8f4_case_3:
            uVar11 = uVar11 | (pcVar5->flags & 0x40) >> 6;
          case '\v':
            sched_record_memory_access(&g_sched_store_list,&g_sched_store_list_tail,pcVar5,pcVar9);
            break;
          case '\n':
            iVar10 = bitset_iter_next((c2_bitset *)pcVar5->sym);
            while (iVar10 != -1) {
              sched_record_reg_def(g_reg_symbols + iVar10,pcVar9);
              iVar10 = bitset_iter_next((c2_bitset *)0x0);
            }
          }
        }
        if (pcVar9->preds == (c2_sched_edge *)0x0) {
          e = sched_add_edge(g_sched_last_barrier,pcVar9,0x80000);
          sched_mark_call_arg_edge(e);
        }
        if (uVar11 != 0) {
          sched_make_barrier(pcVar9);
        }
      }
      first = first->next;
    } while (first != *end);
  }
  g_sched_dag_exit_node = sched_new_node((c2_tuple *)0x0);
  sched_make_barrier(g_sched_dag_exit_node);
  pcVar6 = g_sched_dag;
  pcVar9 = g_sched_dag_exit_node;
  g_sched_dag->first = g_sched_dag_entry_node;
  iVar10 = g_sched_node_count;
  pcVar6->last = pcVar9;
  iVar7 = g_sched_edge_count;
  pcVar6->node_count = iVar10;
  pcVar6->edge_count = iVar7;
  return;
}

