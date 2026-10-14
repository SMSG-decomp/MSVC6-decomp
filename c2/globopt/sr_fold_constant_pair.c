void __fastcall sr_fold_constant_pair(c2_tuple *t,c2_operand *a,c2_operand *b,int op,c2_operand *x)

{
  c2_symbol *pcVar1;
  uint32_t uVar2;
  c2_const_operand *new_op;
  uint16_t type;
  
  if (a->kind == '\a') {
    pcVar1 = (a->u18).reg;
    uVar2 = (b->u18).lo;
  }
  else {
    pcVar1 = (c2_symbol *)a->sym->offset;
    uVar2 = b->sym->offset;
  }
  if (op == 0x16d) {
    uVar2 = (int)pcVar1 - uVar2;
    type = t->src->next->type;
  }
  else {
    uVar2 = (int)pcVar1 / (int)uVar2;
    type = t->src->next->type;
  }
  new_op = operand_new_intconst(type,uVar2,(int)uVar2 >> 0x1f);
  tuple_replace_src(t,t->src->next,new_op);
  tuple_replace_src(t,t->src,x);
  return;
}

