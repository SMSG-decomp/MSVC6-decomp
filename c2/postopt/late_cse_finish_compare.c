void __fastcall late_cse_finish_compare(c2_tuple *t,c2_operand *op)

{
  uint32_t uVar1;
  c2_operand *new_op;
  c2_operand *old;
  c2_tuple *pcVar2;
  
  if ((((t->op == 0x2f) && (new_op = t->src, new_op->kind == '\x01')) &&
      (old = new_op->next, old->kind == '\a')) && ((old->u18).reg == (c2_symbol *)0x0)) {
    t->op = 0x33;
    tuple_replace_src(t,old,new_op);
  }
  t->flags = t->flags & 0xfb;
  pcVar2 = t;
  do {
    do {
      pcVar2 = pcVar2->prev;
    } while ((pcVar2->flags & 1) == 0);
  } while ((op != pcVar2->dst) && (op != pcVar2->src));
  uVar1 = t->op;
  pcVar2->flags = pcVar2->flags & 0xfb;
  if ((uVar1 == 1) && (t->src->kind == '\x01')) {
    if ((t->dst->kind == '\x01') && ((t->dst->u18).reg == (t->src->u18).reg)) {
      tuple_unlink_free(t);
    }
  }
  return;
}

