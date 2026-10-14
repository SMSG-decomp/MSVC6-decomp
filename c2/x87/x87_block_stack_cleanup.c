void __fastcall
x87_block_stack_cleanup(c2_function *fn,c2_bitset *x87_ranges,c2_bitset *ranges_to_free)

{
  ushort uVar1;
  c2_block *pcVar2;
  c2_loop *loop;
  c2_symbol *pcVar3;
  int iVar4;
  uint32_t uVar5;
  c2_live_range *lr;
  c2_symbol **pred_slot;
  c2_operand *pcVar6;
  c2_operand *pcVar7;
  c2_tuple *pcVar8;
  c2_tuple *pcVar9;
  int iVar10;
  c2_tuple *pcVar11;
  int iVar12;
  c2_symbol **ppcVar13;
  c2_tuple *t;
  code *insert_fn_00;
  int anon_count;
  int deferred_pops;
  int top;
  c2_tuple *next;
  c2_symbol *stack [8];
  c2_insert_fn *insert_fn;
  
  pcVar2 = fn->cfg->first;
  anon_count = 0;
  deferred_pops = 0;
  do {
    if (pcVar2 == (c2_block *)0x0) {
      uVar5 = bitset_iter_next(ranges_to_free);
      while (uVar5 != 0xffffffff) {
        lr = live_range_from_id(uVar5);
        free_split_cell_list(lr->prefs);
        free_split_cell_list((lr->u38).def);
        free_live_range(lr,0);
        uVar5 = bitset_iter_next((c2_bitset *)0x0);
      }
      return;
    }
    if (pcVar2->preds == (c2_edge *)0x0) {
      pred_slot = stack;
      for (iVar10 = 8; iVar10 != 0; iVar10 = iVar10 + -1) {
        *pred_slot = (c2_symbol *)0x0;
        pred_slot = pred_slot + 1;
      }
    }
    else {
      iVar10 = 8;
      pred_slot = ((pcVar2->preds->from->u58).x87_stack)->slot;
      ppcVar13 = stack;
      for (; iVar10 != 0; iVar10 = iVar10 + -1) {
        *ppcVar13 = *pred_slot;
        pred_slot = pred_slot + 1;
        ppcVar13 = ppcVar13 + 1;
      }
    }
    iVar10 = 0;
    if (stack[0] != (c2_symbol *)0x0) {
      pred_slot = stack;
      do {
        ppcVar13 = pred_slot + 1;
        pred_slot = pred_slot + 1;
        iVar10 = iVar10 + 1;
      } while (*ppcVar13 != (c2_symbol *)0x0);
    }
    iVar10 = iVar10 + -1;
    t = pcVar2->head;
    top = iVar10;
    if (pcVar2->head != pcVar2->end) {
      do {
        next = t->next;
        t->flags12 = '\0';
        if (((t->flags & 1) != 0) &&
           ((((t->type & 0xf000) == 0x4000 || (t->kind == '\x0e')) || (t->op == 0x5b)))) {
          uVar1 = t->line;
          if (uVar1 != 0) {
            g_current_line_abs = fn->line_base + (uint)uVar1;
            g_cur_line = uVar1;
          }
          if (t->flags13 != '\x13') {
            pcVar6 = t->src;
            if (pcVar6 != (c2_operand *)0x0) {
LAB_1075e3b8:
              if ((((pcVar6->type & 0xf000) != 0x4000) || (pcVar6->kind != '\x01')) ||
                 (pcVar3 = (pcVar6->u18).reg, pcVar3->cls != '\x02')) goto LAB_1075e3dd;
              if (t->op != 99) {
                if ((pcVar6->flags11 & 0x10) == 0) {
                  iVar12 = 0;
                  if (stack[0] != pcVar3) {
                    pred_slot = stack;
                    do {
                      ppcVar13 = pred_slot + 1;
                      pred_slot = pred_slot + 1;
                      iVar12 = iVar12 + 1;
                    } while (*ppcVar13 != pcVar3);
                  }
                  iVar10 = top;
                  if ((t->op == 0x60) && (iVar12 == top)) {
                    pcVar11 = t->next;
                    if ((pcVar11->flags & 1) != 0) {
                      while ((((pcVar11->flags13 != '\0' || ((pcVar11->type & 0xf000) != 0x4000)) ||
                              (pcVar11->op == 0x163)) || (pcVar11->op == 0x164))) {
                        pcVar7 = find_src_reg_operand(pcVar3,pcVar11);
                        if ((pcVar7 != (c2_operand *)0x0) ||
                           (pcVar11 = pcVar11->next, (pcVar11->flags & 1) == 0)) break;
                      }
                    }
                    if ((pcVar11->op == 99) && ((pcVar11->src->u18).reg == pcVar3)) {
                      pcVar8 = t->next;
                      if (pcVar8 == pcVar11) {
                        pcVar8 = pcVar8->next;
                      }
                      for (pcVar7 = pcVar8->src; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next)
                      {
                        if ((pcVar7->kind == '\x01') &&
                           (pcVar7->sym->storage == t->dst->sym->storage)) {
                          if (pcVar7 != (c2_operand *)0x0) {
                            pcVar6 = tuple_replace_src(pcVar8,pcVar7,t->src);
                            (pcVar6->u18).reg = g_reg_symbols + 0x1f;
                            tuple_unlink_free(t);
                            if (pcVar11 == next) {
                              next = pcVar11->next;
                            }
                            tuple_unlink_free(pcVar11);
                            anon_count = anon_count + 1;
                            stack[top] = &g_x87_anon_slot;
                            goto LAB_1075e34a;
                          }
                          break;
                        }
                      }
                    }
                  }
                  (pcVar6->u18).reg = g_reg_symbols + (top - iVar12) + deferred_pops + 0x1f;
                }
                goto LAB_1075e3dd;
              }
              if (stack[iVar10] == pcVar3) {
                (pcVar6->u18).reg = g_reg_symbols + 0x1f;
                goto LAB_1075e3dd;
              }
              iVar12 = 0;
              if (stack[0] != pcVar3) {
                pred_slot = stack;
                do {
                  ppcVar13 = pred_slot + 1;
                  pred_slot = pred_slot + 1;
                  iVar12 = iVar12 + 1;
                } while (*ppcVar13 != pcVar3);
              }
              if (iVar12 < iVar10) {
                pred_slot = stack + iVar12;
                iVar12 = iVar10 - iVar12;
                do {
                  *pred_slot = pred_slot[1];
                  pred_slot = pred_slot + 1;
                  iVar12 = iVar12 + -1;
                } while (iVar12 != 0);
              }
              stack[iVar10] = (c2_symbol *)0x0;
              iVar10 = iVar10 + -1;
              deferred_pops = deferred_pops + 1;
              top = iVar10;
              goto LAB_1075e34a;
            }
LAB_1075e3e7:
            iVar4 = x87_stack_effect(t);
            iVar12 = iVar10;
            if (iVar4 < 0) {
              if (stack[iVar10] == &g_x87_anon_slot) {
                anon_count = anon_count + -1;
              }
              stack[iVar10] = (c2_symbol *)0x0;
              iVar12 = iVar10 + -1;
              top = iVar12;
              if (iVar4 == -2) {
                if (stack[iVar12] == &g_x87_anon_slot) {
                  anon_count = anon_count + -1;
                }
                stack[iVar12] = (c2_symbol *)0x0;
                iVar12 = iVar10 + -2;
                top = iVar12;
              }
            }
            pcVar6 = t->dst;
            if ((((pcVar6 == (c2_operand *)0x0) || (pcVar6->kind != '\x01')) ||
                ((pcVar6->type & 0xf000) != 0x4000)) ||
               (pcVar3 = (pcVar6->u18).reg, pcVar3->cls != '\x02')) {
              if (iVar4 < 1) {
                if (((t->op == 0x62) && (pcVar6->kind == '\x01')) &&
                   (((pcVar6->u18).reg == g_reg_symbols + 0x1f &&
                    (pcVar6->sym == g_reg_symbols + 0x1f)))) {
                  stack[iVar12] = (c2_symbol *)0x0;
                  anon_count = anon_count + -1;
                  iVar12 = iVar12 + -1;
                  top = iVar12;
                }
              }
              else {
                stack[iVar12 + 1] = &g_x87_anon_slot;
                anon_count = anon_count + 1;
                iVar12 = iVar12 + 1;
                top = iVar12;
              }
LAB_1075e32c:
              if ((deferred_pops != 0) && (anon_count == 0)) {
                uVar5 = t->op;
                if (((uVar5 == 0x62) || (uVar5 == 99)) && (pcVar6 = t->dst, pcVar6->kind == '\x01'))
                {
                  (pcVar6->u18).reg = g_reg_symbols + ((pcVar6->u18).reg)->id + deferred_pops;
                  pcVar11 = t->prev;
                  if (pcVar11->op == 0x62) {
                    pcVar11 = pcVar11->prev;
                  }
                  if (uVar5 == 0x62) {
                    tuple_unlink_free(pcVar11);
                    t->op = 99;
                    deferred_pops = deferred_pops + -1;
                  }
                }
                pcVar11 = t->prev;
                iVar10 = deferred_pops;
                if ((pcVar11->op == 0x62) && (pcVar11->dst->kind != '\x01')) {
                  pcVar11 = pcVar11->prev;
                }
                for (; iVar10 != 0; iVar10 = iVar10 + -1) {
                  pcVar8 = pcVar11->prev;
                  (pcVar11->src->u18).reg = g_reg_symbols + 0x1f;
                  tuple_move_after(t,pcVar11);
                  deferred_pops = deferred_pops + -1;
                  pcVar11 = pcVar8;
                }
              }
              iVar10 = iVar12;
              if (((t->op == 0x62) && (pcVar6 = t->dst, pcVar6->kind == '\x01')) &&
                 ((pcVar6->u18).reg == g_reg_symbols + 0x1f)) {
                pcVar3 = t->src->sym;
                if ((pcVar3->cls == '\x03') && (pcVar11 = pcVar3->def, pcVar11 != (c2_tuple *)0x0))
                {
                  pcVar7 = pcVar11->dst;
                  while ((pcVar7 != (c2_operand *)0x0 &&
                         ((pcVar7->kind != '\x01' || (pcVar7->sym->storage != pcVar3->storage))))) {
                    pcVar7 = pcVar7->next;
                  }
                  tuple_replace_dst(pcVar11,pcVar7,pcVar6);
                }
                tuple_unlink_free(t);
              }
            }
            else {
              iVar10 = 0;
              if (-1 < iVar12) {
                pred_slot = stack;
                do {
                  if (*pred_slot == pcVar3) {
                    if (iVar10 <= iVar12) {
                      (pcVar6->u18).reg = g_reg_symbols + (iVar12 - iVar10) + 0x20;
                      goto LAB_1075e238;
                    }
                    break;
                  }
                  iVar10 = iVar10 + 1;
                  pred_slot = pred_slot + 1;
                } while (iVar10 <= iVar12);
              }
              uVar5 = t->op;
              iVar12 = iVar12 + 1;
              stack[iVar12] = pcVar3;
              (pcVar6->u18).reg = g_reg_symbols + 0x1f;
              t->op = (-(uint)(uVar5 != 99) & 0xfffffffe) + 0x62;
              top = iVar12;
LAB_1075e238:
              if ((pcVar6->rank == 0) && (t->op != 0x60)) {
                uVar5 = next->op;
                pcVar11 = next;
                while (uVar5 != 0x164) {
                  pcVar11 = pcVar11->next;
                  uVar5 = pcVar11->op;
                }
                pcVar6 = pcVar11->src;
                pcVar11->flags12 = '\0';
                pcVar11->op = 0x62;
                loop = pcVar2->loop;
                (pcVar6->u18).reg = g_reg_symbols + 0x1f;
                iVar12 = top;
                if (loop != (c2_loop *)0x0) {
                  pcVar3 = pcVar6->sym;
                  uVar5 = bitset_test(loop->candidates,((pcVar3->u30).ra)->id);
                  if ((uVar5 == 0) &&
                     ((g_opt_favor_speed != 0 || (loop->exits->next == (c2_loop_exit *)0x0)))) {
                    if (pcVar11 == next) {
                      next = pcVar11->next;
                    }
                    x87_insert_edge_fixups(loop,pcVar11,pcVar3,x87_ranges,fn);
                    t->dst->rank = 1;
                    goto LAB_1075e23f;
                  }
                }
                tuple_unlink(pcVar11);
                tuple_insert_before(t,pcVar11);
                next = t->next;
              }
LAB_1075e23f:
              if (deferred_pops == 0) {
                if ((anon_count < 1) || (t->op == 99)) goto LAB_1075e32c;
                pcVar11 = t->src->sym->def;
                for (pcVar8 = t->prev;
                    (pcVar8 != pcVar11 &&
                    (((pcVar8->type & 0xf000) != 0x4000 || (pcVar8->op == 0x162))));
                    pcVar8 = pcVar8->prev) {
                }
                pcVar9 = t;
                iVar10 = anon_count;
                if ((pcVar8->op == 0x5f) && (((pcVar8->src->u18).reg)->id - 0x1f == anon_count)) {
                  tuple_unlink_free(pcVar8);
                  iVar10 = anon_count + -1;
                  if (0 < iVar10) {
                    iVar12 = anon_count + 0x1e;
                    pcVar8 = t;
                    do {
                      insert_fn = tuple_insert_after;
                      pcVar6 = operand_new_hardreg(iVar12,0x4008);
                      pcVar7 = operand_new_hardreg(0x1f,0x4008);
                      pcVar8 = tuple_new(0x5f,0x4008,pcVar7,pcVar6,insert_fn,pcVar8);
                      iVar12 = iVar12 + -1;
                      iVar10 = iVar10 + -1;
                    } while (iVar10 != 0);
                  }
                  tuple_replace_dst(pcVar11,pcVar11->dst,t->dst);
                  if (t->dst->rank == 0) {
                    pcVar8 = t->prev;
                    tuple_unlink(pcVar8);
                    tuple_insert_after(pcVar11,pcVar8);
                  }
                }
                else {
                  do {
                    insert_fn_00 = tuple_insert_after;
                    pcVar6 = operand_new_hardreg(iVar10 + 0x1f,0x4008);
                    pcVar7 = operand_new_hardreg(0x1f,0x4008);
                    pcVar9 = tuple_new(0x5f,0x4008,pcVar7,pcVar6,insert_fn_00,pcVar9);
                    iVar10 = iVar10 + -1;
                  } while (0 < iVar10);
                  pcVar3 = t->src->sym;
                  pcVar11 = pcVar3->def;
                  pcVar6 = pcVar11->dst;
                  while ((pcVar6 != (c2_operand *)0x0 &&
                         ((pcVar6->kind != '\x01' || (pcVar6->sym->storage != pcVar3->storage))))) {
                    pcVar6 = pcVar6->next;
                  }
                  tuple_replace_dst(pcVar11,pcVar6,t->dst);
                }
                tuple_unlink_free(t);
                pcVar3 = stack[top];
                pred_slot = stack + top;
                iVar10 = anon_count;
                if (0 < anon_count) {
                  do {
                    *pred_slot = pred_slot[-1];
                    pred_slot = pred_slot + -1;
                    iVar10 = iVar10 + -1;
                  } while (iVar10 != 0);
                }
                stack[top - anon_count] = pcVar3;
                iVar10 = top;
              }
              else {
                if (anon_count < 1) goto LAB_1075e32c;
                pcVar11 = t->prev;
                if (t->dst->rank == 0) {
                  pcVar11 = pcVar11->prev;
                }
                pcVar8 = pcVar11->prev;
                pcVar11->flags13 = '\x13';
                if (1 < deferred_pops) {
                  iVar10 = deferred_pops + -1;
                  do {
                    pcVar8->flags13 = '\x13';
                    pcVar8 = pcVar8->prev;
                    iVar10 = iVar10 + -1;
                  } while (iVar10 != 0);
                }
                for (pcVar9 = next;
                    ((((pcVar6 = pcVar9->dst, pcVar6 == (c2_operand *)0x0 ||
                       ((pcVar6->type & 0xf000) != 0x4000)) || (pcVar6->kind != '\x01')) ||
                     (((pcVar6->u18).reg)->cls != '\x02')) &&
                    (((pcVar9->flags13 != '\0' || (pcVar9->op == 0x163)) || (pcVar9->op == 0x164))))
                    ; pcVar9 = pcVar9->next) {
                }
                tuple_move_range(pcVar9,pcVar8->next,pcVar11);
                iVar10 = iVar12;
                if (t->op == 99) {
                  (t->dst->u18).reg = g_reg_symbols + ((t->dst->u18).reg)->id + deferred_pops;
                }
                else {
                  iVar4 = deferred_pops + anon_count;
                  t->op = 99;
                  deferred_pops = deferred_pops + -1;
                  (t->dst->u18).reg = g_reg_symbols + iVar4 + 0x1f;
                  tuple_unlink_free(pcVar11);
                  pcVar3 = stack[iVar12];
                  pred_slot = stack + iVar12;
                  iVar4 = anon_count;
                  if (0 < anon_count) {
                    do {
                      *pred_slot = pred_slot[-1];
                      pred_slot = pred_slot + -1;
                      iVar4 = iVar4 + -1;
                    } while (iVar4 != 0);
                  }
                  stack[iVar12 - anon_count] = pcVar3;
                }
              }
            }
          }
        }
LAB_1075e34a:
        t = next;
      } while (next != pcVar2->end);
    }
    bitset_andnot(pcVar2->live_in,x87_ranges);
    bitset_andnot(pcVar2->live_out,x87_ranges);
    bitset_andnot(pcVar2->live,x87_ranges);
    pcVar2 = pcVar2->next;
  } while( true );
LAB_1075e3dd:
  pcVar6 = pcVar6->next;
  if (pcVar6 == (c2_operand *)0x0) goto LAB_1075e3e7;
  goto LAB_1075e3b8;
}

