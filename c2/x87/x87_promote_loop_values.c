void x87_promote_loop_values(void)

{
  c2_symbol **ppcVar1;
  uint8_t uVar2;
  uint16_t type;
  c2_block *pcVar3;
  c2_block *pcVar4;
  c2_block *pcVar5;
  c2_symbol **ppcVar6;
  c2_tuple *pcVar7;
  c2_bitset *pcVar8;
  c2_block *pcVar9;
  uint32_t uVar10;
  c2_symbol *sym;
  c2_live_range *range;
  c2_operand *dst;
  c2_tuple *pcVar11;
  c2_operand *dst_00;
  c2_operand *pcVar12;
  uint32_t uVar13;
  c2_symbol **stack_slot;
  c2_operand *pcVar14;
  int stack_count;
  c2_operand *src_op;
  c2_list_cell *def_cell;
  c2_tuple *block_end;
  c2_tuple *store;
  c2_tuple *reload;
  c2_tuple *span;
  c2_tuple *scan;
  c2_insert_fn *insert_fn;
  c2_edge *second_succ;
  c2_live_range *slot_range;
  c2_operand *reload_dst;
  c2_tuple *cand_store;
  c2_tuple *rewrite;
  c2_live_range *base_range;
  c2_tuple *check;
  c2_loop *fp_loop;
  
  fp_loop = g_fp_loop_list;
  do {
    if (fp_loop == (c2_loop *)0x0) {
      return;
    }
    pcVar3 = fp_loop->first;
    pcVar4 = pcVar3->prev;
    if ((pcVar4->succs->to == pcVar3) && (pcVar4->succs->next_succ == (c2_edge *)0x0)) {
      pcVar5 = pcVar3->next;
      if ((pcVar5->preds->from == pcVar3) && (pcVar5->preds->next_pred == (c2_edge *)0x0)) {
        pcVar9 = pcVar3->succs->to;
        if ((((pcVar9 == pcVar3) || (pcVar9 == pcVar5)) &&
            (second_succ = pcVar3->succs->next_succ, second_succ != (c2_edge *)0x0)) &&
           ((second_succ->to == pcVar3 || (second_succ->to == pcVar5)))) {
          ppcVar6 = ((pcVar3->u58).x87_stack)->slot;
          block_end = pcVar3->end;
          stack_count = 0;
          stack_slot = ppcVar6;
          if (*ppcVar6 != (c2_symbol *)0x0) {
            do {
              slot_range = (c2_live_range *)*stack_slot;
              for (def_cell = (c2_list_cell *)(slot_range->u38).def; def_cell != (c2_list_cell *)0x0
                  ; def_cell = def_cell->next) {
                pcVar7 = (def_cell->u04).tuple;
                pcVar9 = tuple_get_block_nonnull(pcVar7);
                if (pcVar9 == pcVar3) {
                  if (pcVar7->kind == '\x19') goto LAB_10779c8d;
                  reload = pcVar3->head;
                  store = reload;
                  while ((store != block_end &&
                         (((store->op != 99 || (src_op = store->src, src_op->kind != '\x01')) ||
                          (((src_op->u18).reg != (c2_symbol *)slot_range ||
                           ((src_op->flags11 & 0x10) == 0))))))) {
                    store = store->next;
                  }
                  while ((reload != block_end &&
                         (((((reload->flags & 1) == 0 ||
                            (reload_dst = reload->dst, reload_dst == (c2_operand *)0x0)) ||
                           (reload_dst->kind != '\x01')) ||
                          ((reload_dst->u18).reg != (c2_symbol *)slot_range))))) {
                    reload = reload->next;
                  }
                  if (reload->op == 0x163) goto LAB_10779c8d;
                  span = store->next;
                  for (scan = span; scan != reload; scan = scan->next) {
                    if (((scan->flags & 1) != 0) &&
                       (((scan->kind == '\x0e' &&
                         ((scan->src->kind != '\x04' || (((uint)scan->src->sym->def & 0x10000) == 0)
                          ))) || ((scan->kind == '\x15' || (scan->flags12 == '\b')))))) {
                      if (scan != reload) goto LAB_10779c8d;
                      break;
                    }
                  }
                  for (; span != reload; span = span->next) {
                    if ((span->flags & 1) != 0) {
                      span->flags12 = span->flags12 + '\x01';
                    }
                  }
                  tuple_unlink_free(store);
                }
              }
              ppcVar1 = stack_slot + 1;
              stack_count = stack_count + 1;
              stack_slot = stack_slot + 1;
            } while (*ppcVar1 != (c2_symbol *)0x0);
            if (6 < stack_count) goto LAB_10779c8d;
          }
          pcVar7 = pcVar3->head;
          for (cand_store = pcVar7; cand_store != block_end; cand_store = cand_store->next) {
            if ((((cand_store->flags & 1) != 0) &&
                (pcVar12 = cand_store->dst, pcVar12 != (c2_operand *)0x0)) &&
               (((pcVar12->kind == '\x06' &&
                 ((((pcVar12->type & 0xf000) == 0x4000 && (pcVar12->op == 0x14c)) &&
                  (base_range = (pcVar12->base->u18).range, base_range->kind == '\x02')))) &&
                ((uVar10 = bitset_test(pcVar3->live_in,base_range->id), uVar10 != 0 &&
                 (uVar10 = bitset_test(pcVar3->live_out,base_range->id), check = pcVar7, uVar10 != 0
                 )))))) {
              for (; check != block_end; check = check->next) {
                if ((check->flags & 1) != 0) {
                  if (((check->kind == '\x0e') &&
                      ((check->src->kind != '\x04' || (((uint)check->src->sym->def & 0x10000) == 0))
                      )) || ((check->kind == '\x15' || (check->flags12 == '\b')))) {
LAB_10779ee5:
                    if (check != block_end) goto LAB_10779eef;
                    break;
                  }
                  for (pcVar14 = check->dst; pcVar14 != (c2_operand *)0x0; pcVar14 = pcVar14->next)
                  {
                    switch(pcVar14->kind) {
                    case '\x01':
                      if ((pcVar14->u18).reg == (c2_symbol *)base_range) goto LAB_10779ee5;
                      break;
                    case '\x02':
                      uVar10 = symbol_in_alias_class(pcVar14->sym,pcVar12->tag);
                      goto joined_r0x10779f38;
                    case '\x06':
                      if (pcVar14 != pcVar12) {
                        uVar10 = alias_classes_intersect(pcVar12->tag,pcVar14->tag);
                        goto joined_r0x10779f38;
                      }
                      break;
                    case '\v':
                      uVar10 = alias_classes_intersect(pcVar12->tag,(uint32_t)pcVar14->sym);
joined_r0x10779f38:
                      if (uVar10 != 0) goto LAB_10779ee5;
                    }
                  }
                  for (pcVar14 = check->src; pcVar14 != (c2_operand *)0x0; pcVar14 = pcVar14->next)
                  {
                    uVar2 = pcVar14->kind;
                    if (uVar2 == '\x02') {
                      uVar10 = symbol_in_alias_class(pcVar14->sym,pcVar12->tag);
joined_r0x10779fc9:
                      if (uVar10 != 0) goto LAB_10779ee5;
                    }
                    else if (uVar2 == '\x06') {
                      uVar10 = alias_classes_intersect(pcVar12->tag,pcVar14->tag);
                      if ((uVar10 != 0) &&
                         (((((pcVar14->op != 0x14c ||
                             ((pcVar14->base->u18).reg != (c2_symbol *)base_range)) ||
                            ((pcVar14->type & 0xf000) != 0x4000)) ||
                           ((((pcVar14->type ^ pcVar12->type) & 0xfff) != 0 ||
                            (pcVar14->disp != pcVar12->disp)))) ||
                          (pcVar14->base_sym != pcVar12->base_sym)))) goto LAB_10779ee5;
                    }
                    else if (uVar2 == '\v') {
                      uVar10 = alias_classes_intersect(pcVar12->tag,(uint32_t)pcVar14->sym);
                      goto joined_r0x10779fc9;
                    }
                  }
                }
              }
              type = pcVar12->type;
              sym = symbol_new_temp_plain(type);
              range = new_live_range(sym);
              pcVar8 = g_class_candidates[1];
              range->flags5 = range->flags5 & 0xfe;
              bitset_clear_all(pcVar8);
              range->colour = g_reg_symbols + 0x1f;
              dst = operand_new_reg(0x149,type,sym,(c2_symbol *)range);
              g_cur_line = 0;
              pcVar11 = tuple_new_unary_temp(0x60,type,pcVar12,tuple_insert_before,pcVar4->end);
              pcVar14 = pcVar11->dst;
              (pcVar14->u18).reg = g_reg_symbols + 0x1f;
              pcVar11->flags13 = '\x01';
              pcVar11->flags12 = (uint8_t)stack_count;
              pcVar11 = tuple_new(99,type,dst,pcVar14,tuple_insert_after,pcVar11);
              pcVar11->flags12 = (uint8_t)stack_count + '\x01';
              pcVar11->dst->rank = 1;
              pcVar11 = tuple_new_unary_temp(0x60,type,dst,tuple_insert_after,pcVar5->head);
              pcVar14 = pcVar11->dst;
              pcVar11->flags13 = '\x01';
              pcVar11->flags12 = (uint8_t)stack_count + '\x02';
              (pcVar14->u18).reg = g_reg_symbols + 0x1f;
              pcVar11 = tuple_new(99,type,pcVar12,pcVar14,tuple_insert_after,pcVar11);
              insert_fn = tuple_insert_after;
              pcVar11->flags12 = (uint8_t)stack_count + '\x01';
              pcVar14 = dst;
              dst_00 = operand_new_reg(0x149,type,g_reg_symbols + 0x1f,g_reg_symbols + 0x1f);
              pcVar11 = tuple_new(99,type,dst_00,pcVar14,insert_fn,pcVar11);
              pcVar11->src->flags11 = pcVar11->src->flags11 | 0x10;
              pcVar11->flags12 = (uint8_t)stack_count;
              ppcVar6[stack_count] = (c2_symbol *)range;
              ((pcVar4->u58).x87_stack)->slot[stack_count] = (c2_symbol *)range;
              for (rewrite = pcVar7; rewrite != block_end; rewrite = rewrite->next) {
                if ((rewrite->flags & 1) != 0) {
                  for (pcVar14 = rewrite->src; pcVar14 != (c2_operand *)0x0; pcVar14 = pcVar14->next
                      ) {
                    if (((pcVar14->kind == '\x06') && (pcVar14->op == 0x14c)) &&
                       (((pcVar14->base->u18).reg == (c2_symbol *)base_range &&
                        (pcVar14->disp == pcVar12->disp)))) {
                      tuple_replace_src(rewrite,pcVar14,dst);
                      break;
                    }
                  }
                  rewrite->flags12 = rewrite->flags12 + '\x01';
                }
              }
              pcVar12 = tuple_replace_dst(cand_store,pcVar12,dst);
              pcVar12->rank = 1;
              uVar10 = base_range->id;
              pcVar8 = pcVar5->live_in;
              uVar13 = bitset_test(pcVar8,uVar10);
              if (uVar13 == 0) {
                bitset_set(pcVar8,uVar10);
                bitset_set(pcVar5->live,uVar10);
                base_range->last_block = pcVar5;
              }
              stack_count = stack_count + 1;
              if (6 < stack_count) break;
            }
LAB_10779eef:
          }
        }
      }
    }
LAB_10779c8d:
    fp_loop = (fp_loop->u30).fp_loop_next;
  } while( true );
}

