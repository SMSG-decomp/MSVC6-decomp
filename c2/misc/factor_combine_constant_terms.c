int __fastcall factor_combine_constant_terms(c2_tuple *t,int inner_op,int outer_op)

{
  c2_operand *pcVar1;
  c2_operand *inner_term;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  c2_operand *term;
  int iVar4;
  
  term = t->src;
  iVar4 = 0;
  g_factor_lookthrough_op = outer_op;
  g_factor_inner_op = inner_op;
  if (term != (c2_operand *)0x0) {
    do {
      inner_term = term;
      if (term->op == outer_op) {
        inner_term = (term->u18).children;
      }
      if (inner_term->kind == '\a') {
LAB_1070ab4e:
        iVar4 = iVar4 + 1;
      }
      else if (inner_term->op == inner_op) {
        if ((inner_op == 0x171) || (inner_op == 0x177)) {
          if (((inner_term->u18).children)->next->kind == '\a') goto LAB_1070ab4e;
        }
        else {
          for (pcVar1 = (inner_term->u18).children; pcVar1 != (c2_operand *)0x0;
              pcVar1 = pcVar1->next) {
            if (pcVar1->kind == '\a') goto LAB_1070ab4e;
          }
        }
      }
      if (1 < iVar4) goto LAB_1070ab98;
      term = term->next;
    } while (term != (c2_operand *)0x0);
    if (1 < iVar4) {
LAB_1070ab98:
      refresh_node_cost_shallow(t);
      sort_commutative_operands_rec(t,inner_op,outer_op);
      for (pcVar1 = t->src;
          ((pcVar1 != (c2_operand *)0x0 &&
           (pcVar2 = (c2_operand *)factor_strip_ops((c2_node *)pcVar1), pcVar2->kind == '\a')) &&
          ((t->op != 0x173 || ((inner_op != 0x172 || (pcVar2 != pcVar1)))))); pcVar1 = pcVar1->next)
      {
        for (pcVar2 = pcVar1->next;
            ((pcVar2 != (c2_operand *)0x0 &&
             (pcVar3 = (c2_operand *)factor_strip_ops((c2_node *)pcVar2), pcVar3->kind == '\a')) &&
            ((t->op != 0x173 || ((inner_op != 0x172 || (pcVar3 != pcVar2))))));
            pcVar2 = pcVar2->next) {
          iVar4 = factor_pair_has_common_factor(t,pcVar1,pcVar2,inner_op);
          if (iVar4 != 0) {
            g_simplify_changed = 1;
            factor_emit_combined(t,(c2_node *)pcVar1,(c2_node *)pcVar2,inner_op,outer_op);
            return 1;
          }
        }
      }
      return 0;
    }
  }
  return 0;
}

