void __fastcall ra_trim_live_range_span(c2_live_range *lr)

{
  uint32_t n;
  c2_edge *pcVar1;
  c2_block *pcVar2;
  c2_edge *pcVar3;
  c2_block *pcVar4;
  uint32_t uVar5;
  int iVar6;
  c2_block *local_8;
  
  local_8 = lr->last_block;
  n = lr->id;
  if (local_8 != lr->first_block) {
    do {
      uVar5 = bitset_test(local_8->live_out,n);
      if (((uVar5 == 0) && (uVar5 = bitset_test(local_8->live_in,n), uVar5 != 0)) &&
         (iVar6 = ra_block_has_upward_exposed_use(local_8,lr), iVar6 == 0)) {
        bitset_clear(local_8->live_in,n);
        bitset_clear(local_8->live,n);
        for (pcVar1 = local_8->preds; pcVar1 != (c2_edge *)0x0; pcVar1 = pcVar1->next_pred) {
          pcVar2 = pcVar1->from;
          uVar5 = bitset_test(pcVar2->live_out,n);
          if (uVar5 != 0) {
            for (pcVar3 = pcVar2->succs; pcVar3 != (c2_edge *)0x0; pcVar3 = pcVar3->next_succ) {
              uVar5 = bitset_test(pcVar3->to->live_in,n);
              if (uVar5 != 0) {
                if (pcVar3 != (c2_edge *)0x0) goto LAB_1078eef4;
                break;
              }
            }
            bitset_clear(pcVar2->live_out,n);
            ra_flag_last_source_use_in_block(pcVar2,lr);
          }
LAB_1078eef4:
        }
      }
      local_8 = local_8->prev;
    } while (local_8 != lr->first_block);
  }
  pcVar2 = lr->last_block;
  pcVar4 = lr->first_block;
  while ((pcVar2 != pcVar4 && (uVar5 = bitset_test(pcVar2->live,n), uVar5 == 0))) {
    pcVar2 = pcVar2->prev;
  }
  lr->last_block = pcVar2;
  return;
}

