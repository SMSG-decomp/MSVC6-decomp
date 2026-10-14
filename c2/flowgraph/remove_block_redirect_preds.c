void __fastcall remove_block_redirect_preds(c2_function *fn,c2_block *b,c2_block *block)

{
  c2_edge *pcVar1;
  c2_loop *loop;
  c2_tuple *pcVar2;
  
  for (pcVar1 = b->preds; pcVar1 != (c2_edge *)0x0; pcVar1 = pcVar1->next_pred) {
    cfg_add_edge(fn,pcVar1->from,block);
  }
  loop = b->loop;
  if (loop != (c2_loop *)0x0) {
    if (loop->guard == b) {
      loop->guard = block;
    }
    if (loop->first == b) {
      loop->first = block;
    }
    if (loop->last == b) {
      loop_set_latch(loop,block);
    }
  }
  pcVar2 = b->head->next;
  if (pcVar2->kind == '\x1a') {
    (pcVar2->u14).block = block;
  }
  block_delete(fn,b);
  return;
}

