c2_tuple * __fastcall insert_push_reg(int32_t reg,c2_tuple *after)

{
  c2_operand *src2;
  c2_operand *src1;
  c2_operand *dst;
  c2_tuple *pcVar1;
  c2_insert_fn *insert_fn;
  
  insert_fn = tuple_insert_after;
  src2 = operand_new_hardreg(5,0x1004);
  src1 = operand_new_hardreg(reg,0x1004);
  dst = operand_new_hardreg(5,0x1004);
  pcVar1 = tuple_new_binary(0xd,0x1004,dst,src1,src2,insert_fn,after);
  return pcVar1;
}

