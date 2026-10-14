c2_sched_edge * __fastcall sched_find_soft_edge_to(c2_sched_node *n,c2_sched_node *to)

{
  c2_sched_edge *pcVar1;
  byte bVar2;
  
  if (g_sched_cpu_index != 3) {
    for (pcVar1 = n->succs; pcVar1 != (c2_sched_edge *)0x0; pcVar1 = pcVar1->next_succ) {
      if (pcVar1->to == to) {
        bVar2 = pcVar1->soft & 0x1f;
        if (bVar2 == 6) {
          return pcVar1;
        }
        if (bVar2 == 8) {
          return pcVar1;
        }
        if (bVar2 == 10) {
          return pcVar1;
        }
      }
    }
  }
  return (c2_sched_edge *)0x0;
}

