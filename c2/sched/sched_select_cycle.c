int __fastcall sched_select_cycle(int cycle)

{
  uint16_t uVar1;
  c2_sched_edge *edge;
  int16_t iVar2;
  int iVar3;
  uint uVar4;
  c2_sched_edge *pcVar5;
  uint uVar6;
  c2_sched_node *n;
  int local_c;
  c2_sched_node **local_8;
  
  sched_dynamic_priority(g_sched_ready_head,cycle);
  sched_ready_resort();
  local_c = 0;
  if (0 < g_sched_issue_width) {
    local_8 = g_sched_cycle_picks;
    while (n = g_sched_ready_head, g_sched_ready_head != (c2_sched_node *)0x0) {
      while( true ) {
        if (n == g_sched_exit_node) {
          return local_c;
        }
        iVar2 = (*g_sched_pick_unit_fn)(n,g_sched_cycle_picks,local_c);
        if ((((-1 < iVar2) && (iVar3 = sched_defer_for_bypassed_pred(n,cycle), iVar3 == 0)) &&
            ((g_opt_favor_speed == 0 ||
             (iVar3 = sched_fxch_hold(n,cycle,g_sched_ready_head,g_sched_emit_tail), iVar3 == 0))))
           && (uVar6 = (g_sched_units[iVar2].busy < 1) - 1 & g_sched_units[iVar2].busy,
              (uint)n->earliest <= cycle + uVar6)) break;
        n = n->ready_next;
        if (n == (c2_sched_node *)0x0) {
          return local_c;
        }
      }
      if (n == (c2_sched_node *)0x0) {
        return local_c;
      }
      sched_ready_remove(n);
      *local_8 = n;
      uVar1 = n->npred;
      n->pipe = (n->pipe ^ (byte)iVar2) & 7 ^ n->pipe;
      n->sflags = n->sflags | 4;
      if (uVar1 == 0) {
        if ((g_sched_last_picked != (c2_sched_node *)0x0) &&
           ((g_sched_last_picked->tuple->op == 0x12 &&
            (pcVar5 = sched_find_soft_edge_to(g_sched_last_picked,n), pcVar5 != (c2_sched_edge *)0x0
            )))) {
          g_sched_last_picked->nsucc = g_sched_last_picked->nsucc + 1;
          n->npred = n->npred + 1;
          n->soft_preds = n->soft_preds + 1;
          sched_adjust_memory_operand(pcVar5);
        }
      }
      else {
        pcVar5 = n->preds;
        do {
          edge = pcVar5;
          if (edge == (c2_sched_edge *)0x0) break;
          pcVar5 = edge->next_pred;
        } while (((edge->from->sflags & 4) != 0) || (sched_adjust_memory_operand(edge), uVar1 != 0))
        ;
      }
      for (pcVar5 = n->succs; pcVar5 != (c2_sched_edge *)0x0; pcVar5 = pcVar5->next_succ) {
        uVar4 = pcVar5->latency + uVar6 + cycle;
        if ((uint)pcVar5->to->earliest < uVar4) {
          pcVar5->to->earliest = uVar4;
        }
        sched_edge_satisfied(pcVar5);
      }
      local_c = local_c + 1;
      local_8 = local_8 + 1;
      g_sched_last_picked = n;
      if (g_sched_issue_width <= local_c) {
        return local_c;
      }
    }
  }
  return local_c;
}

