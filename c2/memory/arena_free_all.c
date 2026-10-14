void arena_free_all(void)

{
  c2_arena *pcVar1;
  int iVar2;
  
  pcVar1 = g_arenas;
  iVar2 = 0;
  do {
    free_malloc_list((c2_link *)pcVar1->pages);
    pcVar1->remaining = 0;
    pcVar1->pages = (c2_arena_page *)0x0;
    pcVar1->cursor = (char *)0x0;
    *(undefined4 *)((int)g_bitset_chunk_free_head + iVar2) = 0;
    *(undefined4 *)((int)g_bitset_chunk_free_tail + iVar2) = 0;
    *(undefined4 *)((int)g_bitset_free_head + iVar2) = 0;
    *(undefined4 *)((int)g_bitset_free_tail + iVar2) = 0;
    pcVar1 = pcVar1 + 1;
    iVar2 = iVar2 + 4;
    g_bitset_extra_free_head = (void *)0x0;
    g_bitset_extra_free_tail = (void *)0x0;
  } while ((int)pcVar1 < 0x1079f5c0);
  free_malloc_list((c2_link *)g_arena_free_pages);
  g_arena_free_pages = (c2_arena_page *)0x0;
  return;
}

