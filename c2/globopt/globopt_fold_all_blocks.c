void __fastcall globopt_fold_all_blocks(c2_function *fn)

{
  c2_block *pcVar1;
  c2_block *block;
  
  pcVar1 = fn->cfg->first;
  while (block = pcVar1, block != (c2_block *)0x0) {
    pcVar1 = block->next;
    if ((block->flags & 0x2000000) == 0) {
      fold_block_tuples(block,fn);
    }
  }
  return;
}

