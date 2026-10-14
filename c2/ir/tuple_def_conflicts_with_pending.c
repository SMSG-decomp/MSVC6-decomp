int __fastcall tuple_def_conflicts_with_pending(c2_tuple *t,c2_symbol *s)

{
  c2_tuple *t_00;
  c2_tuple *first;
  c2_operand *op;
  int iVar1;
  uint uVar2;
  
  t_00 = (c2_tuple *)s->defs;
  iVar1 = tuple_kind_is_control(t_00);
  if ((iVar1 == 0) &&
     (((t_00->op != 0x15b || ((t_00->type & 0xf000) != 0x5000)) && (first = t->next, first != t_00))
     )) {
    for (op = t->src; op != (c2_operand *)0x0; op = op->next) {
      uVar2 = 1 << (op->kind & 0x1f);
      if ((((uVar2 & 0x380) == 0) && (((uVar2 & 6) == 0 || (op->sym->def == (c2_tuple *)0x0)))) &&
         (iVar1 = range_dst_may_alias(first,&t_00->prev->next,op), iVar1 != 0)) {
        return 1;
      }
    }
  }
  return 0;
}

