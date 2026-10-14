int __fastcall block_has_predecessor(c2_block *block,c2_block *pred)

{
  c2_edge *pcVar1;
  
  pcVar1 = block->preds;
  while( true ) {
    if (pcVar1 == (c2_edge *)0x0) {
      return 0;
    }
    if (pcVar1->from == pred) break;
    pcVar1 = pcVar1->next_pred;
  }
  return 1;
}

