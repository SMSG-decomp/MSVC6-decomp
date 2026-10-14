int __fastcall loops_share_block(c2_loop *loop)

{
  c2_loop *pcVar1;
  c2_loop_exit *pcVar2;
  c2_loop_exit *pcVar3;
  
  pcVar1 = loop->parent;
  do {
    if (pcVar1 == (c2_loop *)0x0) {
      return 0;
    }
    pcVar3 = pcVar1->exits;
    if (pcVar3 != (c2_loop_exit *)0x0) {
      do {
        if (loop->exits != (c2_loop_exit *)0x0) {
          pcVar2 = loop->exits;
          do {
            if (pcVar3->block == pcVar2->block) {
              return 1;
            }
            pcVar2 = pcVar2->next;
          } while (pcVar2 != (c2_loop_exit *)0x0);
        }
        pcVar3 = pcVar3->next;
      } while (pcVar3 != (c2_loop_exit *)0x0);
    }
    pcVar1 = pcVar1->parent;
  } while( true );
}

