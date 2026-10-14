uint pp_cond_stack_push(void)

{
  uint n;
  
  g_pp_cond_depth = g_pp_cond_depth + 1;
  if (g_pp_cond_capacity <= (uint)g_pp_cond_depth) {
    if (g_pp_cond_capacity == 0) {
      g_pp_cond_capacity = 0x20;
      g_pp_cond_states = mem_xmalloc(0x80);
      return g_pp_cond_depth;
    }
    n = g_pp_cond_capacity << 3;
    g_pp_cond_capacity = g_pp_cond_capacity * 2;
    g_pp_cond_states = mem_xrealloc(g_pp_cond_states,n);
  }
  return g_pp_cond_depth;
}

