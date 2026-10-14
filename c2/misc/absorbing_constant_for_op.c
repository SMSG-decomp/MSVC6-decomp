c2_operand * __fastcall absorbing_constant_for_op(uint32_t op,uint16_t type)

{
  uint16_t uVar1;
  c2_float_const *fconst;
  c2_operand *pcVar2;
  c2_const_operand *pcVar3;
  uint64_t uVar4;
  
  if ((op == 0x16f) || (op == 0x172)) {
    if ((1 << (byte)(type >> 0xc) & 0xeU) != 0) {
      pcVar3 = operand_new_intconst(type,0,0);
      return pcVar3;
    }
    if ((type & 0xf000) == 0x4000) {
      fconst = arena_alloc(0,0xc);
      fconst->mantissa_low = g_ld_const_zero.mantissa_low;
      fconst->mantissa_high = g_ld_const_zero.mantissa_high;
      uVar1 = g_ld_const_zero.size_tag;
      fconst->exp_sign = g_ld_const_zero.exp_sign;
      fconst->size_tag = uVar1;
      pcVar2 = operand_new_fconst(type,fconst);
      return pcVar2;
    }
  }
  else if (op != 0x173) {
    return (c2_operand *)0x0;
  }
  uVar4 = const_normalize(type,0xffffffff,-1);
  pcVar3 = operand_new_intconst(type,(uint32_t)uVar4,(int32_t)(uVar4 >> 0x20));
  return pcVar3;
}

