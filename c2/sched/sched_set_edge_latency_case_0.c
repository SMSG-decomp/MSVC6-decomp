void sched_set_edge_latency_case_0
               (c2_sched_edge *edge,c2_symbol *producer,int latency,c2_symbol *consumer)

{
  int iVar1;
  int iVar2;
  
  iVar1 = sched_agi_penalty(edge,consumer);
  iVar2 = sched_extra_latency_for_order(producer,consumer);
  iVar2 = latency + iVar1 + iVar2;
  if (edge->from->tuple->op != 0x162) {
    if ((int)(uint)edge->latency < iVar2) {
      edge->latency = (uint16_t)iVar2;
    }
    return;
  }
  edge->latency = 0;
  return;
}

