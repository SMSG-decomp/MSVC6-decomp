void __fastcall sched_ready_remove(c2_sched_node *snode)

{
  c2_sched_node *pcVar1;
  c2_sched_node *pcVar2;
  
  g_sched_ready_count = g_sched_ready_count + -1;
  pcVar1 = snode->ready_next;
  pcVar2 = pcVar1;
  if (g_sched_ready_head != snode) {
    snode->ready_prev->ready_next = pcVar1;
    pcVar2 = g_sched_ready_head;
  }
  g_sched_ready_head = pcVar2;
  if (g_sched_ready_tail != snode) {
    pcVar1->ready_prev = snode->ready_prev;
    snode->ready_prev = (c2_sched_node *)0x0;
    snode->ready_next = (c2_sched_node *)0x0;
    return;
  }
  g_sched_ready_tail = snode->ready_prev;
  snode->ready_prev = (c2_sched_node *)0x0;
  snode->ready_next = (c2_sched_node *)0x0;
  return;
}

