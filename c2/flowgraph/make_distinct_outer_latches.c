c2_block * __fastcall make_distinct_outer_latches(c2_loop *loop,c2_function *fn)

{
  int16_t iVar1;
  c2_tuple *t2;
  c2_block *block;
  c2_edge *edge;
  int iVar2;
  c2_fe_symbol *label_sym;
  c2_tuple *pcVar3;
  c2_block *block_00;
  c2_block *pcVar4;
  c2_block *local_10;
  
  pcVar4 = loop->last;
  local_10 = pcVar4;
  if (loop == (c2_loop *)0x0) {
    return pcVar4;
  }
  do {
    if (loop->inner == (c2_loop *)0x0) {
      block_00 = loop->last;
    }
    else {
      block = make_distinct_outer_latches(loop->inner,fn);
      block_00 = loop->last;
      if ((block_00->rpo < block->rpo) || (block == block_00)) {
        edge = flow_edge_find(block_00,loop->first);
        iVar1 = block->rpo;
        iVar2 = cfg_repair_fallthrough(block,block->next,block->end->prev,fn);
        if (iVar2 != 0) {
          block = block->next;
          block->loop = loop;
        }
        label_sym = label_symbol_new();
        pcVar3 = tuple_new_label(label_sym);
        tuple_insert_before(block->next->head,pcVar3);
        block_00 = block_split_before(fn,block,pcVar3);
        t2 = loop->first->head->next;
        redirect_branch_edge(edge,pcVar3,t2,fn);
        pcVar3 = block_00->end;
        block_00->loop = loop;
        loop->last = block_00;
        block_00->rpo = iVar1;
        tuple_new_jmp_before(t2,pcVar3);
        cfg_add_edge(fn,block_00,loop->first);
        g_loop_latch_split_changed = 1;
        pcVar4 = local_10;
      }
    }
    if (pcVar4->rpo < block_00->rpo) {
      pcVar4 = block_00;
      local_10 = block_00;
    }
    loop = loop->next;
  } while (loop != (c2_loop *)0x0);
  return pcVar4;
}

