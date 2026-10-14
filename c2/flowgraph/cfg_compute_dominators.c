void __fastcall cfg_compute_dominators(c2_function *fn)

{
  c2_block *pcVar1;
  c2_edge *pcVar2;
  bool bVar3;
  c2_bitvec *pcVar4;
  int iVar5;
  c2_block *pcVar6;
  
  pcVar1 = fn->cfg->first;
  pcVar4 = bitvec_new(0xf,g_block_count);
  pcVar1->dominators = pcVar4;
  bitvec_set(pcVar4,0);
  for (pcVar6 = pcVar1->next; pcVar6 != (c2_block *)0x0; pcVar6 = pcVar6->next) {
    pcVar4 = bitvec_new(0xf,g_block_count);
    pcVar6->dominators = pcVar4;
    bitvec_fill(pcVar4,g_block_count);
  }
  pcVar4 = bitvec_new(0xf,g_block_count);
  do {
    pcVar6 = pcVar1->next;
    bVar3 = false;
    if (pcVar6 == (c2_block *)0x0) break;
    do {
      pcVar2 = pcVar6->preds;
      if (pcVar2 != (c2_edge *)0x0) {
        bitvec_copy(pcVar4,pcVar2->from->dominators);
        for (pcVar2 = pcVar2->next_pred; pcVar2 != (c2_edge *)0x0; pcVar2 = pcVar2->next_pred) {
          bitvec_and(pcVar4,pcVar2->from->dominators);
        }
        bitvec_set(pcVar4,(int)pcVar6->rpo);
        iVar5 = bitvec_equal(pcVar4,pcVar6->dominators);
        if (iVar5 == 0) {
          bitvec_copy(pcVar6->dominators,pcVar4);
          bVar3 = true;
        }
      }
      pcVar6 = pcVar6->next;
    } while (pcVar6 != (c2_block *)0x0);
  } while (bVar3);
  bitset_header_free(pcVar4);
  return;
}

