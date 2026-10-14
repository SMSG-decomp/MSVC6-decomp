void __fastcall factor_sort_operands_rec(c2_tuple *t,uint32_t op,uint32_t inner)

{
  int iVar1;
  c2_operand *pcVar2;
  c2_operand *t_00;
  
  for (pcVar2 = t->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
    t_00 = pcVar2;
    if (pcVar2->op == inner) {
      t_00 = (pcVar2->u18).children;
    }
    if (t_00->op == op) {
      factor_sort_operands_rec((c2_tuple *)t_00,0x145,inner);
    }
  }
  g_factor_lookthrough_op = inner;
  g_factor_inner_op = op;
  iVar1 = tuple_is_commutative(t);
  if (iVar1 != 0) {
    pcVar2 = merge_sort_operand_list(t->src,factor_compare_operands);
    t->src = pcVar2;
  }
  return;
}

