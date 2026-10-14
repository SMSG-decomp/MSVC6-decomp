c2_block * __fastcall block_lowest_rpo_pred_or_self(c2_block *b)

{
  short sVar1;
  c2_block *pcVar2;
  c2_edge *pcVar3;
  
  pcVar3 = b->succs;
  pcVar2 = (c2_block *)0x0;
  if (pcVar3 != (c2_edge *)0x0) {
    do {
      sVar1 = pcVar3->to->rpo;
      if ((sVar1 <= b->rpo) && ((pcVar2 == (c2_block *)0x0 || (sVar1 < pcVar2->rpo)))) {
        pcVar2 = pcVar3->to;
      }
      pcVar3 = pcVar3->next_succ;
    } while (pcVar3 != (c2_edge *)0x0);
  }
  return pcVar2;
}

