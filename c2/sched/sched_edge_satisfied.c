void __fastcall sched_edge_satisfied(c2_sched_edge *sedge)

{
  uint16_t uVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  uint uVar4;
  uint uVar5;
  c2_sched_node *pcVar6;
  c2_sched_node *pcVar7;
  c2_sched_node *pcVar8;
  
  pcVar7 = sedge->to;
  uVar2 = pcVar7->npred;
  uVar3 = pcVar7->soft_preds;
  if ((sedge->soft & 0x1f) != 0) {
    pcVar7->soft_preds = uVar3 - 1;
  }
  uVar1 = uVar2 - 1;
  pcVar7->npred = uVar1;
  pcVar6 = g_sched_ready_tail;
  if ((uVar2 != uVar3) && (uVar1 == pcVar7->soft_preds)) {
    g_sched_ready_count = g_sched_ready_count + 1;
    if (g_sched_ready_head == (c2_sched_node *)0x0) {
      g_sched_ready_tail = pcVar7;
      g_sched_ready_head = pcVar7;
      pcVar7->ready_prev = (c2_sched_node *)0x0;
      pcVar7->ready_next = (c2_sched_node *)0x0;
      return;
    }
    uVar4 = pcVar7->priority;
    pcVar8 = g_sched_ready_head;
    while ((uVar5 = pcVar8->priority, uVar4 < uVar5 || uVar4 == uVar5 &&
           ((uVar4 != uVar5 || ((ushort)pcVar8->index <= (ushort)pcVar7->index))))) {
      pcVar8 = pcVar8->ready_next;
      if (pcVar8 == (c2_sched_node *)0x0) {
        pcVar8 = pcVar7;
        pcVar7->ready_prev = g_sched_ready_tail;
        g_sched_ready_tail = pcVar8;
        pcVar6->ready_next = pcVar7;
        pcVar7->ready_next = (c2_sched_node *)0x0;
        return;
      }
    }
    pcVar6 = pcVar8->ready_prev;
    pcVar7->ready_next = pcVar8;
    pcVar7->ready_prev = pcVar6;
    if (pcVar8->ready_prev == (c2_sched_node *)0x0) {
      g_sched_ready_head = pcVar7;
      pcVar8->ready_prev = pcVar7;
      return;
    }
    pcVar8->ready_prev->ready_next = pcVar7;
    pcVar8->ready_prev = pcVar7;
    return;
  }
  return;
}

