void __fastcall rebuild_flow_graph(c2_function *fn,int renumber)

{
  c2_tuple *t;
  
  arena_reset(6);
  cfg_rebuild(fn);
  cfg_reanalyze(fn,0);
  if (renumber != 0) {
    for (t = fn->cfg->first->head; t != (c2_tuple *)0x0; t = t->next) {
      if (t->op == 0x15b) {
        number_assignment(t,0);
      }
      else if (t->op == 0x17d) {
        number_compare_expression(t);
      }
    }
  }
  g_flowgraph_dirty = 0;
  return;
}

