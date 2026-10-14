c2_block * __fastcall find_loop_top_block(c2_block *b)

{
  c2_block *pcVar1;
  uint32_t uVar2;
  c2_block *pcVar3;
  
  pcVar1 = block_lowest_rpo_pred_or_self(b);
  if (b != pcVar1) {
    do {
      uVar2 = block_has_back_edge(b);
      if (uVar2 != 0) {
        pcVar3 = block_lowest_rpo_pred_or_self(b);
        if (pcVar3->rpo < pcVar1->rpo) {
          pcVar1 = pcVar3;
        }
      }
      b = b->prev;
    } while (b != pcVar1);
  }
  return pcVar1;
}

