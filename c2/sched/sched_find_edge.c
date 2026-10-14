c2_sched_edge * __fastcall sched_find_edge(c2_sched_node *from,c2_sched_node *to)

{
  c2_sched_edge *pcVar1;
  
  for (pcVar1 = to->preds; (pcVar1 != (c2_sched_edge *)0x0 && (pcVar1->from != from));
      pcVar1 = pcVar1->next_pred) {
  }
  return pcVar1;
}

