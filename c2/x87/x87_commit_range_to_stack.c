c2_bitset * __fastcall
x87_commit_range_to_stack
          (c2_function *fn,c2_live_range *lr,c2_bitset *on_stack,c2_bitset *all_ranges)

{
  uint8_t *puVar1;
  ushort uVar2;
  int16_t iVar3;
  c2_block *pcVar4;
  c2_ra_split_block *pcVar5;
  c2_loop *pcVar6;
  c2_symbol *pcVar7;
  c2_x87_block_stack stack;
  c2_edge *edge;
  bool bVar8;
  bool bVar9;
  c2_ra_split_block *pcVar10;
  c2_operand *pcVar11;
  c2_operand *pcVar12;
  c2_tuple *pcVar13;
  c2_bitset *dst;
  c2_bitset *pcVar14;
  uint32_t uVar15;
  c2_ra_split_block *worklist_last;
  uint32_t uVar16;
  c2_tuple *pcVar17;
  c2_ra_split_block *requeue_node;
  c2_symbol **ppcVar18;
  c2_block *pcVar19;
  c2_bitset *pcVar20;
  c2_bitset *pcVar21;
  c2_symbol **ppcVar22;
  c2_tuple *pcVar23;
  uint8_t uVar24;
  int iVar25;
  c2_tuple *pcVar26;
  c2_symbol **slot_ptr;
  uint16_t uVar27;
  c2_symbol **slot_prev;
  c2_edge *pcVar28;
  undefined4 unaff_EBP;
  uint32_t type_dword;
  c2_block *walk_block;
  c2_block *last_block;
  int iVar29;
  code *insert_fn_00;
  c2_tuple *walk;
  int block_tos;
  int range_live;
  c2_ra_split_block *worklist_tail;
  c2_ra_split_block *worklist_head;
  c2_live_range *range_cell;
  c2_block *block;
  c2_bitset *scratch;
  c2_tuple *insert_at;
  int depth_overflow;
  int operand_pass;
  c2_tuple *block_end;
  c2_x87_block_stack stack_model;
  c2_insert_fn *insert_fn;
  c2_live_range *src_owner;
  c2_live_range *other;
  c2_live_range *dst_owner;
  c2_list_cell *def_cell;
  c2_list_cell *def_cursor;
  
  uVar27 = lr->sym->type;
  type_dword = CONCAT22((short)((uint)unaff_EBP >> 0x10),uVar27);
  for (def_cell = (lr->u38).x87_defs; def_cell != (c2_list_cell *)0x0; def_cell = def_cell->next) {
    pcVar23 = (def_cell->u04).tuple;
    def_cursor = def_cell;
    if (pcVar23->kind != '\x19') {
      while (((pcVar23->flags & 1) == 0 ||
             (pcVar11 = find_src_reg_operand((c2_symbol *)lr,pcVar23), pcVar11 == (c2_operand *)0x0)
             )) {
        pcVar23 = pcVar23->prev;
      }
      pcVar11->flags11 = pcVar11->flags11 & 0xef;
      pcVar13 = pcVar23;
      if (pcVar23 != (def_cell->u04).tuple) {
        pcVar13 = pcVar23->next;
        while ((pcVar13 != (def_cell->u04).tuple &&
               (((((pcVar13->flags & 1) == 0 ||
                  (pcVar11 = pcVar13->dst, pcVar11 == (c2_operand *)0x0)) ||
                 ((pcVar11->type & 0xf000) != 0x4000)) ||
                ((pcVar11->kind != '\x01' || (((pcVar11->u18).reg)->cls != '\x02'))))))) {
          pcVar13 = pcVar13->next;
        }
      }
      if (((pcVar13->dst != (c2_operand *)0x0) && ((pcVar13->dst->type & 0xf000) == 0x4000)) &&
         (pcVar13 = pcVar13->prev, pcVar13->op == 99)) {
        stack.slot[1] = stack_model.slot[1];
        stack.slot[2] = stack_model.slot[2];
        stack.slot[3] = stack_model.slot[3];
        stack.slot[4] = stack_model.slot[4];
        stack.slot[5] = stack_model.slot[5];
        stack.slot[6] = stack_model.slot[6];
        stack.slot[7] = stack_model.slot[7];
        stack.slot[0] = stack_model.slot[0];
        pcVar14 = x87_commit_range_tail
                            (pcVar13,pcVar23,99,uVar27,lr,walk,block_tos,range_live,worklist_tail,
                             worklist_head,lr,block,scratch,fn,insert_at,depth_overflow,def_cursor,
                             operand_pass,block_end,type_dword,stack,on_stack,all_ranges);
        return pcVar14;
      }
      def_cell = def_cursor;
      if (pcVar23->op == 0x19e) {
        if (pcVar13 == pcVar23) {
          pcVar13 = pcVar13->prev;
        }
        tuple_unlink_free(pcVar23);
        def_cell = def_cursor;
      }
      uVar2 = pcVar13->line;
      if (uVar2 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar2;
        g_cur_line = uVar2;
      }
      insert_fn = tuple_insert_after;
      pcVar11 = operand_new_reg(0x149,uVar27,lr->sym,(c2_symbol *)lr);
      pcVar12 = operand_new_reg(0x149,uVar27,g_reg_symbols + 0x1f,g_reg_symbols + 0x1f);
      pcVar13 = tuple_new(99,uVar27,pcVar12,pcVar11,insert_fn,pcVar13);
      pcVar23 = pcVar13->prev;
      uVar2 = pcVar23->type;
      while ((((uVar2 & 0xf000) != 0x4000 && (pcVar23->kind != '\x0e')) && (pcVar23->op != 0x5b))) {
        pcVar23 = pcVar23->prev;
        uVar2 = pcVar23->type;
      }
      uVar24 = pcVar23->flags13;
      pcVar13->flags12 = pcVar23->flags12;
      pcVar13->flags13 = uVar24;
      puVar1 = &pcVar13->src->flags11;
      *puVar1 = *puVar1 | 0x10;
    }
  }
  dst = bitset_new(6);
  pcVar14 = bitset_new(6);
  walk_block = lr->first_block;
  uVar16 = lr->id;
  pcVar4 = lr->last_block;
  bVar9 = false;
  worklist_tail = (c2_ra_split_block *)0x0;
  worklist_head = (c2_ra_split_block *)0x0;
  while( true ) {
    uVar15 = bitset_test(walk_block->live,uVar16);
    pcVar5 = worklist_tail;
    pcVar10 = worklist_head;
    if (uVar15 != 0) {
      worklist_last = alloc_split_node();
      worklist_last->block = walk_block;
      worklist_last->next = (c2_ra_split_block *)0x0;
      pcVar5 = worklist_last;
      pcVar10 = worklist_last;
      if (worklist_tail != (c2_ra_split_block *)0x0) {
        worklist_tail->next = worklist_last;
        pcVar5 = worklist_last;
        pcVar10 = worklist_head;
      }
    }
    worklist_head = pcVar10;
    worklist_tail = pcVar5;
    if (walk_block == pcVar4) break;
    walk_block = walk_block->next;
  }
  insert_at = (c2_tuple *)0x0;
  do {
    while( true ) {
      if (worklist_head == (c2_ra_split_block *)0x0) {
        bitset_free(dst);
        if (pcVar14->chunks == (c2_bitset_chunk *)0x0) {
          bitset_free(pcVar14);
          pcVar14 = (c2_bitset *)0x0;
        }
        return pcVar14;
      }
      pcVar4 = worklist_head->block;
      pcVar5 = worklist_head->next;
      free_split_node(worklist_head);
      uVar16 = bitset_test(pcVar4->live_in,lr->id);
      worklist_head = pcVar5;
      if (uVar16 != 0) break;
      if (pcVar4->preds == (c2_edge *)0x0) {
        iVar25 = 8;
        ppcVar18 = stack_model.slot;
        for (; iVar25 != 0; iVar25 = iVar25 + -1) {
          *ppcVar18 = (c2_symbol *)0x0;
          ppcVar18 = ppcVar18 + 1;
        }
      }
      else {
        iVar25 = 8;
        ppcVar18 = ((pcVar4->preds->from->u58).x87_stack)->slot;
        ppcVar22 = stack_model.slot;
        for (; iVar25 != 0; iVar25 = iVar25 + -1) {
          *ppcVar22 = *ppcVar18;
          ppcVar18 = ppcVar18 + 1;
          ppcVar22 = ppcVar22 + 1;
        }
      }
      bVar8 = false;
LAB_1075edcf:
      if (stack_model.slot[0] == (c2_symbol *)0x0) {
        iVar25 = 0;
      }
      else {
        iVar25 = 0;
        ppcVar18 = stack_model.slot;
        do {
          ppcVar22 = ppcVar18 + 1;
          ppcVar18 = ppcVar18 + 1;
          iVar25 = iVar25 + 1;
        } while (*ppcVar22 != (c2_symbol *)0x0);
      }
      iVar25 = iVar25 + -1;
      bitset_copy(dst,all_ranges);
      bitset_andnot(dst,on_stack);
      bitset_and(dst,pcVar4->live_in);
      pcVar13 = pcVar4->end;
      pcVar23 = pcVar4->head;
      block_tos = iVar25;
      while (pcVar23 != pcVar13) {
        pcVar26 = pcVar23;
        if (((pcVar23->flags & 1) != 0) &&
           (((pcVar23->type & 0xf000) == 0x4000 || (pcVar23->kind == '\x0e')))) {
          uVar2 = pcVar23->line;
          if (uVar2 != 0) {
            g_current_line_abs = fn->line_base + (uint)uVar2;
            g_cur_line = uVar2;
          }
          pcVar11 = pcVar23->src;
          if (pcVar11 != (c2_operand *)0x0) {
LAB_1075f014:
            pcVar17 = insert_at;
            if ((((pcVar11->type & 0xf000) != 0x4000) || (pcVar11->kind != '\x01')) ||
               (((pcVar11->flags11 & 0x10) == 0 ||
                (src_owner = (pcVar11->u18).range, src_owner->kind != '\x02')))) goto LAB_1075f034;
            if (src_owner != lr) {
              if (src_owner->colour == (c2_register_descriptor *)0x0) {
                bitset_clear(dst,src_owner->id);
              }
              else {
                stack_model.slot[iVar25] = (c2_symbol *)0x0;
                iVar25 = iVar25 + -1;
              }
              goto LAB_1075f034;
            }
            if (stack_model.slot[iVar25] == (c2_symbol *)lr) {
              uVar24 = pcVar23->flags13;
              stack_model.slot[iVar25] = (c2_symbol *)0x0;
              iVar25 = iVar25 + -1;
              if (uVar24 == '\0') {
                bVar8 = false;
              }
              else {
                for (pcVar17 = pcVar23->next;
                    ((pcVar17->flags13 != '\0' ||
                     ((((pcVar17->type & 0xf000) != 0x4000 && (pcVar17->kind != '\x0e')) ||
                      (pcVar17->op == 0x163)))) || (pcVar17->op == 0x164)); pcVar17 = pcVar17->next)
                {
                }
                pcVar17 = pcVar17->prev;
                uVar2 = pcVar17->type;
                while (((uVar2 & 0xf000) != 0x4000 && (pcVar17->kind != '\x0e'))) {
                  pcVar17 = pcVar17->prev;
                  uVar2 = pcVar17->type;
                }
                if (pcVar17 == pcVar23) {
                  bVar8 = false;
                  pcVar17 = insert_at;
                }
              }
              goto LAB_1075f034;
            }
            pcVar26 = pcVar23->prev;
            pcVar17 = pcVar23->next;
            ppcVar18 = stack_model.slot + iVar25 + -1;
            pcVar7 = stack_model.slot[iVar25 + -1];
            while (pcVar7 != (c2_symbol *)lr) {
              slot_prev = ppcVar18 + -1;
              pcVar17 = pcVar17->next;
              ppcVar18 = ppcVar18 + -1;
              pcVar7 = *slot_prev;
            }
            tuple_move_after(pcVar17,pcVar23);
            block_tos = iVar25;
            goto LAB_1075efba;
          }
LAB_1075f040:
          iVar29 = iVar25;
          iVar25 = block_tos;
          for (pcVar11 = pcVar23->dst; pcVar11 != (c2_operand *)0x0; pcVar11 = pcVar11->next) {
            if ((((pcVar11->type & 0xf000) == 0x4000) && (pcVar11->kind == '\x01')) &&
               (dst_owner = (pcVar11->u18).range, dst_owner->kind == '\x02')) {
              if (dst_owner->colour == (c2_register_descriptor *)0x0) {
                bitset_set(dst,dst_owner->id);
              }
              else {
                iVar25 = 0;
                if (-1 < iVar29) {
                  slot_prev = stack_model.slot;
                  do {
                    if (*slot_prev == (c2_symbol *)dst_owner) {
                      if (iVar25 <= iVar29) goto LAB_1075ef86;
                      break;
                    }
                    iVar25 = iVar25 + 1;
                    slot_prev = slot_prev + 1;
                  } while (iVar25 <= iVar29);
                }
                iVar29 = iVar29 + 1;
                stack_model.slot[iVar25] = (c2_symbol *)dst_owner;
                if (lr == dst_owner) {
                  bVar8 = true;
                }
              }
            }
LAB_1075ef86:
            iVar25 = iVar29;
          }
          if (bVar8) {
            uVar24 = pcVar23->flags12 + '\x01';
            pcVar23->flags12 = uVar24;
            if (uVar24 == '\b') {
              bVar9 = true;
            }
            if (pcVar23 == insert_at) {
              bVar8 = false;
              insert_at = (c2_tuple *)0x0;
            }
          }
          block_tos = iVar25;
          if ((((bVar9) && (pcVar23->flags13 == '\0')) && (pcVar23->op != 0x163)) &&
             (pcVar23->op != 0x164)) {
            bVar9 = false;
            if (dst->chunks != (c2_bitset_chunk *)0x0) {
              insert_split_marker_after_spill(pcVar23,dst);
              bitset_or(pcVar14,dst);
              pcVar4->flags = pcVar4->flags | 0x40000;
            }
            pcVar23 = pcVar23->prev;
            uVar24 = pcVar23->kind;
            while (uVar24 != '\x19') {
              if ((((pcVar23->flags & 1) != 0) && (pcVar23->op != 0x163)) && (pcVar23->op != 0x164))
              {
                operand_pass = 0;
                do {
                  if (operand_pass == 0) {
                    if (pcVar23->flags13 != '\0') {
                      pcVar11 = pcVar23->dst;
                      goto joined_r0x10778bcb;
                    }
                  }
                  else {
                    pcVar11 = pcVar23->src;
joined_r0x10778bcb:
                    for (; pcVar11 != (c2_operand *)0x0; pcVar11 = pcVar11->next) {
                      if ((((pcVar11->type & 0xf000) == 0x4000) && (pcVar11->kind == '\x01')) &&
                         ((other = (pcVar11->u18).range, other->kind == '\x02' &&
                          ((other->colour == (c2_register_descriptor *)0x0 && (other != lr)))))) {
                        pcVar21 = bitset_new(6);
                        bitset_set(pcVar21,other->id);
                        insert_split_marker_after_spill(pcVar23,pcVar21);
                        insert_split_marker_after_spill(pcVar23->prev,pcVar21);
                        bitset_free(pcVar21);
                        bitset_set(pcVar14,((pcVar11->u18).range)->id);
                        pcVar4->flags = pcVar4->flags | 0x40000;
                      }
                    }
                  }
                  operand_pass = operand_pass + 1;
                } while (operand_pass < 2);
                if (pcVar23->flags13 == '\0') break;
              }
              pcVar23 = pcVar23->prev;
              uVar24 = pcVar23->kind;
            }
          }
        }
LAB_1075efba:
        pcVar23 = pcVar26->next;
      }
      if (bVar8) {
        pcVar28 = pcVar4->succs;
        while (edge = pcVar28, edge != (c2_edge *)0x0) {
          last_block = edge->to;
          pcVar28 = edge->next_succ;
          uVar16 = bitset_test(last_block->live_in,lr->id);
          if (uVar16 == 0) {
            if (last_block->preds->next_pred == (c2_edge *)0x0) {
              pcVar23 = last_block->head;
              if (pcVar23->kind == '\x19') {
                do {
                  pcVar23 = pcVar23->next;
                  if (pcVar23 == last_block->end) {
                    pcVar23 = pcVar23->prev;
                    break;
                  }
                } while (pcVar23->kind == '\x19');
              }
              if ((pcVar23->flags & 1) != 0) {
                pcVar23 = pcVar23->prev;
              }
              slot_ptr = stack_model.slot + block_tos;
              pcVar7 = stack_model.slot[block_tos];
              while (pcVar7 != (c2_symbol *)lr) {
                ppcVar18 = slot_ptr + -1;
                pcVar23 = pcVar23->next;
                slot_ptr = slot_ptr + -1;
                pcVar7 = *ppcVar18;
              }
            }
            else {
              pcVar19 = split_edge_with_new_block(fn,edge,pcVar4,last_block);
              pcVar21 = last_block->live_in;
              pcVar20 = bitset_clone(pcVar21);
              pcVar19->live_in = pcVar20;
              pcVar20 = bitset_clone(pcVar21);
              pcVar19->live_out = pcVar20;
              pcVar21 = bitset_clone(pcVar21);
              pcVar19->live = pcVar21;
              pcVar21 = bitset_new(8);
              pcVar19->set24 = pcVar21;
              pcVar21 = bitset_new(8);
              pcVar19->set28 = pcVar21;
              pcVar21 = bitset_new(6);
              iVar3 = last_block->loop_depth;
              pcVar19->set4c = pcVar21;
              pcVar6 = last_block->loop;
              pcVar19->loop_depth = iVar3;
              pcVar19->loop = pcVar6;
              ppcVar22 = arena_alloc(4,0x20);
              ppcVar18 = ((pcVar4->u58).x87_stack)->slot;
              (pcVar19->u58).x87_stack = (c2_x87_block_stack *)ppcVar22;
              pcVar23 = pcVar19->head;
              for (iVar25 = 8; iVar25 != 0; iVar25 = iVar25 + -1) {
                *ppcVar22 = *ppcVar18;
                ppcVar18 = ppcVar18 + 1;
                ppcVar22 = ppcVar22 + 1;
              }
              pcVar13 = pcVar23->next;
              last_block = pcVar19;
              if (pcVar13->kind == '\x1a') {
                pcVar23 = pcVar13;
              }
            }
            uVar2 = pcVar23->line;
            if (uVar2 != 0) {
              g_current_line_abs = fn->line_base + (uint)uVar2;
              g_cur_line = uVar2;
            }
            insert_fn_00 = tuple_insert_after;
            uVar27 = (uint16_t)type_dword;
            pcVar11 = operand_new_reg(0x149,uVar27,lr->sym,(c2_symbol *)lr);
            pcVar12 = operand_new_reg(0x149,uVar27,g_reg_symbols + 0x1f,g_reg_symbols + 0x1f);
            pcVar23 = tuple_new(99,uVar27,pcVar12,pcVar11,insert_fn_00,pcVar23);
            uVar16 = lr->id;
            pcVar23->src->flags11 = pcVar23->src->flags11 | 0x10;
            bitset_set(last_block->live_in,uVar16);
            bitset_set(last_block->live,uVar16);
          }
        }
        iVar25 = 8;
        ppcVar18 = stack_model.slot;
        ppcVar22 = ((pcVar4->u58).x87_stack)->slot;
        for (; iVar25 != 0; iVar25 = iVar25 + -1) {
          *ppcVar22 = *ppcVar18;
          ppcVar18 = ppcVar18 + 1;
          ppcVar22 = ppcVar22 + 1;
        }
      }
    }
    pcVar28 = pcVar4->preds;
    if (pcVar28 != (c2_edge *)0x0) {
LAB_107789ff:
      iVar25 = 0;
      ppcVar18 = ((pcVar28->from->u58).x87_stack)->slot;
LAB_10778a07:
      if (*ppcVar18 != (c2_symbol *)lr) break;
      if (iVar25 < 8) {
        if (pcVar28 != (c2_edge *)0x0) {
          bVar8 = true;
          iVar25 = 8;
          ppcVar18 = ((pcVar28->from->u58).x87_stack)->slot;
          ppcVar22 = stack_model.slot;
          for (; iVar25 != 0; iVar25 = iVar25 + -1) {
            *ppcVar22 = *ppcVar18;
            ppcVar18 = ppcVar18 + 1;
            ppcVar22 = ppcVar22 + 1;
          }
          goto LAB_1075edcf;
        }
        goto LAB_10778a1b;
      }
      goto LAB_10778a14;
    }
LAB_10778a1b:
    requeue_node = alloc_split_node();
    requeue_node->next = (c2_ra_split_block *)0x0;
    requeue_node->block = pcVar4;
    worklist_tail->next = requeue_node;
    worklist_tail = requeue_node;
  } while( true );
  iVar25 = iVar25 + 1;
  ppcVar18 = ppcVar18 + 1;
  if (7 < iVar25) goto LAB_10778a14;
  goto LAB_10778a07;
LAB_10778a14:
  pcVar28 = pcVar28->next_pred;
  if (pcVar28 == (c2_edge *)0x0) goto LAB_10778a1b;
  goto LAB_107789ff;
LAB_1075f034:
  insert_at = pcVar17;
  pcVar11 = pcVar11->next;
  block_tos = iVar25;
  if (pcVar11 == (c2_operand *)0x0) goto LAB_1075f040;
  goto LAB_1075f014;
}

