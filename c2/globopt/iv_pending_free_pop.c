c2_tuple * iv_pending_free_pop(void)

{
  c2_tuple *local_4;
  
  g_iv_pending_free_list = list_node_pop(g_iv_pending_free_list,&local_4);
  return local_4;
}

