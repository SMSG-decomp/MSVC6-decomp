uint32_t __fastcall block_has_back_edge(c2_block *b)

{
  c2_edge *pcVar1;
  
  pcVar1 = b->succs;
  if (pcVar1 != (c2_edge *)0x0) {
    do {
      if (pcVar1->to->rpo <= b->rpo) {
        return 1;
      }
      pcVar1 = pcVar1->next_succ;
    } while (pcVar1 != (c2_edge *)0x0);
  }
  return 0;
}

