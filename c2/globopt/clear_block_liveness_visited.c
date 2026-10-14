void __fastcall clear_block_liveness_visited(c2_block *block,c2_block *block2)

{
  c2_block *pcVar1;
  
  pcVar1 = block->prev;
  for (; block2 != pcVar1; block2 = block2->prev) {
    block2->flags = block2->flags & 0xfbffffff;
  }
  return;
}

