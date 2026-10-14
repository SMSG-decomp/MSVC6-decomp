void __fastcall sched_make_barrier(c2_sched_node *to)

{
  c2_sched_node *from;
  
  for (from = g_sched_last_barrier; from != (c2_sched_node *)0x0; from = from->next) {
    if ((from->succs == (c2_sched_edge *)0x0) && (from != to)) {
      sched_add_edge(from,to,0x80000);
    }
  }
  g_sched_last_barrier = to;
  to->sflags = to->sflags | 8;
  sched_free_access_lists();
  sched_free_mem_access_list(g_sched_load_list,g_sched_load_list_tail);
  g_sched_load_list_tail = (c2_sched_mem_access *)0x0;
  g_sched_load_list = (c2_sched_mem_access *)0x0;
  sched_free_mem_access_list(g_sched_store_list,g_sched_store_list_tail);
  g_sched_store_list_tail = (c2_sched_mem_access *)0x0;
  g_sched_store_list = (c2_sched_mem_access *)0x0;
  return;
}

