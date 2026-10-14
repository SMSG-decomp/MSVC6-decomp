int __fastcall fold_adjacent_reg_arith(c2_tuple *t,c2_tuple **next)

{
  c2_tuple *pcVar1;
  c2_operand *t_reg;
  c2_operand *prev_reg;
  c2_const_operand *pcVar2;
  int iVar3;
  uint32_t uVar4;
  uint uVar5;
  uint32_t lo;
  uint32_t local_4;
  uint32_t k_lo;
  
  pcVar1 = t->prev;
  if ((t->type & 0xfff) != 4) {
    return 0;
  }
  uVar4 = pcVar1->op;
  if ((((uVar4 != 0x2d) && (uVar4 != 0x32)) || (pcVar1->src->next->kind != '\a')) &&
     ((uVar4 != 0x21 && (uVar4 != 0x1e)))) {
    return 0;
  }
  t_reg = t->src;
  if (t_reg->kind != '\x01') {
    return 0;
  }
  prev_reg = pcVar1->src;
  if (prev_reg->kind != '\x01') {
    return 0;
  }
  if ((t_reg->u18).reg != (prev_reg->u18).reg) {
    return 0;
  }
  switch(t->op) {
  case 0x1e:
    iVar3 = fold_add_sub_constant_pair(t,t_reg,uVar4,0xffffffff,0xffffffff,prev_reg,next);
    return iVar3;
  default:
    iVar3 = fold_add_sub_constant_pair(t,t_reg,uVar4,(uint32_t)next,local_4,prev_reg,next);
    return iVar3;
  case 0x21:
    break;
  case 0x2d:
    iVar3 = fold_add_sub_constant_pair
                      (t,t_reg,uVar4,(t_reg->next->u18).lo,t_reg->next->tag,prev_reg,next);
    return iVar3;
  case 0x32:
    k_lo = (t_reg->next->u18).lo;
    iVar3 = fold_add_sub_constant_pair
                      (t,t_reg,uVar4,-k_lo,-(t_reg->next->tag + (uint)(k_lo != 0)),prev_reg,next);
    return iVar3;
  }
  lo = 1;
  uVar5 = 0;
  switch(uVar4) {
  case 0x1e:
    lo = 0;
    uVar5 = 0;
    break;
  case 0x21:
    lo = 2;
    uVar5 = 0;
    break;
  case 0x2d:
    uVar5 = (prev_reg->next->u18).lo;
    lo = uVar5 + 1;
    uVar5 = prev_reg->next->tag + (uint)(0xfffffffe < uVar5);
    break;
  case 0x32:
    uVar5 = (prev_reg->next->u18).lo;
    lo = 1 - uVar5;
    uVar5 = -(uint)(1 < uVar5) - prev_reg->next->tag;
  }
  tuple_unlink_free(t->prev);
  if (lo != 0 || uVar5 != 0) {
    if (((lo != 1) || (uVar5 != 0)) && ((lo & uVar5) != 0xffffffff)) {
      if (t_reg->next == (c2_operand *)0x0) {
        pcVar2 = operand_new_intconst(t->type,lo,uVar5);
        tuple_append_src(t,pcVar2);
        t->op = 0x2d;
        add_sub_const_to_inc_dec(t);
        return 0;
      }
      pcVar2 = operand_new_intconst(t->type,lo,uVar5);
      tuple_replace_src(t,t_reg->next,pcVar2);
      t->op = 0x2d;
      add_sub_const_to_inc_dec(t);
      return 0;
    }
    if (t_reg->next != (c2_operand *)0x0) {
      tuple_remove_src(t,t_reg->next);
    }
    if ((lo != 1) || (uVar4 = 0x21, uVar5 != 0)) {
      uVar4 = 0x1e;
    }
    t->op = uVar4;
    return 0;
  }
  *next = t->next;
  tuple_unlink_free(t);
  return 1;
}

