void __thiscall import_depgraph_mark_emitted(c1_import_depgraph *graph,int item)

{
  int iVar1;
  c1_import_edge *next_edge;
  c1_import_edge *prev_edge;
  c1_import_edge *edge;
  
  graph->emitted[item] = '\x01';
  if (item == graph->first_pending) {
    iVar1 = graph->first_pending + 1;
    graph->first_pending = iVar1;
    if (iVar1 < graph->n) {
      do {
        if (graph->emitted[iVar1] == '\0') break;
        iVar1 = iVar1 + 1;
        graph->first_pending = iVar1;
      } while (iVar1 < graph->n);
    }
  }
  if (graph->dependents[item] != 0) {
    next_edge = graph->edges;
    edge = (c1_import_edge *)&graph->edges;
    do {
      do {
        prev_edge = edge;
        edge = next_edge;
        if (edge == (c1_import_edge *)0x0) {
          return;
        }
        next_edge = edge->next;
      } while (edge->from != item);
      prev_edge->next = next_edge;
      edge->next = graph->free_edges;
      graph->free_edges = edge;
      graph->unmet[edge->to] = graph->unmet[edge->to] + -1;
      graph->dependents[item] = graph->dependents[item] + -1;
      edge = prev_edge;
    } while (graph->dependents[item] != 0);
  }
  return;
}

