void __fastcall flow_edge_move_src(c2_edge *edge,c2_block *from,c2_function *fn)

{
  c2_block *to;
  uint32_t uVar1;
  c2_edge *pcVar2;
  
  to = edge->to;
  uVar1 = edge->flags;
  cfg_remove_edge(fn,edge);
  pcVar2 = cfg_add_edge(fn,from,to);
  pcVar2->flags = uVar1;
  return;
}

