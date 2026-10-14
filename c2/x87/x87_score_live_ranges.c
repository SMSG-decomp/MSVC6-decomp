void __fastcall x87_score_live_ranges(c2_function *fn,c2_bitset *ranges)

{
  uint8_t uVar1;
  ushort uVar2;
  c2_block *pcVar3;
  c2_register_preference *pcVar4;
  c2_tuple *pcVar5;
  c2_operand *pcVar6;
  c2_edge *pcVar7;
  c2_block *pcVar8;
  c2_tuple *pcVar9;
  bool bVar10;
  c2_bitset *dst;
  c2_bitset *dst_00;
  int iVar11;
  uint32_t uVar12;
  int32_t iVar13;
  c2_list_cell *def_cell;
  uint32_t uVar14;
  c2_list_cell *end_cell;
  c2_live_range *pcVar15;
  c2_list_cell *exit_def;
  c2_symbol **ppcVar16;
  c2_tuple *pcVar17;
  c2_tuple *t;
  c2_tuple *scan;
  c2_symbol **ppcVar18;
  int local_1c;
  c2_live_range *use_range;
  
  dst = bitset_new(6);
  dst_00 = bitset_new(6);
  pcVar3 = fn->cfg->first;
  do {
    if (pcVar3 == (c2_block *)0x0) {
      bitset_free(dst);
      bitset_free(dst_00);
      return;
    }
    if ((pcVar3->u58).x87_stack == (c2_x87_block_stack *)0x0) {
      ppcVar16 = arena_alloc(4,0x20);
      (pcVar3->u58).x87_stack = (c2_x87_block_stack *)ppcVar16;
      iVar11 = 8;
      ppcVar18 = ((pcVar3->preds->from->u58).x87_stack)->slot;
      for (; iVar11 != 0; iVar11 = iVar11 + -1) {
        *ppcVar16 = *ppcVar18;
        ppcVar18 = ppcVar18 + 1;
        ppcVar16 = ppcVar16 + 1;
      }
    }
    iVar11 = bitset_intersects(pcVar3->live,ranges);
    if (iVar11 != 0) {
      bitset_copy(dst,ranges);
      bitset_and(dst,pcVar3->live_in);
      uVar12 = bitset_iter_next(dst);
      while (uVar12 != 0xffffffff) {
        pcVar15 = live_range_from_id(uVar12);
        if (pcVar15->first_block == (c2_block *)0x0) {
          pcVar15->first_block = pcVar3;
        }
        pcVar15->last_block = pcVar3;
        uVar12 = bitset_iter_next((c2_bitset *)0x0);
      }
      if (g_opt_favor_speed == 0) {
        local_1c = 1;
      }
      else {
        local_1c = 1 << ((byte)pcVar3->loop_depth & 0x1f);
      }
      t = pcVar3->head;
      if (t != pcVar3->end) {
        do {
          pcVar5 = t->next;
          if (((t->flags & 1) != 0) && ((t->type & 0xf000) == 0x4000)) {
            uVar2 = t->line;
            if (uVar2 != 0) {
              g_current_line_abs = fn->line_base + (uint)uVar2;
              g_cur_line = uVar2;
            }
            for (pcVar6 = t->src; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
              if (((((pcVar6->type & 0xf000) == 0x4000) && (pcVar6->kind == '\x01')) &&
                  (use_range = (pcVar6->u18).range, use_range->kind == '\x02')) &&
                 ((use_range->flags5 & 1) != 0)) {
                if (t->op == 0x164) {
                  if (((g_opt_favor_speed == 0) || (pcVar3->loop == (c2_loop *)0x0)) ||
                     (uVar12 = bitset_test(pcVar3->loop->candidates,((pcVar6->sym->u30).ra)->id),
                     uVar12 != 0)) {
                    iVar11 = x87_def_benefit(pcVar6->sym,fn);
                    iVar13 = use_range->priority - iVar11 * local_1c;
                    use_range->weight = use_range->weight - iVar11 * local_1c;
                    goto LAB_1075d972;
                  }
                }
                else if (((pcVar6->flags11 & 0x10) == 0) ||
                        (iVar13 = x87_result_feeds_store_or_compare(t), iVar13 != 0)) {
                  if (t->op == 0x60) {
                    if ((pcVar6->flags11 & 0x10) == 0) {
                      iVar11 = x87_use_benefit(pcVar6->sym,fn);
                    }
                    else {
                      iVar11 = x87_fld_last_use_benefit(pcVar6->sym,fn);
                    }
                  }
                  else {
                    iVar11 = x87_use_benefit(pcVar6->sym,fn);
                  }
                  iVar13 = use_range->priority + iVar11 * local_1c;
                  use_range->weight = use_range->weight + iVar11 * local_1c;
LAB_1075d972:
                  use_range->priority = iVar13;
                }
                if ((pcVar6->flags11 & 0x10) != 0) {
                  bVar10 = false;
                  scan = t;
                  if ((t->op != 0x164) && (t != (c2_tuple *)0x0)) {
                    do {
                      if ((scan->flags & 1) != 0) {
                        uVar12 = scan->op;
                        if (((uVar12 == 99) && (scan->dst->kind == '\x01')) &&
                           ((scan->dst->u18).reg == (c2_symbol *)use_range)) {
                          bVar10 = true;
                          pcVar6->flags11 = pcVar6->flags11 & 0xef;
                        }
                        if (((scan->flags13 == '\0') && (uVar12 != 0x163)) && (uVar12 != 0x164))
                        break;
                      }
                      scan = scan->next;
                    } while (scan != (c2_tuple *)0x0);
                    if (bVar10) goto LAB_1075dba5;
                  }
                  def_cell = alloc_split_cell();
                  def_cell->next = (c2_list_cell *)use_range->u38;
                  uVar12 = use_range->id;
                  (def_cell->u04).tuple = scan;
                  (use_range->u38).x87_defs = def_cell;
                  bitset_clear(dst,uVar12);
                }
              }
LAB_1075dba5:
            }
            for (pcVar6 = t->dst; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
              if ((((pcVar6->type & 0xf000) == 0x4000) && (pcVar6->kind == '\x01')) &&
                 ((pcVar15 = (pcVar6->u18).range, pcVar15->kind == '\x02' &&
                  ((pcVar15->flags5 & 1) != 0)))) {
                if (t->op == 0x163) {
                  iVar11 = x87_fld_last_use_benefit(pcVar6->sym,fn);
                  pcVar15->priority = pcVar15->priority - iVar11 * local_1c;
                  pcVar17 = t->prev;
                  pcVar15->weight = pcVar15->weight - iVar11 * local_1c;
                  uVar1 = pcVar17->kind;
                  while ((uVar1 != '\x19' &&
                         ((((pcVar17->flags & 1) == 0 || (pcVar17->op == 0x163)) ||
                          (pcVar17->op == 0x164))))) {
                    pcVar17 = pcVar17->prev;
                    uVar1 = pcVar17->kind;
                  }
                  if ((pcVar17->flags & 1) != 0) {
                    do {
                      if (((pcVar17->flags13 == '\0') && (pcVar17->op != 0x163)) &&
                         (pcVar17->op != 0x164)) break;
                      pcVar17 = pcVar17->prev;
                    } while ((pcVar17->flags & 1) != 0);
                    if (pcVar17->next->op == 0x164) {
                      pcVar17 = pcVar17->next;
                    }
                    tuple_move_after(pcVar17,t);
                  }
                }
                else {
                  iVar11 = x87_def_benefit(pcVar6->sym,fn);
                  pcVar15->weight = pcVar15->weight + iVar11 * local_1c;
                  pcVar15->priority = pcVar15->priority + iVar11 * local_1c;
                }
                uVar12 = pcVar15->id;
                uVar14 = bitset_test(dst,uVar12);
                if (uVar14 == 0) {
                  end_cell = alloc_split_cell();
                  pcVar4 = pcVar15->prefs;
                  (end_cell->u04).tuple = t;
                  end_cell->next = (c2_list_cell *)pcVar4;
                  pcVar15->prefs = (c2_register_preference *)end_cell;
                  if (pcVar15->first_block == (c2_block *)0x0) {
                    pcVar15->first_block = pcVar3;
                  }
                  pcVar15->last_block = pcVar3;
                  bitset_set(dst,uVar12);
                }
              }
            }
          }
          t = pcVar5;
        } while (pcVar5 != pcVar3->end);
      }
      if (dst->chunks != (c2_bitset_chunk *)0x0) {
        for (pcVar7 = pcVar3->succs; pcVar7 != (c2_edge *)0x0; pcVar7 = pcVar7->next_succ) {
          bitset_copy(dst_00,dst);
          pcVar8 = pcVar7->to;
          bitset_andnot(dst_00,pcVar8->live_in);
          if (dst_00->chunks != (c2_bitset_chunk *)0x0) {
            if (g_opt_favor_speed != 0) {
              local_1c = 1 << ((byte)pcVar8->loop_depth & 0x1f);
            }
            pcVar5 = pcVar8->head;
            uVar12 = bitset_iter_next(dst_00);
            while (uVar12 != 0xffffffff) {
              pcVar15 = live_range_from_id(uVar12);
              pcVar15->weight = pcVar15->weight - local_1c;
              pcVar17 = (pcVar15->u38).def;
              pcVar15->priority = pcVar15->priority - local_1c;
              for (pcVar9 = pcVar17; pcVar9 != (c2_tuple *)0x0; pcVar9 = pcVar9->next) {
                if ((c2_tuple *)pcVar9->op == pcVar5) {
                  if (pcVar9 != (c2_tuple *)0x0) goto LAB_1075dcf6;
                  break;
                }
              }
              exit_def = alloc_split_cell();
              (exit_def->u04).tuple = pcVar5;
              exit_def->next = (c2_list_cell *)pcVar17;
              (pcVar15->u38).x87_defs = exit_def;
LAB_1075dcf6:
              uVar12 = bitset_iter_next((c2_bitset *)0x0);
            }
          }
        }
      }
    }
    pcVar3 = pcVar3->next;
  } while( true );
}

