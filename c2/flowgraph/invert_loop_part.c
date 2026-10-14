int invert_loop_part(c2_edge *edge,c2_block *new_test,c2_tuple *new_label,c2_function *fn,
                    c2_tuple *header_branch,c2_block *loop_first,c2_tuple *old_label,c2_loop *loop)

{
  c2_tuple *label;
  c2_loop *loop_00;
  c2_tuple *at;
  c2_block *block;
  uint32_t uVar1;
  int iVar2;
  c2_edge *edge_00;
  
  do {
    do {
      edge_00 = edge;
      if (edge_00 == (c2_edge *)0x0) {
        loop_set_latch(loop,new_test);
        label = *(c2_tuple **)((int)&header_branch->src->sym->u30 + 2);
        at = tuple_new_jmp_before(label,new_test->end);
        block = block_split_before(fn,new_test,at);
        loop_00 = loop->parent;
        block->loop = loop_00;
        if ((loop_00 != (c2_loop *)0x0) && (loop_00->last == new_test)) {
          loop_set_latch(loop_00,block);
        }
        cfg_add_edge(fn,new_test,block);
        cfg_add_edge(fn,block,(label->prev->u14).block);
        return 1;
      }
      edge = edge_00->next_pred;
    } while ((edge_00->from == new_test) || (edge_00->from == loop_first->prev));
    uVar1 = redirect_branch_edge(edge_00,new_label,old_label,fn);
  } while (uVar1 != 0);
  cfg_edge_redirect(edge_00,new_test,fn);
  iVar2 = invert_loop_part(edge,new_test,new_label,fn,header_branch,loop_first,old_label,loop);
  return iVar2;
}

