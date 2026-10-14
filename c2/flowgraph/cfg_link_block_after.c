void __fastcall cfg_link_block_after(c2_block *block,c2_block *block2,c2_function *fn)

{
  c2_block *old_succ;
  c2_tuple *pcVar1;
  c2_tuple *at;
  int iVar2;
  
  old_succ = block->next;
  if (old_succ == block2) {
    if (block2 != (c2_block *)0x0) {
      block2->prev = block;
    }
  }
  else {
    block->next = block2;
    at = block_last_tuple_before_boundary(block);
    if (block2 != (c2_block *)0x0) {
      pcVar1 = block2->head;
      block2->prev = block;
      block->end = pcVar1;
      at->next = pcVar1;
      pcVar1->prev = at;
    }
    iVar2 = cfg_repair_fallthrough(block,old_succ,at,fn);
    if ((iVar2 != 0) && (block->loop != (c2_loop *)0x0)) {
      iVar2 = loop_is_within(old_succ->loop,block->loop);
      if (iVar2 == 0) {
        invert_branch_after_repair(block,fn);
        return;
      }
    }
  }
  return;
}

