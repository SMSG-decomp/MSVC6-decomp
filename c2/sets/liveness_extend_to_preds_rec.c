void __fastcall
liveness_extend_to_preds_rec(c2_bitset *src,c2_block *block,int block2,c2_bitset *bs)

{
  short sVar1;
  c2_edge *pcVar2;
  c2_block *block_00;
  uint32_t uVar3;
  
  for (pcVar2 = block->preds; pcVar2 != (c2_edge *)0x0; pcVar2 = pcVar2->next_pred) {
    block_00 = pcVar2->from;
    if (block_00 != (c2_block *)block2) {
      sVar1 = block_00->rpo;
      uVar3 = bitset_test(bs,(int)sVar1);
      if (uVar3 == 0) {
        bitset_or(block_00->live_in,src);
        bitset_or(block_00->live_out,src);
        bitset_set(bs,(int)sVar1);
        liveness_extend_to_preds_rec(src,block_00,block2,bs);
      }
    }
  }
  return;
}

