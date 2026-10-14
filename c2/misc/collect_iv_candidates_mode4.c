c2_list_cell * collect_iv_candidates_mode4(c2_bitset *iv_syms,c2_loop *loop)

{
  c2_block *pcVar1;
  c2_symbol_cell *pcVar2;
  c2_cse_expr *pcVar3;
  c2_list_cell *pcVar4;
  c2_operand *pcVar5;
  c2_block *pcVar6;
  uint32_t uVar7;
  c2_symbol *pcVar8;
  c2_tuple *pcVar9;
  int iVar10;
  c2_tuple *pcVar11;
  c2_block *pcStack00000010;
  
  pcVar1 = loop->preheader;
  pcVar11 = pcVar1->head->next;
  pcStack00000010 = pcVar1;
  uVar7 = bitset_iter_next(iv_syms);
  do {
    if (uVar7 == 0xffffffff) {
      uVar7 = bitset_iter_next(g_iv_syms);
      pcVar6 = pcStack00000010;
      while (pcStack00000010 = pcVar6, uVar7 != 0xffffffff) {
        pcVar8 = symbol_by_id(uVar7);
        for (pcVar4 = pcVar8->defs; pcVar4 != (c2_list_cell *)0x0; pcVar4 = pcVar4->next) {
          pcVar11 = (pcVar4->u04).tuple;
          if (pcVar11->op == 0x15b) {
            uVar7 = pcVar11->prev->op;
            if ((((uVar7 == 0x16d) || (uVar7 == 0x16e)) &&
                (iVar10 = operand_compare(pcVar11->src,pcVar11->prev->dst), iVar10 == 0)) &&
               (iVar10 = operand_compare(pcVar11->dst,pcVar11->prev->src), iVar10 == 0)) {
              pcVar11->flags13 = '\x04';
              pcVar11->prev->flags13 = '\x04';
            }
          }
        }
        uVar7 = bitset_iter_next((c2_bitset *)0x0);
        pcVar6 = pcStack00000010;
      }
      pcVar11 = pcVar1->head->next;
      if (pcVar11 == pcVar1->end) {
        return g_iv_worklist;
      }
      do {
        if (((pcVar11->op == 0x15b) && (pcVar11->flags13 != '\x01')) &&
           (pcVar11->src->kind != '\x05')) {
          pcVar5 = pcVar11->dst;
          uVar7 = is_induction_variable_operand(pcVar5);
          if (((uVar7 != 0) && (pcVar4 = pcVar5->sym->defs, pcVar4 != (c2_list_cell *)0x0)) &&
             ((pcVar4->next == (c2_list_cell *)0x0 && (((pcVar4->u04).tuple)->flags13 == '\x04'))))
          {
            iv_worklist_push(pcVar11);
          }
        }
        pcVar11 = pcVar11->next;
      } while (pcVar11 != pcVar6->end);
      return g_iv_worklist;
    }
    pcVar8 = symbol_by_id(uVar7);
    uVar7 = bitset_test(pcVar1->de,uVar7);
    if (uVar7 != 0) {
      for (pcVar2 = pcVar8->copy_equivs; pcVar2 != (c2_symbol_cell *)0x0; pcVar2 = pcVar2->next) {
        pcVar3 = (pcVar2->sym->u18).expr;
        uVar7 = bitset_test(pcVar1->set54,pcVar2->sym->id);
        if ((uVar7 != 0) &&
           ((pcVar5 = pcVar3->operands->next, (1 << (pcVar5->kind & 0x1f) & 6U) == 0 ||
            (pcVar5->sym->def == (c2_tuple *)0x0)))) {
          pcVar9 = tuple_new(0x15b,pcVar3->type,pcVar3->operands,pcVar3->operands->next,
                             tuple_insert_before,pcVar11);
          pcVar9->flags13 = '\t';
          break;
        }
      }
    }
    uVar7 = bitset_iter_next((c2_bitset *)0x0);
  } while( true );
}

