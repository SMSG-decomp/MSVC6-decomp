void __fastcall recse_loop_after_strength_reduction(c2_loop *loop,c2_function *fn)

{
  c2_symbol *pcVar1;
  c2_edge *pcVar2;
  uint32_t uVar3;
  c2_block *pcVar4;
  c2_tuple *pcVar5;
  
  if (g_sr_init_exprs->chunks != (c2_bitset_chunk *)0x0) {
    for (pcVar2 = loop->first->preds; pcVar2 != (c2_edge *)0x0; pcVar2 = pcVar2->next_pred) {
      bitset_or(pcVar2->from->set54,g_sr_init_exprs);
    }
  }
  pcVar4 = loop->first;
  if (pcVar4 != loop->last->next) {
    do {
      cse_block(pcVar4,fn);
      pcVar4 = pcVar4->next;
    } while (pcVar4 != loop->last->next);
  }
  pcVar4 = loop->first;
  if (pcVar4 != loop->last->next) {
    do {
      pcVar5 = pcVar4->head->next;
      if (pcVar5 != pcVar4->end) {
        do {
          if (((pcVar5->op == 0x15b) && (pcVar1 = (pcVar5->u14).expr, pcVar1 != (c2_symbol *)0x0))
             && (uVar3 = is_induction_variable_operand(pcVar5->dst), uVar3 != 0)) {
            bitset_set(g_iv_assigned_exprs,pcVar1->id);
          }
          pcVar5 = pcVar5->next;
        } while (pcVar5 != pcVar4->end);
      }
      pcVar4 = pcVar4->next;
    } while (pcVar4 != loop->last->next);
  }
  if (g_sr_init_exprs->chunks != (c2_bitset_chunk *)0x0) {
    for (pcVar2 = loop->first->preds; pcVar2 != (c2_edge *)0x0; pcVar2 = pcVar2->next_pred) {
      bitset_andnot(pcVar2->from->set54,g_sr_init_exprs);
    }
  }
  return;
}

