c2_list_cell * __fastcall collect_iv_candidates(c2_loop *loop,int mode)

{
  uint16_t uVar1;
  c2_symbol_cell *pcVar2;
  c2_cse_expr *pcVar3;
  uint uVar4;
  uint uVar5;
  c2_list_cell *pcVar6;
  c2_tuple *pcVar7;
  c2_tuple *pcVar8;
  c2_symbol *pcVar9;
  int iVar10;
  uint32_t uVar11;
  c2_operand *pcVar12;
  c2_tuple *pcVar13;
  c2_operand *pcVar14;
  c2_block *pcVar15;
  
  if (g_iv_syms->chunks == (c2_bitset_chunk *)0x0) {
    return (c2_list_cell *)0x0;
  }
  switch(mode) {
  case 1:
    pcVar15 = loop->first;
    if (pcVar15 != loop->last->next) {
      do {
        pcVar8 = pcVar15->head->next;
        if (pcVar8 != pcVar15->end) {
          do {
            if (pcVar8->flags13 == '\x04') {
              pcVar8->flags13 = '\0';
            }
            pcVar8 = pcVar8->next;
          } while (pcVar8 != pcVar15->end);
        }
        pcVar15 = pcVar15->next;
      } while (pcVar15 != loop->last->next);
    }
    uVar11 = bitset_iter_next(g_iv_syms);
    while (uVar11 != 0xffffffff) {
      pcVar9 = symbol_by_id(uVar11);
      for (pcVar6 = pcVar9->defs; pcVar6 != (c2_list_cell *)0x0; pcVar6 = pcVar6->next) {
        pcVar8 = (pcVar6->u04).tuple;
        if (pcVar8->op == 0x15b) {
          uVar11 = pcVar8->prev->op;
          if ((((uVar11 == 0x16d) || (uVar11 == 0x16e)) &&
              (iVar10 = operand_compare(pcVar8->src,pcVar8->prev->dst), iVar10 == 0)) &&
             (iVar10 = operand_compare(pcVar8->dst,pcVar8->prev->src), iVar10 == 0)) {
            pcVar8->flags13 = '\x04';
            pcVar8->prev->flags13 = '\x04';
          }
        }
      }
      uVar11 = bitset_iter_next((c2_bitset *)0x0);
    }
    pcVar15 = loop->first;
    if (pcVar15 != loop->last->next) {
      do {
        pcVar8 = pcVar15->head->next;
        if (pcVar8 != pcVar15->end) {
          do {
            if ((pcVar8->flags & 0x40) != 0) break;
            uVar11 = pcVar8->op;
            if (uVar11 == 0x15f) {
              if ((((1 << (byte)(pcVar8->type >> 0xc) & 0xeU) != 0) && ((pcVar8->type & 0xfff) == 4)
                  ) && ((uVar11 = is_induction_variable_operand(pcVar8->src), uVar11 != 0 &&
                        (iVar10 = operand_symbol_is_narrow_iv(pcVar8->src), iVar10 != 0)))) {
                iv_worklist_push(pcVar8);
                pcVar8->flags12 = '\x06';
              }
            }
            else if (uVar11 == 0x16d) {
              if ((1 << (byte)(pcVar8->type >> 0xc) & 0xeU) != 0) {
                uVar11 = is_induction_variable_operand(pcVar8->src);
                if ((uVar11 == 0) ||
                   (uVar11 = is_loop_invariant_operand(pcVar8->src->next), uVar11 == 0)) {
                  uVar11 = is_loop_invariant_operand(pcVar8->src);
                  if ((uVar11 == 0) ||
                     (uVar11 = is_induction_variable_operand(pcVar8->src->next), uVar11 == 0))
                  goto LAB_10746302;
                  tuple_swap_first_srcs(pcVar8);
                }
                if (((pcVar8->flags13 != '\x04') &&
                    (uVar11 = iv_operand_has_unpaired_def(pcVar8->src), uVar11 == 0)) &&
                   (uVar11 = operand_live_out_of_preheader(pcVar8->src), uVar11 != 0)) {
                  iv_worklist_push(pcVar8);
                  pcVar8->flags = pcVar8->flags | 0x40;
                }
              }
            }
            else if ((uVar11 == 0x16f) && ((1 << (byte)(pcVar8->type >> 0xc) & 0xeU) != 0)) {
              uVar11 = is_induction_variable_operand(pcVar8->src);
              if ((uVar11 == 0) ||
                 (uVar11 = is_loop_invariant_operand(pcVar8->src->next), uVar11 == 0)) {
                uVar11 = is_loop_invariant_operand(pcVar8->src);
                if (((uVar11 != 0) &&
                    (uVar11 = is_induction_variable_operand(pcVar8->src->next), uVar11 != 0)) &&
                   (uVar11 = bitset_test(g_hoisted_exprs,pcVar8->src->next->sym->id), uVar11 == 0))
                {
                  tuple_swap_first_srcs(pcVar8);
                  iv_worklist_push(pcVar8);
                  pcVar8->flags = pcVar8->flags | 0x40;
                }
              }
              else {
                uVar11 = bitset_test(g_hoisted_exprs,pcVar8->src->sym->id);
                if (uVar11 == 0) {
                  iv_worklist_push(pcVar8);
                  pcVar8->flags = pcVar8->flags | 0x40;
                }
              }
            }
LAB_10746302:
            pcVar8 = pcVar8->next;
          } while (pcVar8 != pcVar15->end);
        }
        pcVar15 = pcVar15->next;
        if (pcVar15 == loop->last->next) {
          return g_iv_worklist;
        }
      } while( true );
    }
    break;
  case 2:
    pcVar15 = loop->first;
    if (pcVar15 != loop->last->next) {
      do {
        pcVar8 = pcVar15->head->next;
        if (pcVar8 != pcVar15->end) {
          do {
            if (((pcVar8->op == 0x17d) && ((1 << (byte)(pcVar8->type >> 0xc) & 0xeU) != 0)) &&
               (((uVar11 = is_induction_variable_operand(pcVar8->src), uVar11 != 0 &&
                 (uVar11 = is_loop_invariant_operand(pcVar8->src->next), uVar11 != 0)) ||
                ((uVar11 = is_loop_invariant_operand(pcVar8->src), uVar11 != 0 &&
                 (uVar11 = is_induction_variable_operand(pcVar8->src->next), uVar11 != 0)))))) {
              iv_worklist_push(pcVar8);
            }
            pcVar8 = pcVar8->next;
          } while (pcVar8 != pcVar15->end);
        }
        pcVar15 = pcVar15->next;
      } while (pcVar15 != loop->last->next);
      return g_iv_worklist;
    }
    break;
  case 3:
    pcVar15 = loop->first;
    if (pcVar15 != loop->last->next) {
      do {
        pcVar8 = pcVar15->head->next;
        if (pcVar8 != pcVar15->end) {
          do {
            if (pcVar8->op == 0x15b) {
              if (((pcVar8->dst->kind == '\x06') &&
                  (uVar11 = is_induction_variable_operand(pcVar8->dst->base), uVar11 != 0)) &&
                 (iVar10 = node_has_side_effects((c2_node *)pcVar8), iVar10 == 0)) {
                uVar11 = is_loop_invariant_operand(pcVar8->src);
                if (uVar11 == 0) {
                  pcVar13 = pcVar8->prev;
                  if (((pcVar13->op == 0x15d) && (pcVar13->src->kind == '\x06')) &&
                     ((iVar10 = operand_compare(pcVar13->dst,pcVar8->src), iVar10 == 0 &&
                      ((uVar11 = is_induction_variable_operand(pcVar8->prev->src->base), uVar11 != 0
                       && (iVar10 = node_has_side_effects((c2_node *)pcVar8->prev), iVar10 == 0)))))
                     ) {
                    pcVar14 = pcVar8->prev->src;
                  }
                  else {
                    if (((pcVar8->type & 0xf000) != 0x5000) ||
                       (((pcVar8->src->kind != '\x06' ||
                         (uVar11 = is_induction_variable_operand(pcVar8->src->base), uVar11 == 0))
                        || (iVar10 = node_has_side_effects((c2_node *)pcVar8->src), iVar10 != 0))))
                    goto LAB_10746516;
                    pcVar14 = pcVar8->src;
                  }
                  iVar10 = operands_may_alias(pcVar8->dst,pcVar14);
                  if (iVar10 != 0) goto LAB_10746516;
                }
LAB_10746621:
                iv_worklist_push(pcVar8);
              }
            }
            else if (pcVar8->kind == '\x12') {
              uVar1 = (pcVar8->u20).intrinsic.id;
              if (uVar1 == 0xad) {
                pcVar14 = convert_loop_stores_size_case(1,pcVar8);
                uVar11 = is_induction_variable_operand(pcVar14);
                if (uVar11 != 0) {
                  pcVar14 = convert_loop_stores_size_case(2,pcVar8);
                  uVar11 = is_loop_invariant_operand(pcVar14);
                  if (uVar11 != 0) {
                    pcVar14 = convert_loop_stores_size_case(3,pcVar8);
                    uVar11 = is_loop_invariant_operand(pcVar14);
                    if (uVar11 != 0) goto LAB_10746621;
                  }
                }
              }
              else if (uVar1 == 0xac) {
                pcVar14 = convert_loop_stores_size_case(1,pcVar8);
                uVar11 = is_induction_variable_operand(pcVar14);
                if (uVar11 != 0) {
                  pcVar14 = convert_loop_stores_size_case(2,pcVar8);
                  uVar11 = is_induction_variable_operand(pcVar14);
                  if (uVar11 != 0) {
                    pcVar14 = convert_loop_stores_size_case(3,pcVar8);
                    uVar11 = is_loop_invariant_operand(pcVar14);
                    if (uVar11 != 0) {
                      pcVar14 = operand_list_find_kind_b(pcVar8->src);
                      pcVar12 = operand_list_find_kind_b(pcVar8->dst);
                      iVar10 = operands_may_alias(pcVar14,pcVar12);
                      if (iVar10 == 0) goto LAB_10746621;
                    }
                  }
                }
              }
            }
LAB_10746516:
            pcVar8 = pcVar8->next;
          } while (pcVar8 != pcVar15->end);
        }
        pcVar15 = pcVar15->next;
        if (pcVar15 == loop->last->next) {
          return g_iv_worklist;
        }
      } while( true );
    }
    break;
  case 4:
    pcVar15 = loop->preheader;
    pcVar8 = pcVar15->head->next;
    uVar11 = bitset_iter_next(g_iv_syms);
    while (uVar11 != 0xffffffff) {
      pcVar9 = symbol_by_id(uVar11);
      uVar11 = bitset_test(pcVar15->de,uVar11);
      if (uVar11 != 0) {
        for (pcVar2 = pcVar9->copy_equivs; pcVar2 != (c2_symbol_cell *)0x0; pcVar2 = pcVar2->next) {
          pcVar3 = (pcVar2->sym->u18).expr;
          uVar11 = bitset_test(pcVar15->set54,pcVar2->sym->id);
          if ((uVar11 != 0) &&
             ((pcVar14 = pcVar3->operands->next, (1 << (pcVar14->kind & 0x1f) & 6U) == 0 ||
              (pcVar14->sym->def == (c2_tuple *)0x0)))) {
            pcVar13 = tuple_new(0x15b,pcVar3->type,pcVar3->operands,pcVar3->operands->next,
                                tuple_insert_before,pcVar8);
            pcVar13->flags13 = '\t';
            break;
          }
        }
      }
      uVar11 = bitset_iter_next((c2_bitset *)0x0);
    }
    uVar11 = bitset_iter_next(g_iv_syms);
    while (uVar11 != 0xffffffff) {
      pcVar9 = symbol_by_id(uVar11);
      for (pcVar6 = pcVar9->defs; pcVar6 != (c2_list_cell *)0x0; pcVar6 = pcVar6->next) {
        pcVar8 = (pcVar6->u04).tuple;
        if (pcVar8->op == 0x15b) {
          uVar11 = pcVar8->prev->op;
          if ((((uVar11 == 0x16d) || (uVar11 == 0x16e)) &&
              (iVar10 = operand_compare(pcVar8->src,pcVar8->prev->dst), iVar10 == 0)) &&
             (iVar10 = operand_compare(pcVar8->dst,pcVar8->prev->src), iVar10 == 0)) {
            pcVar8->flags13 = '\x04';
            pcVar8->prev->flags13 = '\x04';
          }
        }
      }
      uVar11 = bitset_iter_next((c2_bitset *)0x0);
    }
    pcVar8 = pcVar15->head->next;
    if (pcVar8 != pcVar15->end) {
      do {
        if (((pcVar8->op == 0x15b) && (pcVar8->flags13 != '\x01')) && (pcVar8->src->kind != '\x05'))
        {
          pcVar14 = pcVar8->dst;
          uVar11 = is_induction_variable_operand(pcVar14);
          if (((uVar11 != 0) && (pcVar6 = pcVar14->sym->defs, pcVar6 != (c2_list_cell *)0x0)) &&
             ((pcVar6->next == (c2_list_cell *)0x0 && (((pcVar6->u04).tuple)->flags13 == '\x04'))))
          {
            iv_worklist_push(pcVar8);
          }
        }
        pcVar8 = pcVar8->next;
      } while (pcVar8 != pcVar15->end);
      return g_iv_worklist;
    }
    break;
  case 5:
    pcVar15 = loop->preheader;
    pcVar8 = pcVar15->head->next;
    if (pcVar8 != pcVar15->end) {
      do {
        if (pcVar8->op == 0x15b) {
          pcVar14 = pcVar8->src;
          pcVar12 = pcVar8->dst;
          uVar11 = is_induction_variable_operand(pcVar14);
          if ((uVar11 != 0) &&
             (pcVar13 = find_store_matching_operand(pcVar12,loop), pcVar13 != (c2_tuple *)0x0)) {
            pcVar9 = pcVar14->sym;
            pcVar6 = pcVar9->defs;
            if (((pcVar6 != (c2_list_cell *)0x0) &&
                ((pcVar6->next == (c2_list_cell *)0x0 && (((pcVar6->u04).tuple)->flags13 == '\x04'))
                )) && (uVar11 = block_range_dominated(pcVar8,(pcVar6->u04).tuple), uVar11 != 0)) {
              iv_worklist_push(pcVar8);
              pcVar13 = pcVar8->next;
              pcVar7 = loop->exit_compare;
              if (pcVar13 != pcVar7->next) {
                do {
                  if (((pcVar13->flags & 1) != 0) &&
                     (pcVar14 = find_src_symbol_ref(pcVar13,pcVar9), pcVar14 != (c2_operand *)0x0))
                  {
                    iv_worklist_pop();
                    break;
                  }
                  pcVar13 = pcVar13->next;
                } while (pcVar13 != pcVar7->next);
              }
            }
          }
        }
        pcVar8 = pcVar8->next;
        if (pcVar8 == pcVar15->end) {
          return g_iv_worklist;
        }
      } while( true );
    }
    break;
  case 6:
    pcVar15 = loop->preheader;
    pcVar8 = pcVar15->head->next;
    if (pcVar8 != pcVar15->end) {
      do {
        if (pcVar8->op == 0x15b) {
          pcVar14 = pcVar8->dst;
          uVar11 = is_induction_variable_operand(pcVar14);
          if ((((uVar11 != 0) &&
               (pcVar9 = pcVar14->sym, ((pcVar9->u30).sizeopt.width_facts & 1) != 0)) &&
              (pcVar9->uses != (c2_list_cell *)0x0)) &&
             (pcVar3 = (pcVar9->u18).expr, pcVar3 != (c2_cse_expr *)0x0)) {
            pcVar14 = pcVar3->operands;
            pcVar9 = pcVar14->sym;
            pcVar12 = pcVar14->next;
            uVar11 = operand_live_out_of_preheader(pcVar14);
            if ((uVar11 != 0) && (pcVar9->uses != (c2_list_cell *)0x0)) {
              uVar11 = pcVar3->op;
              if (uVar11 == 0x179) {
LAB_107468bc:
                iv_worklist_push(pcVar8);
              }
              else if (uVar11 == 0x17a) {
                if (pcVar12->kind == '\a') goto LAB_107468bc;
              }
              else if ((uVar11 == 0x17b) && (pcVar12->kind == '\a')) {
                uVar4 = pcVar12->tag;
                uVar5 = (pcVar12->u18).lo;
                if ((-1 < (int)uVar4) &&
                   (((0 < (int)uVar4 || (uVar5 != 0)) &&
                    ((uVar5 - 1 & uVar5) == 0 && (uVar4 - (uVar5 == 0) & uVar4) == 0))))
                goto LAB_107468bc;
              }
            }
          }
        }
        pcVar8 = pcVar8->next;
      } while (pcVar8 != pcVar15->end);
    }
  }
  return g_iv_worklist;
}

