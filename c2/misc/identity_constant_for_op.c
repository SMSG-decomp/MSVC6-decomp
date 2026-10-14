c2_operand * __fastcall identity_constant_for_op(uint32_t op,uint16_t type)

{
  uint16_t uVar1;
  c2_const_operand *pcVar2;
  c2_float_const *value;
  c2_operand *fconst_opnd;
  c2_float_const *value_template;
  uint64_t uVar3;
  
  if ((1 << (byte)(type >> 0xc) & 0xeU) == 0) {
    if ((type & 0xf000) == 0x4000) {
      switch(op) {
      case 0x16d:
      case 0x16e:
        value_template = &g_ld_const_zero;
        break;
      case 0x16f:
      case 0x175:
        value_template = &g_ld_const_one;
        break;
      default:
        goto switchD_1070a7fb_caseD_170;
      }
      value = arena_alloc(0,0xc);
      value->mantissa_low = value_template->mantissa_low;
      value->mantissa_high = value_template->mantissa_high;
      uVar1 = value_template->size_tag;
      value->exp_sign = value_template->exp_sign;
      value->size_tag = uVar1;
      fconst_opnd = (c2_operand *)node_alloc('\t');
      fconst_opnd->type = type;
      fconst_opnd->sym = (c2_symbol *)value;
      fconst_opnd->op = 0x148;
      return fconst_opnd;
    }
  }
  else {
    switch(op) {
    case 0x16d:
    case 0x16e:
    case 0x171:
    case 0x173:
    case 0x174:
    case 0x177:
      pcVar2 = operand_new_intconst(type,0,0);
      return pcVar2;
    case 0x16f:
    case 0x175:
      pcVar2 = operand_new_intconst(type,1,0);
      return pcVar2;
    case 0x172:
switchD_1070a7fb_caseD_172:
      uVar3 = const_normalize(type,0xffffffff,-1);
      pcVar2 = operand_new_intconst(type,(uint32_t)uVar3,(int32_t)(uVar3 >> 0x20));
      return pcVar2;
    case 0x176:
      if ((type & 0xf000) != 0x1000) goto switchD_1070a7fb_caseD_172;
    }
  }
switchD_1070a7fb_caseD_170:
  return (c2_operand *)0x0;
}

