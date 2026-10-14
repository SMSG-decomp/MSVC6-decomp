void reset_list_node_pool(void)

{
  arena_reset(3);
  g_list_node_free = (c2_list_cell *)0xffffffff;
  return;
}

