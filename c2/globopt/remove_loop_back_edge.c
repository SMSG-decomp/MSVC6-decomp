void __fastcall remove_loop_back_edge(c2_block *block,c2_block *to,c2_function *fn)

{
  c2_edge *pcVar1;
  int iVar2;
  c2_block *b;
  
  pcVar1 = flow_edge_find(block,to);
  cfg_remove_edge(fn,pcVar1);
  if ((to->preds == (c2_edge *)0x0) && (b = fn->cfg->first, b != (c2_block *)0x0)) {
    do {
      if (((b->flags & 0x2000000) == 0) &&
         ((iVar2 = bitvec_test(b->dominators,(int)to->rpo), iVar2 != 0 ||
          ((b->preds == (c2_edge *)0x0 && (b->prev != (c2_block *)0x0)))))) {
        b->flags = b->flags | 0x2000000;
        delete_block_tuples(b);
        pcVar1 = b->succs;
        while (pcVar1 != (c2_edge *)0x0) {
          cfg_remove_edge(fn,pcVar1);
          pcVar1 = b->succs;
        }
      }
      b = b->next;
    } while (b != (c2_block *)0x0);
    g_flowgraph_dirty = 1;
    return;
  }
  g_flowgraph_dirty = 1;
  return;
}

