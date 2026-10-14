c2_list_cell * collect_iv_candidates_mode1(c2_loop *loop,c2_bitset *iv_syms)

{
  c2_list_cell *pcVar1;
  c2_tuple *pcVar2;
  uint32_t uVar3;
  c2_symbol *pcVar4;
  int iVar5;
  c2_block *pcVar6;
  
  pcVar6 = loop->first;
  if (pcVar6 != loop->last->next) {
    do {
      pcVar2 = pcVar6->head->next;
      if (pcVar2 != pcVar6->end) {
        do {
          if (pcVar2->flags13 == '\x04') {
            pcVar2->flags13 = '\0';
          }
          pcVar2 = pcVar2->next;
        } while (pcVar2 != pcVar6->end);
      }
      pcVar6 = pcVar6->next;
      iv_syms = g_iv_syms;
    } while (pcVar6 != loop->last->next);
  }
  uVar3 = bitset_iter_next(iv_syms);
  while (uVar3 != 0xffffffff) {
    pcVar4 = symbol_by_id(uVar3);
    for (pcVar1 = pcVar4->defs; pcVar1 != (c2_list_cell *)0x0; pcVar1 = pcVar1->next) {
      pcVar2 = (pcVar1->u04).tuple;
      if (pcVar2->op == 0x15b) {
        uVar3 = pcVar2->prev->op;
        if ((((uVar3 == 0x16d) || (uVar3 == 0x16e)) &&
            (iVar5 = operand_compare(pcVar2->src,pcVar2->prev->dst), iVar5 == 0)) &&
           (iVar5 = operand_compare(pcVar2->dst,pcVar2->prev->src), iVar5 == 0)) {
          pcVar2->flags13 = '\x04';
          pcVar2->prev->flags13 = '\x04';
        }
      }
    }
    uVar3 = bitset_iter_next((c2_bitset *)0x0);
  }
  pcVar6 = loop->first;
  if (pcVar6 == loop->last->next) {
    return g_iv_worklist;
  }
  do {
    pcVar2 = pcVar6->head->next;
    if (pcVar2 != pcVar6->end) {
      do {
        if ((pcVar2->flags & 0x40) != 0) break;
        uVar3 = pcVar2->op;
        if (uVar3 == 0x15f) {
          if ((((1 << (byte)(pcVar2->type >> 0xc) & 0xeU) != 0) && ((pcVar2->type & 0xfff) == 4)) &&
             ((uVar3 = is_induction_variable_operand(pcVar2->src), uVar3 != 0 &&
              (iVar5 = operand_symbol_is_narrow_iv(pcVar2->src), iVar5 != 0)))) {
            iv_worklist_push(pcVar2);
            pcVar2->flags12 = '\x06';
          }
        }
        else if (uVar3 == 0x16d) {
          if ((1 << (byte)(pcVar2->type >> 0xc) & 0xeU) != 0) {
            uVar3 = is_induction_variable_operand(pcVar2->src);
            if ((uVar3 == 0) || (uVar3 = is_loop_invariant_operand(pcVar2->src->next), uVar3 == 0))
            {
              uVar3 = is_loop_invariant_operand(pcVar2->src);
              if ((uVar3 == 0) ||
                 (uVar3 = is_induction_variable_operand(pcVar2->src->next), uVar3 == 0))
              goto LAB_10746302;
              tuple_swap_first_srcs(pcVar2);
            }
            if (((pcVar2->flags13 != '\x04') &&
                (uVar3 = iv_operand_has_unpaired_def(pcVar2->src), uVar3 == 0)) &&
               (uVar3 = operand_live_out_of_preheader(pcVar2->src), uVar3 != 0)) {
              iv_worklist_push(pcVar2);
              pcVar2->flags = pcVar2->flags | 0x40;
            }
          }
        }
        else if ((uVar3 == 0x16f) && ((1 << (byte)(pcVar2->type >> 0xc) & 0xeU) != 0)) {
          uVar3 = is_induction_variable_operand(pcVar2->src);
          if ((uVar3 == 0) || (uVar3 = is_loop_invariant_operand(pcVar2->src->next), uVar3 == 0)) {
            uVar3 = is_loop_invariant_operand(pcVar2->src);
            if (((uVar3 != 0) &&
                (uVar3 = is_induction_variable_operand(pcVar2->src->next), uVar3 != 0)) &&
               (uVar3 = bitset_test(g_hoisted_exprs,pcVar2->src->next->sym->id), uVar3 == 0)) {
              tuple_swap_first_srcs(pcVar2);
              iv_worklist_push(pcVar2);
              pcVar2->flags = pcVar2->flags | 0x40;
            }
          }
          else {
            uVar3 = bitset_test(g_hoisted_exprs,pcVar2->src->sym->id);
            if (uVar3 == 0) {
              iv_worklist_push(pcVar2);
              pcVar2->flags = pcVar2->flags | 0x40;
            }
          }
        }
LAB_10746302:
        pcVar2 = pcVar2->next;
      } while (pcVar2 != pcVar6->end);
    }
    pcVar6 = pcVar6->next;
    if (pcVar6 == loop->last->next) {
      return g_iv_worklist;
    }
  } while( true );
}

