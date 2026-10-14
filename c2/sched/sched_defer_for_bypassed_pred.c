int __fastcall sched_defer_for_bypassed_pred(c2_sched_node *n,int cycle)

{
  c2_sched_edge *pcVar1;
  c2_sched_node *pcVar2;
  
  if ((n->npred != 0) && (g_sched_cpu_index != 3)) {
    for (pcVar1 = n->preds; pcVar1 != (c2_sched_edge *)0x0; pcVar1 = pcVar1->next_pred) {
      if ((((0xf < (pcVar1->soft & 0x1f)) && (pcVar2 = pcVar1->from, (pcVar2->sflags & 4) == 0)) &&
          (pcVar2->npred == pcVar2->soft_preds)) && ((uint)pcVar2->earliest <= cycle + 1U)) {
        return 1;
      }
    }
  }
  return 0;
}

