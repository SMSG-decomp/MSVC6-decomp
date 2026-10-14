c2_sched_edge * __fastcall cfg_edge_remove(int list,c2_sched_edge *edge)

{
  c2_sched_edge *pcVar1;
  c2_sched_edge *pcVar2;
  c2_sched_edge **ppcVar3;
  
  pcVar2 = (c2_sched_edge *)&edge->from->succs;
  for (pcVar1 = *(c2_sched_edge **)pcVar2; (pcVar1 != (c2_sched_edge *)0x0 && (pcVar1 != edge));
      pcVar1 = pcVar1->next_succ) {
    pcVar2 = pcVar1;
  }
  pcVar2->next_succ = edge->next_succ;
  ppcVar3 = &edge->to->preds;
  for (pcVar2 = *ppcVar3; (pcVar2 != (c2_sched_edge *)0x0 && (pcVar2 != edge));
      pcVar2 = pcVar2->next_pred) {
    ppcVar3 = &pcVar2->next_pred;
  }
  *ppcVar3 = edge->next_pred;
  pcVar2 = *(c2_sched_edge **)(list + 0x20);
  edge->next_succ = pcVar2;
  *(c2_sched_edge **)(list + 0x20) = edge;
  return pcVar2;
}

