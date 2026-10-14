void __fastcall cfg_dfs_rpo(c2_function *fn)

{
  c2_cfg *pcVar1;
  c2_block *pcVar2;
  c2_block *pcVar3;
  c2_block *pcVar4;
  
  pcVar1 = fn->cfg;
  pcVar3 = pcVar1->first;
  pcVar1->rpo_first = (c2_block *)0x0;
  for (pcVar4 = pcVar3; pcVar4 != (c2_block *)0x0; pcVar4 = pcVar4->next) {
    pcVar4->flags = pcVar4->flags & 0xfffffffe;
  }
  pcVar3->rpo_next = (c2_block *)pcVar3->succs;
  pcVar3->rpo_prev = (c2_block *)0x0;
  pcVar3->flags = pcVar3->flags | 1;
LAB_10704100:
  do {
    pcVar4 = pcVar3->rpo_next;
    do {
      if (pcVar4 == (c2_block *)0x0) {
        pcVar4 = pcVar1->rpo_first;
        pcVar2 = pcVar3->rpo_prev;
        if (pcVar4 == (c2_block *)0x0) {
          pcVar1->rpo_last = pcVar3;
          pcVar3->rpo_next = (c2_block *)0x0;
        }
        else {
          pcVar4->rpo_prev = pcVar3;
          pcVar3->rpo_next = pcVar4;
        }
        pcVar1->rpo_first = pcVar3;
        pcVar3 = pcVar2;
        if (pcVar2 == (c2_block *)0x0) {
          return;
        }
        goto LAB_10704100;
      }
      pcVar2 = (c2_block *)pcVar4->succs;
      pcVar4 = pcVar4->next;
    } while ((pcVar2->flags & 1) != 0);
    pcVar3->rpo_next = pcVar4;
    pcVar2->rpo_prev = pcVar3;
    pcVar2->rpo_next = (c2_block *)pcVar2->succs;
    pcVar2->flags = pcVar2->flags | 1;
    pcVar3 = pcVar2;
  } while( true );
}

