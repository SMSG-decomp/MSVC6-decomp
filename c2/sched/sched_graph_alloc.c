c2_sched_graph * __fastcall sched_graph_alloc(c2_node_hook_fn *node_hook,c2_edge_hook_fn *edge_hook)

{
  c2_sched_graph *cfg;
  
  cfg = arena_alloc(4,0x38);
  cfg_init((c2_cfg *)cfg,4,0x3c,0x18);
  g_sched_edge_hook = edge_hook;
  g_sched_node_hook = node_hook;
  return cfg;
}

