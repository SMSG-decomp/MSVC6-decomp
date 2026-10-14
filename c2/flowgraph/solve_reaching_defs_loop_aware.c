void __fastcall solve_reaching_defs_loop_aware(c2_block *first,int loop_aware)

{
  c2_block *pcVar1;
  c2_edge *pcVar2;
  c2_loop *pcVar3;
  bool bVar4;
  c2_bitset *pcVar5;
  int iVar6;
  c2_block *pcVar7;
  
  for (pcVar1 = first; pcVar1 != (c2_block *)0x0; pcVar1 = pcVar1->next) {
    pcVar5 = bitset_new(6);
    (pcVar1->avail_in).set = pcVar5;
    pcVar5 = bitset_clone(pcVar1->de);
    (pcVar1->avail_out).set = pcVar5;
  }
  pcVar5 = bitset_new(6);
  pcVar1 = first->next;
  do {
    bVar4 = false;
    pcVar7 = pcVar1;
    if (pcVar1 == (c2_block *)0x0) break;
    do {
      bitset_clear_all(pcVar5);
      for (pcVar2 = pcVar7->preds; pcVar2 != (c2_edge *)0x0; pcVar2 = pcVar2->next_pred) {
        if (loop_aware == 0) {
LAB_10767e14:
          bitset_or(pcVar5,(pcVar2->from->avail_out).set);
        }
        else {
          pcVar3 = pcVar7->loop;
          if (((pcVar3 == (c2_loop *)0x0) || ((pcVar3->flags & 1) != 0)) ||
             (pcVar3->last != pcVar2->from)) {
            pcVar3 = pcVar2->from->loop;
            if (((pcVar3 != (c2_loop *)0x0) && ((pcVar3->flags & 1) == 0)) &&
               (iVar6 = loop_is_within(pcVar2->to->loop,pcVar3), iVar6 == 0)) {
              bitset_or(pcVar5,(pcVar3->last->avail_out).set);
            }
            goto LAB_10767e14;
          }
        }
      }
      bitset_and(pcVar5,pcVar7->live_in);
      iVar6 = bitset_equal(pcVar5,(pcVar7->avail_in).set);
      if (iVar6 == 0) {
        bitset_copy((pcVar7->avail_in).set,pcVar5);
        bitset_assign_or((pcVar7->avail_out).set,pcVar5,pcVar7->de);
        bVar4 = true;
      }
      pcVar7 = pcVar7->next;
    } while (pcVar7 != (c2_block *)0x0);
  } while (bVar4);
  bitset_free(pcVar5);
  return;
}

