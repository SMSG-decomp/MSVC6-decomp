c2_sched_edge * __fastcall sched_add_edge(c2_sched_node *from,c2_sched_node *to,uint32_t type)

{
  byte bVar1;
  c2_edge_hook_fn *pcVar2;
  c2_sched_edge *edge;
  
  edge = (c2_sched_edge *)cfg_edge_new((c2_cfg *)g_sched_dag,(c2_block *)from,(c2_block *)to);
  pcVar2 = g_sched_edge_hook;
  bVar1 = edge->soft;
  edge->type = type;
  from->nsucc = from->nsucc + 1;
  to->npred = to->npred + 1;
  edge->soft = bVar1 & 0xe0;
  edge->latency = 0;
  g_sched_edge_count = g_sched_edge_count + 1;
  if (pcVar2 != (c2_edge_hook_fn *)0x0) {
    (*pcVar2)(from,to,edge,type);
  }
  return edge;
}

