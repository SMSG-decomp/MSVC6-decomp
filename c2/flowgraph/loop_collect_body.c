void __fastcall loop_collect_body(c2_loop *loop,c2_block *block)

{
  c2_edge *pcVar1;
  
  if ((block->loop != loop) && (block != loop->first->prev)) {
    pcVar1 = block->preds;
    block->loop = loop;
    for (; pcVar1 != (c2_edge *)0x0; pcVar1 = pcVar1->next_pred) {
      loop_collect_body(loop,pcVar1->from);
    }
  }
  return;
}

