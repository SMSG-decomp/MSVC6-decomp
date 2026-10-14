void __thiscall import_depgraph_force_emit(c1_import_depgraph *graph,int item)

{
  c1_import_edge *edge;
  c1_import_edge *next_edge;
  c1_import_edge *prev_edge;
  
  next_edge = graph->edges;
  edge = (c1_import_edge *)&graph->edges;
  do {
    do {
      prev_edge = edge;
      edge = next_edge;
      if (edge == (c1_import_edge *)0x0) goto LAB_1049b402;
      next_edge = edge->next;
    } while (edge->to != item);
    prev_edge->next = next_edge;
    edge->next = graph->free_edges;
    graph->free_edges = edge;
    graph->dependents[edge->from] = graph->dependents[edge->from] + -1;
    graph->unmet[item] = graph->unmet[item] + -1;
    edge = prev_edge;
  } while (graph->unmet[item] != 0);
LAB_1049b402:
  import_depgraph_mark_emitted(graph,item);
  return;
}

