int __fastcall loop_has_side_entry(c2_loop *loop)

{
  short sVar1;
  c2_loop_exit *pcVar2;
  c2_edge *pcVar3;
  
  pcVar2 = loop->exits;
  while( true ) {
    if (pcVar2 == (c2_loop_exit *)0x0) {
      return 0;
    }
    sVar1 = pcVar2->block->rpo;
    if (sVar1 < 0) break;
    for (pcVar3 = pcVar2->block->succs; pcVar3 != (c2_edge *)0x0; pcVar3 = pcVar3->next_succ) {
      if ((pcVar3->to->loop != loop) && (pcVar3->to->rpo < sVar1)) {
        return 1;
      }
    }
    pcVar2 = pcVar2->next;
  }
  return 1;
}

