void init_iv_scratch_list(void)

{
  g_iv_scratch_list_head = tuple_new_block_boundary();
  g_iv_scratch_tail = tuple_new_block_boundary();
  g_iv_scratch_tail->prev = g_iv_scratch_list_head;
  g_iv_scratch_list_head->next = g_iv_scratch_tail;
  return;
}

