void __thiscall import_depgraph_add_edge(c1_import_depgraph *graph,int from,int to)

{
  int iVar1;
  c1_import_edge *pcVar2;
  c1_import_edge *edge_cell;
  c1_import_edge *edge_cell_2;
  c1_import_edge *edge_cell_3;
  
  if (graph->emitted[from] == '\0') {
    iVar1 = graph->unmet[to];
    if ((iVar1 != 0) && (graph->dependents[from] != 0)) {
      for (edge_cell = graph->edges; edge_cell != (c1_import_edge *)0x0; edge_cell = edge_cell->next
          ) {
        if ((edge_cell->from == from) && (edge_cell->to == to)) {
          return;
        }
      }
    }
    graph->unmet[to] = iVar1 + 1;
    graph->dependents[from] = graph->dependents[from] + 1;
    pcVar2 = (c1_import_edge *)g_arenas[5].cur;
    edge_cell_2 = graph->free_edges;
    if (edge_cell_2 == (c1_import_edge *)0x0) {
      g_arenas[5].cur = g_arenas[5].cur + 0xc;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
    }
    else {
      graph->free_edges = edge_cell_2->next;
      pcVar2 = edge_cell_2;
    }
    edge_cell_3 = graph->edges;
    pcVar2->from = from;
    pcVar2->next = edge_cell_3;
    pcVar2->to = to;
    graph->edges = pcVar2;
  }
  return;
}

