void __fastcall reader_discard_value(c2_tuple *t)

{
  c2_operand *old;
  c2_operand *pcVar1;
  c2_const_operand *new_op;
  c2_operand *op;
  
  old = t->src->next;
  if ((((1 << (old->kind & 0x1f) & 6U) != 0) && (op = old, old->sym->def != (c2_tuple *)0x0)) ||
     (((old->kind == 6 &&
       ((op = old->base, op == (c2_operand *)0x0 ||
        (((1 << (op->kind & 0x1f) & 6U) != 0 && (op->sym->def != (c2_tuple *)0x0)))))) &&
      ((pcVar1 = old->index, pcVar1 == (c2_operand *)0x0 ||
       (((1 << (pcVar1->kind & 0x1f) & 6U) != 0 && (pcVar1->sym->def != (c2_tuple *)0x0)))))))) {
    tuple_drop_unused_results(op);
  }
  new_op = operand_new_intconst(0x1004,0,0);
  tuple_replace_src(t,old,new_op);
  return;
}

