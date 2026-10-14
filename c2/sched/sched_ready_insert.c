void __fastcall sched_ready_insert(c2_sched_node *n)

{
  uint uVar1;
  uint uVar2;
  c2_sched_node *pcVar3;
  c2_sched_node *pcVar4;
  
  pcVar3 = g_sched_ready_tail;
  g_sched_ready_count = g_sched_ready_count + 1;
  if (g_sched_ready_head == (c2_sched_node *)0x0) {
    g_sched_ready_tail = n;
    g_sched_ready_head = n;
    n->ready_prev = (c2_sched_node *)0x0;
    n->ready_next = (c2_sched_node *)0x0;
    return;
  }
  uVar1 = n->priority;
  pcVar4 = g_sched_ready_head;
  while ((uVar2 = pcVar4->priority, uVar1 < uVar2 || uVar1 == uVar2 &&
         ((uVar1 != uVar2 || ((ushort)pcVar4->index <= (ushort)n->index))))) {
    pcVar4 = pcVar4->ready_next;
    if (pcVar4 == (c2_sched_node *)0x0) {
      pcVar4 = n;
      n->ready_prev = g_sched_ready_tail;
      g_sched_ready_tail = pcVar4;
      pcVar3->ready_next = n;
      n->ready_next = (c2_sched_node *)0x0;
      return;
    }
  }
  pcVar3 = pcVar4->ready_prev;
  n->ready_next = pcVar4;
  n->ready_prev = pcVar3;
  if (pcVar4->ready_prev == (c2_sched_node *)0x0) {
    g_sched_ready_head = n;
    pcVar4->ready_prev = n;
    return;
  }
  pcVar4->ready_prev->ready_next = n;
  pcVar4->ready_prev = n;
  return;
}

