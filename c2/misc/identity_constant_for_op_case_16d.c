c2_operand * identity_constant_for_op_case_16d(uint16_t type)

{
  uint16_t uVar1;
  c2_float_const *value;
  c2_operand *fconst_opnd;
  
  value = arena_alloc(0,0xc);
  value->mantissa_low = g_ld_const_zero.mantissa_low;
  value->mantissa_high = g_ld_const_zero.mantissa_high;
  uVar1 = g_ld_const_zero.size_tag;
  value->exp_sign = g_ld_const_zero.exp_sign;
  value->size_tag = uVar1;
  fconst_opnd = (c2_operand *)node_alloc('\t');
  fconst_opnd->type = type;
  fconst_opnd->sym = (c2_symbol *)value;
  fconst_opnd->op = 0x148;
  return fconst_opnd;
}

