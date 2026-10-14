void __fastcall sched_add_reg_dep_edges(c2_symbol *reg,c2_sched_node *n,uint32_t type)

{
  c2_sched_access *pcVar1;
  int iVar2;
  c2_sched_edge *e;
  
  for (pcVar1 = g_sched_reg_use_list; pcVar1 != (c2_sched_access *)0x0; pcVar1 = pcVar1->next) {
    iVar2 = symbols_overlap(pcVar1->sym,reg);
    if (iVar2 != 0) {
      e = sched_add_or_merge_edge(pcVar1->node,n,type);
      sched_mark_call_arg_edge(e);
    }
  }
  return;
}

