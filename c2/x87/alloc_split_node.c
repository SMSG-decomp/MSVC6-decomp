void * alloc_split_node(void)

{
  void *pvVar1;
  
  pvVar1 = g_split_node_free;
  if (g_split_node_free != (void *)0x0) {
    g_split_node_free = *(void **)g_split_node_free;
    return pvVar1;
  }
  pvVar1 = arena_alloc(4,0x14);
  return pvVar1;
}

