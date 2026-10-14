void __thiscall set_loop_depth_and_exits(c2_loop *loop,int16_t depth)

{
  c2_edge *pcVar1;
  c2_loop_exit *pcVar2;
  int iVar3;
  c2_loop_exit *pcVar4;
  c2_block *pcVar5;
  
  if ((loop != (c2_loop *)0x0) && (pcVar5 = loop->first, pcVar5 != loop->last->next)) {
    do {
      if (pcVar5->loop == loop) {
        pcVar5->loop_depth = depth;
      }
      for (pcVar1 = pcVar5->succs; pcVar1 != (c2_edge *)0x0; pcVar1 = pcVar1->next_succ) {
        iVar3 = loop_is_within(pcVar1->to->loop,loop);
        if (iVar3 == 0) {
          pcVar4 = arena_alloc(0xc,0xc);
          pcVar2 = loop->exits;
          pcVar4->block = pcVar5;
          pcVar4->next = pcVar2;
          loop->exits = pcVar4;
          break;
        }
      }
      pcVar5 = pcVar5->next;
    } while (pcVar5 != loop->last->next);
  }
  return;
}

