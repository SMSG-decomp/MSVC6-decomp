void __fastcall
x87_block_stack_cleanup_part
          (c2_tuple *t,int anon_slots,int popped,int tos_frame,c2_tuple *next,
          c2_operand *src_operand,c2_block *block,c2_function *fn,c2_bitset *x87_ranges,
          c2_x87_block_stack stack,c2_bitset *ranges_to_free)

{
  ushort uVar1;
  c2_loop *loop;
  c2_symbol *pcVar2;
  c2_symbol **pred_slot;
  int iVar3;
  c2_live_range *lr;
  uint32_t uVar4;
  c2_operand *pcVar5;
  c2_operand *pcVar6;
  c2_tuple *pcVar7;
  c2_tuple *pcVar8;
  c2_tuple *pcVar9;
  c2_block *cur_block;
  int iVar10;
  int iVar11;
  c2_symbol **ppcVar12;
  undefined4 uStack00000004;
  code *insert_fn_00;
  c2_insert_fn *insert_fn;
  
  iVar10 = tos_frame;
LAB_1075e23f:
  do {
    do {
      cur_block = block;
      if (popped == 0) {
        if (anon_slots < 1) goto LAB_1075e32c;
        if (t->op == 99) goto LAB_1075e32c;
        pcVar9 = t->src->sym->def;
        for (pcVar7 = t->prev;
            (pcVar7 != pcVar9 && (((pcVar7->type & 0xf000) != 0x4000 || (pcVar7->op == 0x162))));
            pcVar7 = pcVar7->prev) {
        }
        pcVar8 = t;
        iVar10 = anon_slots;
        if ((pcVar7->op == 0x5f) && (((pcVar7->src->u18).reg)->id - 0x1f == anon_slots)) {
          tuple_unlink_free(pcVar7);
          iVar10 = anon_slots + -1;
          if (0 < iVar10) {
            iVar11 = anon_slots + 0x1e;
            pcVar7 = t;
            do {
              insert_fn = tuple_insert_after;
              pcVar5 = operand_new_hardreg(iVar11,0x4008);
              pcVar6 = operand_new_hardreg(0x1f,0x4008);
              pcVar7 = tuple_new(0x5f,0x4008,pcVar6,pcVar5,insert_fn,pcVar7);
              iVar11 = iVar11 + -1;
              iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
          }
          tuple_replace_dst(pcVar9,pcVar9->dst,t->dst);
          if (t->dst->rank == 0) {
            pcVar7 = t->prev;
            tuple_unlink(pcVar7);
            tuple_insert_after(pcVar9,pcVar7);
          }
        }
        else {
          do {
            insert_fn_00 = tuple_insert_after;
            pcVar5 = operand_new_hardreg(iVar10 + 0x1f,0x4008);
            pcVar6 = operand_new_hardreg(0x1f,0x4008);
            pcVar8 = tuple_new(0x5f,0x4008,pcVar6,pcVar5,insert_fn_00,pcVar8);
            iVar10 = iVar10 + -1;
          } while (0 < iVar10);
          pcVar2 = t->src->sym;
          pcVar9 = pcVar2->def;
          pcVar5 = pcVar9->dst;
          while ((pcVar5 != (c2_operand *)0x0 &&
                 ((pcVar5->kind != '\x01' || (pcVar5->sym->storage != pcVar2->storage))))) {
            pcVar5 = pcVar5->next;
          }
          tuple_replace_dst(pcVar9,pcVar5,t->dst);
        }
        tuple_unlink_free(t);
        pcVar2 = stack.slot[tos_frame];
        pred_slot = stack.slot + tos_frame;
        iVar10 = anon_slots;
        if (0 < anon_slots) {
          do {
            *pred_slot = pred_slot[-1];
            pred_slot = pred_slot + -1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
        }
        *(c2_symbol **)((int)&stack + (tos_frame - anon_slots) * 4) = pcVar2;
        iVar11 = tos_frame;
      }
      else {
        if (anon_slots < 1) goto LAB_1075e32c;
        pcVar9 = t->prev;
        if (t->dst->rank == 0) {
          pcVar9 = pcVar9->prev;
        }
        pcVar7 = pcVar9->prev;
        pcVar9->flags13 = '\x13';
        if (1 < popped) {
          iVar11 = popped + -1;
          do {
            pcVar7->flags13 = '\x13';
            pcVar7 = pcVar7->prev;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
        }
        for (pcVar8 = next;
            ((((pcVar5 = pcVar8->dst, pcVar5 == (c2_operand *)0x0 ||
               ((pcVar5->type & 0xf000) != 0x4000)) || (pcVar5->kind != '\x01')) ||
             (((pcVar5->u18).reg)->cls != '\x02')) &&
            (((pcVar8->flags13 != '\0' || (pcVar8->op == 0x163)) || (pcVar8->op == 0x164))));
            pcVar8 = pcVar8->next) {
        }
        tuple_move_range(pcVar8,pcVar7->next,pcVar9);
        iVar11 = iVar10;
        if (t->op == 99) {
          (t->dst->u18).reg = g_reg_symbols + ((t->dst->u18).reg)->id + popped;
        }
        else {
          iVar3 = popped + anon_slots;
          t->op = 99;
          popped = popped + -1;
          (t->dst->u18).reg = g_reg_symbols + iVar3 + 0x1f;
          tuple_unlink_free(pcVar9);
          pcVar2 = stack.slot[iVar10];
          pred_slot = stack.slot + iVar10;
          iVar3 = anon_slots;
          if (0 < anon_slots) {
            do {
              *pred_slot = pred_slot[-1];
              pred_slot = pred_slot + -1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          *(c2_symbol **)((int)&stack + (iVar10 - anon_slots) * 4) = pcVar2;
        }
      }
LAB_1075e34a:
      do {
        do {
          t = next;
          if (next == cur_block->end) {
            do {
              bitset_andnot(cur_block->live_in,x87_ranges);
              bitset_andnot(cur_block->live_out,x87_ranges);
              bitset_andnot(cur_block->live,x87_ranges);
              cur_block = cur_block->next;
              if (cur_block == (c2_block *)0x0) {
                uStack00000004 = 0x1075e52e;
                uVar4 = bitset_iter_next(ranges_to_free);
                while (uVar4 != 0xffffffff) {
                  uStack00000004 = 0x1075e53a;
                  lr = live_range_from_id(uVar4);
                  uStack00000004 = 0x1075e544;
                  free_split_cell_list(lr->prefs);
                  uStack00000004 = 0x1075e54c;
                  free_split_cell_list((lr->u38).def);
                  uStack00000004 = 0x1075e555;
                  free_live_range(lr,0);
                  uStack00000004 = 0x1075e55c;
                  uVar4 = bitset_iter_next((c2_bitset *)0x0);
                }
                return;
              }
              if (cur_block->preds == (c2_edge *)0x0) {
                iVar10 = 8;
                pred_slot = stack.slot;
                for (; iVar10 != 0; iVar10 = iVar10 + -1) {
                  *pred_slot = (c2_symbol *)0x0;
                  pred_slot = pred_slot + 1;
                }
              }
              else {
                iVar10 = 8;
                pred_slot = ((cur_block->preds->from->u58).x87_stack)->slot;
                ppcVar12 = stack.slot;
                for (; iVar10 != 0; iVar10 = iVar10 + -1) {
                  *ppcVar12 = *pred_slot;
                  pred_slot = pred_slot + 1;
                  ppcVar12 = ppcVar12 + 1;
                }
              }
              iVar11 = 0;
              if (stack.slot[0] != (c2_symbol *)0x0) {
                pred_slot = stack.slot;
                do {
                  ppcVar12 = pred_slot + 1;
                  pred_slot = pred_slot + 1;
                  iVar11 = iVar11 + 1;
                } while (*ppcVar12 != (c2_symbol *)0x0);
              }
              t = cur_block->head;
              iVar11 = iVar11 + -1;
              tos_frame = iVar11;
              block = cur_block;
            } while (t == cur_block->end);
          }
          next = t->next;
          t->flags12 = '\0';
        } while (((t->flags & 1) == 0) ||
                ((((t->type & 0xf000) != 0x4000 && (t->kind != '\x0e')) && (t->op != 0x5b))));
        uVar1 = t->line;
        if (uVar1 != 0) {
          g_current_line_abs = fn->line_base + (uint)uVar1;
          g_cur_line = uVar1;
        }
      } while (t->flags13 == '\x13');
      pcVar5 = t->src;
      if (pcVar5 != (c2_operand *)0x0) {
LAB_1075e3b8:
        if ((((pcVar5->type & 0xf000) != 0x4000) || (pcVar5->kind != '\x01')) ||
           (pcVar2 = (pcVar5->u18).reg, pcVar2->cls != '\x02')) goto LAB_1075e3dd;
        cur_block = block;
        if (t->op != 99) {
          if ((pcVar5->flags11 & 0x10) == 0) {
            iVar10 = 0;
            if (stack.slot[0] != pcVar2) {
              pred_slot = stack.slot;
              do {
                ppcVar12 = pred_slot + 1;
                pred_slot = pred_slot + 1;
                iVar10 = iVar10 + 1;
              } while (*ppcVar12 != pcVar2);
            }
            iVar11 = tos_frame;
            if ((t->op == 0x60) && (iVar10 == tos_frame)) {
              pcVar9 = t->next;
              if ((pcVar9->flags & 1) != 0) {
                while ((((pcVar9->flags13 != '\0' || ((pcVar9->type & 0xf000) != 0x4000)) ||
                        (pcVar9->op == 0x163)) || (pcVar9->op == 0x164))) {
                  pcVar6 = find_src_reg_operand(pcVar2,pcVar9);
                  if ((pcVar6 != (c2_operand *)0x0) ||
                     (pcVar9 = pcVar9->next, (pcVar9->flags & 1) == 0)) break;
                }
              }
              if ((pcVar9->op == 99) && ((pcVar9->src->u18).reg == pcVar2)) {
                pcVar7 = t->next;
                if (pcVar7 == pcVar9) {
                  pcVar7 = pcVar7->next;
                }
                for (pcVar6 = pcVar7->src; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
                  if ((pcVar6->kind == '\x01') && (pcVar6->sym->storage == t->dst->sym->storage)) {
                    if (pcVar6 != (c2_operand *)0x0) {
                      pcVar5 = tuple_replace_src(pcVar7,pcVar6,t->src);
                      (pcVar5->u18).reg = g_reg_symbols + 0x1f;
                      tuple_unlink_free(t);
                      if (pcVar9 == next) {
                        next = pcVar9->next;
                      }
                      tuple_unlink_free(pcVar9);
                      anon_slots = anon_slots + 1;
                      stack.slot[tos_frame] = &g_x87_anon_slot;
                      goto LAB_1075e34a;
                    }
                    break;
                  }
                }
              }
            }
            (pcVar5->u18).reg = g_reg_symbols + (tos_frame - iVar10) + popped + 0x1f;
          }
LAB_1075e3dd:
          pcVar5 = pcVar5->next;
          if (pcVar5 == (c2_operand *)0x0) goto LAB_1075e3e7;
          goto LAB_1075e3b8;
        }
        if (stack.slot[iVar11] == pcVar2) {
          (pcVar5->u18).reg = g_reg_symbols + 0x1f;
          goto LAB_1075e3dd;
        }
        iVar10 = 0;
        if (stack.slot[0] != pcVar2) {
          pred_slot = stack.slot;
          do {
            ppcVar12 = pred_slot + 1;
            pred_slot = pred_slot + 1;
            iVar10 = iVar10 + 1;
          } while (*ppcVar12 != pcVar2);
        }
        if (iVar10 < iVar11) {
          pred_slot = stack.slot + iVar10;
          iVar10 = iVar11 - iVar10;
          do {
            *pred_slot = pred_slot[1];
            pred_slot = pred_slot + 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
        }
        stack.slot[iVar11] = (c2_symbol *)0x0;
        tos_frame = iVar11 + -1;
        popped = popped + 1;
        iVar11 = tos_frame;
        goto LAB_1075e34a;
      }
LAB_1075e3e7:
      iVar3 = x87_stack_effect(t);
      iVar10 = iVar11;
      if (iVar3 < 0) {
        if (stack.slot[iVar11] == &g_x87_anon_slot) {
          anon_slots = anon_slots + -1;
        }
        stack.slot[iVar11] = (c2_symbol *)0x0;
        iVar10 = iVar11 + -1;
        tos_frame = iVar10;
        if (iVar3 == -2) {
          if (stack.slot[iVar11 + -1] == &g_x87_anon_slot) {
            anon_slots = anon_slots + -1;
          }
          stack.slot[iVar11 + -1] = (c2_symbol *)0x0;
          iVar10 = iVar11 + -2;
          tos_frame = iVar10;
        }
      }
      pcVar5 = t->dst;
      if ((((pcVar5 == (c2_operand *)0x0) || (pcVar5->kind != '\x01')) ||
          ((pcVar5->type & 0xf000) != 0x4000)) ||
         (pcVar2 = (pcVar5->u18).reg, pcVar2->cls != '\x02')) {
        if (iVar3 < 1) {
          if (((t->op == 0x62) && (pcVar5->kind == '\x01')) &&
             (((pcVar5->u18).reg == g_reg_symbols + 0x1f && (pcVar5->sym == g_reg_symbols + 0x1f))))
          {
            stack.slot[iVar10] = (c2_symbol *)0x0;
            anon_slots = anon_slots + -1;
            iVar10 = iVar10 + -1;
            tos_frame = iVar10;
          }
        }
        else {
          stack.slot[iVar10 + 1] = &g_x87_anon_slot;
          anon_slots = anon_slots + 1;
          iVar10 = iVar10 + 1;
          tos_frame = iVar10;
        }
LAB_1075e32c:
        if ((popped != 0) && (anon_slots == 0)) {
          uVar4 = t->op;
          if (((uVar4 == 0x62) || (uVar4 == 99)) && (pcVar5 = t->dst, pcVar5->kind == '\x01')) {
            (pcVar5->u18).reg = g_reg_symbols + ((pcVar5->u18).reg)->id + popped;
            pcVar9 = t->prev;
            if (pcVar9->op == 0x62) {
              pcVar9 = pcVar9->prev;
            }
            if (uVar4 == 0x62) {
              tuple_unlink_free(pcVar9);
              t->op = 99;
              popped = popped + -1;
            }
          }
          pcVar9 = t->prev;
          iVar11 = popped;
          if ((pcVar9->op == 0x62) && (pcVar9->dst->kind != '\x01')) {
            pcVar9 = pcVar9->prev;
          }
          for (; iVar11 != 0; iVar11 = iVar11 + -1) {
            pcVar7 = pcVar9->prev;
            (pcVar9->src->u18).reg = g_reg_symbols + 0x1f;
            tuple_move_after(t,pcVar9);
            popped = popped + -1;
            pcVar9 = pcVar7;
          }
        }
        iVar11 = iVar10;
        cur_block = block;
        if (((t->op == 0x62) && (pcVar5 = t->dst, pcVar5->kind == '\x01')) &&
           ((pcVar5->u18).reg == g_reg_symbols + 0x1f)) {
          pcVar2 = t->src->sym;
          if ((pcVar2->cls == '\x03') && (pcVar9 = pcVar2->def, pcVar9 != (c2_tuple *)0x0)) {
            pcVar6 = pcVar9->dst;
            while ((pcVar6 != (c2_operand *)0x0 &&
                   ((pcVar6->kind != '\x01' || (pcVar6->sym->storage != pcVar2->storage))))) {
              pcVar6 = pcVar6->next;
            }
            tuple_replace_dst(pcVar9,pcVar6,pcVar5);
          }
          tuple_unlink_free(t);
        }
        goto LAB_1075e34a;
      }
      iVar11 = 0;
      if (-1 < iVar10) {
        pred_slot = stack.slot;
        do {
          if (*pred_slot == pcVar2) {
            if (iVar11 <= iVar10) {
              (pcVar5->u18).reg = g_reg_symbols + (iVar10 - iVar11) + 0x20;
              goto LAB_1075e238;
            }
            break;
          }
          iVar11 = iVar11 + 1;
          pred_slot = pred_slot + 1;
        } while (iVar11 <= iVar10);
      }
      uVar4 = t->op;
      tos_frame = iVar10 + 1;
      stack.slot[iVar10 + 1] = pcVar2;
      (pcVar5->u18).reg = g_reg_symbols + 0x1f;
      t->op = (-(uint)(uVar4 != 99) & 0xfffffffe) + 0x62;
      iVar10 = tos_frame;
LAB_1075e238:
    } while ((pcVar5->rank != 0) || (t->op == 0x60));
    uVar4 = next->op;
    pcVar9 = next;
    while (uVar4 != 0x164) {
      pcVar9 = pcVar9->next;
      uVar4 = pcVar9->op;
    }
    pcVar5 = pcVar9->src;
    pcVar9->flags12 = '\0';
    pcVar9->op = 0x62;
    loop = block->loop;
    (pcVar5->u18).reg = g_reg_symbols + 0x1f;
    iVar10 = tos_frame;
    if (loop != (c2_loop *)0x0) {
      pcVar2 = pcVar5->sym;
      uVar4 = bitset_test(loop->candidates,((pcVar2->u30).ra)->id);
      if ((uVar4 == 0) && ((g_opt_favor_speed != 0 || (loop->exits->next == (c2_loop_exit *)0x0))))
      {
        if (pcVar9 == next) {
          next = pcVar9->next;
        }
        x87_insert_edge_fixups(loop,pcVar9,pcVar2,x87_ranges,fn);
        t->dst->rank = 1;
        goto LAB_1075e23f;
      }
    }
    tuple_unlink(pcVar9);
    tuple_insert_before(t,pcVar9);
    next = t->next;
  } while( true );
}

