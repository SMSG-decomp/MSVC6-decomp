void __fastcall find_loop_fp_candidates(c2_loop *loop,uint32_t n)

{
  c2_block *pcVar1;
  c2_loop_exit *pcVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  c2_loop *pcVar5;
  c2_bitset *dst;
  c2_bitset *dst_00;
  int iVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  c2_tuple *pcVar9;
  
  dst = bitset_new(6);
  do {
    if (loop == (c2_loop *)0x0) {
      bitset_free(dst);
      return;
    }
    dst_00 = bitset_new(6);
    loop->candidates = dst_00;
    bitset_set_range(dst_00,n);
    if ((((loop->flags & 1) == 0) && (iVar6 = loops_share_block(loop), iVar6 == 0)) &&
       (iVar6 = loop_has_side_entry(loop), iVar6 == 0)) {
      pcVar1 = loop->first;
      bitset_copy(dst,pcVar1->live_in);
      for (pcVar2 = loop->exits; pcVar2 != (c2_loop_exit *)0x0; pcVar2 = pcVar2->next) {
        bitset_and(dst,pcVar2->block->live_out);
      }
      bitset_andnot(dst_00,dst);
      if (pcVar1 == loop->last) {
        pcVar9 = pcVar1->head;
        pcVar3 = pcVar1->end;
        if (pcVar9 != pcVar3) {
          do {
            if ((((pcVar9->flags & 1) != 0) && (pcVar4 = pcVar9->dst, pcVar4 != (c2_operand *)0x0))
               && ((pcVar4->kind == '\x06' &&
                   ((pcVar4->op == 0x14c && (((pcVar4->base->u18).reg)->cls == '\x02')))))) {
              uVar7 = ((pcVar4->base->sym->u30).ra)->id;
              uVar8 = bitset_test(pcVar1->kill,uVar7);
              if ((uVar8 == 0) && (uVar7 = bitset_test(pcVar1->live_in,uVar7), uVar7 != 0)) break;
            }
            pcVar9 = pcVar9->next;
          } while (pcVar9 != pcVar3);
          if (pcVar9 != pcVar3) {
            pcVar5 = loop;
            (loop->u30).fp_loop_next = g_fp_loop_list;
            g_fp_loop_list = pcVar5;
          }
        }
      }
    }
    find_loop_fp_candidates(loop->inner,n);
    loop = loop->next;
  } while( true );
}

