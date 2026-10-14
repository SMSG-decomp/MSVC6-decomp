void __fastcall liveness_extend_to_preds(c2_bitset *src,c2_block *block,c2_block *block2)

{
  c2_bitset *bs;
  
  bs = bitset_new(6);
  liveness_extend_to_preds_rec(src,block,(int)block2,bs);
  bitset_free(bs);
  return;
}

