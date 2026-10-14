uint32_t __fastcall block_dominates_loop_exits(c2_block *block,c2_loop *loop)

{
  c2_loop_exit *pcVar1;
  int iVar2;
  
  pcVar1 = loop->exits;
  while( true ) {
    if (pcVar1 == (c2_loop_exit *)0x0) {
      return 1;
    }
    iVar2 = bitvec_test(pcVar1->block->dominators,(int)block->rpo);
    if (iVar2 == 0) break;
    pcVar1 = pcVar1->next;
  }
  return 0;
}

