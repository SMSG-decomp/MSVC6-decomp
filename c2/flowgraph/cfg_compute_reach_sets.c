void __fastcall cfg_compute_reach_sets(c2_function *fn)

{
  c2_block *pcVar1;
  c2_bitvec *vec2;
  c2_edge *pcVar2;
  bool bVar3;
  c2_bitvec *pcVar4;
  int iVar5;
  c2_block *pcVar6;
  
  pcVar1 = fn->cfg->first;
  for (pcVar6 = pcVar1; pcVar6 != (c2_block *)0x0; pcVar6 = pcVar6->next) {
    pcVar4 = bitvec_new(4,g_block_count);
    pcVar6->x64 = (uint32_t)pcVar4;
    bitvec_set(pcVar4,(int)pcVar6->rpo);
  }
  pcVar4 = bitvec_new(4,g_block_count);
  do {
    bVar3 = false;
    pcVar6 = pcVar1;
    if (pcVar1 == (c2_block *)0x0) {
      return;
    }
    do {
      vec2 = (c2_bitvec *)pcVar6->x64;
      bitvec_copy(pcVar4,vec2);
      for (pcVar2 = pcVar6->preds; pcVar2 != (c2_edge *)0x0; pcVar2 = pcVar2->next_pred) {
        bitvec_or(pcVar4,(c2_bitvec *)pcVar2->from->x64);
      }
      iVar5 = bitvec_equal(pcVar4,vec2);
      if (iVar5 == 0) {
        bitvec_copy(vec2,pcVar4);
        bVar3 = true;
      }
      pcVar6 = pcVar6->next;
    } while (pcVar6 != (c2_block *)0x0);
  } while (bVar3);
  return;
}

