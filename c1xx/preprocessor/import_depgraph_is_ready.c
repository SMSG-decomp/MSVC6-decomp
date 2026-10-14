byte __thiscall import_depgraph_is_ready(void *graph,int item)

{
  if ((*(char *)(*(int *)((int)graph + 8) + item) == '\0') &&
     (*(int *)(*(int *)((int)graph + 0xc) + item * 4) == 0)) {
    return 1;
  }
  return 0;
}

