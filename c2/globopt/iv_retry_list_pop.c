c2_tuple * iv_retry_list_pop(void)

{
  c2_tuple *local_4;
  
  g_iv_retry_list = list_node_pop(g_iv_retry_list,&local_4);
  return local_4;
}

