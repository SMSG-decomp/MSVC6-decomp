void __fastcall sched_fp_adjust_edges(c2_sched_node *first,c2_sched_node *end)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  c2_symbol *value_parent;
  c2_sched_node *to;
  c2_sched_edge *edge;
  
  if ((g_sched_fp_mode == 0) && (g_sched_fn_uses_fp != 0)) {
    for (; first != end; first = first->next) {
      pcVar1 = first->tuple;
      if (((((pcVar1 != (c2_tuple *)0x0) && ((pcVar1->flags & 1) != 0)) &&
           (pcVar2 = pcVar1->dst, pcVar2 != (c2_operand *)0x0)) &&
          (((pcVar2->type & 0xf000) == 0x4000 && (pcVar2->kind == '\x01')))) && (pcVar1->op != 0xe))
      {
        value_parent = pcVar2->sym->storage;
        if (pcVar1->op == 0x162) {
          sched_bypass_round_marker_edges(first,value_parent);
        }
        else {
          for (to = first->next; to != end; to = to->next) {
            pcVar1 = to->tuple;
            if (((pcVar1->type & 0xf000) == 0x4000) || (pcVar1->kind == '\x0e')) {
              for (pcVar2 = pcVar1->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
                if ((pcVar2->kind == '\x01') && (pcVar2->sym->storage == value_parent)) {
                  edge = sched_add_or_merge_edge(first,to,1);
                  sched_set_edge_latency(edge,value_parent,value_parent);
                  goto LAB_1073b9a4;
                }
              }
            }
          }
        }
      }
LAB_1073b9a4:
    }
  }
  return;
}

