c2_tuple * __fastcall insert_pop_reg(int32_t reg,c2_tuple *after)

{
  c2_operand *esp_opnd;
  c2_operand *dst;
  c2_tuple *t;
  c2_insert_fn *insert_fn;
  
  insert_fn = tuple_insert_after;
  esp_opnd = operand_new_hardreg(5,0x1004);
  dst = operand_new_hardreg(reg,0x1004);
  t = tuple_new(0xc,0x1004,dst,esp_opnd,insert_fn,after);
  esp_opnd = operand_new_hardreg(5,0x1004);
  tuple_append_dst(t,esp_opnd);
  return t;
}

