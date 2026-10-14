void __fastcall thread_jumps_at_block_end(c2_block *block,c2_function *fn)

{
  byte bVar1;
  c2_operand *pcVar2;
  c2_loop *outer;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  c2_block *to;
  c2_block *block_00;
  c2_tuple *pcVar5;
  c2_tuple *pcVar6;
  bool bVar7;
  c2_tuple *e;
  c2_function *fn_00;
  uint8_t uVar8;
  ushort uVar9;
  c2_tuple *pcVar10;
  c2_tuple *pcVar11;
  int iVar12;
  c2_edge *pcVar13;
  c2_fe_symbol *label_sym;
  uint uVar14;
  uint32_t b_lo_00;
  byte bVar15;
  uint32_t a_hi;
  uint32_t a_lo_00;
  uint32_t b_hi;
  bool bVar16;
  uint16_t uVar17;
  c2_symbol *pcVar18;
  c2_symbol *pcVar19;
  int is_signed;
  c2_tuple *target_label;
  c2_edge *next_edge;
  c2_block *succ;
  c2_function *local_34;
  c2_block *local_30;
  uint32_t cc;
  int reuse_block_cmp;
  c2_tuple *block_cmp;
  c2_tuple *block_branch;
  c2_tuple *branch_clone;
  c2_tuple *chain_cmp;
  uint32_t branch_cc;
  uint32_t a_lo;
  uint32_t local_c;
  uint32_t b_lo;
  uint32_t local_4;
  c2_block *succ_block;
  
  if (((fn->flags & 0x40) == 0) && ((fn->fsym->attrs & 0x1000) == 0)) {
    reuse_block_cmp = 0;
    local_34 = fn;
    local_30 = block;
    block_branch = tuple_prev_real_in_block(block->end);
    if (block_branch != (c2_tuple *)0x0) {
      if (block_branch->op == 0x18b) {
        return;
      }
      if (((((block_branch->kind == '\x11') &&
            ((block_branch->u20).cond_cells != (c2_cond_cell *)0x0)) &&
           (pcVar2 = block_branch->src, pcVar2->kind == '\x04')) &&
          ((*(int *)((int)&pcVar2->sym->u30 + 2) != 0 &&
           (block_cmp = pcVar2->next->sym->def, block_cmp->op == 0x17d)))) &&
         ((block_cmp->src->kind != '\x06' && (block_cmp->src->next->kind != '\x06')))) {
        reuse_block_cmp = 1;
      }
    }
    next_edge = (c2_edge *)block->succs;
    while (e = (c2_tuple *)next_edge, e != (c2_tuple *)0x0) {
      next_edge = (c2_edge *)e->next;
      succ = (c2_block *)e->prev;
      if (((block->next != succ) || (block = local_30, g_opt_favor_speed != 0)) &&
         ((pcVar10 = follow_trivial_branch_chain(&succ), block = local_30, chain_cmp = pcVar10,
          pcVar10 != (c2_tuple *)0x0 && (local_30->rpo <= succ->rpo)))) {
        outer = local_30->loop;
        if (((outer == succ->loop) ||
            ((outer != (c2_loop *)0x0 &&
             (iVar12 = loop_is_within(succ->loop,outer), block = local_30, iVar12 == 0)))) &&
           (block = local_30, pcVar10->op == 0x17d)) {
          pcVar2 = pcVar10->src;
          pcVar3 = pcVar2->next;
          if ((((pcVar2->kind != '\x02') || ((pcVar2->flags & 0x40) == 0)) &&
              ((pcVar3->kind != '\x02' || ((pcVar3->flags & 0x40) == 0)))) &&
             ((pcVar11 = find_next_use_of_dst(pcVar10,(c2_operand **)0x0), block = local_30,
              pcVar11->prev == pcVar10 && (pcVar11->kind != '\x10')))) {
            pcVar10 = tuple_new_compare(0x17d,pcVar10->type,pcVar2,pcVar3,(c2_insert_fn *)0x0,
                                        (c2_tuple *)0x0);
            branch_clone = tuple_new_branch(0x185,(uint8_t)pcVar11->type,
                                            *(c2_node **)((int)&pcVar11->src->sym->u30 + 2),
                                            pcVar10->dst,pcVar10,(c2_insert_fn *)0x0,(c2_tuple *)0x0
                                           );
            pcVar10->next = branch_clone;
            branch_clone->prev = pcVar10;
            iVar12 = cse_replace_operands(pcVar10);
            if (iVar12 == 0) goto LAB_1070f3f4;
            pcVar2 = pcVar10->src;
            bVar7 = false;
            pcVar3 = pcVar2->next;
            iVar12 = operand_compare(pcVar2,pcVar3);
            if (iVar12 == 0) {
              bVar7 = true;
              uVar9 = pcVar10->type & 0xf000;
              a_lo = 1;
              b_lo = 1;
              local_c = 0;
              local_4 = local_c;
              if (uVar9 == 0x4000) {
                is_signed = 1;
              }
              else {
                is_signed = (int)(uVar9 == 0x1000);
              }
              goto switchD_1070f4bf_default;
            }
            if ((pcVar2->kind != '\t') || (pcVar3->kind != '\t')) {
switchD_10790818_default:
              pcVar4 = pcVar10->src;
              if ((pcVar4->kind == '\x03') && (pcVar4->next->kind == '\x03')) {
                is_signed = 0;
                if (pcVar4->sym->storage == pcVar4->next->sym->storage) {
                  compare_consumer_condition(pcVar10);
                  bVar7 = true;
                  a_lo = pcVar10->src->sym->offset;
                  local_c = (int)a_lo >> 0x1f;
                  b_lo = pcVar10->src->next->sym->offset;
                  local_4 = (int)b_lo >> 0x1f;
                }
                else {
                  compare_consumer_condition(pcVar10);
LAB_10790956:
                  a_lo = 0;
                  b_lo = 1;
LAB_10790969:
                  local_c = 0;
                  is_signed = 0;
                  bVar7 = true;
                  local_4 = 0;
                }
              }
              else if ((pcVar10->type & 0xf000) == 0x2000) {
                is_signed = 0;
                uVar8 = compare_consumer_condition(pcVar10);
                cc = CONCAT31(cc._1_3_,uVar8);
                switch(uVar8) {
                case '\x03':
                  if ((pcVar3->kind == '\a') &&
                     ((pcVar3->u18).reg == (c2_symbol *)0x0 && pcVar3->tag == 0)) {
thread_jumps_at_block_end_fold_unsigned_vs_zero:
                    a_lo = 1;
                    b_lo = 0;
                    goto LAB_10790969;
                  }
                  break;
                case '\x04':
                  if (pcVar2->kind == '\a') {
                    bVar16 = (pcVar2->u18).reg == (c2_symbol *)0x0 && pcVar2->tag == 0;
LAB_1070f6d5:
                    if (bVar16) goto LAB_10790956;
                  }
                  break;
                case '\x05':
                  if (pcVar2->kind == '\a') {
                    bVar16 = (pcVar2->u18).reg == (c2_symbol *)0x0 && pcVar2->tag == 0;
                    goto LAB_1070f6d5;
                  }
                  break;
                case '\x06':
                  if ((pcVar3->kind == '\a') &&
                     ((pcVar3->u18).reg == (c2_symbol *)0x0 && pcVar3->tag == 0))
                  goto thread_jumps_at_block_end_fold_unsigned_vs_zero;
                }
              }
              goto switchD_1070f4bf_default;
            }
            uVar8 = compare_consumer_condition(pcVar10);
            cc = CONCAT31(cc._1_3_,uVar8);
            is_signed = 0;
            switch(uVar8) {
            case '\x01':
              pcVar19 = pcVar3->sym;
              pcVar18 = pcVar2->sym;
              break;
            case '\x02':
              pcVar19 = pcVar3->sym;
              pcVar18 = pcVar2->sym;
              break;
            case '\x03':
              pcVar19 = pcVar3->sym;
              pcVar18 = pcVar2->sym;
              uVar17 = 4;
              goto LAB_10790881;
            case '\x04':
              pcVar19 = pcVar3->sym;
              pcVar18 = pcVar2->sym;
              uVar17 = 2;
              goto LAB_10790829;
            case '\x05':
              pcVar19 = pcVar3->sym;
              pcVar18 = pcVar2->sym;
              uVar17 = 5;
LAB_10790881:
              b_lo = float_const_compare_mask
                               (uVar17,(c2_float_const *)pcVar18,(c2_float_const *)pcVar19);
              local_4 = (int)b_lo >> 0x1f;
              if (b_lo == 0) {
                bVar7 = true;
                a_lo = 1;
                local_c = 0;
              }
              else {
                bVar7 = true;
                a_lo = 0;
                local_c = 0;
              }
              goto switchD_1070f4bf_default;
            case '\x06':
              pcVar19 = pcVar3->sym;
              pcVar18 = pcVar2->sym;
              uVar17 = 3;
LAB_10790829:
              a_lo = float_const_compare_mask
                               (uVar17,(c2_float_const *)pcVar18,(c2_float_const *)pcVar19);
              local_c = (int)a_lo >> 0x1f;
              if (a_lo == 0) {
                bVar7 = true;
                b_lo = 1;
                local_4 = 0;
              }
              else {
                bVar7 = true;
                b_lo = 0;
                local_4 = 0;
              }
              goto switchD_1070f4bf_default;
            default:
              goto switchD_10790818_default;
            }
            bVar7 = true;
            a_lo = float_const_compare_mask(1,(c2_float_const *)pcVar18,(c2_float_const *)pcVar19);
            local_c = (int)a_lo >> 0x1f;
            b_lo = 1;
            local_4 = 0;
switchD_1070f4bf_default:
            b_lo_00 = b_lo;
            uVar14 = is_signed;
            a_hi = local_c;
            a_lo_00 = a_lo;
            b_hi = local_4;
            if (bVar7) {
LAB_1070f560:
              iVar12 = fold_constant_compare
                                 (uVar14,chain_cmp->type & 0xfff,a_lo_00,a_hi,b_lo_00,b_hi,
                                  (uint8_t)pcVar11->type);
              succ_block = succ;
              to = (c2_block *)e->prev;
              block_00 = *(c2_block **)&e->kind;
              pcVar6 = to->head->next;
              chain_cmp = e;
              if (iVar12 == 0) {
                pcVar5 = pcVar11->next;
                if (((pcVar5->kind == '\x11') && ((pcVar5->u20).cond_cells == (c2_cond_cell *)0x0))
                   && (pcVar5->op != 0x18b)) {
                  target_label = *(c2_tuple **)((int)&pcVar5->src->sym->u30 + 2);
                }
                else {
                  target_label = pcVar5->next;
                  if (target_label->kind != '\x1a') {
                    if (pcVar11->line != 0) {
                      g_current_line_abs = local_34->line_base + (uint)pcVar11->line;
                      g_cur_line = pcVar11->line;
                    }
                    label_sym = label_symbol_new();
                    target_label = tuple_new_label(label_sym);
                    tuple_insert_after(pcVar11->next,target_label);
                    (target_label->u14).block = succ_block->next;
                  }
                }
              }
              else {
                target_label = *(c2_tuple **)((int)&pcVar11->src->sym->u30 + 2);
              }
              fn_00 = local_34;
              pcVar11 = tuple_prev_real_in_block(block_00->end);
              if (pcVar11 == (c2_tuple *)0x0) {
LAB_1070f7cb:
                pcVar11 = tuple_next_real(block_00->end);
                if (pcVar11->line != 0) {
                  g_current_line_abs = fn_00->line_base + (uint)pcVar11->line;
                  g_cur_line = pcVar11->line;
                }
                tuple_new_jmp_before(target_label,block_00->end);
              }
              else {
                bVar15 = pcVar11->kind;
                if (((bVar15 == 0x11) && ((pcVar11->u20).cond_cells == (c2_cond_cell *)0x0)) &&
                   ((pcVar11->op != 0x18b &&
                    (*(c2_tuple **)((int)&pcVar11->src->sym->u30 + 2) != pcVar6)))) {
                  pcVar11 = tuple_prev_real_before_boundary(pcVar11);
                }
                else {
                  if (((1 << (bVar15 & 0x1f) & 0xa0000U) == 0) ||
                     (((bVar15 == 0x11 &&
                       (((pcVar11->u20).cond_cells != (c2_cond_cell *)0x0 || (pcVar11->op == 0x18b))
                       )) && (*(c2_tuple **)((int)&pcVar11->src->sym->u30 + 2) != pcVar6))))
                  goto LAB_1070f7cb;
                  if ((bVar15 == 0x13) && ((pcVar11->u20).default_label != pcVar6)) {
                    for (pcVar11 = (c2_tuple *)(pcVar11->u24).cases;
                        (pcVar11 != (c2_tuple *)0x0 && ((pcVar11->u14).arg != pcVar6));
                        pcVar11 = pcVar11->next) {
                    }
                  }
                }
                tuple_retarget(pcVar11,(c2_node *)target_label,1);
              }
              if (to == (target_label->u14).block) {
                next_edge = (c2_edge *)e->next;
              }
              else {
                pcVar13 = flow_edge_find(block_00,to);
                if (pcVar13 == (c2_edge *)0x0) {
                  next_edge = (c2_edge *)chain_cmp;
                }
                else {
                  do {
                    next_edge = cfg_add_edge(fn_00,block_00,(target_label->u14).block);
                    compute_dominators(fn_00);
                    remove_loop_back_edge(block_00,to,fn_00);
                    pcVar13 = flow_edge_find(block_00,to);
                  } while (pcVar13 != (c2_edge *)0x0);
                }
              }
            }
            else {
              pcVar2 = pcVar10->src;
              if ((pcVar2->kind == '\a') &&
                 ((pcVar3 = pcVar2->next, pcVar3 == (c2_operand *)0x0 || (pcVar3->kind == '\a')))) {
                a_lo_00 = (pcVar2->u18).lo;
                a_hi = pcVar2->tag;
                if (pcVar3 == (c2_operand *)0x0) {
                  b_lo_00 = 0;
                  b_hi = 0;
                }
                else {
                  b_lo_00 = (pcVar3->u18).lo;
                  b_hi = pcVar3->tag;
                }
                uVar14 = (uint)((pcVar10->type & 0xf000) == 0x1000);
                goto LAB_1070f560;
              }
LAB_1070f3f4:
              pcVar6 = block_cmp;
              if (reuse_block_cmp != 0) {
                bVar15 = (byte)branch_clone->type;
                branch_cc = CONCAT31(branch_cc._1_3_,bVar15);
                iVar12 = operand_compare(pcVar10->src,block_cmp->src);
                if ((iVar12 != 0) ||
                   (iVar12 = operand_compare(pcVar10->src->next,pcVar6->src->next), iVar12 != 0)) {
                  iVar12 = operand_compare(pcVar10->src,pcVar6->src->next);
                  if ((iVar12 != 0) ||
                     (iVar12 = operand_compare(pcVar10->src->next,block_cmp->src), iVar12 != 0))
                  goto LAB_1070f437;
                  bVar15 = g_cond_swapped_operands[branch_cc & 0xff];
                }
                bVar1 = (byte)block_branch->type;
                if (bVar15 == bVar1) {
                  uVar14 = 1;
                }
                else {
                  if (bVar15 != g_cond_inverse[bVar1]) goto LAB_1070f437;
                  uVar14 = 0;
                }
                pcVar6 = ((c2_block *)e->prev)->head->next;
                if ((pcVar6->kind != '\x1a') ||
                   (*(c2_tuple **)((int)&block_branch->src->sym->u30 + 2) != pcVar6)) {
                  uVar14 = (uint)(uVar14 == 0);
                }
                next_edge = thread_jump_to_successor(local_34,(c2_edge *)e,pcVar11,uVar14,succ);
              }
            }
LAB_1070f437:
            node_free((c2_node *)pcVar10);
            node_free((c2_node *)branch_clone);
            block = local_30;
          }
        }
      }
    }
  }
  return;
}

