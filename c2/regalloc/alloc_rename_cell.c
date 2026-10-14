void * alloc_rename_cell(void)

{
  void *pvVar1;
  
  pvVar1 = g_rename_cell_free;
  if (g_rename_cell_free == (void *)0x0) {
    pvVar1 = arena_alloc(4,8);
    return pvVar1;
  }
  g_rename_cell_free = *(void **)g_rename_cell_free;
  return pvVar1;
}

