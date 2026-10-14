int __fastcall arena_reset(int arena)

{
  arena_release_pages(g_arenas + arena);
  g_arenas[arena].remaining = 0;
  g_arenas[arena].pages = (c2_arena_page *)0x0;
  g_arenas[arena].cursor = (char *)0x0;
  g_bitset_chunk_free_head[arena] = (c2_bitset_chunk *)0x0;
  g_bitset_chunk_free_tail[arena] = (c2_bitset_chunk *)0x0;
  g_bitset_free_head[arena] = (c2_bitset *)0x0;
  g_bitset_free_tail[arena] = (c2_bitset *)0x0;
  g_bitset_extra_free_head = (void *)0x0;
  g_bitset_extra_free_tail = (void *)0x0;
  return 0;
}

