c2_list_cell * collect_iv_candidates_mode3(c2_loop *loop,c2_loop *loop_slot)

{
  uint16_t uVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  uint32_t uVar4;
  c2_operand *b;
  int iVar5;
  c2_block *pcVar6;
  c2_tuple *t;
  
  pcVar6 = loop->first;
  if (pcVar6 == loop->last->next) {
    return g_iv_worklist;
  }
  do {
    t = pcVar6->head->next;
    if (t != pcVar6->end) {
      do {
        if (t->op == 0x15b) {
          if (((t->dst->kind == '\x06') &&
              (uVar4 = is_induction_variable_operand(t->dst->base), uVar4 != 0)) &&
             (iVar5 = node_has_side_effects((c2_node *)t), iVar5 == 0)) {
            uVar4 = is_loop_invariant_operand(t->src);
            if (uVar4 == 0) {
              pcVar2 = t->prev;
              if (((pcVar2->op == 0x15d) && (pcVar2->src->kind == '\x06')) &&
                 ((iVar5 = operand_compare(pcVar2->dst,t->src), iVar5 == 0 &&
                  ((uVar4 = is_induction_variable_operand(t->prev->src->base), uVar4 != 0 &&
                   (iVar5 = node_has_side_effects((c2_node *)t->prev), iVar5 == 0)))))) {
                pcVar3 = t->prev->src;
              }
              else {
                if (((t->type & 0xf000) != 0x5000) ||
                   (((t->src->kind != '\x06' ||
                     (uVar4 = is_induction_variable_operand(t->src->base), uVar4 == 0)) ||
                    (iVar5 = node_has_side_effects((c2_node *)t->src), iVar5 != 0))))
                goto LAB_10746516;
                pcVar3 = t->src;
              }
              iVar5 = operands_may_alias(t->dst,pcVar3);
              if (iVar5 != 0) goto LAB_10746516;
            }
LAB_10746621:
            iv_worklist_push(t);
          }
        }
        else if (t->kind == '\x12') {
          uVar1 = (t->u20).intrinsic.id;
          if (uVar1 == 0xad) {
            pcVar3 = convert_loop_stores_size_case(1,t);
            uVar4 = is_induction_variable_operand(pcVar3);
            if (uVar4 != 0) {
              pcVar3 = convert_loop_stores_size_case(2,t);
              uVar4 = is_loop_invariant_operand(pcVar3);
              if (uVar4 != 0) {
                pcVar3 = convert_loop_stores_size_case(3,t);
                uVar4 = is_loop_invariant_operand(pcVar3);
                if (uVar4 != 0) goto LAB_10746621;
              }
            }
          }
          else if (uVar1 == 0xac) {
            pcVar3 = convert_loop_stores_size_case(1,t);
            uVar4 = is_induction_variable_operand(pcVar3);
            if (uVar4 != 0) {
              pcVar3 = convert_loop_stores_size_case(2,t);
              uVar4 = is_induction_variable_operand(pcVar3);
              if (uVar4 != 0) {
                pcVar3 = convert_loop_stores_size_case(3,t);
                uVar4 = is_loop_invariant_operand(pcVar3);
                if (uVar4 != 0) {
                  pcVar3 = operand_list_find_kind_b(t->src);
                  b = operand_list_find_kind_b(t->dst);
                  iVar5 = operands_may_alias(pcVar3,b);
                  if (iVar5 == 0) goto LAB_10746621;
                }
              }
            }
          }
        }
LAB_10746516:
        t = t->next;
      } while (t != pcVar6->end);
    }
    pcVar6 = pcVar6->next;
    if (pcVar6 == loop_slot->last->next) {
      return g_iv_worklist;
    }
  } while( true );
}

