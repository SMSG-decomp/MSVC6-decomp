uint32_t __fastcall block_blocks_loop_inversion(c2_block *block)

{
  c2_tuple *pcVar1;
  
  pcVar1 = block->head;
  while( true ) {
    if (pcVar1 == block->end) {
      return 0;
    }
    if (((pcVar1->kind == '\x12') && ((pcVar1->u20).intrinsic.id == 0xde)) ||
       (pcVar1->kind == '\x15')) break;
    pcVar1 = pcVar1->next;
  }
  return 1;
}

