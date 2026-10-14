c2_block * __fastcall split_exit_edge_block(c2_function *fn,void *a,void *b,c2_block *to)

{
  c2_block *b_00;
  c2_tuple *at;
  c2_tuple *pcVar1;
  c2_block *pcVar2;
  c2_edge *edge;
  
  pcVar2 = split_edge_with_new_block(fn,a,b,to);
  b_00 = pcVar2->prev;
  at = b_00->end->prev;
  pcVar1 = at->prev;
  if ((pcVar1->kind == '\x11') &&
     (((pcVar1->u20).cond_cells != (c2_cond_cell *)0x0 || (pcVar1->op == 0x18b)))) {
    block_split_before(fn,b_00,at);
    edge = flow_edge_find(b_00,to);
    cfg_remove_edge(fn,edge);
    cfg_add_edge(fn,b_00,b_00->next);
    cfg_add_edge(fn,b_00->next,to);
  }
  return pcVar2;
}

