void __fastcall sched_list_unlink_free(c2_sched_graph *graph,c2_sched_node *node)

{
  c2_sched_node *pcVar1;
  
  pcVar1 = node->prev;
  if (pcVar1 == (c2_sched_node *)0x0) {
    graph->first = node->next;
  }
  else {
    pcVar1->next = node->next;
  }
  if (node->next == (c2_sched_node *)0x0) {
    graph->last = pcVar1;
    node->next = graph->free_nodes;
    graph->free_nodes = node;
    return;
  }
  node->next->prev = pcVar1;
  node->next = graph->free_nodes;
  graph->free_nodes = node;
  return;
}

