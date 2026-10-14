void __fastcall sched_bypass_round_marker_edges(c2_sched_node *node,c2_symbol *value_parent)

{
  c2_sched_node *to;
  c2_sched_edge *pcVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  c2_sched_edge *pcVar4;
  
  pcVar1 = node->succs;
  while (pcVar4 = pcVar1, pcVar4 != (c2_sched_edge *)0x0) {
    to = pcVar4->to;
    pcVar1 = pcVar4->next_succ;
    pcVar2 = to->tuple;
    if (((((pcVar2 != (c2_tuple *)0x0) && (pcVar2->kind != '\x0e')) &&
         ((pcVar2->type & 0xf000) == 0x4000)) && (pcVar3 = pcVar2->src, pcVar3 != (c2_operand *)0x0)
        ) && (((pcVar3->kind != '\x01' || (value_parent != pcVar3->sym)) &&
              ((pcVar3 = pcVar3->next, pcVar3 == (c2_operand *)0x0 ||
               ((pcVar3->kind != '\x01' || (value_parent != pcVar3->sym)))))))) {
      sched_remove_edge(pcVar4);
      for (pcVar4 = node->preds; pcVar4 != (c2_sched_edge *)0x0; pcVar4 = pcVar4->next_pred) {
        sched_add_or_merge_edge(pcVar4->from,to,pcVar4->type);
      }
    }
  }
  return;
}

