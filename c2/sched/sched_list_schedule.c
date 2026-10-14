void __fastcall sched_list_schedule(c2_sched_graph *graph)

{
  uint8_t *puVar1;
  c2_sched_edge *pcVar2;
  c2_sched_node *pcVar3;
  int iVar4;
  c2_sched_node *pcVar5;
  int iVar6;
  c2_sched_node **ppcVar7;
  
  g_sched_entry_node = graph->first;
  g_sched_exit_node = graph->last;
  g_sched_emitted_count = 0;
  g_sched_retired_count = 0;
  g_sched_last_picked = (c2_sched_node *)0x0;
  sched_reset_units();
  pcVar3 = g_sched_entry_node;
  pcVar5 = (c2_sched_node *)0x0;
  g_sched_ready_tail = (c2_sched_node *)0x0;
  g_sched_ready_head = (c2_sched_node *)0x0;
  g_sched_ready_count = 0;
  g_sched_entry_node->sflags = g_sched_entry_node->sflags | 4;
  for (pcVar2 = pcVar3->succs; pcVar2 != (c2_sched_edge *)0x0; pcVar2 = pcVar2->next_succ) {
    pcVar3 = pcVar2->to;
    pcVar3->npred = pcVar3->npred - 1;
    if (pcVar3->npred == pcVar3->soft_preds) {
      sched_ready_insert(pcVar3);
      pcVar5 = g_sched_ready_head;
    }
  }
  g_sched_cycle = 0;
  do {
    if ((pcVar5 == (c2_sched_node *)0x0) || (pcVar5 == g_sched_exit_node)) {
      return;
    }
    iVar4 = sched_select_cycle(g_sched_cycle);
    if (iVar4 < 2) {
LAB_1073c063:
      if (0 < iVar4) {
        ppcVar7 = g_sched_cycle_picks;
        do {
          pcVar5 = *ppcVar7;
          sched_emit_tuple(pcVar5->tuple);
          sched_occupy_unit(pcVar5);
          sched_fp_depth_update(pcVar5);
          ppcVar7 = ppcVar7 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
    }
    else if (0 < iVar4) {
      ppcVar7 = g_sched_cycle_picks;
      iVar6 = iVar4;
      do {
        pcVar5 = *ppcVar7;
        ppcVar7 = ppcVar7 + 1;
        puVar1 = &pcVar5->tuple->flags;
        *puVar1 = *puVar1 & 0xfb;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      goto LAB_1073c063;
    }
    g_sched_cycle = g_sched_cycle + 1;
    sched_advance_cycle();
    pcVar5 = g_sched_ready_head;
  } while( true );
}

