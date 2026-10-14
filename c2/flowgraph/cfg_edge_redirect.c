void __fastcall cfg_edge_redirect(c2_edge *edge,c2_block *to,c2_function *fn)

{
  c2_block *from;
  uint32_t uVar1;
  c2_edge *pcVar2;
  
  from = edge->from;
  uVar1 = edge->flags;
  cfg_remove_edge(fn,edge);
  pcVar2 = cfg_add_edge(fn,from,to);
  pcVar2->flags = uVar1;
  return;
}

