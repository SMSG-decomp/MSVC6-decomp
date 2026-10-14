int __fastcall compares_equivalent(c2_tuple *cmp,c2_tuple *other,c2_tuple *jcc,int swap_to_match)

{
  int iVar1;
  c2_tuple *pcVar2;
  
  iVar1 = tuples_equal(cmp,other);
  if (iVar1 != 0) {
    return 1;
  }
  if ((((cmp->op == other->op) && (((cmp->type ^ other->type) & 0xfff) == 0)) &&
      (iVar1 = operand_lists_equal(cmp->src,other->src->next), iVar1 != 0)) &&
     ((iVar1 = operand_lists_equal(cmp->src->next,other->src), iVar1 != 0 &&
      (iVar1 = operand_lists_equal(cmp->dst,other->dst), iVar1 != 0)))) {
    if (cmp->op != 0x2f) {
      return 1;
    }
    pcVar2 = tuple_prev_real_in_block(jcc);
    if (pcVar2 == cmp) {
      pcVar2 = tuple_next_real(jcc);
      iVar1 = reg_read_before_redefined(pcVar2,(jcc->src->next->u18).reg);
      if (iVar1 == 0) {
        pcVar2 = tuple_next_real(*(c2_tuple **)((int)&jcc->src->sym->u30 + 2));
        iVar1 = reg_read_before_redefined(pcVar2,(jcc->src->next->u18).reg);
        if (iVar1 == 0) {
          if (swap_to_match == 0) {
            return 1;
          }
          tuple_swap_first_srcs(cmp);
          branch_swap_condition(jcc);
          return 1;
        }
      }
    }
  }
  return 0;
}

