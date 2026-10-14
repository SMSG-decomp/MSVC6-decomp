void init_list_node_pool(void)

{
  arena_reset(3);
  g_list_node_free = (c2_list_cell *)0x0;
  return;
}

