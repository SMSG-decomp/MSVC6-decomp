void sched_ready_resort(void)

{
  c2_sched_node *pcVar1;
  c2_sched_node *n;
  
  n = g_sched_ready_head;
  if (1 < g_sched_ready_count) {
    g_sched_ready_tail = (c2_sched_node *)0x0;
    g_sched_ready_head = (c2_sched_node *)0x0;
    g_sched_ready_count = 0;
    while (n != (c2_sched_node *)0x0) {
      pcVar1 = n->ready_next;
      sched_ready_insert(n);
      n = pcVar1;
    }
  }
  return;
}

