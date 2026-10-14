void __fastcall flow_edge_delete_to(c2_block *block,c2_block *to,c2_function *fn)

{
  c2_edge **ppcVar1;
  c2_edge *edge;
  
  edge = block->succs;
  if (block->succs != (c2_edge *)0x0) {
    while (ppcVar1 = &edge->next_succ, edge->to != to) {
      edge = *ppcVar1;
      if (*ppcVar1 == (c2_edge *)0x0) {
        return;
      }
    }
    cfg_remove_edge(fn,edge);
  }
  return;
}

