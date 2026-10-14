void __fastcall sr_queue_dead_iv_tuples(c2_operand *op,c2_tuple *t)

{
  c2_operand *opnd;
  c2_tuple *t_00;
  int iVar1;
  uint32_t uVar2;
  
  if ((((op != (c2_operand *)0x0) && (t->op != 0x15b)) && (t->kind == '\f')) &&
     (((t->dst != (c2_operand *)0x0 && (iVar1 = operand_compare(op,t->dst), iVar1 == 0)) &&
      (iVar1 = iv_pending_free_add_unique(t), iVar1 != 0)))) {
    t_00 = t->prev;
    for (opnd = t->src; opnd != (c2_operand *)0x0; opnd = opnd->next) {
      uVar2 = is_induction_variable_operand(opnd);
      if (uVar2 != 0) {
        symbol_remove_use(opnd->sym,t);
      }
      sr_queue_dead_iv_tuples(opnd,t_00);
    }
  }
  return;
}

