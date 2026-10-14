void * alloc_split_cell(void)

{
  void *pvVar1;
  
  pvVar1 = g_split_cell_free;
  if (g_split_cell_free != (void *)0x0) {
    g_split_cell_free = *(void **)g_split_cell_free;
    return pvVar1;
  }
  pvVar1 = arena_alloc(4,8);
  return pvVar1;
}

