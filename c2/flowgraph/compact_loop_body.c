int __fastcall compact_loop_body(c2_loop *loop,c2_function *fn)

{
  short sVar1;
  c2_block *pcVar2;
  c2_block *block;
  c2_block *block2;
  c2_block *block_00;
  int iVar3;
  int iVar4;
  c2_block *b;
  
  iVar4 = 0;
  if ((loop == (c2_loop *)0x0) || ((loop->flags & 8) != 0)) {
    return 0;
  }
  pcVar2 = loop->last;
  block = loop->first;
  do {
    if (block == pcVar2) {
      return iVar4;
    }
    iVar3 = loop_is_within(block->next->loop,loop);
    if (iVar3 == 0) {
      block2 = block->next;
      iVar4 = loop_is_within(block2->next->loop,loop);
      block_00 = block2;
      while (iVar4 == 0) {
        block_00 = block_00->next;
        iVar4 = loop_is_within(block_00->next->loop,loop);
      }
      cfg_link_block_after(block,block_00->next,fn);
      for (b = pcVar2->next; b != (c2_block *)0x0; b = b->next) {
        iVar4 = loop_is_within(b->loop,loop);
        if (iVar4 == 0) {
          sVar1 = block2->rpo;
          if ((sVar1 < b->rpo) ||
             ((b->rpo < 0 && (iVar4 = block_first_numbered_index(b), sVar1 < iVar4)))) {
            if (b != (c2_block *)0x0) goto LAB_10743dce;
            break;
          }
        }
      }
      b = pcVar2->next;
LAB_10743dce:
      cfg_link_block_after(b->prev,block2,fn);
      cfg_link_block_after(block_00,b,fn);
      iVar4 = 1;
    }
    block = block->next;
  } while( true );
}

