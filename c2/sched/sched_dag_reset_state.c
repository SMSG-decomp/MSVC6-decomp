void __fastcall sched_dag_reset_state(c2_sched_graph *graph)

{
  g_sched_dag = graph;
  g_sched_reg_def_list = (c2_sched_access *)0x0;
  g_sched_dag_state_f174 = 0;
  g_sched_reg_use_list = (c2_sched_access *)0x0;
  g_sched_dag_state_f15c = 0;
  g_sched_node_seq = 0;
  g_sched_node_count = 0;
  g_sched_edge_count = 0;
  return;
}

