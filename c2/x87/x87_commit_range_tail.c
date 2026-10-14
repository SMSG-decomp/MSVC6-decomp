c2_bitset *
x87_commit_range_tail
          (c2_tuple *anchor,c2_tuple *use,uint32_t fstp_op,uint16_t type,c2_live_range *lr,
          c2_tuple *walk,int block_tos,int range_live,c2_ra_split_block *worklist_tail,
          c2_ra_split_block *worklist_head,c2_live_range *range,c2_block *block,c2_bitset *scratch,
          c2_function *fn,c2_tuple *insert_at,int depth_overflow,c2_list_cell *def_cursor,
          int operand_pass,c2_tuple *block_end,uint32_t type_dword,c2_x87_block_stack stack,
          c2_bitset *on_stack,c2_bitset *all_ranges)

{
  uint8_t *puVar1;
  int *piVar2;
  ushort uVar3;
  int16_t iVar4;
  c2_live_range *pcVar5;
  c2_edge *pcVar6;
  c2_loop *pcVar7;
  c2_symbol *pcVar8;
  c2_x87_block_stack stack_00;
  c2_edge *edge;
  bool bVar9;
  bool bVar10;
  c2_ra_split_block *pcVar11;
  c2_operand *pcVar12;
  c2_operand *pcVar13;
  c2_tuple *pcVar14;
  c2_bitset *pcVar15;
  c2_bitset *dst;
  uint32_t uVar16;
  c2_ra_split_block *new_node;
  uint32_t uVar17;
  c2_tuple *pcVar18;
  c2_symbol **ppcVar19;
  c2_block *pcVar20;
  c2_bitset *pcVar21;
  c2_bitset *pcVar22;
  c2_symbol **ppcVar23;
  c2_tuple *pcVar24;
  uint8_t uVar25;
  int iVar26;
  c2_tuple *pcVar27;
  uint16_t type_00;
  c2_block *pcVar28;
  c2_block *pcVar29;
  int iVar30;
  undefined4 uStack0000000c;
  code *insert_fn_00;
  c2_insert_fn *insert_fn;
  c2_live_range *dst_owner;
  
  do {
    if (((anchor->src->u18).reg)->cls != '\x02') break;
    anchor = anchor->prev;
  } while (anchor->op == fstp_op);
LAB_1075ec57:
  if (use->op == 0x19e) {
    if (anchor == use) {
      anchor = anchor->prev;
    }
    tuple_unlink_free(use);
  }
  uVar3 = anchor->line;
  if (uVar3 != 0) {
    g_current_line_abs = fn->line_base + (uint)uVar3;
    g_cur_line = uVar3;
  }
  insert_fn = tuple_insert_after;
  pcVar12 = operand_new_reg(0x149,type,lr->sym,(c2_symbol *)lr);
  pcVar13 = operand_new_reg(0x149,type,g_reg_symbols + 0x1f,g_reg_symbols + 0x1f);
  pcVar14 = tuple_new(99,type,pcVar13,pcVar12,insert_fn,anchor);
  pcVar24 = pcVar14->prev;
  uVar3 = pcVar24->type;
  while ((((uVar3 & 0xf000) != 0x4000 && (pcVar24->kind != '\x0e')) && (pcVar24->op != 0x5b))) {
    pcVar24 = pcVar24->prev;
    uVar3 = pcVar24->type;
  }
  uVar25 = pcVar24->flags13;
  pcVar14->flags12 = pcVar24->flags12;
  pcVar14->flags13 = uVar25;
  puVar1 = &pcVar14->src->flags11;
  *puVar1 = *puVar1 | 0x10;
  while (def_cursor = def_cursor->next, def_cursor != (c2_list_cell *)0x0) {
    use = (def_cursor->u04).tuple;
    if (use->kind != '\x19') goto LAB_1075ebd4;
  }
  pcVar15 = bitset_new(6);
  dst = bitset_new(6);
  pcVar28 = range->first_block;
  uVar17 = range->id;
  pcVar29 = range->last_block;
  bVar10 = false;
  worklist_tail = (c2_ra_split_block *)0x0;
  worklist_head = (c2_ra_split_block *)0x0;
  while( true ) {
    uVar16 = bitset_test(pcVar28->live,uVar17);
    new_node = worklist_tail;
    pcVar11 = worklist_head;
    if (uVar16 != 0) {
      new_node = alloc_split_node();
      new_node->block = pcVar28;
      new_node->next = (c2_ra_split_block *)0x0;
      pcVar11 = new_node;
      if (worklist_tail != (c2_ra_split_block *)0x0) {
        worklist_tail->next = new_node;
        pcVar11 = worklist_head;
      }
    }
    worklist_head = pcVar11;
    worklist_tail = new_node;
    if (pcVar28 == pcVar29) break;
    pcVar28 = pcVar28->next;
  }
  insert_at = (c2_tuple *)0x0;
  do {
    while( true ) {
      if (worklist_head == (c2_ra_split_block *)0x0) {
        bitset_free(pcVar15);
        if (dst->chunks == (c2_bitset_chunk *)0x0) {
          uStack0000000c = 0x1075ee5c;
          bitset_free(dst);
          dst = (c2_bitset *)0x0;
        }
        return dst;
      }
      pcVar28 = worklist_head->block;
      new_node = worklist_head->next;
      free_split_node(worklist_head);
      uVar17 = bitset_test(pcVar28->live_in,range->id);
      worklist_head = new_node;
      if (uVar17 != 0) break;
      if (pcVar28->preds == (c2_edge *)0x0) {
        iVar26 = 8;
        ppcVar19 = stack.slot;
        for (; iVar26 != 0; iVar26 = iVar26 + -1) {
          *ppcVar19 = (c2_symbol *)0x0;
          ppcVar19 = ppcVar19 + 1;
        }
      }
      else {
        iVar26 = 8;
        ppcVar19 = ((pcVar28->preds->from->u58).x87_stack)->slot;
        ppcVar23 = stack.slot;
        for (; iVar26 != 0; iVar26 = iVar26 + -1) {
          *ppcVar23 = *ppcVar19;
          ppcVar19 = ppcVar19 + 1;
          ppcVar23 = ppcVar23 + 1;
        }
      }
      bVar9 = false;
LAB_1075edcf:
      if (stack.slot[0] == (c2_symbol *)0x0) {
        iVar26 = 0;
      }
      else {
        iVar26 = 0;
        ppcVar19 = stack.slot;
        do {
          ppcVar23 = ppcVar19 + 1;
          ppcVar19 = ppcVar19 + 1;
          iVar26 = iVar26 + 1;
        } while (*ppcVar23 != (c2_symbol *)0x0);
      }
      iVar26 = iVar26 + -1;
      bitset_copy(pcVar15,all_ranges);
      bitset_andnot(pcVar15,on_stack);
      bitset_and(pcVar15,pcVar28->live_in);
      pcVar14 = pcVar28->end;
      pcVar24 = pcVar28->head;
      block_tos = iVar26;
      while (pcVar24 != pcVar14) {
        pcVar27 = pcVar24;
        if (((pcVar24->flags & 1) != 0) &&
           (((pcVar24->type & 0xf000) == 0x4000 || (pcVar24->kind == '\x0e')))) {
          uVar3 = pcVar24->line;
          if (uVar3 != 0) {
            g_current_line_abs = fn->line_base + (uint)uVar3;
            g_cur_line = uVar3;
          }
          pcVar12 = pcVar24->src;
          if (pcVar12 != (c2_operand *)0x0) {
LAB_1075f014:
            pcVar18 = insert_at;
            if ((((pcVar12->type & 0xf000) != 0x4000) || (pcVar12->kind != '\x01')) ||
               (((pcVar12->flags11 & 0x10) == 0 ||
                (pcVar5 = (pcVar12->u18).range, pcVar5->kind != '\x02')))) goto LAB_1075f034;
            if (pcVar5 != range) {
              if (pcVar5->colour == (c2_register_descriptor *)0x0) {
                bitset_clear(pcVar15,pcVar5->id);
              }
              else {
                stack.slot[iVar26] = (c2_symbol *)0x0;
                iVar26 = iVar26 + -1;
              }
              goto LAB_1075f034;
            }
            if (stack.slot[iVar26] == (c2_symbol *)range) {
              uVar25 = pcVar24->flags13;
              stack.slot[iVar26] = (c2_symbol *)0x0;
              iVar26 = iVar26 + -1;
              if (uVar25 == '\0') {
                bVar9 = false;
              }
              else {
                for (pcVar18 = pcVar24->next;
                    (pcVar18->flags13 != '\0' ||
                    (((((pcVar18->type & 0xf000) != 0x4000 && (pcVar18->kind != '\x0e')) ||
                      (pcVar18->op == 0x163)) || (pcVar18->op == 0x164)))); pcVar18 = pcVar18->next)
                {
                }
                pcVar18 = pcVar18->prev;
                uVar3 = pcVar18->type;
                while (((uVar3 & 0xf000) != 0x4000 && (pcVar18->kind != '\x0e'))) {
                  pcVar18 = pcVar18->prev;
                  uVar3 = pcVar18->type;
                }
                if (pcVar18 == pcVar24) {
                  bVar9 = false;
                  pcVar18 = insert_at;
                }
              }
              goto LAB_1075f034;
            }
            pcVar27 = pcVar24->prev;
            pcVar18 = pcVar24->next;
            ppcVar19 = stack.slot + iVar26 + -1;
            pcVar8 = stack.slot[iVar26 + -1];
            while (pcVar8 != (c2_symbol *)range) {
              piVar2 = (int *)(ppcVar19 + -1);
              pcVar18 = pcVar18->next;
              ppcVar19 = ppcVar19 + -1;
              pcVar8 = (c2_symbol *)*piVar2;
            }
            tuple_move_after(pcVar18,pcVar24);
            block_tos = iVar26;
            goto LAB_1075efba;
          }
LAB_1075f040:
          iVar30 = iVar26;
          iVar26 = block_tos;
          for (pcVar12 = pcVar24->dst; pcVar12 != (c2_operand *)0x0; pcVar12 = pcVar12->next) {
            if ((((pcVar12->type & 0xf000) == 0x4000) && (pcVar12->kind == '\x01')) &&
               (dst_owner = (pcVar12->u18).range, dst_owner->kind == '\x02')) {
              if (dst_owner->colour == (c2_register_descriptor *)0x0) {
                bitset_set(pcVar15,dst_owner->id);
              }
              else {
                iVar26 = 0;
                if (-1 < iVar30) {
                  ppcVar19 = stack.slot;
                  do {
                    if ((c2_live_range *)*ppcVar19 == dst_owner) {
                      if (iVar26 <= iVar30) goto LAB_1075ef86;
                      break;
                    }
                    iVar26 = iVar26 + 1;
                    ppcVar19 = ppcVar19 + 1;
                  } while (iVar26 <= iVar30);
                }
                iVar30 = iVar30 + 1;
                stack.slot[iVar26] = (c2_symbol *)dst_owner;
                if (range == dst_owner) {
                  bVar9 = true;
                }
              }
            }
LAB_1075ef86:
            iVar26 = iVar30;
          }
          if (bVar9) {
            uVar25 = pcVar24->flags12 + '\x01';
            pcVar24->flags12 = uVar25;
            if (uVar25 == '\b') {
              bVar10 = true;
            }
            if (pcVar24 == insert_at) {
              bVar9 = false;
              insert_at = (c2_tuple *)0x0;
            }
          }
          block_tos = iVar26;
          if ((((bVar10) && (pcVar24->flags13 == '\0')) && (pcVar24->op != 0x163)) &&
             (pcVar24->op != 0x164)) {
            bVar10 = false;
            if (pcVar15->chunks != (c2_bitset_chunk *)0x0) {
              insert_split_marker_after_spill(pcVar24,pcVar15);
              bitset_or(dst,pcVar15);
              pcVar28->flags = pcVar28->flags | 0x40000;
            }
            pcVar24 = pcVar24->prev;
            uVar25 = pcVar24->kind;
            while (uVar25 != '\x19') {
              if ((((pcVar24->flags & 1) != 0) && (pcVar24->op != 0x163)) && (pcVar24->op != 0x164))
              {
                operand_pass = 0;
                do {
                  if (operand_pass == 0) {
                    if (pcVar24->flags13 != '\0') {
                      pcVar12 = pcVar24->dst;
                      goto joined_r0x10778bcb;
                    }
                  }
                  else {
                    pcVar12 = pcVar24->src;
joined_r0x10778bcb:
                    for (; pcVar12 != (c2_operand *)0x0; pcVar12 = pcVar12->next) {
                      if ((((pcVar12->type & 0xf000) == 0x4000) && (pcVar12->kind == '\x01')) &&
                         ((pcVar5 = (pcVar12->u18).range, pcVar5->kind == '\x02' &&
                          ((pcVar5->colour == (c2_register_descriptor *)0x0 && (pcVar5 != range)))))
                         ) {
                        pcVar22 = bitset_new(6);
                        bitset_set(pcVar22,pcVar5->id);
                        insert_split_marker_after_spill(pcVar24,pcVar22);
                        insert_split_marker_after_spill(pcVar24->prev,pcVar22);
                        bitset_free(pcVar22);
                        bitset_set(dst,((pcVar12->u18).range)->id);
                        pcVar28->flags = pcVar28->flags | 0x40000;
                      }
                    }
                  }
                  operand_pass = operand_pass + 1;
                } while (operand_pass < 2);
                if (pcVar24->flags13 == '\0') break;
              }
              pcVar24 = pcVar24->prev;
              uVar25 = pcVar24->kind;
            }
          }
        }
LAB_1075efba:
        pcVar24 = pcVar27->next;
      }
      if (bVar9) {
        pcVar6 = pcVar28->succs;
        while (edge = pcVar6, edge != (c2_edge *)0x0) {
          pcVar29 = edge->to;
          pcVar6 = edge->next_succ;
          uVar17 = bitset_test(pcVar29->live_in,range->id);
          if (uVar17 == 0) {
            if (pcVar29->preds->next_pred == (c2_edge *)0x0) {
              pcVar24 = pcVar29->head;
              if (pcVar24->kind == '\x19') {
                do {
                  pcVar24 = pcVar24->next;
                  if (pcVar24 == pcVar29->end) {
                    pcVar24 = pcVar24->prev;
                    break;
                  }
                } while (pcVar24->kind == '\x19');
              }
              if ((pcVar24->flags & 1) != 0) {
                pcVar24 = pcVar24->prev;
              }
              ppcVar19 = stack.slot + block_tos;
              pcVar8 = stack.slot[block_tos];
              while (pcVar8 != (c2_symbol *)range) {
                piVar2 = (int *)(ppcVar19 + -1);
                pcVar24 = pcVar24->next;
                ppcVar19 = ppcVar19 + -1;
                pcVar8 = (c2_symbol *)*piVar2;
              }
            }
            else {
              pcVar20 = split_edge_with_new_block(fn,edge,pcVar28,pcVar29);
              pcVar22 = pcVar29->live_in;
              pcVar21 = bitset_clone(pcVar22);
              pcVar20->live_in = pcVar21;
              pcVar21 = bitset_clone(pcVar22);
              pcVar20->live_out = pcVar21;
              pcVar22 = bitset_clone(pcVar22);
              pcVar20->live = pcVar22;
              pcVar22 = bitset_new(8);
              pcVar20->set24 = pcVar22;
              pcVar22 = bitset_new(8);
              pcVar20->set28 = pcVar22;
              pcVar22 = bitset_new(6);
              iVar4 = pcVar29->loop_depth;
              pcVar20->set4c = pcVar22;
              pcVar7 = pcVar29->loop;
              pcVar20->loop_depth = iVar4;
              pcVar20->loop = pcVar7;
              ppcVar23 = arena_alloc(4,0x20);
              ppcVar19 = ((pcVar28->u58).x87_stack)->slot;
              (pcVar20->u58).x87_stack = (c2_x87_block_stack *)ppcVar23;
              pcVar24 = pcVar20->head;
              for (iVar26 = 8; iVar26 != 0; iVar26 = iVar26 + -1) {
                *ppcVar23 = *ppcVar19;
                ppcVar19 = ppcVar19 + 1;
                ppcVar23 = ppcVar23 + 1;
              }
              pcVar14 = pcVar24->next;
              pcVar29 = pcVar20;
              if (pcVar14->kind == '\x1a') {
                pcVar24 = pcVar14;
              }
            }
            uVar3 = pcVar24->line;
            if (uVar3 != 0) {
              g_current_line_abs = fn->line_base + (uint)uVar3;
              g_cur_line = uVar3;
            }
            insert_fn_00 = tuple_insert_after;
            type_00 = (uint16_t)type_dword;
            pcVar12 = operand_new_reg(0x149,type_00,range->sym,(c2_symbol *)range);
            pcVar13 = operand_new_reg(0x149,type_00,g_reg_symbols + 0x1f,g_reg_symbols + 0x1f);
            pcVar24 = tuple_new(99,type_00,pcVar13,pcVar12,insert_fn_00,pcVar24);
            uVar17 = range->id;
            pcVar24->src->flags11 = pcVar24->src->flags11 | 0x10;
            bitset_set(pcVar29->live_in,uVar17);
            bitset_set(pcVar29->live,uVar17);
          }
        }
        iVar26 = 8;
        ppcVar19 = stack.slot;
        ppcVar23 = ((pcVar28->u58).x87_stack)->slot;
        for (; iVar26 != 0; iVar26 = iVar26 + -1) {
          *ppcVar23 = *ppcVar19;
          ppcVar19 = ppcVar19 + 1;
          ppcVar23 = ppcVar23 + 1;
        }
      }
    }
    pcVar6 = pcVar28->preds;
joined_r0x107789fd:
    if (pcVar6 != (c2_edge *)0x0) {
      iVar26 = 0;
      ppcVar19 = ((pcVar6->from->u58).x87_stack)->slot;
LAB_10778a07:
      if (*ppcVar19 != (c2_symbol *)range) goto code_r0x10778a0b;
      if (iVar26 < 8) {
        if (pcVar6 != (c2_edge *)0x0) {
          bVar9 = true;
          iVar26 = 8;
          ppcVar19 = ((pcVar6->from->u58).x87_stack)->slot;
          ppcVar23 = stack.slot;
          for (; iVar26 != 0; iVar26 = iVar26 + -1) {
            *ppcVar23 = *ppcVar19;
            ppcVar19 = ppcVar19 + 1;
            ppcVar23 = ppcVar23 + 1;
          }
          goto LAB_1075edcf;
        }
        goto LAB_10778a1b;
      }
      goto LAB_10778a14;
    }
LAB_10778a1b:
    new_node = alloc_split_node();
    new_node->next = (c2_ra_split_block *)0x0;
    new_node->block = pcVar28;
    worklist_tail->next = new_node;
    worklist_tail = new_node;
  } while( true );
LAB_1075ebd4:
  while (((use->flags & 1) == 0 ||
         (pcVar12 = find_src_reg_operand((c2_symbol *)lr,use), pcVar12 == (c2_operand *)0x0))) {
    use = use->prev;
  }
  pcVar12->flags11 = pcVar12->flags11 & 0xef;
  anchor = use;
  if (use != (def_cursor->u04).tuple) {
    anchor = use->next;
    while ((anchor != (def_cursor->u04).tuple &&
           ((((anchor->flags & 1) == 0 || (pcVar12 = anchor->dst, pcVar12 == (c2_operand *)0x0)) ||
            (((pcVar12->type & 0xf000) != 0x4000 ||
             ((pcVar12->kind != '\x01' || (((pcVar12->u18).reg)->cls != '\x02'))))))))) {
      anchor = anchor->next;
    }
  }
  if (((anchor->dst != (c2_operand *)0x0) && ((anchor->dst->type & 0xf000) == 0x4000)) &&
     (anchor = anchor->prev, anchor->op == 99)) {
    stack_00.slot[1] = stack.slot[1];
    stack_00.slot[2] = stack.slot[2];
    stack_00.slot[3] = stack.slot[3];
    stack_00.slot[4] = stack.slot[4];
    stack_00.slot[5] = stack.slot[5];
    stack_00.slot[6] = stack.slot[6];
    stack_00.slot[7] = stack.slot[7];
    stack_00.slot[0] = stack.slot[0];
    pcVar15 = x87_commit_range_tail
                        (anchor,use,99,type,lr,walk,block_tos,range_live,worklist_tail,worklist_head
                         ,range,block,scratch,fn,insert_at,depth_overflow,def_cursor,operand_pass,
                         block_end,type_dword,stack_00,on_stack,all_ranges);
    return pcVar15;
  }
  goto LAB_1075ec57;
code_r0x10778a0b:
  iVar26 = iVar26 + 1;
  ppcVar19 = ppcVar19 + 1;
  if (7 < iVar26) goto LAB_10778a14;
  goto LAB_10778a07;
LAB_10778a14:
  pcVar6 = pcVar6->next_pred;
  goto joined_r0x107789fd;
LAB_1075f034:
  insert_at = pcVar18;
  pcVar12 = pcVar12->next;
  block_tos = iVar26;
  if (pcVar12 == (c2_operand *)0x0) goto LAB_1075f040;
  goto LAB_1075f014;
}

