c2_sched_edge * __fastcall
sched_add_or_merge_edge(c2_sched_node *from,c2_sched_node *to,uint32_t type)

{
  c2_sched_edge *pcVar1;
  
  pcVar1 = sched_find_edge(from,to);
  if (pcVar1 == (c2_sched_edge *)0x0) {
    pcVar1 = sched_add_edge(from,to,type);
    return pcVar1;
  }
  pcVar1->type = pcVar1->type | type;
  return pcVar1;
}

