c2_coff_chunk * coff_alloc_chunk(void)

{
  c2_coff_chunk *pcVar1;
  
  pcVar1 = g_coff_chunk_free_list;
  if (g_coff_chunk_free_list == (c2_coff_chunk *)0x0) {
    pcVar1 = (*g_coff_alloc_fn)(0x1fc);
    return pcVar1;
  }
  g_coff_chunk_free_list = g_coff_chunk_free_list->next;
  return pcVar1;
}

