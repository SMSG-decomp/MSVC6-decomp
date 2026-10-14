int __fastcall factor_out_common_operand(c2_tuple *t,uint32_t op,uint32_t inner)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_operand *n;
  bool bVar3;
  c2_node *b;
  c2_node *a;
  int iVar4;
  
  pcVar1 = t->src;
  pcVar2 = pcVar1->next;
  bVar3 = false;
  g_factor_lookthrough_op = inner;
  g_factor_inner_op = op;
  if (((((pcVar2->next != (c2_operand *)0x0) || (pcVar1->op == op)) || (pcVar2->op == op)) ||
      ((pcVar1->op == inner && (((pcVar1->u18).children)->op == op)))) ||
     ((pcVar2->op == inner && (((pcVar2->u18).children)->op == op)))) {
    refresh_node_cost_shallow(t);
    factor_clear_scratch();
    factor_count_terms(t,op,inner);
    factor_sort_operands_rec(t,op,inner);
  }
  pcVar1 = t->src->next;
  while ((pcVar1 != (c2_operand *)0x0 &&
         (((pcVar2 = pcVar1->next, op != 0x171 && (op != 0x177)) ||
          ((t->src->op == op && (pcVar1->op == op))))))) {
    n = t->src;
    b = factor_strip_ops((c2_node *)pcVar1);
    a = factor_strip_ops((c2_node *)n);
    iVar4 = trees_equal_and_pure(a,b);
    if (iVar4 == 0) break;
    g_simplify_changed = 1;
    bVar3 = true;
    factor_emit_combined(t,(c2_node *)t->src,(c2_node *)pcVar1,op,inner);
    pcVar1 = pcVar2;
  }
  arena5_reset();
  if (!bVar3) {
    iVar4 = factor_combine_constant_terms(t,op,inner);
    return iVar4;
  }
  return 1;
}

