int __fastcall
fold_add_sub_constant_pair
          (c2_tuple *t,c2_operand *t_reg,uint32_t prev_op,uint32_t adjust_lo,uint32_t adjust_hi,
          c2_operand *prev_reg,c2_tuple **next)

{
  c2_symbol *pcVar1;
  uint uVar2;
  c2_const_operand *pcVar3;
  uint32_t uVar4;
  bool bVar5;
  
  switch(prev_op) {
  case 0x1e:
    bVar5 = adjust_lo != 0;
    adjust_lo = adjust_lo - 1;
    adjust_hi = (adjust_hi - 1) + (uint)bVar5;
    break;
  case 0x21:
    bVar5 = 0xfffffffe < adjust_lo;
    adjust_lo = adjust_lo + 1;
    adjust_hi = adjust_hi + bVar5;
    break;
  case 0x2d:
    pcVar1 = (prev_reg->next->u18).reg;
    bVar5 = CARRY4(adjust_lo,(uint)pcVar1);
    adjust_lo = (int)&pcVar1->fe + adjust_lo;
    adjust_hi = adjust_hi + prev_reg->next->tag + (uint)bVar5;
    break;
  case 0x32:
    uVar2 = (prev_reg->next->u18).lo;
    bVar5 = adjust_lo < uVar2;
    adjust_lo = adjust_lo - uVar2;
    adjust_hi = (adjust_hi - prev_reg->next->tag) - (uint)bVar5;
  }
  tuple_unlink_free(t->prev);
  if (adjust_lo == 0 && adjust_hi == 0) {
    *next = t->next;
    tuple_unlink_free(t);
    return 1;
  }
  if (((adjust_lo != 1) || (adjust_hi != 0)) && ((adjust_lo & adjust_hi) != 0xffffffff)) {
    if (t_reg->next != (c2_operand *)0x0) {
      pcVar3 = operand_new_intconst(t->type,adjust_lo,adjust_hi);
      tuple_replace_src(t,t_reg->next,pcVar3);
      t->op = 0x2d;
      add_sub_const_to_inc_dec(t);
      return 0;
    }
    pcVar3 = operand_new_intconst(t->type,adjust_lo,adjust_hi);
    tuple_append_src(t,pcVar3);
    t->op = 0x2d;
    add_sub_const_to_inc_dec(t);
    return 0;
  }
  if (t_reg->next != (c2_operand *)0x0) {
    tuple_remove_src(t,t_reg->next);
  }
  if ((adjust_lo != 1) || (uVar4 = 0x21, adjust_hi != 0)) {
    uVar4 = 0x1e;
  }
  t->op = uVar4;
  return 0;
}

