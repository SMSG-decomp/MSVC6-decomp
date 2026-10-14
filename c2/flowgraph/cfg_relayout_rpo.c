void __fastcall cfg_relayout_rpo(c2_function *fn)

{
  c2_cfg *pcVar1;
  c2_block *block2;
  c2_block *pcVar2;
  c2_tuple *pcVar3;
  c2_block *block2_00;
  c2_tuple *pcVar4;
  
  pcVar1 = fn->cfg;
  block2 = pcVar1->last;
  pcVar2 = pcVar1->rpo_last;
  pcVar1->first = (c2_block *)0x0;
  pcVar3 = block2->end;
  for (; pcVar2 != (c2_block *)0x0; pcVar2 = pcVar2->rpo_prev) {
    block2_00 = pcVar1->first;
    if (block2_00 == (c2_block *)0x0) {
      pcVar1->last = pcVar2;
    }
    pcVar1->first = pcVar2;
    cfg_link_block_after(pcVar2,block2_00,fn);
  }
  if (block2 != pcVar1->last) {
    pcVar2 = block2->prev;
    if ((pcVar2 != (c2_block *)0x0) && (pcVar2->next == block2)) {
      pcVar4 = block2->end->prev;
      cfg_link_block_after(pcVar2,block2->next,fn);
      block2->end = pcVar3;
      pcVar4->next = pcVar3;
      pcVar3->prev = pcVar4;
    }
    block2->next = (c2_block *)0x0;
    cfg_link_block_after(pcVar1->last,block2,fn);
    pcVar1->last = block2;
  }
  return;
}

