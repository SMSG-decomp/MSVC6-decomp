void reset_iv_worklists(void)

{
  g_iv_worklist = (c2_list_cell *)0x0;
  g_iv_retry_list = (c2_list_cell *)0x0;
  g_iv_pending_free_list = (c2_list_cell *)0x0;
  g_iv_unused_list = (c2_list_cell *)0x0;
  g_derived_iv_head = (c2_symbol *)0xffffffff;
  g_derived_iv_tail = (c2_symbol *)0xffffffff;
  return;
}

