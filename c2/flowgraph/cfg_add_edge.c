c2_edge * __fastcall cfg_add_edge(c2_function *fn,c2_block *from,c2_block *to)

{
  c2_edge *pcVar1;
  
  pcVar1 = cfg_edge_new(fn->cfg,from,to);
  pcVar1->flags = 0;
  return pcVar1;
}

