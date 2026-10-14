void reader_free_stack_and_reset(void)

{
  for (; g_reader_stack_cell_free != (c2_reader_cell *)0x0;
      g_reader_stack_cell_free = g_reader_stack_cell_free->next) {
    node_free((c2_node *)g_reader_stack_cell_free->head);
  }
  if (g_inlining_active != 0) {
    return;
  }
  arena_reset(4);
  return;
}

