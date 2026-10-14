c1_node * __thiscall conv_build_floating_constant(c1_conversion *conv,c1_node *dest)

{
  c1_u32 *pcVar1;
  char cVar2;
  c1xx_float_const *pcVar3;
  c1_node *pcVar4;
  c1xx_float_const cStack_c;
  
  cVar2 = conv_constant_warnings_enabled(conv);
  if (cVar2 != '\0') {
    conv_warn_float_truncation_2(conv->op,conv->expr,conv->target);
  }
  pcVar1 = conv->expr->left;
  cStack_c.mantissa_lo = *pcVar1;
  cStack_c.mantissa_hi = pcVar1[1];
  cStack_c._8_4_ = pcVar1[2];
  pcVar3 = conv_float_constant_for_target(conv,&cStack_c);
  conv->expr->left = pcVar3;
  conv->expr->type = conv->target;
  if (dest != (c1_node *)0x0) {
    pcVar4 = conv_store_converted_value(conv,dest,conv->expr);
    return pcVar4;
  }
  return conv->expr;
}

