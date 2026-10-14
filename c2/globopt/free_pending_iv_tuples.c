void free_pending_iv_tuples(void)

{
  c2_operand *opnd;
  c2_tuple *t;
  uint32_t uVar1;
  
  t = iv_pending_free_pop();
  while (t != (c2_tuple *)0x0) {
    for (opnd = t->src; opnd != (c2_operand *)0x0; opnd = opnd->next) {
      uVar1 = is_induction_variable_operand(opnd);
      if (uVar1 != 0) {
        symbol_remove_use(opnd->sym,t);
      }
    }
    tuple_unlink_free(t);
    t = iv_pending_free_pop();
  }
  return;
}

