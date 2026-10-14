int __fastcall
reload_hoist_path_clear_rec(uint32_t n,c2_block *block,c2_block *stop,c2_bitset *visited)

{
  short sVar1;
  uint32_t uVar2;
  int iVar3;
  c2_edge *edge;
  c2_block *pred;
  
  edge = block->preds;
  do {
    if (edge == (c2_edge *)0x0) {
      return 1;
    }
    pred = edge->from;
    if (pred != stop) {
      sVar1 = pred->rpo;
      uVar2 = bitset_test(visited,(int)sVar1);
      if (uVar2 == 0) {
        uVar2 = bitset_test(pred->kill,n);
        if (uVar2 != 0) {
          return 0;
        }
        bitset_set(visited,(int)sVar1);
        iVar3 = reload_hoist_path_clear_rec(n,pred,stop,visited);
        if (iVar3 == 0) {
          return 0;
        }
      }
    }
    edge = edge->next_pred;
  } while( true );
}

