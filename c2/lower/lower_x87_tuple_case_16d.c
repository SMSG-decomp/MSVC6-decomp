c2_tuple * lower_x87_tuple_case_16d(c2_tuple *t,uint32_t il_op,c2_tuple *result)

{
  uint32_t uVar1;
  
  uVar1 = lookup_opcode_pair_table(g_il_to_x87_op_table,il_op);
  t->op = uVar1;
  lower_x87_binary_op(t);
  return result;
}

