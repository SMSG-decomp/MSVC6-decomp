c2_operand * __fastcall split_make_memory_use(c2_tuple *t,c2_operand *op)

{
  uint8_t *puVar1;
  uint uVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  
  op->rank = 0;
  uVar2 = can_use_memory_operand(t,op);
  if ((uVar2 != 0) && ((t->op != 0xd || (g_opt_favor_speed == 0)))) {
    operand_make_sym(op);
    return op;
  }
  operand_make_sym(op);
  pcVar3 = tuple_new_unary_temp(1,op->type,op,tuple_insert_before,t);
  pcVar4 = pcVar3->dst;
  pcVar4->flags11 = pcVar4->flags11 | 0x10;
  if ((op->type & 0xfff) == 1) {
    puVar1 = &((pcVar4->u18).reg)->flags5;
    *puVar1 = *puVar1 | 0x80;
  }
  pcVar4 = tuple_replace_src(t,op,pcVar4);
  pcVar4->flags11 = pcVar4->flags11 | 0x10;
  return pcVar4;
}

