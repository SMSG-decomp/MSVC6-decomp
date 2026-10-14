void __fastcall compute_dominators(c2_function *fn)

{
  c2_block *pcVar1;
  c2_edge *pcVar2;
  bool bVar3;
  c2_bitvec *vec;
  int iVar4;
  c2_block *pcVar5;
  
  pcVar1 = fn->cfg->first;
  vec = bitvec_new(0xf,g_block_count);
  do {
    bVar3 = false;
    pcVar5 = pcVar1->next;
    if (pcVar5 == (c2_block *)0x0) break;
    do {
      pcVar2 = pcVar5->preds;
      if (pcVar2 != (c2_edge *)0x0) {
        bitvec_copy(vec,pcVar2->from->dominators);
        for (pcVar2 = pcVar2->next_pred; pcVar2 != (c2_edge *)0x0; pcVar2 = pcVar2->next_pred) {
          bitvec_and(vec,pcVar2->from->dominators);
        }
        bitvec_set(vec,(int)pcVar5->rpo);
        iVar4 = bitvec_equal(vec,pcVar5->dominators);
        if (iVar4 == 0) {
          bitvec_copy(pcVar5->dominators,vec);
          bVar3 = true;
        }
      }
      pcVar5 = pcVar5->next;
    } while (pcVar5 != (c2_block *)0x0);
  } while (bVar3);
  bitset_header_free(vec);
  return;
}

