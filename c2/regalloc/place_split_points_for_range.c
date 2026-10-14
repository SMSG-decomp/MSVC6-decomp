void __fastcall place_split_points_for_range(c2_live_range *range,c2_bitset *regs)

{
  c2_edge *pcVar1;
  c2_tuple *pcVar2;
  int *piVar3;
  c2_block *pcVar4;
  c2_bitset *dst;
  int iVar5;
  uint32_t uVar6;
  int *piVar7;
  uint32_t uVar8;
  c2_bitset *pcVar9;
  int *piVar10;
  int *n;
  c2_block *pcVar11;
  c2_edge *pcVar12;
  c2_bitset *local_18;
  
  pcVar9 = (c2_bitset *)0x0;
  local_18 = (c2_bitset *)0x0;
  dst = bitset_new(6);
  pcVar11 = range->first_block;
  do {
    uVar8 = bitset_test(pcVar11->live,range->id);
    if (uVar8 != 0) {
      if ((pcVar11->avail_out).set == (c2_bitset *)0x0) {
        local_18 = (c2_bitset *)((int)&pcVar9->chunks + 1);
        (pcVar11->avail_out).set = local_18;
        if ((pcVar11->avail_in).set == (c2_bitset *)0x0) {
          (pcVar11->avail_in).set = local_18;
          bitset_clear_all(dst);
        }
        else {
          bitset_copy(dst,regs);
        }
        iVar5 = scan_block_register_availability(range,pcVar11,dst,1,regs);
        if (iVar5 != 0) {
          uVar8 = range->id;
          uVar6 = bitset_test(pcVar11->live_out,uVar8);
          if (uVar6 != 0) {
            pcVar12 = pcVar11->succs;
            for (pcVar1 = pcVar12; pcVar1 != (c2_edge *)0x0; pcVar1 = pcVar1->next_succ) {
              if ((pcVar1->to->avail_in).set != (c2_bitset *)0x0) {
                if (pcVar1 != (c2_edge *)0x0) {
                  pcVar2 = pcVar11->end->prev;
                  if (pcVar2->kind == '\x1b') {
                    bitset_set((pcVar2->u14).regs,uVar8);
                    pcVar11->flags = pcVar11->flags | 0x40000;
                  }
                  else {
                    insert_split_marker_after(pcVar2,uVar8);
                    pcVar11->flags = pcVar11->flags | 0x40000;
                  }
                  goto LAB_1072584d;
                }
                break;
              }
            }
            piVar10 = (int *)0x0;
            if (pcVar12 != (c2_edge *)0x0) {
              do {
                pcVar4 = pcVar12->to;
                uVar6 = bitset_test(pcVar4->live_in,uVar8);
                piVar7 = piVar10;
                if (uVar6 != 0) {
                  piVar7 = alloc_split_node();
                  *piVar7 = (int)piVar10;
                  piVar7[2] = (int)pcVar4;
                  (pcVar4->avail_in).set = local_18;
                }
                pcVar12 = pcVar12->next_succ;
                piVar10 = piVar7;
              } while (pcVar12 != (c2_edge *)0x0);
              while ((piVar7 != (int *)0x0 &&
                     (piVar10 = (int *)0x0, n = piVar7, piVar7 != (int *)0x0))) {
                do {
                  pcVar4 = (c2_block *)n[2];
                  piVar3 = (int *)*n;
                  free_split_node(n);
                  iVar5 = scan_block_register_availability(range,pcVar4,dst,0,regs);
                  if (iVar5 != 0) {
                    uVar8 = range->id;
                    uVar6 = bitset_test(pcVar4->live_out,uVar8);
                    if (uVar6 != 0) {
                      pcVar12 = pcVar4->succs;
                      for (pcVar1 = pcVar12; pcVar1 != (c2_edge *)0x0; pcVar1 = pcVar1->next_succ) {
                        pcVar9 = (pcVar1->to->avail_in).set;
                        if ((pcVar9 != (c2_bitset *)0x0) && (pcVar9 != local_18)) {
                          if (pcVar1 != (c2_edge *)0x0) {
                            pcVar2 = pcVar4->end->prev;
                            if (pcVar2->kind == '\x1b') {
                              bitset_set((pcVar2->u14).regs,uVar8);
                            }
                            else {
                              insert_split_marker_after(pcVar2,uVar8);
                            }
                            pcVar4->flags = pcVar4->flags | 0x40000;
                            goto LAB_107257a3;
                          }
                          break;
                        }
                      }
                      for (; pcVar12 != (c2_edge *)0x0; pcVar12 = pcVar12->next_succ) {
                        pcVar4 = pcVar12->to;
                        piVar7 = piVar10;
                        if (((pcVar4->avail_in).set == (c2_bitset *)0x0) &&
                           (uVar6 = bitset_test(pcVar4->live_in,uVar8), uVar6 != 0)) {
                          piVar7 = alloc_split_node();
                          *piVar7 = (int)piVar10;
                          piVar7[2] = (int)pcVar4;
                          (pcVar4->avail_in).set = local_18;
                        }
                        piVar10 = piVar7;
                      }
                    }
                  }
LAB_107257a3:
                  n = piVar3;
                  piVar7 = piVar10;
                } while (piVar3 != (int *)0x0);
              }
            }
          }
        }
      }
LAB_1072584d:
      pcVar9 = local_18;
      if (pcVar11 == range->last_block) {
        bitset_free(dst);
        pcVar11 = range->first_block;
        pcVar4 = range->last_block;
        (pcVar11->avail_in).set = (c2_bitset *)0x0;
        (pcVar11->avail_out).set = (c2_bitset *)0x0;
        while (pcVar11 != pcVar4) {
          pcVar11 = pcVar11->next;
          (pcVar11->avail_in).set = (c2_bitset *)0x0;
          (pcVar11->avail_out).set = (c2_bitset *)0x0;
        }
        return;
      }
    }
    pcVar11 = pcVar11->next;
  } while( true );
}

