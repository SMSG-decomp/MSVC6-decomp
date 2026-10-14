c1_import_depgraph * __thiscall import_depgraph_init(c1_import_depgraph *graph,int n)

{
  c1_u8 *pcVar1;
  int iVar2;
  int iVar3;
  
  graph->n = n;
  graph->first_pending = 0;
  graph->edges = (c1_import_edge *)0x0;
  graph->free_edges = (c1_import_edge *)0x0;
  pcVar1 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + (n + 3U & 0xfffffffc);
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  graph->emitted = pcVar1;
  pcVar1 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + graph->n * 4;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  graph->unmet = (int *)pcVar1;
  pcVar1 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + graph->n * 4;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  graph->dependents = (int *)pcVar1;
  iVar2 = 0;
  if (0 < graph->n) {
    do {
      iVar3 = iVar2 + 1;
      graph->emitted[iVar2] = '\0';
      graph->unmet[iVar2] = 0;
      graph->dependents[iVar2] = 0;
      iVar2 = iVar3;
    } while (iVar3 < graph->n);
  }
  return graph;
}

