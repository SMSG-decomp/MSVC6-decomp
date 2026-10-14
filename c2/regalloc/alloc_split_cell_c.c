c2_split_uf_cell * alloc_split_cell_c(void)

{
  c2_split_uf_cell *pcVar1;
  
  pcVar1 = g_split_uf_cell_free;
  if (g_split_uf_cell_free != (c2_split_uf_cell *)0x0) {
    g_split_uf_cell_free->parent = (c2_split_uf_cell *)0x0;
    g_split_uf_cell_free = g_split_uf_cell_free->next;
    return pcVar1;
  }
  pcVar1 = arena_alloc(4,0xc);
  return pcVar1;
}

