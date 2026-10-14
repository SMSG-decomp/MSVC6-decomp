void cache_loop_memory_base(void)

{
  uint8_t uVar1;
  ushort type;
  c2_block *pcVar2;
  c2_block *pcVar3;
  c2_block *pcVar4;
  c2_edge *pcVar5;
  c2_loop *pcVar6;
  c2_block *pcVar7;
  c2_tuple *pcVar8;
  c2_tuple *pcVar9;
  c2_operand *pcVar10;
  c2_symbol *pcVar11;
  c2_operand *old;
  c2_tuple *pcVar12;
  uint32_t *puVar13;
  c2_bitset *dst;
  uint32_t uVar14;
  uint32_t uVar15;
  c2_bitset *pcVar16;
  c2_symbol *pcVar17;
  c2_symbol *sym;
  c2_operand *pcVar18;
  c2_tuple *local_24;
  
  pcVar6 = g_fp_loop_list;
  do {
    if (pcVar6 == (c2_loop *)0x0) {
      return;
    }
    pcVar2 = pcVar6->first;
    pcVar3 = pcVar2->prev;
    if ((pcVar3->succs->to == pcVar2) && (pcVar3->succs->next_succ == (c2_edge *)0x0)) {
      pcVar4 = pcVar2->next;
      pcVar5 = pcVar4->preds;
      if ((pcVar5 != (c2_edge *)0x0) &&
         ((pcVar5->from == pcVar2 && (pcVar5->next_pred == (c2_edge *)0x0)))) {
        pcVar7 = pcVar2->succs->to;
        if (((pcVar7 == pcVar2) || (pcVar7 == pcVar4)) &&
           ((pcVar5 = pcVar2->succs->next_succ, pcVar5 != (c2_edge *)0x0 &&
            ((pcVar7 = pcVar5->to, pcVar7 == pcVar2 || (pcVar7 == pcVar4)))))) {
          pcVar8 = pcVar2->end;
          dst = bitset_new(6);
          pcVar9 = pcVar2->head;
          for (pcVar12 = pcVar9; pcVar12 != pcVar8; pcVar12 = pcVar12->next) {
            if ((pcVar12->flags & 1) != 0) {
              for (pcVar10 = pcVar12->dst; pcVar10 != (c2_operand *)0x0; pcVar10 = pcVar10->next) {
                if (pcVar10->kind == '\x01') {
                  bitset_set(dst,((pcVar10->u18).reg)->storage->id);
                }
                else if (pcVar10->kind == '\n') {
                  bitset_or(dst,(c2_bitset *)pcVar10->sym);
                }
              }
            }
          }
          local_24 = pcVar9;
          if (pcVar9 != pcVar8) {
LAB_10734837:
            if (((((local_24->flags & 1) != 0) &&
                 (pcVar10 = local_24->dst, pcVar10 != (c2_operand *)0x0)) &&
                (pcVar10->kind == '\x06')) &&
               ((((pcVar10->type & 0xf000) != 0x4000 && (pcVar10->op == 0x14c)) &&
                ((pcVar10->flags & 0x40) == 0)))) {
              pcVar11 = (pcVar10->base->u18).reg;
              uVar15 = pcVar11->id;
              uVar14 = bitset_test(dst,uVar15);
              if (((uVar14 != 0) || (uVar15 = bitset_test(pcVar2->set24,uVar15), uVar15 == 0)) ||
                 (uVar15 = bitset_test(pcVar2->set28,pcVar11->id), uVar15 == 0)) goto LAB_1073481d;
              type = pcVar10->type;
              pcVar16 = bitset_new(6);
              puVar13 = g_local_register_order;
              uVar15 = g_local_register_order[0];
              while (puVar13 = puVar13 + 1, uVar15 != 0) {
                bitset_set(pcVar16,uVar15);
                uVar15 = *puVar13;
              }
              if ((type & 0xfff) == 1) {
                bitset_clear(pcVar16,7);
                bitset_clear(pcVar16,8);
                bitset_clear(pcVar16,6);
              }
              bitset_andnot(pcVar16,dst);
              bitset_andnot(pcVar16,pcVar2->set24);
              pcVar12 = pcVar9;
              if (pcVar16->chunks == (c2_bitset_chunk *)0x0) {
                bitset_free(pcVar16);
                goto LAB_1073481d;
              }
              for (; pcVar12 != pcVar8; pcVar12 = pcVar12->next) {
                if ((pcVar12->flags & 1) != 0) {
                  for (pcVar18 = pcVar12->dst; pcVar18 != (c2_operand *)0x0; pcVar18 = pcVar18->next
                      ) {
                    uVar1 = pcVar18->kind;
                    if (uVar1 == '\x02') {
                      uVar15 = symbol_in_alias_class(pcVar18->sym,pcVar10->tag);
joined_r0x1078bf80:
                      if (uVar15 != 0) goto LAB_1073480a;
                    }
                    else if (uVar1 == '\x06') {
                      if (pcVar18 != pcVar10) {
                        pcVar17 = (c2_symbol *)pcVar18->tag;
                        goto LAB_1078bf51;
                      }
                    }
                    else if (uVar1 == '\v') {
                      pcVar17 = pcVar18->sym;
LAB_1078bf51:
                      uVar15 = alias_classes_intersect(pcVar10->tag,(uint32_t)pcVar17);
                      goto joined_r0x1078bf80;
                    }
                  }
                  for (pcVar18 = pcVar12->src; pcVar18 != (c2_operand *)0x0; pcVar18 = pcVar18->next
                      ) {
                    uVar1 = pcVar18->kind;
                    if (uVar1 == '\x02') {
                      uVar15 = symbol_in_alias_class(pcVar18->sym,pcVar10->tag);
joined_r0x1078bf98:
                      if (uVar15 != 0) goto LAB_1073480a;
                    }
                    else if (uVar1 == '\x06') {
                      uVar15 = alias_classes_intersect(pcVar10->tag,pcVar18->tag);
                      if ((uVar15 != 0) &&
                         (((((pcVar18->op != 0x14c || ((pcVar18->base->u18).reg != pcVar11)) ||
                            (pcVar18->type != type)) ||
                           ((((pcVar10->type ^ pcVar18->type) & 0xfff) != 0 ||
                            (pcVar18->disp != pcVar10->disp)))) ||
                          (pcVar18->base_sym != pcVar10->base_sym)))) goto LAB_1073480a;
                    }
                    else if (uVar1 == '\v') {
                      uVar15 = alias_classes_intersect(pcVar10->tag,(uint32_t)pcVar18->sym);
                      goto joined_r0x1078bf98;
                    }
                  }
                }
              }
              goto cache_loop_memory_base_emit;
            }
            goto LAB_1073481d;
          }
LAB_10734724:
          bitset_free(dst);
        }
      }
    }
    pcVar6 = (pcVar6->u30).fp_loop_next;
  } while( true );
LAB_1073480a:
  if (pcVar12 == pcVar8) {
cache_loop_memory_base_emit:
    puVar13 = g_local_register_order;
    uVar15 = g_local_register_order[0];
    while ((puVar13 = puVar13 + 1, uVar15 != 0 &&
           (uVar14 = bitset_test(pcVar16,uVar15), uVar14 == 0))) {
      uVar15 = *puVar13;
    }
    bitset_free(pcVar16);
    g_reg_symbols[uVar15].flags5 = g_reg_symbols[uVar15].flags5 | 0x10;
    g_reg_symbols[uVar15].u34.refs = 0x1000000;
    pcVar17 = reg_find_subreg(g_reg_symbols + uVar15,(type & 0xfff) << 3,0);
    sym = symbol_new_temp_plain(type);
    pcVar18 = operand_new_reg(0x149,type,sym,pcVar17);
    g_cur_line = 0;
    tuple_new(1,type,pcVar18,pcVar10,tuple_insert_before,pcVar3->end);
    tuple_new(1,type,pcVar10,pcVar18,tuple_insert_after,pcVar4->head);
    for (pcVar12 = pcVar9; pcVar12 != pcVar8; pcVar12 = pcVar12->next) {
      if ((pcVar12->flags & 1) != 0) {
        for (old = pcVar12->src; old != (c2_operand *)0x0; old = old->next) {
          if ((((old->kind == '\x06') && (old->op == 0x14c)) && ((old->base->u18).reg == pcVar11))
             && (old->disp == pcVar10->disp)) {
            tuple_replace_src(pcVar12,old,pcVar18);
            break;
          }
        }
      }
    }
    tuple_replace_dst(local_24,pcVar10,pcVar18);
    bitset_set(pcVar3->set28,uVar15);
    bitset_set(pcVar2->set24,uVar15);
    bitset_set(pcVar2->set28,uVar15);
    pcVar16 = pcVar4->set24;
    bitset_set(pcVar16,uVar15);
    bitset_set(pcVar16,pcVar11->id);
  }
  else {
    bitset_free(pcVar16);
  }
LAB_1073481d:
  local_24 = local_24->next;
  if (local_24 == pcVar8) goto LAB_10734724;
  goto LAB_10734837;
}

