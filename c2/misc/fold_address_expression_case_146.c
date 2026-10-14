void fold_address_expression_case_146(int32_t disp,c2_tuple *t)

{
  c2_const_operand *op;
  
  t->op = 1;
  op = operand_new_intconst(t->type,disp,disp >> 0x1f);
  tuple_append_src(t,op);
  return;
}

