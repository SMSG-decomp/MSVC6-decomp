void __fastcall cfg_remove_edge(c2_function *fn,c2_edge *edge)

{
  c2_cfg *pcVar1;
  c2_edge *pcVar2;
  c2_edge *pcVar3;
  c2_edge **ppcVar4;
  
  pcVar1 = fn->cfg;
  pcVar3 = (c2_edge *)&edge->from->succs;
  for (pcVar2 = *(c2_edge **)pcVar3; (pcVar2 != (c2_edge *)0x0 && (pcVar2 != edge));
      pcVar2 = pcVar2->next_succ) {
    pcVar3 = pcVar2;
  }
  pcVar3->next_succ = edge->next_succ;
  ppcVar4 = &edge->to->preds;
  for (pcVar3 = *ppcVar4; (pcVar3 != (c2_edge *)0x0 && (pcVar3 != edge)); pcVar3 = pcVar3->next_pred
      ) {
    ppcVar4 = &pcVar3->next_pred;
  }
  *ppcVar4 = edge->next_pred;
  edge->next_succ = pcVar1->free_edges;
  pcVar1->free_edges = edge;
  return;
}

