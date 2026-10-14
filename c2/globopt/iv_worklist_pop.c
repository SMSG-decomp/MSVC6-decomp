c2_tuple * iv_worklist_pop(void)

{
  c2_tuple *local_4;
  
  g_iv_worklist = list_node_pop(g_iv_worklist,&local_4);
  return local_4;
}

