void arena5_reset(void)

{
  arena_release_pages(g_arenas + 4);
  g_arenas[4].remaining = 0;
  g_arenas[4].pages = (c2_arena_page *)0x0;
  g_arenas[4].cursor = (char *)0x0;
  g_bitset_chunk_free_head[4] = (c2_bitset_chunk *)0x0;
  g_bitset_chunk_free_tail[4] = (c2_bitset_chunk *)0x0;
  g_bitset_free_head[4] = (c2_bitset *)0x0;
  g_bitset_free_tail[4] = (c2_bitset *)0x0;
  g_bitset_extra_free_head = (void *)0x0;
  g_bitset_extra_free_tail = (void *)0x0;
  return;
}

