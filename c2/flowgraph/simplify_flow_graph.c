int __fastcall simplify_flow_graph(c2_function *fn)

{
  c2_block *block;
  c2_tuple *t;
  int iVar1;
  uint32_t uVar2;
  int iVar3;
  c2_block *b;
  
  iVar3 = 0;
  b = fn->cfg->first->next;
  if (b == (c2_block *)0x0) {
    return 0;
  }
  do {
    while( true ) {
      block = b->next;
      iVar1 = remove_jump_to_next_block(b);
      if ((iVar1 == 0) && (uVar2 = invert_jcc_over_jmp(b,fn), uVar2 == 0)) break;
LAB_10705331:
      iVar3 = 1;
    }
    iVar1 = collapse_label_only_blocks(b,fn);
    if ((iVar1 != 0) ||
       ((t = b->head->next, t->kind == '\x1a' && (iVar1 = label_try_remove(t), iVar1 != 0)))) {
LAB_10705328:
      if (b->prev != (c2_block *)0x0) {
        b = b->prev;
      }
      goto LAB_10705331;
    }
    if (((block == (c2_block *)0x0) ||
        ((block->loop == (c2_loop *)0x0 || (block->loop->first != block)))) &&
       ((b->loop == (c2_loop *)0x0 || (b->loop->first != b)))) {
      if (b->head->next == b->end) {
        remove_block_redirect_preds(fn,b,block);
        goto LAB_10705328;
      }
      if ((((block != (c2_block *)0x0) && (b != fn->cfg->first)) && (block != fn->cfg->last)) &&
         (((block->head->next->kind != '\x1a' && (block->preds != (c2_edge *)0x0)) &&
          ((b == block->preds->from && (b->succs->next_succ == (c2_edge *)0x0)))))) {
        remove_block_redirect_preds(fn,b,block);
        iVar3 = 1;
      }
    }
    b = block;
    if (block == (c2_block *)0x0) {
      return iVar3;
    }
  } while( true );
}

