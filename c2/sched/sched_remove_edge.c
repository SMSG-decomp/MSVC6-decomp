int32_t __fastcall sched_remove_edge(c2_sched_edge *edge)

{
  uint16_t *puVar1;
  byte bVar2;
  c2_sched_node *pcVar3;
  c2_sched_edge *pcVar4;
  
  bVar2 = edge->soft;
  puVar1 = &edge->from->nsucc;
  *puVar1 = *puVar1 - 1;
  pcVar3 = edge->to;
  puVar1 = &pcVar3->npred;
  *puVar1 = *puVar1 - 1;
  if ((bVar2 & 0x1f) != 0) {
    puVar1 = &pcVar3->soft_preds;
    *puVar1 = *puVar1 - 1;
  }
  pcVar4 = cfg_edge_remove((int)g_sched_dag,edge);
  g_sched_edge_count = g_sched_edge_count + -1;
  return (int32_t)pcVar4;
}

