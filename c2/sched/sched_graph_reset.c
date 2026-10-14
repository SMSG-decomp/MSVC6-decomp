void __fastcall sched_graph_reset(c2_sched_graph *graph)

{
  c2_sched_node *node;
  c2_sched_node *node_00;
  c2_sched_edge *edge;
  c2_sched_node *pcVar1;
  
  node = graph->first;
  node_00 = graph->last;
  for (pcVar1 = node_00; pcVar1 != node; pcVar1 = pcVar1->prev) {
    for (edge = pcVar1->preds; edge != (c2_sched_edge *)0x0; edge = edge->next_pred) {
      cfg_edge_remove((int)graph,edge);
    }
  }
  for (; node_00 != node; node_00 = node_00->prev) {
    sched_list_unlink_free(graph,node_00);
  }
  if (node != (c2_sched_node *)0x0) {
    sched_list_unlink_free(graph,node);
  }
  graph->first = (c2_sched_node *)0x0;
  graph->last = (c2_sched_node *)0x0;
  graph->x08 = 0;
  graph->x0c = 0;
  return;
}

