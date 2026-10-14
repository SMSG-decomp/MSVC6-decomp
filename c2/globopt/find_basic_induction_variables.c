void __fastcall find_basic_induction_variables(c2_loop *loop)

{
  uint uVar1;
  c2_operand *pcVar2;
  bool bVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  c2_tuple *pcVar8;
  c2_block *pcVar9;
  c2_block *local_10;
  
  bitset_copy(g_iv_syms_prev,g_iv_syms);
  pcVar9 = loop->first;
  if (pcVar9 != loop->last->next) {
    do {
      if ((pcVar9->loop == loop) && (pcVar8 = pcVar9->head->next, pcVar8 != pcVar9->end)) {
        do {
          uVar1 = pcVar8->op;
          if (uVar1 == 0x15b) {
            if ((pcVar8->flags13 != '\x01') && (pcVar8->flags13 != '\x0e')) goto LAB_10745671;
          }
          else if ((0x16c < uVar1) && (uVar1 < 0x16f)) {
LAB_10745671:
            if (((1 << (byte)(pcVar8->type >> 0xc) & 0xeU) != 0) && (pcVar8->dst->kind == '\x02')) {
              bitset_set(g_iv_syms,pcVar8->dst->sym->id);
            }
          }
          pcVar8 = pcVar8->next;
        } while (pcVar8 != pcVar9->end);
      }
      pcVar9 = pcVar9->next;
    } while (pcVar9 != loop->last->next);
  }
  bitset_andnot(g_iv_syms,g_iv_excluded_syms);
  do {
    local_10 = loop->first;
    bVar3 = false;
    if (local_10 == loop->last->next) {
      return;
    }
    do {
      pcVar8 = local_10->head->next;
      if (pcVar8 != local_10->end) {
        do {
          uVar1 = pcVar8->op;
          if (uVar1 == 0x15b) {
            uVar4 = is_induction_variable_operand(pcVar8->dst);
            if ((uVar4 != 0) && (uVar4 = is_induction_variable_operand(pcVar8->src), uVar4 == 0)) {
              uVar4 = pcVar8->dst->sym->id;
              uVar5 = bitset_test(g_iv_syms_prev,uVar4);
              if (uVar5 == 0) {
                bitset_clear(g_iv_syms,uVar4);
                bVar3 = true;
              }
            }
          }
          else if ((uVar1 < 0x16d) || (0x16e < uVar1)) {
            if (((pcVar8->flags & 1) != 0) &&
               ((((pcVar2 = pcVar8->dst, pcVar2 != (c2_operand *)0x0 && (pcVar2->kind == '\x02')) &&
                 (pcVar2->sym->def == (c2_tuple *)0x0)) &&
                (uVar4 = sparse_set_test_and_remove(g_iv_syms,pcVar2->sym->id), uVar4 != 0)))) {
              bVar3 = true;
            }
          }
          else {
            uVar4 = is_induction_variable_operand(pcVar8->dst);
            if (uVar4 != 0) {
              uVar4 = is_induction_variable_operand(pcVar8->src);
              uVar5 = is_loop_invariant_operand(pcVar8->src);
              uVar6 = is_induction_variable_operand(pcVar8->src->next);
              uVar7 = is_loop_invariant_operand(pcVar8->src->next);
              if ((((((uVar4 == 0) && (uVar5 == 0)) || ((uVar6 == 0 && (uVar7 == 0)))) ||
                   ((uVar5 != 0 && (uVar7 != 0)))) || ((uVar4 != 0 && (uVar6 != 0)))) ||
                 ((uVar1 == 0x16e && (uVar4 == 0)))) {
                uVar4 = pcVar8->dst->sym->id;
                uVar5 = bitset_test(g_iv_syms_prev,uVar4);
                if (uVar5 == 0) {
                  bitset_clear(g_iv_syms,uVar4);
                  bVar3 = true;
                }
              }
            }
          }
          pcVar8 = pcVar8->next;
        } while (pcVar8 != local_10->end);
      }
      local_10 = local_10->next;
    } while (local_10 != loop->last->next);
  } while (bVar3);
  return;
}

