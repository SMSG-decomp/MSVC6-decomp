void sahf_to_test_ah_case_1(c2_tuple *t,c2_tuple *branch)

{
  c2_operand *op;
  c2_const_operand *op_00;
  
  op_00 = operand_new_intconst(t->type,0x40,0);
  tuple_append_src(t,op_00);
  op = t->src;
  operand_set_type(op,t->type);
  (op->u18).reg = g_reg_symbols + 0x15;
  t->op = 0x33;
  *(undefined1 *)&branch->type = 2;
  return;
}

