c2_operand * __fastcall tuple_add_flags_result(c2_tuple *t)

{
  c2_operand *op;
  
  op = operand_new_temp_in_reg(0x42,0x8000);
  tuple_append_dst(t,op);
  op->sym->def = t;
  return op;
}

