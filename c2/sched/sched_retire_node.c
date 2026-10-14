void __fastcall sched_retire_node(c2_sched_node *snode)

{
  c2_sched_edge *pcVar1;
  
  g_sched_retired_count = g_sched_retired_count + 1;
  if (snode->npred == snode->soft_preds) {
    sched_ready_remove(snode);
  }
  for (pcVar1 = snode->preds; pcVar1 != (c2_sched_edge *)0x0; pcVar1 = pcVar1->next_pred) {
    sched_remove_edge(pcVar1);
  }
  for (pcVar1 = snode->succs; pcVar1 != (c2_sched_edge *)0x0; pcVar1 = pcVar1->next_succ) {
    sched_edge_satisfied(pcVar1);
  }
  return;
}

