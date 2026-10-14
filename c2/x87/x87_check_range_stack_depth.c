int __fastcall x87_check_range_stack_depth(c2_function *fn,c2_live_range *lr)

{
  c2_live_range **ppcVar1;
  ushort uVar2;
  uint32_t n;
  c2_block *pcVar3;
  c2_block *pcVar4;
  c2_edge *pcVar5;
  c2_edge *pcVar6;
  c2_block *pcVar7;
  c2_tuple *pcVar8;
  c2_live_range *pcVar9;
  c2_operand *pcVar10;
  c2_ra_split_block *pcVar11;
  uint32_t uVar12;
  c2_ra_split_block *new_node;
  c2_ra_split_block *pcVar13;
  c2_bitset *bs;
  int iVar14;
  int iVar15;
  c2_live_range **ppcVar16;
  int pred_top;
  c2_ra_split_block *worklist_head;
  c2_block *block;
  c2_block *pcVar17;
  c2_symbol **ppcVar18;
  c2_ra_split_block *worklist_tail;
  c2_live_range *stack [8];
  c2_operand *opnd;
  c2_live_range **pred_slots;
  c2_tuple *t;
  
  n = lr->id;
  pcVar3 = lr->first_block;
  pcVar4 = lr->last_block;
  worklist_tail = (c2_ra_split_block *)0x0;
  pcVar13 = (c2_ra_split_block *)0x0;
  pcVar17 = pcVar3;
  while( true ) {
    uVar12 = bitset_test(pcVar17->live_out,n);
    worklist_head = pcVar13;
    pcVar11 = worklist_tail;
    if (uVar12 != 0) {
      new_node = alloc_split_node();
      new_node->block = pcVar17;
      new_node->next = (c2_ra_split_block *)0x0;
      worklist_head = new_node;
      pcVar11 = new_node;
      if (worklist_tail != (c2_ra_split_block *)0x0) {
        worklist_tail->next = new_node;
        worklist_head = pcVar13;
        pcVar11 = new_node;
      }
    }
    worklist_tail = pcVar11;
    if (pcVar17 == pcVar4) break;
    pcVar17 = pcVar17->next;
    pcVar13 = worklist_head;
  }
  while (worklist_head != (c2_ra_split_block *)0x0) {
    pcVar17 = worklist_head->block;
    pcVar13 = worklist_head->next;
    free_split_node(worklist_head);
    uVar12 = bitset_test(pcVar17->live_in,n);
    pcVar5 = pcVar17->preds;
    worklist_head = pcVar13;
    if (uVar12 == 0) {
      if (pcVar5 == (c2_edge *)0x0) {
        ppcVar16 = stack;
        for (iVar14 = 8; iVar14 != 0; iVar14 = iVar14 + -1) {
          *ppcVar16 = (c2_live_range *)0x0;
          ppcVar16 = ppcVar16 + 1;
        }
      }
      else {
        iVar14 = 8;
        ppcVar18 = ((pcVar5->from->u58).x87_stack)->slot;
        ppcVar16 = stack;
        for (; iVar14 != 0; iVar14 = iVar14 + -1) {
          *ppcVar16 = (c2_live_range *)*ppcVar18;
          ppcVar18 = ppcVar18 + 1;
          ppcVar16 = ppcVar16 + 1;
        }
      }
LAB_1077868e:
      iVar14 = 0;
      if (stack[0] != (c2_live_range *)0x0) {
        ppcVar16 = stack;
        do {
          ppcVar1 = ppcVar16 + 1;
          ppcVar16 = ppcVar16 + 1;
          iVar14 = iVar14 + 1;
        } while (*ppcVar1 != (c2_live_range *)0x0);
      }
      iVar14 = iVar14 + -1;
      pcVar8 = pcVar17->end;
      for (t = pcVar17->head; t != pcVar8; t = t->next) {
        if (((t->flags & 1) != 0) && ((t->type & 0xf000) == 0x4000)) {
          uVar2 = t->line;
          if (uVar2 != 0) {
            g_current_line_abs = fn->line_base + (uint)uVar2;
            g_cur_line = uVar2;
          }
          for (opnd = t->src; opnd != (c2_operand *)0x0; opnd = opnd->next) {
            if (((opnd->kind == '\x01') && ((opnd->flags11 & 0x10) != 0)) &&
               (pcVar9 = (opnd->u18).range, pcVar9->kind == '\x02')) {
              if (pcVar9->colour == (c2_register_descriptor *)0x0) {
                if (pcVar9 == lr) {
                  if (stack[iVar14] == lr) {
                    stack[iVar14] = (c2_live_range *)0x0;
                    iVar14 = iVar14 + -1;
                  }
                  else {
                    iVar15 = 0;
                    if (0 < iVar14) {
                      ppcVar16 = stack;
LAB_107787da:
                      if (*ppcVar16 != lr) goto code_r0x107787de;
                      ppcVar16 = stack + iVar15;
                      iVar15 = iVar14 - iVar15;
                      do {
                        *ppcVar16 = ppcVar16[1];
                        ppcVar16 = ppcVar16 + 1;
                        iVar15 = iVar15 + -1;
                      } while (iVar15 != 0);
                    }
LAB_107787e6:
                    stack[iVar14] = (c2_live_range *)0x0;
                    iVar14 = iVar14 + -1;
                  }
                }
              }
              else {
                stack[iVar14] = (c2_live_range *)0x0;
                iVar14 = iVar14 + -1;
              }
            }
          }
          for (pcVar10 = t->dst; pcVar10 != (c2_operand *)0x0; pcVar10 = pcVar10->next) {
            if (((pcVar10->kind == '\x01') &&
                (pcVar9 = (pcVar10->u18).range, pcVar9->kind == '\x02')) &&
               ((pcVar9->colour != (c2_register_descriptor *)0x0 || (pcVar9 == lr)))) {
              iVar15 = 0;
              if (-1 < iVar14) {
                ppcVar16 = stack;
                do {
                  if (*ppcVar16 == pcVar9) {
                    if (iVar15 <= iVar14) goto LAB_10778811;
                    break;
                  }
                  iVar15 = iVar15 + 1;
                  ppcVar16 = ppcVar16 + 1;
                } while (iVar15 <= iVar14);
              }
              iVar14 = iVar14 + 1;
              stack[iVar15] = pcVar9;
            }
LAB_10778811:
          }
        }
      }
      iVar14 = 0;
      if (stack[0] != lr) {
        ppcVar16 = stack;
        do {
          ppcVar1 = ppcVar16 + 1;
          ppcVar16 = ppcVar16 + 1;
          iVar14 = iVar14 + 1;
        } while (*ppcVar1 != lr);
      }
      (pcVar17->avail_in).set = (c2_bitset *)(iVar14 + 1);
    }
    else {
      for (; pcVar5 != (c2_edge *)0x0; pcVar5 = pcVar5->next_pred) {
        if ((pcVar5->from->avail_in).set != (c2_bitset *)0x0) {
          if (pcVar5 != (c2_edge *)0x0) {
            pcVar7 = pcVar5->from;
            iVar14 = 0;
            pred_top = (int)&(pcVar7->avail_in).set[-1].nbits + 3;
            if (0 < pred_top) {
              pred_slots = (c2_live_range **)(pcVar7->u58).x87_stack;
              do {
                ppcVar16 = stack + iVar14;
                iVar14 = iVar14 + 1;
                *ppcVar16 = *(c2_live_range **)(((int)pred_slots - (int)stack) + (int)ppcVar16);
              } while (iVar14 < pred_top);
            }
            stack[iVar14] = lr;
            iVar15 = iVar14 + 1;
            if (iVar15 < 8) {
              ppcVar18 = ((pcVar7->u58).x87_stack)->slot + iVar14;
              ppcVar16 = stack + iVar15;
              for (pred_top = 8 - iVar15; pred_top != 0; pred_top = pred_top + -1) {
                *ppcVar16 = (c2_live_range *)*ppcVar18;
                ppcVar18 = ppcVar18 + 1;
                ppcVar16 = ppcVar16 + 1;
              }
            }
            goto LAB_1077868e;
          }
          break;
        }
      }
      pcVar13 = alloc_split_node();
      pcVar13->next = (c2_ra_split_block *)0x0;
      pcVar13->block = pcVar17;
      worklist_tail->next = pcVar13;
      worklist_tail = pcVar13;
    }
  }
  block = (c2_block *)0x0;
  bs = bitset_new(6);
  bitset_set(bs,n);
  pcVar17 = pcVar3;
  do {
    uVar12 = bitset_test(pcVar17->live_in,n);
    if ((uVar12 != 0) && (pcVar5 = pcVar17->preds, pcVar5 != (c2_edge *)0x0)) {
      for (pcVar6 = pcVar5->next_pred; pcVar6 != (c2_edge *)0x0; pcVar6 = pcVar6->next_pred) {
        if ((pcVar6->from->avail_in).set != (pcVar5->from->avail_in).set) {
          if (pcVar6 != (c2_edge *)0x0) {
            insert_split_marker_after_spill(pcVar17->head,bs);
            block = (c2_block *)0x1;
            pcVar17->flags = pcVar17->flags | 0x40000;
          }
          break;
        }
      }
    }
    if (pcVar17 == pcVar4) {
      bitset_free(bs);
      (pcVar3->avail_in).set = (c2_bitset *)0x0;
      while (pcVar3 != pcVar4) {
        pcVar3 = pcVar3->next;
        (pcVar3->avail_in).set = (c2_bitset *)0x0;
      }
      return (int)block;
    }
    pcVar17 = pcVar17->next;
  } while( true );
code_r0x107787de:
  iVar15 = iVar15 + 1;
  ppcVar16 = ppcVar16 + 1;
  if (iVar14 <= iVar15) goto LAB_107787e6;
  goto LAB_107787da;
}

