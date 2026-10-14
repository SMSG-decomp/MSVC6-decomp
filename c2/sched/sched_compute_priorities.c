void __fastcall sched_compute_priorities(c2_sched_graph *graph)

{
  uint8_t *puVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  c2_sched_node *entry;
  c2_sched_node *exit;
  c2_sched_node *pcVar6;
  c2_sched_edge *pcVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  uint32_t uVar11;
  uint32_t uVar12;
  uint uVar13;
  c2_sched_node *pcVar14;
  uint uVar15;
  
  entry = graph->first;
  exit = graph->last;
  sched_mark_branch_feeders(entry,exit);
  sched_fp_adjust_edges(entry,exit);
  pcVar14 = exit->prev;
  pcVar6 = entry->prev;
  exit->height = 0;
  if (pcVar14 != pcVar6) {
    do {
      uVar15 = 0;
      for (pcVar7 = pcVar14->succs; pcVar7 != (c2_sched_edge *)0x0; pcVar7 = pcVar7->next_succ) {
        uVar13 = (uint)(ushort)pcVar7->to->height + (uint)pcVar7->latency;
        if (uVar15 < uVar13) {
          uVar15 = uVar13;
        }
      }
      pcVar6 = entry->prev;
      pcVar14->height = (short)uVar15 + 1;
      pcVar14 = pcVar14->prev;
    } while (pcVar14 != pcVar6);
  }
  entry->pipe = entry->pipe | 0x40;
  for (pcVar14 = entry; pcVar14 != exit; pcVar14 = pcVar14->next) {
    if (g_sched_fp_mode == 0) {
      for (pcVar7 = pcVar14->succs; pcVar7 != (c2_sched_edge *)0x0; pcVar7 = pcVar7->next_succ) {
        sched_break_dep_by_displacement(pcVar7);
      }
    }
    if ((pcVar14 != entry) && (pcVar14->npred == pcVar14->soft_preds)) {
      sched_link_to_previous_barrier(pcVar14);
    }
    bVar3 = pcVar14->pipe;
    if (((bVar3 & 0x40) != 0) && (pcVar7 = pcVar14->succs, pcVar7 != (c2_sched_edge *)0x0)) {
      uVar5 = pcVar14->height;
      do {
        if ((uint)uVar5 == (ushort)pcVar7->to->height + 1 + (uint)pcVar7->latency) {
          puVar1 = &pcVar7->to->pipe;
          *puVar1 = *puVar1 | 0x40;
        }
        pcVar7 = pcVar7->next_succ;
      } while (pcVar7 != (c2_sched_edge *)0x0);
    }
    bVar4 = pcVar14->sflags;
    uVar8 = shift_signed(bVar3 >> 6 & 1,(int)g_sched_weights[3]);
    uVar9 = shift_signed((uint)(ushort)pcVar14->height,(int)g_sched_weights[1]);
    uVar10 = shift_signed((uint)pcVar14->nsucc,(int)g_sched_weights[2]);
    uVar11 = shift_signed(bVar4 & 1,(int)g_sched_weights[5]);
    uVar12 = shift_signed((uint)(bVar3 >> 7),(int)*g_sched_weights);
    iVar2 = uVar8 + uVar9 + uVar10 + uVar11 + uVar12;
    pcVar14->priority_static = iVar2;
    if ((pcVar14->tuple != (c2_tuple *)0x0) && ((pcVar14->tuple->type & 0xf000) == 0x4000)) {
      uVar8 = shift_signed(bVar4 >> 1 & 1,(int)g_sched_weights[6]);
      pcVar14->priority_static = uVar8 + iVar2;
    }
    pcVar14->priority = pcVar14->priority_static;
  }
  return;
}

