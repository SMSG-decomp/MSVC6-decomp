int __fastcall schedule_instructions(c2_function *fn,int fp_mode)

{
  c2_tuple *pcVar1;
  c2_tuple *t;
  uint32_t uVar2;
  int iVar3;
  c2_function *pcVar4;
  
  uVar2 = sched_should_run(fn,fp_mode);
  iVar3 = 0;
  if (uVar2 != 0) {
    g_sched_fp_mode = fp_mode;
    g_sched_graph = sched_graph_alloc((c2_node_hook_fn *)0x0,(c2_edge_hook_fn *)0x0);
    sched_init_cpu_model(fn);
    if (fp_mode == 0) {
      sched_release_prologue_epilogue(fn);
    }
    pcVar1 = fn->cfg->first->head;
    uVar2 = pcVar1->op;
    while (uVar2 != 0x1b4) {
      pcVar1 = pcVar1->next;
      uVar2 = pcVar1->op;
    }
    t = pcVar1->next;
    uVar2 = t->op;
    pcVar4 = fn;
    while (g_sched_emit_tail = pcVar1, uVar2 != 0x1b1) {
      g_sched_window_start = t;
      g_sched_window_end = sched_region_end(t);
      t = g_sched_window_end->next;
      uVar2 = sched_window_worth_scheduling(g_sched_window_start,g_sched_window_end);
      pcVar1 = g_sched_window_start;
      if (uVar2 == 0) {
        g_sched_emit_tail->next = g_sched_window_start;
        pcVar1->prev = g_sched_emit_tail;
        g_sched_emit_tail = g_sched_window_end;
      }
      else {
        sched_graph_reset(g_sched_graph);
        pcVar1 = g_sched_emit_tail;
        if (fp_mode != 0) {
          sched_fp_prepare_window(g_sched_window_start,&g_sched_window_end->next);
          pcVar4 = (c2_function *)pcVar1;
        }
        sched_build_dependency_graph(g_sched_graph,g_sched_window_start,&g_sched_window_end->next);
        sched_compute_priorities(g_sched_graph);
        sched_list_schedule(g_sched_graph);
        if (fp_mode != 0) {
          g_sched_emit_tail->next = (c2_tuple *)0x0;
          sched_fp_assign_stack((c2_tuple *)pcVar4->fsym);
        }
      }
      pcVar1 = g_sched_emit_tail;
      uVar2 = t->op;
    }
    pcVar1->next = t;
    t->prev = pcVar1;
    if (fp_mode == 0) {
      sched_restore_prologue_markers(fn);
    }
    iVar3 = arena_reset(4);
  }
  return iVar3;
}

