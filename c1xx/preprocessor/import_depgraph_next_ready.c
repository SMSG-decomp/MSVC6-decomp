int __fastcall import_depgraph_next_ready(void *graph)

{
  byte bVar1;
  int item;
  
  item = import_depgraph_first_pending(graph);
  if (item < *(int *)graph) {
    do {
      bVar1 = import_depgraph_is_ready(graph,item);
      if (bVar1 != 0) {
        return item;
      }
      item = item + 1;
    } while (item < *(int *)graph);
  }
  return *(int *)graph;
}

