void __fastcall sched_deps_on_prior_defs(c2_symbol *sym,c2_sched_node *n,uint32_t type)

{
  c2_sched_access *pcVar1;
  int iVar2;
  c2_sched_edge *edge;
  
  pcVar1 = g_sched_reg_def_list;
  do {
    if (pcVar1 == (c2_sched_access *)0x0) {
      return;
    }
    iVar2 = symbols_overlap(pcVar1->sym,sym);
    if (iVar2 != 0) {
      if (type == 1) {
        edge = sched_add_or_merge_edge(pcVar1->node,n,1);
        sched_set_edge_latency(edge,pcVar1->sym,sym);
      }
      else if (type == 4) {
        edge = sched_add_or_merge_edge(pcVar1->node,n,4);
        sched_set_output_dep_latency(sym,edge);
        if (sym->storage == g_reg_symbols + 0x42) goto LAB_1073afce;
      }
      else if (type == 0x20) {
        edge = sched_add_or_merge_edge(pcVar1->node,n,0x20);
        edge->latency = 1;
      }
      else {
        edge = sched_add_or_merge_edge(pcVar1->node,n,type);
      }
      sched_mark_call_arg_edge(edge);
      iVar2 = symbol_contains(pcVar1->sym,sym);
      if (iVar2 != 0) {
        return;
      }
    }
LAB_1073afce:
    pcVar1 = pcVar1->next;
  } while( true );
}

