void __fastcall
emit_mul_by_pow2(int32_t multiplier,int32_t partial,c2_operand **value,c2_tuple *anchor)

{
  uint16_t type;
  uint lo;
  c2_mul_decomp *step;
  c2_const_operand *src2;
  c2_tuple *pcVar1;
  
  lo = 0;
  do {
    partial = partial * 2;
    lo = lo + 1;
  } while (multiplier != partial);
  if (lo < 4) {
    step = mul_decomp_lookup(1 << ((byte)lo & 0x1f));
    emit_mul_decomposition(step,value,anchor);
    return;
  }
  type = anchor->type;
  src2 = operand_new_intconst(type,lo,0);
  pcVar1 = tuple_new_binary_temp(0x171,type,*value,src2,tuple_insert_before,anchor);
  *value = pcVar1->dst;
  return;
}

